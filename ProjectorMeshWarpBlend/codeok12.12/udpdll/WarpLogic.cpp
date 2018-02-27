#include "WarpLogic.h"
#include <ostream>
#include <string>
#include <algorithm>

// Static variables
WarpLogic* WarpLogic::m_pInstance = NULL;

WarpLogic::WarpLogic( )
: m_bViewProjectionCreated( false ), m_compactCommunication()
, m_bDrawEdgeBlendMatricesAsOneTexture( false ), num_edge(0)
, m_uiWindowXWidth( 0 ), m_uiWindowYHeight( 0 ), breceivewhite(false), m_edge_alpha(false),
 m_start(true), m_end(false), numProj(0), m_state(false), mark_clip(0),line_clip(0)
{
	m_pLogger = Logger::GetInstance();

	m_pMesh = Mesh::GetInstance();
	// These render states will be set before soft warp start rendering.
	// After rendering the old render states will be reset.
	m_pMesh->m_uiWindowXWidth = m_uiWindowXWidth;
	m_pMesh->m_uiWindowYHeight = m_uiWindowYHeight;
	
//	m_fScaleIndataX = m_pConfig
	Whitelevel["WHITE10"] = false;
	//Whitelevel.insert(std::pair <string, bool>("WHITE102", false));
	//Whitelevel.insert(std::make_pair("WHITE101", false));
	Whitelevel["WHITE50"] = false;
	Whitelevel["WHITE90"] = false;
	
}

WarpLogic::~WarpLogic( void )
{
}

WarpLogic* WarpLogic::GetInstance( void )
{
	if ( m_pInstance == NULL )
		m_pInstance = new WarpLogic();

	return m_pInstance;
}

void  WarpLogic::getAllID(std::string& filename, int &num)
{
	//load seq
	
	m_compactCommunication.getAllID(filename, num, m_uiWindowXWidth, m_uiWindowYHeight);
	numProj = m_compactCommunication.m_numProj;
	save_vec.resize(numProj);
	m_pMesh->m_uiWindowXWidth = m_uiWindowXWidth;
	m_pMesh->m_uiWindowYHeight = m_uiWindowYHeight;
}


void WarpLogic::StartCommunication()
{
	m_compactCommunication.StartCommunication();
}

void WarpLogic::Draw(int &num)
{

//m_pLogger->Write(Logger::LOG_DEBUG, "WarpLogic::Draw");
	NetworkProcess(num);
}

void WarpLogic::NetworkProcess(int &fornum)
{
	CUDPWrapper* pCUDPWrapper;
	int receive_seriel_num(0);
	while ( ( pCUDPWrapper = m_compactCommunication.ReceiveMessage(receive_seriel_num) ) != NULL )
	{
		
		DecodeUDPWrapper( pCUDPWrapper, fornum, receive_seriel_num);
	}
}

void WarpLogic::DecodeUDPWrapper(CUDPWrapper* pCUDPWrapper, int &fornum,int &receive_proj)
{

	//std::lock_guard<std::mutex> locker(m_mutex_receive);
	//std::ostream &outf = std::cout;
	int cur_proj_seriel(0);
	 cur_proj_seriel = receive_proj;
	 std::wofstream outf("data_log_1025.txt", std::ios::out | std::ios::app);
	 outf.imbue(std::locale("chs"));
	 outf.imbue(locale("", locale::all ^ locale::numeric));
	outf << "Num: " << fornum++ << "\n";
	outf << " ....Record Operation and data.... "<<std::endl;
	int numx(0), numy(0);
	int m(0), n(0);
	int posi = (0);
	const CRecordBase* pUnknownReq = NULL;
	unsigned short usType;
	bool bDecoded = false;
	list<WarpMatrix*>::iterator warpMatrixIterator;
	list<EdgeBlendMatrix*>::iterator edgeBlendMatrixIterator;
	
	while (pUnknownReq = pCUDPWrapper->GetNextDataRecord(pUnknownReq))
	{
		switch (usType = pUnknownReq->GetRecordType())
		{

		case CV_DRAWLINE:		
			CCVDrawLineRecord *	pCCVDrawLineRecord;
			pCCVDrawLineRecord = (CCVDrawLineRecord*)pUnknownReq;
		
			outf <<"line: "/*<< pCCVDrawLineRecord->GetPosX()<<" "
				<< pCCVDrawLineRecord->GetPosY() << " "
				<< pCCVDrawLineRecord->GetStyle()<<endl*/;
			outf << " 通道   " << cur_proj_seriel << endl;
			{
				if (pCCVDrawLineRecord->GetStyle() == 0)
				{
					//true if the container size is 0  如果它不为空，把上一个线数组压入，，所以最后一个接受不到，line_vec为空了
					if (!line_vec.empty()) 
					{
						drawline_vec.push_back(line_vec);
						line_vec.swap(std::vector<Point2f>());
						line_clip++;
					}
				}
			Point2f pf2(pCCVDrawLineRecord->GetPosX(), pCCVDrawLineRecord->GetPosY(), pCCVDrawLineRecord->GetStyle(), 0);
			//m_pInstance->line_vec.push_back(pf2);
			line_vec.push_back(pf2);
			
			}
			break;

		case CV_DRAWTEXT:
			CCVDrawTextRecord *	pCCVDrawTextRecord;
			pCCVDrawTextRecord = (CCVDrawTextRecord*)pUnknownReq;
			{
				std::string mark;
				pCCVDrawTextRecord->GetText().GetSZ((char*)mark.c_str());
				Point2font p2str(pCCVDrawTextRecord->GetPosX(), pCCVDrawTextRecord->GetPosY(), mark.c_str());
				mark_vec.push_back(p2str);
				mark_clip++;
			}outf << "text 通道   " << cur_proj_seriel << endl;
			break;

		case 	CV_DRAWCTRL:
			CCVDrawCtrlRecord *	pCCVDrawCtrlRecord;
			pCCVDrawCtrlRecord = (CCVDrawCtrlRecord*)pUnknownReq;
			outf << "ctrl: " << pCCVDrawCtrlRecord->GetControl() << " "
				<< endl; outf << " 通道   " << cur_proj_seriel << endl;
			{ 
				int ctrl = pCCVDrawCtrlRecord->GetControl();
				if (ctrl != 1)
				{
					drawline_ctrl.push_back(ctrl); 
					mark_clip_vec.push_back(mark_clip);
					line_clip_vec.push_back(line_clip);
				}
			//接收geometry开关 line 完毕， many 先横线 many在竖线
			if (drawline_ctrl.size()== 2* numProj)
			{			
				for (int i=0;i<numProj;i++)					
					if (/*drawline_ctrl[i] == 1 && */drawline_ctrl[2*i] == 2	&& drawline_ctrl[2 * i +1] == 4)					
					{
						if (i == numProj - 1)
						{
							drawline_vec.push_back(line_vec); line_vec.swap(std::vector<Point2f>());
							m_pMesh->bGetDrawline = true;
							//两种机制，在这里赋值，还是在mesh中赋值，bool量
							bool waitkey = false;
							while (waitkey)
							{							
								if (m_pMesh->bGetDrawline_receiveok)
								{
									waitkey = false;
									line_clip = 0; mark_clip = 0;
									std::vector <int>().swap(line_clip_vec);
									std::vector <int>().swap(mark_clip_vec);
									std::vector <int>().swap(drawline_ctrl);
									std::vector <Point2font>().swap(mark_vec);

									std::vector <std::vector<Point2f>>().swap(drawline_vec);
									m_pMesh->bGetDrawline_receiveok = false;
									m_pMesh->bGetDrawline = false;
									break;
								}
							}
						}
					}
			}
			
			}
			break;


		case CV_DRAWFILE:
			CCVDrawFileRecord *	pCCVDrawFileRecord;
			pCCVDrawFileRecord = (CCVDrawFileRecord*)pUnknownReq;
			outf << "file: " <<   " "
				<< pCCVDrawFileRecord->GetStyle() <<" "; outf << " 通道   " << cur_proj_seriel << endl;
			{
				char str[100];
				 pCCVDrawFileRecord->GetFileName().GetSZ(str);
// 				 for (int i = 0; i < pCCVDrawFileRecord->GetFileName().GetLength() + 1;  i++)
// 					 cout << str[i];
// 				 cout << endl;			

				 std::map<std::string, bool>::iterator it;
				 for ( it =  Whitelevel.begin();it != Whitelevel.end();it++)
					 if (strcmp((it->first).c_str(), str) == 0) {
						 it->second = true;		 
						 breceivewhite = true; break;
					 }
					 else
				         it->second = false;
				 if (breceivewhite) {
					 m_pMesh->bGetWhitepattern = true;
					 breceivewhite = false;
				 }
    		}
			break;

			
		case CV_GEOMETRY_V1:   //nurbs

			
			const CCVGeometryRecord_V1* pCCVGeometryRecord_V1;
			pCCVGeometryRecord_V1 = (CCVGeometryRecord_V1*)pUnknownReq;
			
			WarpMatrix::interpolation_nurbs = true;
			WarpMatrix::interpolation_poly = false;
			WarpMatrix::nurb_x_order = (int)pCCVGeometryRecord_V1->GetucDegreeX();
			WarpMatrix::nurb_y_order = (int)pCCVGeometryRecord_V1->GetucDegreeY();

			CreateWarpMatrix(AHANDLE_NURBSMESHADJUSTMENT, pCCVGeometryRecord_V1->GetucControlPointsX(),
				pCCVGeometryRecord_V1->GetucControlPointsY(), cur_proj_seriel);

			m_pLogger->Write(Logger::LOG_DEBUG, "WarpLogic::DecodeUDPWrapper, Received CV_GEOMETRY_V1 with handle: ",
				AHANDLE_NURBSMESHADJUSTMENT);
			numx = pCCVGeometryRecord_V1->GetucControlPointsX();
			numy = pCCVGeometryRecord_V1->GetucControlPointsY();
			outf << "CV_geometry_V1: "
				<< "GeometryRecord: " << numx << " " << numy;
			outf << "  usType  "<< usType  << L" 通道   " << cur_proj_seriel << endl;

			break;
		case CV_GEOMETRY_V2:   //polys
		case CV_GEOMETRY_V3:

			const CCVGeometryRecord_V2* pCCVGeometryRecord_V2;
			pCCVGeometryRecord_V2 = (CCVGeometryRecord_V2*)pUnknownReq;
			if ((int)pCCVGeometryRecord_V2->GetucInterpolationMode())
			{
				WarpMatrix::interpolation_poly = true;
				WarpMatrix::interpolation_nurbs = false;
				//WarpMatrix::RenderMatrix::interpolation_poly = true;
				//m_pInstance->interpolation_poly
			}
			else
				WarpMatrix::interpolation_nurbs = true; //不会执行
			WarpMatrix::nurb_x_order = (int)pCCVGeometryRecord_V2->GetucDegreeX();
			WarpMatrix::nurb_y_order = (int)pCCVGeometryRecord_V2->GetucDegreeY();

			CreateWarpMatrix(pCCVGeometryRecord_V2->GetulGeometryHandle(), pCCVGeometryRecord_V2->GetucControlPointsX(), pCCVGeometryRecord_V2->GetucControlPointsY(), cur_proj_seriel);
			
			m_pLogger->Write(Logger::LOG_DEBUG, "WarpLogic::DecodeUDPWrapper, Received CV_GEOMETRY_V2 or CV_GEOMETRY_V3 with handle: ", static_cast<int>(pCCVGeometryRecord_V2->GetulGeometryHandle()));
			numx = pCCVGeometryRecord_V2->GetucControlPointsX();
			numy = pCCVGeometryRecord_V2->GetucControlPointsY();			
			outf << "CV_geometry_V2_V3: "
				<< "GeometryRecord: " << numx << " " << numy;
			//outf << "  " << pCCVGeometryRecord_V2->GetucInterpolationMode() << "\n";
			outf << "  usType  " << usType << L" 通道   " << cur_proj_seriel << endl;
			break;

		case CV_GEOMETRYCONTROLPOINT_V1:
		case CV_GEOMETRYCONTROLPOINT_V2:
		case CV_GEOMETRYCONTROLPOINT_V3:
			Matrix::Cell cell; 
			const CCVGeometryControlPointRecord* pCCVGeometryControlPointRecord;
			pCCVGeometryControlPointRecord = (CCVGeometryControlPointRecord*)pUnknownReq;	
			//一个WarpMatrix 一个句柄，一个cell_ID一个句柄
			m_pMesh->bGetAllMesh = false;
			if (GetWarpMatrix(pCCVGeometryControlPointRecord->GetulGeometryHandle(), warpMatrixIterator, cur_proj_seriel))
			{
				m = pCCVGeometryControlPointRecord->GetusIX();
				n = pCCVGeometryControlPointRecord->GetusIY();

				cell.fXPos = static_cast<float>(pCCVGeometryControlPointRecord->GetdX() - 0.5); // - 0.5 to make the coordinates, from CompactControl, center on (0.0, 0.0)
				cell.fYPos = static_cast<float>(pCCVGeometryControlPointRecord->GetdY() - 0.5); // - 0.5 to make the coordinates, from CompactControl, center on (0.0, 0.0)
				(WarpMatrix*)(*warpMatrixIterator)->SetCellValue(m, n, cell);
				outf << "CV_geometryControlPoint_V1_V2_V3: "
					<< "handle: " << pCCVGeometryControlPointRecord->GetulGeometryHandle() << "  "
					<< "cell: " << cell.fXPos << " " << cell.fYPos << " "
					<< "ControlPointRecord: " << m << " " << n
					<< " usType " << usType << L"  通道" << cur_proj_seriel;
				outf << "\n";
			}
			m_pLogger->Write(Logger::LOG_DEBUG, "WarpLogic::DecodeUDPWrapper, Received CV_GEOMETRYCONTROLPOINT_V1, CV_GEOMETRYCONTROLPOINT_V2 or CV_GEOMETRYCONTROLPOINT_V3");
			m_pMesh->bGetAllMesh = true;

			break;


		case CV_EDGE_V2:  //采样小与2 控制小与17
			const CCVEdgeRecord* pCCVEdgeRecord;
			pCCVEdgeRecord = (CCVEdgeRecord*)pUnknownReq;
			m_pLogger->Write(Logger::LOG_DEBUG, "WarpLogic::DecodeUDPWrapper, Received CV_EDGE_V2");
			break;

		case CV_EDGESAMPLE_V2: //融合带边的坐标
			m_pMesh->bGetAllEdge = false;
			const CCVEdgeSampleRecord* pCCVEdgeSampleRecord;
			pCCVEdgeSampleRecord = (CCVEdgeSampleRecord*)pUnknownReq;
			WarpMatrix::interpolation_poly = true;
			WarpMatrix::interpolation_nurbs = false;

			cout << cur_proj_seriel << endl;
			CreateEdgeBlendMatrix(pCCVEdgeSampleRecord->GetulEdgeHandle(), cur_proj_seriel);
			if (GetEdgeBlendMatrix(pCCVEdgeSampleRecord->GetulEdgeHandle(), edgeBlendMatrixIterator, cur_proj_seriel))
			{
				cell.fXPos = static_cast<float>(pCCVEdgeSampleRecord->GetfX() - 0.5f);
				cell.fYPos = static_cast<float>(pCCVEdgeSampleRecord->GetfY() - 0.5f);
				(*edgeBlendMatrixIterator)->SetCellValue(pCCVEdgeSampleRecord->GetusSample(), cell, pCCVEdgeSampleRecord->GetfLevel());
										
			}
			m_pLogger->Write(Logger::LOG_DEBUG, "WarpLogic::DecodeUDPWrapper, Received CV_EDGESAMPLE_V2");
			
			outf << "CV_EDGESAMPLE_V2: "<<" channel: "<<cur_proj_seriel
				<< "  handle: " << pCCVEdgeSampleRecord->GetulEdgeHandle() << "  "
				<< " cell: " << cell.fXPos << " " << cell.fYPos
				<< " sample: " << pCCVEdgeSampleRecord->GetusSample()
				<< " level: " << pCCVEdgeSampleRecord->GetfLevel();
			outf << "\n"; m_pMesh->bGetAllEdge = true; 
			break;

		case CV_EDGEALPHA://融合带中间颜色衰减   Edge Adjustment 包括参数 Alpha和Edge Gamma   2*17 -> 49*3
			//滑动两个滑动条和调节4根线 都会改变融合带
			const CCVEdgeAlphaRecord* pCCVEdgeAlphaRecord;
			pCCVEdgeAlphaRecord = (CCVEdgeAlphaRecord*)pUnknownReq;

			if (GetEdgeBlendMatrix(pCCVEdgeAlphaRecord->GetulEdgeHandle(), edgeBlendMatrixIterator, cur_proj_seriel))
			{
 				(*edgeBlendMatrixIterator)->SetEdgeBlendAlpha(pCCVEdgeAlphaRecord->GetusEntry(),
 					pCCVEdgeAlphaRecord->GetusNEntries(),
 					pCCVEdgeAlphaRecord->GetusFirstEntry(),
 					pCCVEdgeAlphaRecord->GetusStep(), Alpha_vec);
				
				std::vector<std::pair<int,int>>::iterator it;
				/*int rever= 0;
				for (it = alpha_reverse_vec.begin();it != alpha_reverse_vec.end();it++)
				{	if (pCCVEdgeAlphaRecord->GetulEdgeHandle() == it->first)
						if (cur_proj_seriel == it->second)
							 break;
					rever+=1;				}*/
				reverse(Alpha_vec.begin(), Alpha_vec.end());
// 				if (!(rever % 2))
// 					reverse(Alpha_vec.begin(), Alpha_vec.end());
								
				(*edgeBlendMatrixIterator) ->alpha_vec = Alpha_vec;

				m_pMesh->bGetAllEdgetex = true;
     			m_pMesh->bGetAllEdge = true;
				m_pMesh->bGetAllMesh = true;
				   // m_edge_alpha = true;
			}
			m_pLogger->Write(Logger::LOG_DEBUG, "WarpLogic::DecodeUDPWrapper, Received CV_EDGEALPHA");
			outf << "CV_EDGEALPHA: "<< "channel "<<cur_proj_seriel<<"\n";
			
			break;

		case CV_VALIDHANDLES:
			const CCVValidHandleRecord*	pCCVValidHandleRecord;
			const unsigned long*		aulHandle;
			unsigned long				ulHandle;
			pCCVValidHandleRecord = (CCVValidHandleRecord*)pUnknownReq;
			aulHandle = pCCVValidHandleRecord->GetulHandleArray();
			for (int iHandleIndex = 0; iHandleIndex < pCCVValidHandleRecord->GetusNHandles(); ++iHandleIndex)
			{
				ulHandle = aulHandle[iHandleIndex];
				RemoveObjects(ulHandle);
			}
			m_pLogger->Write(Logger::LOG_DEBUG, "WarpLogic::DecodeUDPWrapper, Received CV_VALIDHANDLES handle: ", static_cast<int>(ulHandle));			
			outf << "Received CV_VALIDHANDLES handle: "<< static_cast<int>(ulHandle) << "\n";
		
			//m_pMesh->bGetAllIDCoordination = true;
			break;

		default:
			//cout << usType << endl;
			m_pLogger->Write(Logger::LOG_DEBUG, "WarpLogic::DecodeUDPWrapper, Received unknown CRecordBase type: ", static_cast<int>(usType));		
			outf << "default: "<< usType<<"\n";			
			WarpMatrix::interpolation_nurbs = false;
			WarpMatrix::interpolation_poly = false;
			m_pMesh->bGetAllMesh = false;
			m_pMesh->bGetAllEdge = false;
			m_pMesh->bGetAllEdgetex = false;
			m_pMesh->bGetDrawline = false;
			
			break;
		}
	}

	outf << " ...end.. \n";	
	outf.close();
}

void WarpLogic::RemoveObjects( const unsigned long ulHandle )
{

}

void WarpLogic::RemoveWarpMatrix(list<WarpMatrix*>::iterator& warpMatrixIterator)
{
	list<WarpMatrix*>::iterator tmp = warpMatrixIterator++;
	m_warpMatrixList.erase(tmp);
}

bool WarpLogic::FindWarpMatrix(const unsigned long ulHandle)
{
	bool bFoundMatrix = false;

	for (list<WarpMatrix*>::iterator warpMatrixIterator = m_warpMatrixList.begin(); warpMatrixIterator != m_warpMatrixList.end(); warpMatrixIterator++)
	{
		if ((*warpMatrixIterator)->GetHandle() == ulHandle)
		{
			bFoundMatrix = true;
			break;
		}
	}

	return bFoundMatrix;
}

void WarpLogic::CreateWarpMatrix(const unsigned long ulHandle, const unsigned int uiColumns, const unsigned int uiRows,int &xuhao)
{
	list<WarpMatrix*>::iterator warpMatrixIterator;
	int position = 0; bool replace = false;

	if (save_vec[xuhao]) //已有
	{
		warpMatrixIterator = m_warpMatrixList.begin();
		for (; position < xuhao; position++)
			warpMatrixIterator++;
		WarpMatrix* pWarpMatrix;
		unsigned int uiColumnInterpolations = 16;
		unsigned int uiRowInterpolations = 16;
		pWarpMatrix = new WarpMatrix(uiColumns, uiRows, uiColumnInterpolations, uiRowInterpolations, ulHandle, m_uiWindowXWidth, m_uiWindowYHeight,0);
	
		testmutex2.lock();
		m_warpMatrixList.erase(warpMatrixIterator++);
		m_warpMatrixList.insert(warpMatrixIterator, pWarpMatrix);
		testmutex2.unlock();
	}
	else //未存
	{
		save_vec[xuhao] = true;

		//AddWarpMatrix(ulHandle, uiColumns, uiRows, warpMatrixIterator, replace, position);
		WarpMatrix* pWarpMatrix;
		unsigned int uiColumnInterpolations = 16;
		unsigned int uiRowInterpolations = 16;

		pWarpMatrix = new WarpMatrix(uiColumns, uiRows, uiColumnInterpolations, 
			uiRowInterpolations, ulHandle, m_uiWindowXWidth, m_uiWindowYHeight,0);
	
		testmutex2.lock();
		m_warpMatrixList.push_back(pWarpMatrix);
		testmutex2.unlock();
	}


}

bool WarpLogic::GetWarpMatrix(const unsigned long ulHandle, list<WarpMatrix*>::iterator& warpMatrix,int &num)
{
	bool bFoundMatrix = false;
	
	list<WarpMatrix*>::iterator tmp2 = m_warpMatrixList.begin();
	//for (, int ii = 0; warpMatrixIterator != m_warpMatrixList.end(), ii < num, ; warpMatrixIterator++, ii++)
	for (int ii = 0; ii < num ; ii++)
		tmp2++;
	warpMatrix = tmp2;

		bFoundMatrix = true;
	return bFoundMatrix;
}

void WarpLogic::AddWarpMatrix(const unsigned long ulHandle, const unsigned int uiColumns, const unsigned int uiRows,
	list<WarpMatrix*>::iterator& warpMatrixIterator, bool &replace,int &posi)
{
	WarpMatrix* pWarpMatrix;
	unsigned int uiColumnInterpolations;
	unsigned int uiRowInterpolations;

	m_pLogger->Write(Logger::LOG_INFO, "WarpLogic::AddWarpMatrix, Added matrix with handle: ", static_cast<int>(ulHandle));

	//控制点之间两两插值个数，务必16的倍数， （n-1）*16+1，这是插值后的点数，前面从0开始，每n-1，就是一个控制点，16+1  得到16个网格 17的显示点
	uiColumnInterpolations = 16;
	uiRowInterpolations = 16;
	pWarpMatrix = new WarpMatrix(uiColumns, uiRows, uiColumnInterpolations, uiRowInterpolations, ulHandle, m_uiWindowXWidth, m_uiWindowYHeight,0);

	testmutex2.lock();
	if (replace)
		m_warpMatrixList.insert(warpMatrixIterator,pWarpMatrix );
	else
		m_warpMatrixList.push_back(pWarpMatrix);	
	testmutex2.unlock();
}





void WarpLogic::CreateEdgeBlendMatrix(const unsigned long ulHandle,int &num)
{
	if (!FindEdgeBlendMatrix(ulHandle, num))
		AddEdgeBlendMatrix(ulHandle, 3, 17, num);
}

bool WarpLogic::FindEdgeBlendMatrix(const unsigned long ulHandle, int &num)
{
	bool bFoundMatrix = false;
	for (list<EdgeBlendMatrix*>::iterator edgeBlendMatrixIterator = m_edgeBlendMatrixList.begin(); edgeBlendMatrixIterator != m_edgeBlendMatrixList.end(); edgeBlendMatrixIterator++)
	{
		if ((*edgeBlendMatrixIterator)->GetHandle() == ulHandle && (*edgeBlendMatrixIterator)->GetHandlechannel() == num)
		{			
				bFoundMatrix = true;
				break;			
		}
	}

	return bFoundMatrix;
}

void WarpLogic::AddEdgeBlendMatrix(const unsigned long ulHandle, const unsigned int uiColumns, const unsigned int uiRows, int &num)
{
	EdgeBlendMatrix* pEdgeBlendMatrix;
	m_pLogger->Write(Logger::LOG_INFO, "WarpLogic::AddEdgeBlendMatrix, Added matrix with handle: ", static_cast<int>(ulHandle));

	pEdgeBlendMatrix = new EdgeBlendMatrix(uiColumns, uiRows, 1, 3, ulHandle,num); //插值成49*3  
	//出错会调用SetupCenteredMatrix 有插值 两个都是false 错误
	//pEdgeBlendMatrix->OnResetDevice(m_pD3DDevice);
	testmutex3.lock();
	m_edgeBlendMatrixList.push_back(pEdgeBlendMatrix);  
	testmutex3.unlock();

	alpha_reverse_vec.push_back(std::make_pair(ulHandle,num));

}

bool WarpLogic::GetEdgeBlendMatrix(const unsigned long ulHandle, list<EdgeBlendMatrix*>::iterator& edgeBlendMatrixIterator, int &num)
{
	bool bFoundMatrix = false;

	for (edgeBlendMatrixIterator = m_edgeBlendMatrixList.begin(); edgeBlendMatrixIterator != m_edgeBlendMatrixList.end(); edgeBlendMatrixIterator++)
	{
		if ((*edgeBlendMatrixIterator)->GetHandle() == ulHandle  && (*edgeBlendMatrixIterator)->GetHandlechannel() == num)
		{
			
				bFoundMatrix = true;
				break;
						
		}
	}

	return bFoundMatrix;
}

// 		case CV_CHANNELS:
// 			m_pLogger->Write(Logger::LOG_DEBUG, "WarpLogic::DecodeUDPWrapper, Received CV_CHANNELS");
// 			const CCVChannelsRecord* pCCVChannelsRecord;
// 			pCCVChannelsRecord = (CCVChannelsRecord*)pUnknownReq;
// 			pCCVChannelsRecord->
// 		case CV_EDGE_V1: //采样小与2 控制小与2
// 			m_pLogger->Write(Logger::LOG_DEBUG, "WarpLogic::DecodeUDPWrapper, Received CV_EDGE_V1");
// 			outf << "CV_EDGE_V1: ";
// 			outf << "\n";
// 			break;
// 		case CV_EDGESAMPLE_V1:
// 			const CCVEdgeSampleRecord* pCCVEdgeSampleRecord;
// 			pCCVEdgeSampleRecord = (CCVEdgeSampleRecord*)pUnknownReq;
// 			CreateEdgeBlendMatrix(pCCVEdgeSampleRecord->GetulEdgeHandle());
// 
// 			if (GetEdgeBlendMatrix(pCCVEdgeSampleRecord->GetulEdgeHandle(), edgeBlendMatrixIterator))
// 			{
// 				cell.fXPos = pCCVEdgeSampleRecord->GetfX() - 0.5f; // - 0.5 to make the coordinates, from CompactControl, center on (0.0, 0.0)
// 				cell.fYPos = pCCVEdgeSampleRecord->GetfY() - 0.5f; // - 0.5 to make the coordinates, from CompactControl, center on (0.0, 0.0)
// 				(*edgeBlendMatrixIterator)->SetCellValue(pCCVEdgeSampleRecord->GetusSample(), cell, pCCVEdgeSampleRecord->GetfLevel());
// 			}
// 			cout << "1 xxx " << cell.fXPos << "yyy " << cell.fYPos << endl;
// 			m_pLogger->Write(Logger::LOG_DEBUG, "WarpLogic::DecodeUDPWrapper, Received CV_EDGESAMPLE_V1");
// 			outf << "CV_EDGESAMPLE_V1: ";
// 			outf << "\n";
// 			break;

// case CV_DRAWRECT:
// 	CCVDrawRectRecord *	pCCVDrawRectRecord;
// 	pCCVDrawRectRecord = (CCVDrawRectRecord*)pUnknownReq;
// 	outf << "rect: " << pCCVDrawRectRecord->GetPosX0() << " "
// 		<< pCCVDrawRectRecord->GetPosX1() << " "
// 		<< pCCVDrawRectRecord->GetPosY0() << " "
// 		<< pCCVDrawRectRecord->GetPosY1() << " "
// 		<< pCCVDrawRectRecord->GetR() << " "
// 		<< pCCVDrawRectRecord->GetG() << " "
// 		<< pCCVDrawRectRecord->GetB() << " "
// 		<< endl;
// 	break;
// case CV_TPENCODED:
// 	break;
// case CV_DYNAMICTESTPATTERN:
// 	break;
// case CV_TESTPATTERN:
// 	break;

		//case CV_GAMMA_V2:  //Gamma Adjustment 单独的
		//	CCVGammaRecord *	pCCVGammaRecord;
		//	pCCVGammaRecord = (CCVGammaRecord*)pUnknownReq;
		//	m_pLogger->Write(Logger::LOG_DEBUG, "WarpLogic::DecodeUDPWrapper, Received CV_GAMMA_V2");
		//	outf << "CV_GAMMA_V2: "
		//		<< " handle: " << pCCVGammaRecord->GetucChannelMask()
		//		<< " NumOfValues: " << pCCVGammaRecord->GetusNEntries()
		//		<< " FirstIndex: " << pCCVGammaRecord->GetusFirstEntry()
		//		<< " IndexStepSize " << pCCVGammaRecord->GetusStep()
		//		<< " GAMMA: ";
		//	for (int iIndex = 0; iIndex < pCCVGammaRecord->GetusNEntries() - 1; ++iIndex)
		//	{
		//		float fAlpha = static_cast<float>(pCCVGammaRecord->GetusEntry()[iIndex]);
		//		outf << fAlpha << "  ";
		//		//cout << fAlpha << "  ";
		//	}
		//	//cout << "  1111111111111111111  " << endl;
		//	outf << " GAMMA  end ";
		//	outf << "\n";
		//	break;
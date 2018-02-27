#include "Mesh.h"


Mesh* Mesh::m_pMeshInstance = new Mesh();

Mesh::Mesh():bUpdateID(false),
bGetControlNum(false), bGetAllEdge(false), bGetAllMesh(false), bGetAllEdgetex(false), bGetDrawline(false), bGetWhitepattern(false),
num_contol_x (0),num_contol_y(0),
id_current(0),id_update(0), cur_cur(0),
 m_uiWindowXWidth(0), m_uiWindowYHeight(0),
mode_interpolation(-1), lastbool(true), numchannels(0)
, m_warplogic(0), colorvalue(0.0), bGetDrawline_receiveok(false)
{
	m_pMeshInstance = this;	
	m_warplogic = WarpLogic::GetInstance();
	texName = 0;
}

Mesh::~Mesh()
{
}

Mesh* Mesh::GetInstance()
{
	//if (m_pMeshInstance == NULL)
	//	m_pMeshInstance = new Mesh();
	return m_pMeshInstance;
}
void   Mesh::IdleFunction(void)
{
	//{std::lock_guard<std::mutex> lck(m_pMeshInstance->testmutex);
	//m_pMeshInstance->testmutex.lock();

	//网格nurbs polys 以及融合带
	if (m_pMeshInstance->bGetAllMesh)
	{
		showSplineMatrixcp(m_pMeshInstance->cur_cur);
		m_pMeshInstance->bGetAllMesh = false;

	}

	//测试模式的geometry
	if (m_pMeshInstance->bGetDrawline)
	{
		showDrawlinectrl();
		m_pMeshInstance->bGetDrawline = false;
	}

	//测试模式的white
	if (m_pMeshInstance->bGetWhitepattern)
	{
		showDrawwhitepattern();
		m_pMeshInstance->bGetWhitepattern = false;
	}
}


void Mesh::SplineMatrixcolor() {

	int width = m_pMeshInstance->m_uiWindowXWidth;
	int hight = m_pMeshInstance->m_uiWindowYHeight;
	int num = m_pMeshInstance->numchannels;

	std::list<WarpMatrix*>::iterator warpMatrixIterator = m_pMeshInstance->warpMatrixList.begin();
	float m(0.0), n(0.0);
	for (int l = 0; warpMatrixIterator != m_pMeshInstance->warpMatrixList.end(); warpMatrixIterator++, l++)
	{
		WarpMatrix* mat = *warpMatrixIterator; 

		glViewport(int(l* width / num), 0, int(width / num), hight);
		//glPointSize(6); //在begin之前有效

		int iColumnInterp = mat->m_splinedMatrix.GetNumOfColumns();
		int iRowInterp = mat->m_splinedMatrix.GetNumOfRows();

		int iColumnControl = (iColumnInterp - 1) / 16 + 1;
		int iRowControl = (iRowInterp - 1) / 16 + 1;

		glColor3f(0.8, 0.8, 0.8);
		for (int uiRowIndex = 0; uiRowIndex < iRowInterp - 1; ++uiRowIndex)
			for (int uiColumnIndex = 0; uiColumnIndex < iColumnInterp - 1; ++uiColumnIndex)
			{
				int tmp = uiColumnIndex + (uiRowIndex * iColumnInterp);
				if ((tmp + 1) % iColumnInterp == 0)
					continue;

				glBegin(GL_QUADS);
				Matrix::Cell cell;
				mat->m_splinedMatrix.GetCellValue(uiColumnIndex, uiRowIndex, cell);
				glVertex2f(cell.fXPos, cell.fYPos);
				mat->m_splinedMatrix.GetCellValue(uiColumnIndex + 1, uiRowIndex, cell);
				glVertex2f(cell.fXPos, cell.fYPos);
				mat->m_splinedMatrix.GetCellValue(uiColumnIndex + 1, uiRowIndex + 1, cell);
     			glVertex2f(cell.fXPos, cell.fYPos);
				mat->m_splinedMatrix.GetCellValue(uiColumnIndex, uiRowIndex + 1, cell);
				glVertex2f(cell.fXPos, cell.fYPos);

				glEnd();

			}
	}
}


void Mesh::showSplineMatrixcp(int &cur_num) {

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);
	m_pMeshInstance->warpMatrixList = m_pMeshInstance->m_warplogic->m_warpMatrixList;

	int width = m_pMeshInstance->m_uiWindowXWidth;
	int hight = m_pMeshInstance->m_uiWindowYHeight;
	int num = m_pMeshInstance->numchannels;  
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, width, hight);
	glColor3f(1, 1, 1);

	glBegin(GL_LINES);
	for (int i = 1; i < num; i++)
	{
		glVertex2f((i*2.0 / num) - 1.0, 1.0);
		glVertex2f((i*2. / num) - 1.0, -1.0);
	}
	glEnd();

	//画 网格中填充白色   黑背景
	m_pMeshInstance->SplineMatrixcolor();

	//画融合带 两条直线  几何网格矫正
	if (m_pMeshInstance->bGetAllEdge)
	{
		m_pMeshInstance->m_edgeBlendMatrixList = m_pMeshInstance->m_warplogic->m_edgeBlendMatrixList;
		m_pMeshInstance->showSplineMatrixEdge(m_pMeshInstance->cur_cur);
	}
	   

	//画网格16*16
	std::list<WarpMatrix*>::iterator warpMatrixIterator = m_pMeshInstance->warpMatrixList.begin();
	float m(0.0), n(0.0);
	for (int l = 0; warpMatrixIterator != m_pMeshInstance->warpMatrixList.end(); warpMatrixIterator++,l++) 
	{
		WarpMatrix* mat = *warpMatrixIterator; //m_pMeshInstance->splinedMatrix_vec[l];

		glViewport(int(l* width / num), 0, int(width / num), hight);
		//glPointSize(6); //在begin之前有效
		
		int iColumnInterp = mat->m_splinedMatrix.GetNumOfColumns(); //4-1*16 +1 = 49
		int iRowInterp = mat->m_splinedMatrix.GetNumOfRows();//3-1*16 +1 = 33
		int iColumnControl = (iColumnInterp-1)/16+1;  //4
		int iRowControl = (iRowInterp - 1) / 16 + 1;  //3

		int perinterpcols = (iColumnInterp - 1) / (iColumnControl - 1); //16
		int perinterprows = (iRowInterp - 1) / (iRowControl - 1);//16
		
		for (int uiColumnIndex = 0; uiColumnIndex < iColumnInterp; ++uiColumnIndex)
			for ( int uiRowIndex = 0; uiRowIndex < iRowInterp; ++uiRowIndex)  //行列插值点
			{
				Matrix::Cell cell;
				mat->m_splinedMatrix.GetCellValue (uiColumnIndex, uiRowIndex, cell);
				
				//画控制点和17个点				
				if (!(uiRowIndex % perinterprows) && !(uiColumnIndex % perinterpcols))//控制点
				{
					glPointSize(9);
					glBegin(GL_POINTS);
					glColor3f(1, 0, 0);  
					glVertex2f(cell.fXPos, cell.fYPos); 
					glEnd();




				}
				else if (!(uiRowIndex % (iRowControl - 1)) && !(uiColumnIndex % (iColumnControl - 1)))//17点
				{
					glPointSize(3);
					glBegin(GL_POINTS);
					glColor3f(0, 0, 0);
					glVertex2f(cell.fXPos, cell.fYPos);
					glEnd();
				}
				
			}

		//画控制点与原始控制点的连线
		glColor3f(0.8, 0.1, 0.5);
		for (int uiColumnIndex = 0; uiColumnIndex < iColumnInterp; ++uiColumnIndex)
		{			
			for (int uiRowIndex = 0; uiRowIndex < iRowInterp; ++uiRowIndex)  //行列插值点
			{
				Matrix::Cell cell;
				mat->m_splinedMatrix.GetCellValue(uiColumnIndex, uiRowIndex, cell);

				//画控制点和17个点
				glBegin(GL_LINES);
				if (!(uiRowIndex % perinterprows) && !(uiColumnIndex % perinterpcols))//控制点
				{				
					glVertex2f(cell.fXPos, cell.fYPos);
					float y = (float)(uiColumnIndex / perinterpcols) / (iColumnControl - 1) - 0.5;
					float x = (float)(uiRowIndex / perinterprows) / (iRowControl - 1.0) - 0.5;
					glVertex2f(y, x);
					
				}
				glEnd();
			}
		}

		glColor3f(0, 0,1);
		//画连线 对所有插值  画竖线再画横线,
		for (int i = 0; i < 2; i++)
		{
			for (int uiColumnIndex = 0; uiColumnIndex < iColumnInterp; ++uiColumnIndex)
			{
				glBegin(GL_LINE_STRIP);
				for (int uiRowIndex = 0; uiRowIndex < iRowInterp; ++uiRowIndex)  //行列插值点
				{
					Matrix::Cell cell;
					if (i)
					{
						mat->m_splinedMatrix.GetCellValue(uiRowIndex, uiColumnIndex, cell);
						if (!(uiColumnIndex % (iRowControl - 1)) && !(uiRowIndex % (iColumnControl - 1)))
					//	    glVertex2f(cell.fXPos, cell.fYPos);
						//if ((!uiRowIndex || !uiColumnIndex) &&  ( !(uiColumnIndex % perinterpcols) && !(uiRowIndex % perinterprows)))
							glVertex2f(cell.fXPos, cell.fYPos);
						
					}
					else
					{
						mat->m_splinedMatrix.GetCellValue(uiColumnIndex, uiRowIndex, cell);
						if (!(uiRowIndex % (iRowControl - 1)) && !(uiColumnIndex % (iColumnControl - 1)))
							glVertex2f(cell.fXPos, cell.fYPos);
					//	if ((!uiRowIndex || !uiColumnIndex) && (!(uiRowIndex % perinterpcols) && !(uiColumnIndex % perinterprows)))
					//		glVertex2f(cell.fXPos, cell.fYPos);
					}
				}
				glEnd();
			}
			int tmp = iColumnInterp;
			iColumnInterp = iRowInterp;
			iRowInterp = tmp;
		}
		
	}
		
	//m_pMeshInstance->bGetAllEdge = false;
	m_pMeshInstance->grabtf();
	glutSwapBuffers();
	

}

void Mesh::showSplineMatrixEdge(int &cur_num) {

	int width = m_pMeshInstance->m_uiWindowXWidth;
	int hight = m_pMeshInstance->m_uiWindowYHeight;
	int num = m_pMeshInstance->numchannels;
	
	//画融合带两线
	std::list<EdgeBlendMatrix*>::iterator warpMatrixIterator = m_pMeshInstance->m_edgeBlendMatrixList.begin();	

	for (; warpMatrixIterator != m_pMeshInstance->m_edgeBlendMatrixList.end(); warpMatrixIterator++) 
	{
		EdgeBlendMatrix* mat = *warpMatrixIterator;
		int channel = mat->GetHandlechannel();

		glViewport(int(channel* width / num), 0, int(width / num), hight);

			int iColumnInterp = mat->m_splinedMatrix.GetNumOfColumns();
			int iRowInterp = mat->m_splinedMatrix.GetNumOfRows();
			m_pMeshInstance->alpha_vec = mat->alpha_vec;
			
			for (int uiColumnIndex = 0; uiColumnIndex < iColumnInterp -1 ; ++uiColumnIndex)
			{
				glPointSize(3);
				if (uiColumnIndex)
					glPointSize(5);
				glColor3f(0, 0.5, 0.5);
				glBegin(GL_POINTS);
				for (int uiRowIndex = 0; uiRowIndex < iRowInterp; ++uiRowIndex)
				{
					Matrix::Cell cell;
					mat->m_splinedMatrix.GetCellValue(uiColumnIndex, uiRowIndex, cell);
					glVertex2f(cell.fXPos, cell.fYPos);
					//cout<<cell.fXPos<<" "<<cell.fYPos<<endl;  //x怎么反向呢
					if (uiColumnIndex == 0 && uiRowIndex == 0)
					{
						
					//融合带几何坐标
						//m_pMeshInstance->alpha_cor.resize(4);resize后 在pushback 是第五个元素
						// vecInt.swap(vector<int>()) ;
						vector <Matrix::Cell>().swap(m_pMeshInstance->alpha_cor); 
						m_pMeshInstance->alpha_cor.push_back(cell);
					}
					if (uiColumnIndex == 0 && uiRowIndex == iRowInterp - 1)
						m_pMeshInstance->alpha_cor.push_back(cell);
					if (uiColumnIndex == iColumnInterp - 2 && uiRowIndex == iRowInterp - 1)
					{
						//cell = m_pMeshInstance->alpha_cor.back();
						m_pMeshInstance->alpha_cor.push_back(cell);
						swap(m_pMeshInstance->alpha_cor[2], m_pMeshInstance->alpha_cor[3]);
					}
					if (uiColumnIndex == iColumnInterp - 2 && uiRowIndex == 0)
						m_pMeshInstance->alpha_cor.push_back(cell);

				}
				glEnd();

			}
	
			
		////画融合带纹理 纹理图片生成

 			int i = 0;
  			inittifusionzone(i);
  			//glClear(GL_COLOR_BUFFER_BIT);
  			glBindTexture(GL_TEXTURE_2D, m_pMeshInstance->texName);
  			glBegin(GL_QUADS);
   			glTexCoord2d(0, 0); glVertex3f(m_pMeshInstance->alpha_cor[1].fXPos, m_pMeshInstance->alpha_cor[1].fYPos, 0.0);			
  			glTexCoord2d(1, 0); glVertex3f(m_pMeshInstance->alpha_cor[2].fXPos, m_pMeshInstance->alpha_cor[2].fYPos, 0.0);
   			glTexCoord2d(1, 1); glVertex3f(m_pMeshInstance->alpha_cor[3].fXPos, m_pMeshInstance->alpha_cor[3].fYPos, 0.0);
  			glTexCoord2d(0, 1); glVertex3f(m_pMeshInstance->alpha_cor[0].fXPos, m_pMeshInstance->alpha_cor[0].fYPos, 0.0); 		
  			glEnd();
 
 			glDisable(GL_DEPTH_TEST);
 			glDisable(GL_TEXTURE_2D);
 			glDisable(GL_BLEND);
  			
  		    glFlush();
		}
	}




void Mesh::reshape(int w, int h)
{
	//坐标右下角 左右上下 
// 	glMatrixMode(GL_MODELVIEW);
// 	glLoadIdentity();
// 	gluOrtho2D(0, 1920, 0, 1080); 

//坐标中心 左右上下 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
	//gluOrtho2D(-0.5, 0.5, -0.5, 0.5);
}




void Mesh::show(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	//glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_STENCIL);
	glutInitWindowSize(m_pMeshInstance->m_uiWindowXWidth, m_pMeshInstance->m_uiWindowYHeight);
	glutInitWindowPosition(m_pMeshInstance->m_uiWindowXWidth, 0);
	glutCreateWindow("demo");
	
	//glutFullScreen();
	//glClearColor(0.0, 0.0, 0.0, 1);
	//glutSpecialFunc(&ProcessSpecialKeyboead);

	glutDisplayFunc(IdleFunction); //回调函数加入参数   线程函数传入参数
	//glutDisplayFunc(display2);
	glutReshapeFunc(reshape);   
	glutIdleFunc(&IdleFunction);

	//glBlendFunc(GL_SRC_ALPHA, GL_ONE);
	glutKeyboardFunc(KeysEvent);
	glutMainLoop();
	//glutMainLoopEvent();
	//sleep_(1000);
	
}


void Mesh::thread_task(){	
	int argc = 1;
	char* argv[] = { "" };
	show(argc, argv);	
}


// 融合带，49行，256列，每一行的数据都一样，做成纹理图
void Mesh::makeCheckImage(int &n) {
	int i, j, c;

	for (i = 0; i < checkImageHeight; i++) {
		for (j = 0; j < checkImageWidth; j++) {
				m_pMeshInstance->checkImage[i][j][0] = (GLubyte)204;
				m_pMeshInstance->checkImage[i][j][1] = (GLubyte)204;
				m_pMeshInstance->checkImage[i][j][2] = (GLubyte)204;
				/*if (j>200 && i>30)
					m_pMeshInstance->checkImage[i][j][3] = (GLubyte)(255 );
				else*/
				   m_pMeshInstance->checkImage[i][j][3] = (GLubyte)(255* m_pMeshInstance->alpha_vec[ j]);  
		}
	}

}

void Mesh::inittifusionzone(int& n) {

	 	glEnable(GL_DEPTH_TEST);
	 	glEnable(GL_TEXTURE_2D);
	 	glEnable(GL_BLEND);
	 	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	//glClearColor(0.0, 0.0, 0.0, 0.0);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//glShadeModel(GL_FLAT);
	glEnable(GL_TEXTURE_2D);

	makeCheckImage(n);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	//多视口要不要改成数组，同一张图贴到3个视口中去
	//另外测试时 每个视口要贴张灰度图，
	glGenTextures(1, &m_pMeshInstance->texName); 
	//cout <<"texture id "<< m_pMeshInstance->texName << endl;

	glBindTexture(GL_TEXTURE_2D, m_pMeshInstance->texName);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth, checkImageHeight,
		0, GL_RGBA, GL_UNSIGNED_BYTE, m_pMeshInstance->checkImage);

	//glDisable(GL_TEXTURE_2D);
}

void Mesh::initpatterntest(int &k) {

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	GLubyte ucolor = ((k - 1) * 4 + 1) * 25.5;
	int i, j, c;
	for (i = 0; i < checkImageHeight; i++) {
		for (j = 0; j < checkImageWidth; j++) {
			m_pMeshInstance->checkImage[i][j][0] = ucolor;
			m_pMeshInstance->checkImage[i][j][1] = ucolor;
			m_pMeshInstance->checkImage[i][j][2] = ucolor;
			m_pMeshInstance->checkImage[i][j][3] = 255;
		}
	}

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	//多视口要不要改成数组，同一张图贴到3个视口中去
	//另外测试时 每个视口要贴张灰度图，
	glGenTextures(1, &m_pMeshInstance->texName);

	glBindTexture(GL_TEXTURE_2D, m_pMeshInstance->texName);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);

	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, checkImageWidth, checkImageHeight,
		0, GL_RGBA, GL_UNSIGNED_BYTE, m_pMeshInstance->checkImage);

	//glDisable(GL_TEXTURE_2D);
}


/* 函数grab
* 抓取窗口中的像素
* 假设窗口宽度为WindowWidth，高度为WindowHeight
*/
#define BMP_Header_Length 54
void Mesh::grabtf(void)
{
	FILE*     pDummyFile;
	FILE*     pWritingFile;
	GLubyte* pPixelData;
	GLubyte   BMP_Header[BMP_Header_Length];
	GLint     i, j;
	GLint     PixelDataLength;

	// 计算像素数据的实际长度
	i = m_pMeshInstance->m_uiWindowXWidth * 3;    // 得到每一行的像素数据长度
	while (i % 4 != 0)       // 补充数据，直到i是的倍数
		++i;                // 本来还有更快的算法，
							// 但这里仅追求直观，对速度没有太高要求
	PixelDataLength = i * m_pMeshInstance->m_uiWindowYHeight;

	// 分配内存和打开文件
	pPixelData = (GLubyte*)malloc(PixelDataLength);
	if (pPixelData == 0)
		exit(0);

	pDummyFile = fopen("dummy1.bmp", "rb");   //1*1的dummy.bmp文件仍然是必要的
	if (pDummyFile == 0)
		exit(0);

	pWritingFile = fopen("grab8.bmp", "wb");
	if (pWritingFile == 0)
		exit(0);

	// 读取像素
	glPixelStorei(GL_UNPACK_ALIGNMENT, 4);
	glReadPixels(0, 0, m_pMeshInstance->m_uiWindowXWidth, m_pMeshInstance->m_uiWindowYHeight,
		GL_BGR_EXT, GL_UNSIGNED_BYTE, pPixelData);

	// 把dummy.bmp的文件头复制为新文件的文件头
	fread(BMP_Header, sizeof(BMP_Header), 1, pDummyFile);
	fwrite(BMP_Header, sizeof(BMP_Header), 1, pWritingFile);
	fseek(pWritingFile, 0x0012, SEEK_SET);
	i = m_pMeshInstance->m_uiWindowXWidth;
	j = m_pMeshInstance->m_uiWindowYHeight;
	fwrite(&i, sizeof(i), 1, pWritingFile);
	fwrite(&j, sizeof(j), 1, pWritingFile);

	// 写入像素数据
	fseek(pWritingFile, 0, SEEK_END);
	fwrite(pPixelData, PixelDataLength, 1, pWritingFile);

	// 释放内存和关闭文件
	fclose(pDummyFile);
	fclose(pWritingFile);
	free(pPixelData);
}




void Mesh::showDrawlinectrl(void) {
	
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_TEXTURE_2D); 
	glDisable(GL_BLEND);
	int width = m_pMeshInstance->m_uiWindowXWidth;
	int hight = m_pMeshInstance->m_uiWindowYHeight;
	int num = m_pMeshInstance->numchannels;  
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, width, hight);
	glColor3f(1, 1, 1); 
	//glColor3f(1, 0,1 - m_pMeshInstance->colorvalue);

	glBegin(GL_LINES);
	for (int i = 1; i < num; i++)
	{
		glVertex2f((i*2.0 / num) - 1.0, 1.0);
		glVertex2f((i*2. / num) - 1.0, -1.0);
	}
	glEnd();

	m_pMeshInstance->testmutex.lock();
	//v2.assign(v1.begin(),v1.end()); 
	m_pMeshInstance->mdrawline_vec = m_pMeshInstance->m_warplogic->drawline_vec;
	m_pMeshInstance->mmark_vec = m_pMeshInstance->m_warplogic->mark_vec;
	m_pMeshInstance->mmark_clip_vec = m_pMeshInstance->m_warplogic->mark_clip_vec;
	m_pMeshInstance->mline_clip_vec = m_pMeshInstance->m_warplogic->line_clip_vec;

	m_pMeshInstance->bGetDrawline_receiveok=true;
	if (m_pMeshInstance->bGetDrawline_receiveok)
	{
		
		m_pMeshInstance->m_warplogic->line_clip = 0; m_pMeshInstance->m_warplogic->mark_clip = 0;
		std::vector <int>().swap(m_pMeshInstance->m_warplogic->line_clip_vec);
		std::vector <int>().swap(m_pMeshInstance->m_warplogic->mark_clip_vec);
		std::vector <int>().swap(m_pMeshInstance->m_warplogic->drawline_ctrl);
		std::vector <Point2font>().swap(m_pMeshInstance->m_warplogic->mark_vec);

		std::vector <std::vector<Point2f>>().swap(m_pMeshInstance->m_warplogic->drawline_vec);
		m_pMeshInstance->bGetDrawline_receiveok = false;
		m_pMeshInstance->bGetDrawline = false;
		
	}
	m_pMeshInstance->testmutex.unlock();


	for (int i=0;i<num;i++)
	{
		glViewport(int(i * width / num), 0, int(width / num), hight);
		glColor3f(1, 1, 1);

		//geometry test pattern
		int start(0); 
		int end(0);
		if (i==0)
			start = m_pMeshInstance->mline_clip_vec[i * 2];	
		else
			start = m_pMeshInstance->mline_clip_vec[i * 2]+1;

		if (i == m_pMeshInstance->numchannels - 1)
			end = m_pMeshInstance->mdrawline_vec.size();
		else
			end = m_pMeshInstance->mline_clip_vec[i * 2 + 1]+1;

		for (int j= start; j< end; j++)
		{
// 			std::vector < Point2f > line = m_pMeshInstance->mdrawline_vec.back();
// 			m_pMeshInstance->mdrawline_vec.pop_back();
			//glPointSize(3);  GL_LINES 分段直线1、GL_LINES ：每一对顶点被解释为一条直线2、GL_LINE_STRIP: 一系列的连续直线
			std::vector < Point2f > line = m_pMeshInstance->mdrawline_vec[j];
			glBegin(GL_LINE_STRIP);
			for (int k = 0;k < line.size(); k++)
			{
				Point2f pf2 = line[k];
				glVertex2f(pf2.fx - 0.5, pf2.fy - 0.5);
			}
			glEnd();
		}

		//显示坐标
		m_pMeshInstance->displaymark(i);	

	}

	m_pMeshInstance->grabtf();
	m_pMeshInstance->bGetDrawline_receiveok = false;
	glutSwapBuffers();
}

void Mesh::showDrawwhitepattern(void) {
	glDisable(GL_DEPTH_TEST);
	glDisable(GL_TEXTURE_2D);
	glDisable(GL_BLEND);

	int width = m_pMeshInstance->m_uiWindowXWidth;
	int hight = m_pMeshInstance->m_uiWindowYHeight;
	int num = m_pMeshInstance->numchannels;
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glViewport(0, 0, width, hight);
	glColor3f(1, 1, 1);
	//glColor3f(1, 0,1 - m_pMeshInstance->colorvalue);

	glBegin(GL_LINES);
	for (int i = 1; i < num; i++)
	{
		glVertex2f((i*2.0 / num) - 1.0, 1.0);
		glVertex2f((i*2. / num) - 1.0, -1.0);
	}
	glEnd();

	m_pMeshInstance->testmutex.lock();
	m_pMeshInstance->mWhitelevel = m_pMeshInstance->m_warplogic->Whitelevel;
	//重置false ，在那边还是这边
	//m_pMeshInstance->m_warplogic->Whitelevel = std::map<string, bool>();
	m_pMeshInstance->testmutex.unlock();

	int k = 0;
	std::map<std::string, bool>::iterator it;
	for (it = m_pMeshInstance->mWhitelevel.begin(); it != m_pMeshInstance->mWhitelevel.end(); it++)
	{
		k++;
		if (it->second) break;
	}

	
	for (int i = 0; i < num; i++)          
	{
		glViewport(int(i * width / num), 0, int(width / num), hight);
		
		//white test pattern     
		initpatterntest(k);
		//glClear(GL_COLOR_BUFFER_BIT);
		glBindTexture(GL_TEXTURE_2D, m_pMeshInstance->texName);
		glBegin(GL_QUADS);
		glTexCoord2d(0, 0); glVertex3f(-1, -1, 0.0);
		glTexCoord2d(1.0, 0.); glVertex3f(1, -1, 0.0);
		glTexCoord2d(1, 1); glVertex3f(1, 1, 0.0);
		glTexCoord2d(0, 1); glVertex3f(-1, 1, 0.0);
		glEnd();

	}

	m_pMeshInstance->grabtf();

	glutSwapBuffers();
}


//! Draw a bitmap string;  
void Mesh::bitmapString(void* fontId, std::string strText)
{
	for (unsigned int i = 0; i < (size_t)strText.size(); ++i)
		glutBitmapCharacter(fontId, strText.at(i));
}

void Mesh::displaymark(int &num) {

	int end = m_pMeshInstance->mmark_clip_vec[num * 2 + 1];
	int start= m_pMeshInstance->mmark_clip_vec[num * 2 ];
	
	for (int i = start; i < end; i++)
	{
		glColor3f(1.0f, 0.0f, 1.0f);
		glRasterPos2f(m_pMeshInstance->mmark_vec[i].fx - 0.5f, m_pMeshInstance->mmark_vec[i].fy - 0.5f);
		bitmapString(GLUT_BITMAP_HELVETICA_10, m_pMeshInstance->mmark_vec[i].mark.c_str());

		glPointSize(5);
		glColor3f(1, 0, 0);
		glBegin(GL_POINTS);
		glVertex2f(m_pMeshInstance->mmark_vec[i].fx - 0.5f, m_pMeshInstance->mmark_vec[i].fy - 0.5f);
		glEnd();
	}

}


void Mesh::KeysEvent(unsigned char key, int w, int h)
{
	switch (key)
	{
	

	case 's':
	{
		int mod = glutGetModifiers();
		if (mod != GLUT_ACTIVE_CTRL)  //ctrl+s 保存所有数据，网格，控制点 融合带 到xml
		{
			int width = m_pMeshInstance->m_uiWindowXWidth;
			int hight = m_pMeshInstance->m_uiWindowYHeight;
			int num = m_pMeshInstance->numchannels;

			//tinyxml2
			tinyxml2::XMLDocument doc;
			tinyxml2::XMLElement *root = doc.NewElement("root");
			root->SetAttribute("NVWarpProject_version", 1.01);
			root->SetAttribute("NumofChannels", num);
			doc.InsertEndChild(root);


			//画网格16*16
			std::list<WarpMatrix*>::iterator warpMatrixIterator = m_pMeshInstance->warpMatrixList.begin();
			float m(0.0), n(0.0);
			for (int l = 0; warpMatrixIterator != m_pMeshInstance->warpMatrixList.end(); warpMatrixIterator++, l++)
			{
				tinyxml2::XMLElement *ProjectIndex = doc.NewElement("ProjectIndex");
				ProjectIndex->SetAttribute("index", l);
				root->InsertEndChild(ProjectIndex);


				WarpMatrix* mat = *warpMatrixIterator;

				int iColumnInterp = mat->m_splinedMatrix.GetNumOfColumns(); //4-1*16 +1 = 49
				int iRowInterp = mat->m_splinedMatrix.GetNumOfRows();//3-1*16 +1 = 33
				int iColumnControl = (iColumnInterp - 1) / 16 + 1;  //4
				int iRowControl = (iRowInterp - 1) / 16 + 1;  //3

				int perinterpcols = (iColumnInterp - 1) / (iColumnControl - 1); //16
				int perinterprows = (iRowInterp - 1) / (iRowControl - 1);//16

				tinyxml2::XMLElement *vertexArray = doc.NewElement("vertexArray");
				vertexArray->SetAttribute("vertexNum", (17 * 17));  //17*17个控制点
				ProjectIndex->InsertEndChild(vertexArray);

				for (int uiColumnIndex = 0; uiColumnIndex < iColumnInterp; ++uiColumnIndex)
					for (int uiRowIndex = 0; uiRowIndex < iRowInterp; ++uiRowIndex)
					{
						Matrix::Cell cell;
						mat->m_splinedMatrix.GetCellValue(uiColumnIndex, uiRowIndex, cell);

						if (!(uiRowIndex % (iRowControl - 1)) && !(uiColumnIndex % (iColumnControl - 1)))//1
						{
							tinyxml2::XMLElement *data = doc.NewElement("data");
							data->SetAttribute("index", (uiColumnIndex / (iColumnControl - 1))*17  
														+ (uiRowIndex / (iRowControl - 1)));
							data->SetAttribute("col", (uiColumnIndex /(iColumnControl - 1)));
							data->SetAttribute("row", (uiRowIndex / (iRowControl - 1)));
							data->SetAttribute("x", cell.fXPos);
							data->SetAttribute("y", cell.fYPos);
							vertexArray->InsertEndChild(data);
						}

					}

			}

			doc.SaveFile("H222.xml");


		}
	}
// 	case 27:
// 		exit(0);
	default:
		break;

	}
}
// udpdll.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Thread.h"
#include "UDPSocket.h"
//#include "WarpLogic.h"
#include "Mesh.h"


int main()
{
	//CUDPWrapper* pCUDPWrapper = new CUDPWrapper();	
	//unsigned char pucAddress[4] = { 192,168,1,103 };
	//pCUDPWrapper->SetSourceIpAddress(pucAddress);
	//pCUDPWrapper->GetulSourcePID
	//CompactCommunication	m_compactCommunication;
	//m_compactCommunication.StartCommunication(strProjectorAddress);	
	//string strProjectorAddress = "CN0704-0050-C23D-CA92"; ///MWDDO.3/DVIO.1
	//string strProjectorAddress = "CI0000-0000-0000-0055";

	int numProjectors(0);
	WarpLogic* pWarpLogic = WarpLogic::GetInstance();
	string str_list_path = "projaddress.txt";
	
	pWarpLogic->getAllID(str_list_path, numProjectors);
	pWarpLogic->StartCommunication();

	int num = 0;

	Mesh* pMesh = Mesh::GetInstance();	
	pMesh->numchannels = numProjectors;
	//pMesh->list_vec.resize(numProjectors);
	//pMesh->num_contol_cols.resize(numProjectors);
	//pMesh->num_contol_rows.resize(numProjectors);

	std::thread tshow(pMesh->thread_task); tshow.detach();
	
	//std::thread tsend(pWarpLogic.StartCommunication("CI0000-0000-0000-0056")); tsend.detach();



	//死循环改成 子线程 设置标志位
	while (true)
	{
		//outf << " Num: " << num++ << "Receive ok\n";
		//std::cout << num << std::endl;
		pWarpLogic->Draw(num);

// 	     pCUDPWrapper = m_compactCommunication.ReceiveMessage();
// 		 if (pCUDPWrapper)
// 		 {
// 			 
// 		 }
		
	}


    return 0;
}


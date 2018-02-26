#include "CompactCommunication.h"

#include <thread>

CompactCommunication::CompactCommunication( void )
: m_usMessageIndex( 0 )
{
	m_pLogger = Logger::GetInstance();
}

CompactCommunication::~CompactCommunication( void )
{
}

void  CompactCommunication::getAllID(std::string& filename, int &num,int &width,int &hight)
{

	//load seq
	std::ifstream fin(filename);
	int cur_number(0);
	std::string sqe;
	std::stringstream ss;


	for (int i = 0; i < 7; i++)
	{
		std::string line;
		getline(fin, line);
		if (i == 1) { ss << line;		ss >> num; }
		if (i == 3) { ss.clear(); ss << line;		ss >> width; }
		if (i == 4) { ss.clear(); ss << line;		ss >> hight; }
		if (i == 6) sqe = line;
	}

	int lenth = sqe.length();
	std::string prefix = sqe.substr(0, lenth - 2);
	std::string postfix = sqe.substr(lenth - 2, lenth - 1);  //sqe-prefix;

	ss.clear();
	ss << postfix;	ss >> cur_number;

	std::cout << "Send Serial: " << endl;
	for (int i = 0; i < num; i++)
	{
		int per_numer = cur_number + i;
		ss.clear();
		ss << per_numer; postfix.clear();
		ss >> postfix;
		std::string per_sqe = prefix + postfix;
		std::cout << per_sqe << endl;
		m_sqe_vec.push_back(per_sqe);
	}

	m_numProj = num;


}

void CompactCommunication::StartCommunication()
{

	//std::string address = sqe_vec.pop_back();	
	std::vector<std::string>::iterator it = m_sqe_vec.begin();
	for (int i = 0; it != m_sqe_vec.end(); it++,i++)
	{
		
		//std::thread tshow(pMesh->thread_task); 
		//tshow.detach();

		StartCommunicationEncode(*it,i);
		Sleep(1000);
	}


}



void CompactCommunication::StartCommunicationEncode( string strProjectorAddress,int num )
{
	char cabuffer[ UDPSocket::m_sciReceiveBufferSize ];
	CUDPWrapper* pCUDPWrapper;
	CProjectorSerialNumber* pCProjectorSerialNumber;
	CProjectorVersionInfo* pCProjectorVersionInfo;
	CProjectorName* pCProjectorName;
	unsigned short usSerialNumber[ 4 ] = { num, 0, 0, 1 };

	m_pLogger->Write( Logger::LOG_INFO, "Started client with projector Address: " + strProjectorAddress );
	
	//strcpy_s( m_caProjectorAddress, m_sciProjectorAddressMaxSize ,strProjectorAddress.c_str() );

	//m_caProjectorAddress = const_cast<char*>(sqe_vec[num].c_str());
	std::string seriel = m_sqe_vec[num];
	//strcpy_s(const_cast<char*>(seriel.c_str()), m_sciProjectorAddressMaxSize, strProjectorAddress.c_str());

	pCUDPWrapper = CUDPWrapper::CreateInBuffer( cabuffer );
	//pCUDPWrapper->SetProjectorAddress( m_caProjectorAddress );
	pCUDPWrapper->SetProjectorAddress((seriel.c_str()));
	pCProjectorSerialNumber = CProjectorSerialNumber::CreateInBuffer( pCUDPWrapper->GetNextPos() );
	pCProjectorSerialNumber->Set( ( const unsigned char* )&usSerialNumber, 'I' );
	pCUDPWrapper->AddRecord();
	pCProjectorVersionInfo = CProjectorVersionInfo::CreateInBuffer( pCUDPWrapper->GetNextPos() );
	pCProjectorVersionInfo->Set( "\nSoftware = 1.0.0.0" );
	pCUDPWrapper->AddRecord();
	pCProjectorName = CProjectorName::CreateInBuffer( pCUDPWrapper->GetNextPos() );
	//pCProjectorName->Set((seriel.c_str())m_caProjectorAddress);
	pCProjectorName->Set((seriel.c_str()) );
	pCUDPWrapper->AddRecord();

	Send( pCUDPWrapper );

	m_pLogger->Write( Logger::LOG_INFO, "CompactCommunication::SendInitiation, Initiation sent to CompactControl device");
}



CUDPWrapper* CompactCommunication::ReceiveMessage(int &receive_seriel_num)
{
	CUDPWrapper*	pCUDPWrapper = (CUDPWrapper*)m_caReceiveBuffer;
	bool			bMessageReceived = false;

	if ( Receive( pCUDPWrapper ) )
	{
		pCUDPWrapper->AssertValid();

		char acProjectorAddress[m_sciProjectorAddressMaxSize];
		pCUDPWrapper->GetProjectorAddress().GetSZ(acProjectorAddress);

	//	std::cout << pCUDPWrapper->GetulSourcePID() << " "
	//		<< pCUDPWrapper->GetusSequenceCounter() << " " <<
	//		pCUDPWrapper->GetucSourceIpAddress() << std::endl;
		//strcmp 一样返回0，大于返回正，小于返回负
		// Is this a message not to this device?
		//if ( strlen( acProjectorAddress ) != 0 && strcmp( acProjectorAddress, m_caProjectorAddress ) != 0 )
		//	pCUDPWrapper = NULL;//序列号不一样 返回null，，

		bool allno = true;
		if ( strlen(acProjectorAddress) != 0)
		{
			for (int i=0;i<m_numProj;i++)
			{
				std::string seriel = m_sqe_vec[i];
				if (strcmp(acProjectorAddress, seriel.c_str()) == 0)  //序号有顺序的，55，56，57，58  0，1，2，3
				{
					receive_seriel_num = i; 
					allno = false;
					break;
				}
				
					
			}
			if (allno)
				pCUDPWrapper = NULL;
		
		}
	}
	else
		pCUDPWrapper = NULL;

	return pCUDPWrapper;
}

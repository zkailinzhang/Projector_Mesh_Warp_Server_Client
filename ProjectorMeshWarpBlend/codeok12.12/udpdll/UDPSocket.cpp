
#include "UDPSocket.h"

UDPSocket::UDPSocket(void)
: m_usMessageInded( 0 )
{
	WORD wVersionRequested;
	WSADATA wsaData;

	m_pLogger = Logger::GetInstance();

	wVersionRequested = MAKEWORD(1, 1);
 	WSAStartup(wVersionRequested, &wsaData);

	if ( OpenSendSocket() )
		m_pLogger->Write( Logger::LOG_INFO, "Send socket opened" );
	if ( OpenReceiveSocket() )
		m_pLogger->Write( Logger::LOG_INFO, "Receive socket opened" );
}

UDPSocket::~UDPSocket(void)
{
}

bool UDPSocket::OpenSendSocket()
{
	bool	bBroadcast = true;
	bool	bReuseAddr = true;
	bool	bOpenSocketOk = true;
	int		iBufferSize;
	int		iReturnValue;

	m_UDPSendSocket = socket( AF_INET, SOCK_DGRAM, 0 );

	// Set the send buffer size.
	iBufferSize = m_sciReceiveBufferSize * m_sciMaxNumOfReceiveBuffers;
	iReturnValue = setsockopt(	m_UDPSendSocket, 
								SOL_SOCKET,
								SO_SNDBUF,
								(char*)&iBufferSize,
								sizeof(int));
	if ( iReturnValue == SOCKET_ERROR )
	{
		sprintf_s( m_caLoggerText,m_scuiLoggTextSize, "Set send buffer size failed, last error code: %d", GetLastError() );
		m_pLogger->Write( Logger::LOG_ERROR, m_caLoggerText );
		bOpenSocketOk = false;
	}

	// Make this a broadcast socket.
	iReturnValue = setsockopt(	m_UDPSendSocket, 
								SOL_SOCKET,
								SO_BROADCAST,
								(char*)&bBroadcast,
								sizeof(bool) );

	if ( iReturnValue == SOCKET_ERROR )
	{
		sprintf_s( m_caLoggerText,m_scuiLoggTextSize, "setsockopt broadcast = true, last error code: %d", GetLastError() );
		m_pLogger->Write( Logger::LOG_ERROR, m_caLoggerText );
		bOpenSocketOk = false;
	}

	// Make the socket reuse addresses.
	iReturnValue = setsockopt(	m_UDPSendSocket, 
								SOL_SOCKET,
								SO_REUSEADDR,
								(char*)&bReuseAddr,
								sizeof(bool));

	if ( iReturnValue == SOCKET_ERROR )
	{
		sprintf_s( m_caLoggerText,m_scuiLoggTextSize, "setsockopt bReuseAddr = true, last error code: %d", GetLastError() );
		m_pLogger->Write( Logger::LOG_ERROR, m_caLoggerText );
		bOpenSocketOk = false;
	}

    m_UDPSendSocketAddress.sin_family = AF_INET;
	//m_UDPSendSocketAddress.sin_addr.s_addr = htonl(INADDR_BROADCAST);
    //m_UDPSendSocketAddress.sin_port = htons(56339);
	//可自定义服务器端口，但必须在服务器界面上也设置相应端口和服务器的ip 如192.168.1.101:56410
	m_UDPSendSocketAddress.sin_addr.s_addr = inet_addr("192.168.1.103"); //htonl( INADDR_ANY );
	m_UDPSendSocketAddress.sin_port = htons(56339);

	return bOpenSocketOk;
}

bool UDPSocket::OpenReceiveSocket()
{
	bool	bBroadcast		= true;
	bool	bReuseAddr		= true;
	bool	bOpenSocketOk	= true;
	int		iBufferSize;
	int		iReturnValue;

	m_UDPReceiveSocket = socket( AF_INET, SOCK_DGRAM, 0 );

	// Set the receive buffer size.
	iBufferSize = m_sciReceiveBufferSize * m_sciMaxNumOfReceiveBuffers;
	iReturnValue = setsockopt(	m_UDPReceiveSocket, 
								SOL_SOCKET,
								SO_RCVBUF,
								(char*)&iBufferSize,
								sizeof(int));
	if ( iReturnValue == SOCKET_ERROR )
	{
		sprintf_s( m_caLoggerText,m_scuiLoggTextSize, "Set receive buffer size failed, last error code: %d", GetLastError() );
		m_pLogger->Write( Logger::LOG_ERROR, m_caLoggerText );
		bOpenSocketOk = false;
	}

	// Make this a broadcast socket.
	iReturnValue = setsockopt(	m_UDPReceiveSocket, 
								SOL_SOCKET,
								SO_BROADCAST,
								(char*)&bBroadcast,
								sizeof(bool) );
	if ( iReturnValue == SOCKET_ERROR )
	{
		sprintf_s( m_caLoggerText,m_scuiLoggTextSize, "setsockopt broadcast = true, last error code: %d", GetLastError() );
		m_pLogger->Write( Logger::LOG_ERROR, m_caLoggerText );
		bOpenSocketOk = false;
	}

	// Make the socket reuse addresses.
	iReturnValue = setsockopt(	m_UDPReceiveSocket, 
								SOL_SOCKET,
								SO_REUSEADDR,
								(char*)&bReuseAddr,
								sizeof(bool) );
	if ( iReturnValue == SOCKET_ERROR )
	{
		sprintf_s( m_caLoggerText,m_scuiLoggTextSize, "setsockopt bReuseAddr = true, last error code: %d", GetLastError() );
		m_pLogger->Write( Logger::LOG_ERROR, m_caLoggerText );
		bOpenSocketOk = false;
	}

	// Make the socket non-blocking. 接收非阻塞，发送也要非阻塞
	unsigned long nonBlocking = true;
	ioctlsocket( m_UDPReceiveSocket, FIONBIO, &nonBlocking );

    m_UDPReceiveSocketAddress.sin_family = AF_INET;
	//m_UDPReceiveSocketAddress.sin_addr.s_addr = htonl( INADDR_ANY );
	//m_UDPReceiveSocketAddress.sin_port = htons(56338);
	//设置客户端ip和port，port写死的，ip可换
	m_UDPReceiveSocketAddress.sin_addr.s_addr = inet_addr("192.168.1.102"); //htonl( INADDR_ANY );
    m_UDPReceiveSocketAddress.sin_port = htons( 56338);


	//client.sin_port = htons(80); ///server的监听端口
	//client.sin_addr.s_addr = inet_addr("192.168.1.101"); //server ip

	//与std::bind 与 winsock2 中的bind冲突 ，，，加域名操作符::
	iReturnValue = ::bind( m_UDPReceiveSocket, ( struct sockaddr* )&m_UDPReceiveSocketAddress, sizeof( sockaddr ) );
	if ( iReturnValue == SOCKET_ERROR )
	{
		sprintf_s( m_caLoggerText,m_scuiLoggTextSize, "bind, last error code: %d", GetLastError() );
		m_pLogger->Write( Logger::LOG_ERROR, m_caLoggerText );
	}

	return bOpenSocketOk;
}

bool UDPSocket::Send( CUDPWrapper* pCUDPWrapper )
{
	int		iReturnValue;
	bool	bSendOk = false;

	pCUDPWrapper->PrepareToSend( &m_usMessageInded );
	m_usMessageInded++;

	iReturnValue = sendto( m_UDPSendSocket, (const char*)pCUDPWrapper, pCUDPWrapper->GetSize(), 0, (sockaddr*)&m_UDPSendSocketAddress, sizeof(sockaddr) );
	if ( iReturnValue == SOCKET_ERROR )
	{
		sprintf_s( m_caLoggerText,m_scuiLoggTextSize, "sendto, last error code: %d", GetLastError() );
		m_pLogger->Write( Logger::LOG_ERROR, m_caLoggerText );
	}
	else
		bSendOk = true;

	return bSendOk;
}



bool UDPSocket::Receive( CUDPWrapper* pCUDPWrapper )
{
	int		iReturnValue;
	bool	bReceivedData = false;
	DWORD	dLastError;

	int iSizeOfSockaddr = sizeof(sockaddr);
	memset( (void*)&m_UDPReceiveSocketAddress, 0, sizeof(sockaddr_in));

	try
	{
		fd_set sockets;
		timeval waitTime;
		waitTime.tv_sec = 0;
		waitTime.tv_usec = 0;
		sockets.fd_count = 1;
		sockets.fd_array[0] = m_UDPReceiveSocket;
		// Is the socket ready to receive data?
		if ( select( 0, &sockets, NULL, NULL, &waitTime ) == 1 )
		{
			iReturnValue = recvfrom( m_UDPReceiveSocket, (char*)pCUDPWrapper, m_sciReceiveBufferSize, 0, (sockaddr*)&m_UDPReceiveSocketAddress, &iSizeOfSockaddr );
			if ( iReturnValue == SOCKET_ERROR )
			{
				dLastError = WSAGetLastError();
				switch( dLastError )
				{
				case WSAEWOULDBLOCK:
					sprintf_s( m_caLoggerText,m_scuiLoggTextSize, "Data could not be received beqause the socket is bisy, last error code: %d", dLastError );
					m_pLogger->Write( Logger::LOG_ERROR, m_caLoggerText );
					break;
				default:
					sprintf_s( m_caLoggerText,m_scuiLoggTextSize, "recvfrom, last error code: %d", dLastError );
					m_pLogger->Write( Logger::LOG_ERROR, m_caLoggerText );
					break;
				}
			}
			else
			{
				// Check the size of the received message to make sure
				// that it's not smaller then CRecordBase.
				if ( iReturnValue >= sizeof( CRecordBase ) )
				{
					bReceivedData = true;
				}
			}
		}
	}
	catch(...)
	{
		m_pLogger->Write( Logger::LOG_ERROR, "Exception when receiving from broadcast socket." );
	}

	return bReceivedData;
}

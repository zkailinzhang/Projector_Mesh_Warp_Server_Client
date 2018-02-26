/** @class UDPSocket
	@version 1.0 
	@date 2008-11-24
	@author Robert Malmstrom
*/

#ifndef UDP_SOCKET_H
#define UDP_SOCKET_H

#include "stdafx.h"
#include <Winsock2.h>		// Windows socket functions
#include "CVprotocol/CVProtocolWrapper.h"
#include "Logger.h"

/// This class uses UDP sockets to communicate
/** This class is used by the class CompactCommunication
	to communicate with the CompactControl or the
	CompactDesign application.
*/

class UDPSocket
{
public:
	static const int			m_sciReceiveBufferSize		= MAX_MESSAGE_SIZE;
	static const int			m_sciMaxNumOfReceiveBuffers	= 1000;
	static const int			m_sciMaxNumOfSendBuffers	= 1000;
	static const unsigned int	m_scuiLoggTextSize			= 256;

	UDPSocket(void);
	~UDPSocket(void);
	/** This function is used to send information in the form of CUDPWrapper to the
		CompactControl or the CompactDesign application. This function returns true
		if the CUDPWrapper was sent.
	*/
	bool Send( CUDPWrapper* pCUDPWrapper );
	/** This function is used to receive information from the CompactControl or the
		CompactDesign application in the form of CUDPWrapper. This function returns
		true if there where a CUDPWrapper received.
	*/
	bool Receive( CUDPWrapper* pCUDPWrapper );

private:
	/** This function creates a UDP socket m_UDPSendSocket to send data.
	*/
	bool OpenSendSocket();
	/** This function creates a UDP socket m_UDPReceiveSocket to receive data.
	*/
	bool OpenReceiveSocket();

	SOCKET			m_UDPSendSocket;
	SOCKET			m_UDPReceiveSocket;
	sockaddr_in		m_UDPSendSocketAddress;
	sockaddr_in		m_UDPReceiveSocketAddress;

	Logger*			m_pLogger;
	char			m_caLoggerText[ m_scuiLoggTextSize ];
	unsigned short	m_usMessageInded;
};

#endif

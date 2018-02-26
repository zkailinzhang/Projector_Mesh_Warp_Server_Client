/** @class CompactCommunication
	@version 1.0 
	@date 2008-11-24
	@author Robert Malmstrom
*/

#ifndef COMPACT_COMMUNICATION_H
#define COMPACT_COMMUNICATION_H

#include "stdafx.h"

#include "CVprotocol/CVProtocolWrapper.h"
#include "CVprotocol/CVProtocolHandshake.h"
#include "CVprotocol/CVProtocolAppRecords.h"
#include "UDPSocket.h"
#include "Logger.h"
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/// This class is used to communicate with the CompactDesigner server.
/** This class is used to initiate the communication with the
	CompactDesigner server and to receive commands from the applikation.
	You start by calling the function StartCommunication with a
	project address to identify this application to the CompactDesigner
	server (project address example: CI0000-0000-0000-0035). You then
	call the ReceiveMessage function until it returns NULL to receive
	the commands that has been received since last call.
*/

class CompactCommunication : public UDPSocket
{
private:
	static const int m_sciProjectorAddressMaxSize = 256;

public:
	CompactCommunication( void );
	~CompactCommunication( void );

	/** This function starts the communication with the CompactDesign
		server by sending its project address as a string.
		(project address example: CI0000-0000-0000-0035)
	*/
	void StartCommunicationEncode( string strProjectorAddress, int num);
	/** This function is called receive commands from the CompactDesgin
		server. Call the function until it returns NULL to receive
		the commands that has been received since last call.
	*/
	CUDPWrapper* ReceiveMessage( int &receive_seriel_num);

private:
	Logger*			m_pLogger;
	unsigned short	m_usMessageIndex;
	char			m_caProjectorAddress[ m_sciProjectorAddressMaxSize ];
	CRecordBase*	m_lastReceivedCRecordBase;
	char			m_caReceiveBuffer[ UDPSocket::m_sciReceiveBufferSize ];


public:
	void StartCommunication();

	void  getAllID(std::string &filename, int& num, int &width, int &hight);
	std::vector<std::string> m_sqe_vec;
	int m_numProj;


};

#endif
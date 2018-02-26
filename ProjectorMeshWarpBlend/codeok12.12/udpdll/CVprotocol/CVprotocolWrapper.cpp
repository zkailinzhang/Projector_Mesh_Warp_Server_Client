//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: CVprotocolWrapper; Package body
//	Implementation of CVcomm wrapper classes
//## Subsystem: cvsetup
//	c:\src\graphics\cvsetup
//## Source file: c:\src\graphics\cvsetup\CVprotocolWrapper.cpp

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include "stdafx.h"
#if (defined(_MFC_VER) && !defined(UNDER_CE)) || (!defined(CVPROJ) && !defined(CVPCI))
//#include <process.h>
#endif
//## end module.includes

// CVprotocolWrapper
#include "CVprotocolWrapper.h"
//## begin module.declarations preserve=no
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


// Class CUDPWrapper 

#if !defined(CVPCI)

#if !defined(CVPROJ) && !defined(CVPCI)
//## begin CUDPWrapper::usLastSequenceCounter.attr preserve=no  private: static unsigned short {U} 0
unsigned short CUDPWrapper::m_usLastSequenceCounter = 0;
//## end CUDPWrapper::usLastSequenceCounter.attr
#endif


//## Other Operations (implementation)
void CUDPWrapper::Create ()
{
  //## begin CUDPWrapper::Create%936176390.body preserve=yes
  m_ProjectorAddress.Reset();
  CreateRecordBase(sizeof(*this) + m_ProjectorAddress.GetExtraSize(),
                   2 + sizeof(m_ucSourceIpAddress) + sizeof(m_ulSourcePID) + sizeof(m_usSequenceCounter) + m_ProjectorAddress.GetSize(),
                   UDP_WRAPPER);

  memset(m_ucSourceIpAddress, 0, sizeof(m_ucSourceIpAddress));  // TODO:  Set IP
#if !defined(_MFC_VER) && (defined(CVPROJ) || defined(CVPCI))
  m_ulSourcePID = 0;
#else
  //m_ulSourcePID = _getpid();
#endif
  m_usSequenceCounter = 0;  // This is set when sent
  //## end CUDPWrapper::Create%936176390.body
}

unsigned short CUDPWrapper::PrepareToSend (unsigned short *pusLastSequenceCounter)
{
  //## begin CUDPWrapper::PrepareToSend%936176354.body preserve=yes
  AssertValid();
  if (pusLastSequenceCounter)
    m_usSequenceCounter = ++ *pusLastSequenceCounter;

  return GetSize();
  //## end CUDPWrapper::PrepareToSend%936176354.body
}

void CUDPWrapper::SetProjectorAddress (const char *pszAddress)
{
  //## begin CUDPWrapper::SetProjectorAddress%936176355.body preserve=yes
  // There must not be anything allocated after address
  ASSERT(GetSize() == sizeof(*this) + m_ProjectorAddress.GetExtraSize());
  SetCVString(&m_ProjectorAddress, pszAddress);
  SetSize(sizeof(*this) + m_ProjectorAddress.GetExtraSize());
  SetIdSizeFromStart(sizeof(*this) + m_ProjectorAddress.GetExtraSize());
  //## end CUDPWrapper::SetProjectorAddress%936176355.body
}

void CUDPWrapper::SetSourceIpAddress (const unsigned char *pucAddress)
{
  //## begin CUDPWrapper::SetSourceIpAddress%939031319.body preserve=yes
	for (unsigned short i = 0; i < 4; i++)
		m_ucSourceIpAddress[i] = pucAddress[i];
  //## end CUDPWrapper::SetSourceIpAddress%939031319.body
}

// Additional Declarations
  //## begin CUDPWrapper.declarations preserve=yes
  //## end CUDPWrapper.declarations


#endif

// Class CSerialOutboundWrapper 


#if !defined(CVPROJ) && !defined(CVPCI)
//## begin CSerialOutboundWrapper::ucLastSequenceCounter.attr preserve=no  private: static unsigned char {U} 0
unsigned char CSerialOutboundWrapper::m_ucLastSequenceCounter = 0;
//## end CSerialOutboundWrapper::ucLastSequenceCounter.attr
#endif


//## Other Operations (implementation)
void CSerialOutboundWrapper::Create ()
{
  //## begin CSerialOutboundWrapper::Create%936176333.body preserve=yes
  CreateRecordBase(sizeof(*this),
                   2 + sizeof(m_ucFirstChainAddress) + sizeof(m_ucLastChainAddress) + sizeof(m_ucSequenceCounter),
                   SERIAL_OUTBOUND_WRAPPER);

  m_ucFirstChainAddress = 1;
  m_ucLastChainAddress = 0xff;
  m_ucSequenceCounter = 0;  // This is set when sent
  //## end CSerialOutboundWrapper::Create%936176333.body
}

void CSerialOutboundWrapper::SetChainAddress (unsigned char ucFirstChainAddress, unsigned char ucLastChainAddress)
{
  //## begin CSerialOutboundWrapper::SetChainAddress%936176392.body preserve=yes
  ASSERT(ucFirstChainAddress > 0);
  ASSERT(ucFirstChainAddress <= ucLastChainAddress);
  m_ucFirstChainAddress = ucFirstChainAddress;
  m_ucLastChainAddress = ucLastChainAddress;
  //## end CSerialOutboundWrapper::SetChainAddress%936176392.body
}

unsigned short CSerialOutboundWrapper::PrepareToSend (unsigned char *pucLastSequenceCounter)
{
  //## begin CSerialOutboundWrapper::PrepareToSend%936176402.body preserve=yes
  AssertValid();
  if (pucLastSequenceCounter)
    m_ucSequenceCounter = ++ *pucLastSequenceCounter;

  AddTail();

  return GetSize();
  //## end CSerialOutboundWrapper::PrepareToSend%936176402.body
}

bool CSerialOutboundWrapper::PrepareToReceive ()
{
  //## begin CSerialOutboundWrapper::PrepareToReceive%939031321.body preserve=yes
  return RemoveTail();
  //## end CSerialOutboundWrapper::PrepareToReceive%939031321.body
}

// Additional Declarations
  //## begin CSerialOutboundWrapper.declarations preserve=yes
  //## end CSerialOutboundWrapper.declarations



// Class CSerialInboundWrapper 


#if !defined(CVPROJ) && !defined(CVPCI)
//## begin CSerialInboundWrapper::ucLastSequenceCounter.attr preserve=no  private: static unsigned char {U} 0
unsigned char CSerialInboundWrapper::m_ucLastSequenceCounter = 0;
//## end CSerialInboundWrapper::ucLastSequenceCounter.attr
#endif


//## Other Operations (implementation)
void CSerialInboundWrapper::Create ()
{
  //## begin CSerialInboundWrapper::Create%936176395.body preserve=yes
  CreateRecordBase(sizeof(*this), 
                   2 + sizeof(m_ucChainAddress) + sizeof(m_ucSequenceCounter),
                   SERIAL_INBOUND_WRAPPER);
  m_ucChainAddress = 1;
  m_ucSequenceCounter = 0;  // This is set when sent
  //## end CSerialInboundWrapper::Create%936176395.body
}

void CSerialInboundWrapper::SetChainAddress (unsigned char ucChainAddress)
{
  //## begin CSerialInboundWrapper::SetChainAddress%936176397.body preserve=yes
  m_ucChainAddress = ucChainAddress;
  //## end CSerialInboundWrapper::SetChainAddress%936176397.body
}

unsigned short CSerialInboundWrapper::PrepareToSend (unsigned char *pucLastSequenceCounter)
{
  //## begin CSerialInboundWrapper::PrepareToSend%936176403.body preserve=yes
  AssertValid();
  if (pucLastSequenceCounter)
    m_ucSequenceCounter = ++ *pucLastSequenceCounter;

  AddTail();

  return GetSize();
  //## end CSerialInboundWrapper::PrepareToSend%936176403.body
}

bool CSerialInboundWrapper::PrepareToReceive ()
{
  //## begin CSerialInboundWrapper::PrepareToReceive%939031323.body preserve=yes
  return RemoveTail();
  //## end CSerialInboundWrapper::PrepareToReceive%939031323.body
}

// Additional Declarations
  //## begin CSerialInboundWrapper.declarations preserve=yes
  //## end CSerialInboundWrapper.declarations



// Class CWrapperBase 


//## Other Operations (implementation)
void CWrapperBase::AddTail ()
{
  //## begin CWrapperBase::AddTail%936176396.body preserve=yes

  SWrapperTail *pTail = (SWrapperTail *) GetNextPos();
  unsigned short usOriginalSize = GetSize();
  SetSize(usOriginalSize + sizeof(SWrapperTail)); // Set size before calculating CRC

  pTail->usCRC = CalculateCRC16(usOriginalSize);

#if defined(_DEBUG)
  *(unsigned long *) (pTail+1) = 0xdeaddead;  // TEST: Make sure we don't send too much
#elif defined(NDEBUG)
#else
#error "Either _DEBUG or NDEBUG must be defined"
#endif

  //## end CWrapperBase::AddTail%936176396.body
}

bool CWrapperBase::RemoveTail ()
{
  //## begin CWrapperBase::RemoveTail%939031318.body preserve=yes
  if (!CheckCRC())
	  return false;				// Datagram is corrupt

  SetSize(GetSize() - sizeof(SWrapperTail));
  return true;
  //## end CWrapperBase::RemoveTail%939031318.body
}

bool CWrapperBase::RemoveRecords ()
{
  //## begin CWrapperBase::RemoveRecords%939291899.body preserve=yes
  AssertValid();
  SetSize(GetIdSizeFromStart());

  return true;
  //## end CWrapperBase::RemoveRecords%939291899.body
}

char * CWrapperBase::GetNextPos ()
{
  //## begin CWrapperBase::GetNextPos%936176398.body preserve=yes
  ASSERT(GetSize());
  return (char *) this + GetSize();
  //## end CWrapperBase::GetNextPos%936176398.body
}

void CWrapperBase::AddRecord ()
{
  //## begin CWrapperBase::AddRecord%936176399.body preserve=yes
  CRecordBase *pLastRecord = (CRecordBase *) GetNextPos();
  pLastRecord->AssertValid();
  SetSize(GetSize() + pLastRecord->GetSize());
  //## end CWrapperBase::AddRecord%936176399.body
}

void CWrapperBase::AppendRecord (const CRecordBase *pItem)
{
  //## begin CWrapperBase::AppendRecord%939636217.body preserve=yes
  memcpy(GetNextPos(), pItem, pItem->GetSize());
  AddRecord();
  //## end CWrapperBase::AppendRecord%939636217.body
}

void CWrapperBase::AppendEmptyRecord (const CRecordBase *pUnknownRequest)
{
  //## begin CWrapperBase::AppendEmptyRecord%939636218.body preserve=yes
  CRecordBase *pEmpty = (CRecordBase *) GetNextPos();
  unsigned short usSize = pUnknownRequest->GetIdSizeFromStart();
  memcpy(pEmpty, pUnknownRequest, usSize);
  pEmpty->SetSize(usSize);
  AddRecord();
  //## end CWrapperBase::AppendEmptyRecord%939636218.body
}

// Additional Declarations
  //## begin CWrapperBase.declarations preserve=yes
  //## end CWrapperBase.declarations



// Class CUDPAckRecord 






//## Other Operations (implementation)
void CUDPAckRecord::Set (const class CUDPWrapper *pWrapper)
{
  //## begin CUDPAckRecord::Set%936276129.body preserve=yes
  memcpy(m_ucSourceIpAddress, pWrapper->GetucSourceIpAddress(), sizeof(m_ucSourceIpAddress));
  m_ulSourcePID = pWrapper->GetulSourcePID();
  m_ProjectorAddress.CopyCVString(&(pWrapper->GetProjectorAddress()));
  m_usSequenceCounter = pWrapper->GetusSequenceCounter();

  ASSERT((unsigned short)sizeof(*this) + m_ProjectorAddress.GetExtraSize() <= pWrapper->GetSize());
  ASSERT((unsigned short)sizeof(*this) + m_ProjectorAddress.GetExtraSize() == pWrapper->GetIdSize() + 4);
  SetSize(sizeof(*this) + m_ProjectorAddress.GetExtraSize());
  SetIdSizeFromStart(sizeof(*this) + m_ProjectorAddress.GetExtraSize());
  //## end CUDPAckRecord::Set%936276129.body
}

void CUDPAckRecord::Create ()
{
  //## begin CUDPAckRecord::Create%936276135.body preserve=yes
  m_ProjectorAddress.Reset();
  CreateRecordBase(sizeof(*this) + m_ProjectorAddress.GetExtraSize(),
                   sizeof(*this) + m_ProjectorAddress.GetExtraSize()-4,
                   UDP_ACK);
  //## end CUDPAckRecord::Create%936276135.body
}

// Additional Declarations
  //## begin CUDPAckRecord.declarations preserve=yes
  //## end CUDPAckRecord.declarations



// Class CSerialAckRecord 





//## Other Operations (implementation)
void CSerialAckRecord::Set (const class CSerialInboundWrapper *pWrapper)
{
  //## begin CSerialAckRecord::Set%936276137.body preserve=yes
  AssertValid();
  m_ucChainAddress = 0;  // If we are acking an inbound message, we must be CVcomm
  m_ucSequenceCounter = pWrapper->GetucSequenceCounter();
  m_usCRC16 = CalculateCRC16(offsetof(CSerialAckRecord, m_usCRC16));
  //## end CSerialAckRecord::Set%936276137.body
}

void CSerialAckRecord::Set (const class CSerialOutboundWrapper *pWrapper)
{
  //## begin CSerialAckRecord::Set%936276138.body preserve=yes
  AssertValid();
  m_ucChainAddress = 1;  // If we are acking an outbound message, we must be a projector
  m_ucSequenceCounter = pWrapper->GetucSequenceCounter();
  m_usCRC16 = CalculateCRC16(offsetof(CSerialAckRecord, m_usCRC16));
  //## end CSerialAckRecord::Set%936276138.body
}

void CSerialAckRecord::Create ()
{
  //## begin CSerialAckRecord::Create%936276139.body preserve=yes
  CreateRecordBase(sizeof(*this),
                   2+sizeof(m_ucChainAddress)+sizeof(m_ucSequenceCounter),
                   SERIAL_ACK);
  //## end CSerialAckRecord::Create%936276139.body
}

// Additional Declarations
  //## begin CSerialAckRecord.declarations preserve=yes
  //## end CSerialAckRecord.declarations


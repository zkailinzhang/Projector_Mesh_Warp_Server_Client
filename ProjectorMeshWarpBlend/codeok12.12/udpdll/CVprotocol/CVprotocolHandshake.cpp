//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: CVprotocolHandshake; Package body
//## Subsystem: cvsetup
//	c:\src\graphics\cvsetup
//## Source file: c:\src\graphics\cvsetup\CVprotocolHandshake.cpp

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include "stdafx.h"
//## end module.includes

// CVprotocolHandshake
#include "CVprotocolHandshake.h"
//## begin module.declarations preserve=no
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
//## end module.additionalDeclarations


// Class CRequestProjectorState 




//## Other Operations (implementation)
void CRequestProjectorState::Set (unsigned short usRequestIdSize, unsigned short usRequestRecordType, const unsigned char *pKey)
{
  //## begin CRequestProjectorState::Set%937312541.body preserve=yes
  m_usRequestIdSize = usRequestIdSize;
  m_usRequestRecordType = usRequestRecordType;
  if (usRequestIdSize > sizeof(m_usRequestRecordType))
    memcpy((char *) &m_usRequestRecordType + sizeof(m_usRequestRecordType), pKey, usRequestIdSize - sizeof(m_usRequestRecordType));

  SetSize(sizeof(*this) + usRequestIdSize - sizeof(m_usRequestRecordType));
  SetIdSizeFromStart(sizeof(*this) + usRequestIdSize - sizeof(m_usRequestRecordType));
  //## end CRequestProjectorState::Set%937312541.body
}

void CRequestProjectorState::Create ()
{
  //## begin CRequestProjectorState::Create%937312540.body preserve=yes
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usRequestIdSize)+sizeof(m_usRequestRecordType), REQUEST_PROJECTOR_STATE);

  m_usRequestIdSize = sizeof(m_usRequestRecordType);
  m_usRequestRecordType = 0;
  //## end CRequestProjectorState::Create%937312540.body
}

// Additional Declarations
  //## begin CRequestProjectorState.declarations preserve=yes
  //## end CRequestProjectorState.declarations



void CRequestStateList::Set (unsigned short usDT, unsigned short usTimeoutMs)
{
  //## begin CRequestProjectorState::Set%937312541.body preserve=yes
  m_usDT = usDT;
  m_usTimeoutMs = usTimeoutMs;

  SetSize(sizeof(*this));
  //## end CRequestProjectorState::Set%937312541.body
}

void CRequestStateList::AddRequest(unsigned short usRequestIdSize, unsigned short usRequestRecordType, const unsigned char *pKey)
{
  unsigned short *pusBuf = (unsigned short *) ((unsigned char *) this + GetSize());
  *pusBuf++ = usRequestIdSize;
  *pusBuf++ = usRequestRecordType;

  if (usRequestIdSize > sizeof(usRequestRecordType))
    memcpy((char *) pusBuf, pKey, usRequestIdSize - sizeof(usRequestRecordType));

  SetSize(GetSize() + usRequestIdSize + sizeof(usRequestIdSize));
}

void CRequestStateList::Create ()
{
  //## begin CRequestProjectorState::Create%937312540.body preserve=yes
  CreateRecordBase(sizeof(*this), 2, REQUEST_STATE_LIST);

  m_usTimeoutMs = 10000;
  m_usDT = 1000;
  //## end CRequestProjectorState::Create%937312540.body
}

// Additional Declarations
  //## begin CRequestProjectorState.declarations preserve=yes
  //## end CRequestProjectorState.declarations



// Class CProjectorSerialNumber 



//## Other Operations (implementation)
void CProjectorSerialNumber::Set (const unsigned char *ucSerialNumber, char cSerialFamily, const char *pcTail /* = NULL */)
{
  //## begin CProjectorSerialNumber::Set%937312543.body preserve=yes
  memcpy(m_ucSerialNumber, ucSerialNumber, sizeof(m_ucSerialNumber));
  m_cSerialFamily = cSerialFamily;
  if (pcTail)
    SetCVString(&m_sTail, pcTail);
  //## end CProjectorSerialNumber::Set%937312543.body
}

void CProjectorSerialNumber::Create ()
{
  //## begin CProjectorSerialNumber::Create%937312544.body preserve=yes
  CreateRecordBase(sizeof(*this), 2, PROJECTOR_SERIAL_NUMBER);
  //## end CProjectorSerialNumber::Create%937312544.body
}

// Additional Declarations
  //## begin CProjectorSerialNumber.declarations preserve=yes
  //## end CProjectorSerialNumber.declarations



// Class CProjectorHostInfo 



void CProjectorHostInfo::Set(const unsigned short usChainAddress, const char* pszHostName)
{
	m_usChainAddress = usChainAddress;
	SetCVString(&m_sHostName, pszHostName);
	SetSize(sizeof(*this) + m_sHostName.GetExtraSize());

}

void CProjectorHostInfo::Create ()
{
  m_sHostName.Reset();
	CreateRecordBase(sizeof(*this) + m_sHostName.GetExtraSize(), 2, PROJECTOR_HOST_INFO);
}


void CProjectorHostInfo_V3::Set(const unsigned long ulAddress, const char* pszHostName, unsigned char tcpConnected)
{
	m_ulAddress = ulAddress;
	m_ucTcpConnected = tcpConnected;
	SetCVString(&m_sHostName, pszHostName);
	SetSize(sizeof(*this) + m_sHostName.GetExtraSize());
}

void CProjectorHostInfo_V3::Create ()
{
  m_sHostName.Reset();
	CreateRecordBase(sizeof(*this) + m_sHostName.GetExtraSize(), 2, PROJECTOR_HOST_INFO_V3);
}


// Class CProjectorErrorMessage 




//## Other Operations (implementation)
void CProjectorErrorMessage::Set (unsigned char ucMessageLevel, unsigned short usMessageNumber, const char *pszText)
{
  //## begin CProjectorErrorMessage::Set%937398738.body preserve=yes
  AssertValid();
  m_ucMessageLevel = ucMessageLevel;
  m_usMessageNumber = usMessageNumber;
  ASSERT(GetSize() == sizeof(*this) + m_sText.GetExtraSize());
  SetCVString(&m_sText, pszText);
  SetSize(sizeof(*this) + m_sText.GetExtraSize());
  //## end CProjectorErrorMessage::Set%937398738.body
}

void CProjectorErrorMessage::Create ()
{
  //## begin CProjectorErrorMessage::Create%937398739.body preserve=yes
  m_sText.Reset();
  CreateRecordBase(sizeof(*this) + m_sText.GetExtraSize(),
                   0,
                   PROJECTOR_ERROR_MESSAGE);
  //## end CProjectorErrorMessage::Create%937398739.body
}

// Additional Declarations
  //## begin CProjectorErrorMessage.declarations preserve=yes
  //## end CProjectorErrorMessage.declarations



// Class CProjectorName 



//## Other Operations (implementation)
void CProjectorName::Set (const char *pszName)
{
  //## begin CProjectorName::Set%937398741.body preserve=yes
  AssertValid();
  ASSERT(GetSize() == sizeof(*this) + m_sName.GetExtraSize());
  SetCVString(&m_sName, pszName);
  SetSize(sizeof(*this) + m_sName.GetExtraSize());
  //## end CProjectorName::Set%937398741.body
}

void CProjectorName::Create ()
{
  //## begin CProjectorName::Create%937398742.body preserve=yes
  m_sName.Reset();
  CreateRecordBase(sizeof(*this) + m_sName.GetExtraSize(),
                   2,
                   PROJECTOR_NAME);
  //## end CProjectorName::Create%937398742.body
}

// Additional Declarations
  //## begin CProjectorName.declarations preserve=yes
  //## end CProjectorName.declarations



// Class CProjectorVersionInfo 



//## Other Operations (implementation)
void CProjectorVersionInfo::Set (const char *pszVersionText)
{
  //## begin CProjectorVersionInfo::Set%937398744.body preserve=yes
  AssertValid();
  ASSERT(GetSize() == sizeof(*this) + m_sVersionText.GetExtraSize());
  SetCVString(&m_sVersionText, pszVersionText);
  SetSize(sizeof(*this) + m_sVersionText.GetExtraSize());
  //## end CProjectorVersionInfo::Set%937398744.body
}

void CProjectorVersionInfo::Create ()
{
  //## begin CProjectorVersionInfo::Create%937398745.body preserve=yes
  m_sVersionText.Reset();
  CreateRecordBase(sizeof(*this) + m_sVersionText.GetExtraSize(),
                   2,
                   PROJECTOR_VERSION_INFO);
  //## end CProjectorVersionInfo::Create%937398745.body
}


// Class CProjectorSoftwareUpdate 

//## Other Operations (implementation)
void CProjectorSoftwareUpdate::Set (unsigned char ucDelaySeconds)
{
  //## begin CProjectorSoftwareUpdate::Set%937560453.body preserve=yes
  m_ucDelaySeconds = ucDelaySeconds;
  //## end CProjectorSoftwareUpdate::Set%937560453.body
}

void CProjectorSoftwareUpdate::Create ()
{
  //## begin CProjectorSoftwareUpdate::Create%937560454.body preserve=yes
  CreateRecordBase(sizeof(*this), 0, PROJECTOR_SOFTWARE_UPDATE);
  //## end CProjectorSoftwareUpdate::Create%937560454.body
}

// Additional Declarations
  //## begin CProjectorSoftwareUpdate.declarations preserve=yes
  //## end CProjectorSoftwareUpdate.declarations



// Class CProjectorRestart 



//## Other Operations (implementation)
void CProjectorRestart::Set (unsigned char ucDelaySeconds)
{
  //## begin CProjectorRestart::Set%937560456.body preserve=yes
  m_ucDelaySeconds = ucDelaySeconds;
  //## end CProjectorRestart::Set%937560456.body
}

void CProjectorRestart::Create ()
{
  //## begin CProjectorRestart::Create%937560457.body preserve=yes
  CreateRecordBase(sizeof(*this), 0, PROJECTOR_RESTART);
  //## end CProjectorRestart::Create%937560457.body
}

// Additional Declarations
  //## begin CProjectorRestart.declarations preserve=yes
  //## end CProjectorRestart.declarations




// Class CProjectorFlashErase 





//## Other Operations (implementation)
void CProjectorFlashErase::Set (unsigned long ulStartAddress, unsigned long ulBlockSize, unsigned char ucDelaySeconds)
{
  //## begin CProjectorFlashErase::Set%937560459.body preserve=yes
  ASSERT(!(ulStartAddress & 0xffff));
  ASSERT(!(ulBlockSize & 0xffff));
  m_ulStartAddress = ulStartAddress;
  m_ulBlockSize = ulBlockSize;
  m_ucDelaySeconds = ucDelaySeconds;
  //## end CProjectorFlashErase::Set%937560459.body
}

void CProjectorFlashErase::Create ()
{
  //## begin CProjectorFlashErase::Create%937560460.body preserve=yes
  CreateRecordBase(sizeof(*this), 0, PROJECTOR_FLASH_ERASE);
  //## end CProjectorFlashErase::Create%937560460.body
}

// Additional Declarations
  //## begin CProjectorFlashErase.declarations preserve=yes
  //## end CProjectorFlashErase.declarations



// Class CProjectorFlashData 




//## Other Operations (implementation)
void CProjectorFlashData::Set (unsigned long ulStartAddress, unsigned short usBlockSize, const unsigned char *pData)
{
  //## begin CProjectorFlashData::Set%937560462.body preserve=yes
  ASSERT(usBlockSize > 0 && usBlockSize <= 1024);
  ASSERT(!(usBlockSize & 1));
  ASSERT(!(ulStartAddress & 1));
  m_ulStartAddress = ulStartAddress;
  m_usBlockSize = usBlockSize;
  memcpy((char *) &m_usBlockSize + sizeof(m_usBlockSize), pData, usBlockSize);
  SetSize(sizeof(*this) + usBlockSize);
  //## end CProjectorFlashData::Set%937560462.body
}

void CProjectorFlashData::Create ()
{
  //## begin CProjectorFlashData::Create%937560463.body preserve=yes
  CreateRecordBase(sizeof(*this),
                   2+sizeof(m_ulStartAddress)+sizeof(m_usBlockSize),
                   PROJECTOR_FLASH_DATA);
  //## end CProjectorFlashData::Create%937560463.body
}

// Additional Declarations
  //## begin CProjectorFlashData.declarations preserve=yes
  //## end CProjectorFlashData.declarations



// Class CProjectorRamData 




//## Other Operations (implementation)
void CProjectorRamData::Set (unsigned long ulStartAddress, unsigned short usBlockSize, const unsigned char *pData)
{
  //## begin CProjectorRamData::Set%937560465.body preserve=yes
  ASSERT(usBlockSize > 0 && usBlockSize <= 1024);
  m_ulStartAddress = ulStartAddress;
  m_usBlockSize = usBlockSize;
  memcpy((char *) &m_usBlockSize + sizeof(m_usBlockSize), pData, usBlockSize);
  SetSize(sizeof(*this) + usBlockSize);
  //## end CProjectorRamData::Set%937560465.body
}

void CProjectorRamData::Create ()
{
  //## begin CProjectorRamData::Create%937560466.body preserve=yes
  CreateRecordBase(sizeof(*this),
                   2+sizeof(m_ulStartAddress)+sizeof(m_usBlockSize),
                   PROJECTOR_RAM_DATA);
  //## end CProjectorRamData::Create%937560466.body
}

// Additional Declarations
  //## begin CProjectorRamData.declarations preserve=yes
  //## end CProjectorRamData.declarations



// Class CProjectorSaveParameters 



//## Other Operations (implementation)
void CProjectorSaveParameters::Set (unsigned char ucDelaySeconds)
{
  //## begin CProjectorSaveParameters::Set%937572554.body preserve=yes
  m_ucDelaySeconds = ucDelaySeconds;
  //## end CProjectorSaveParameters::Set%937572554.body
}

void CProjectorSaveParameters::Create ()
{
  //## begin CProjectorSaveParameters::Create%937572555.body preserve=yes
  CreateRecordBase(sizeof(*this), 0, PROJECTOR_SAVE_PARAMETERS);
  //## end CProjectorSaveParameters::Create%937572555.body
}

// Additional Declarations
  //## begin CProjectorSaveParameters.declarations preserve=yes
  //## end CProjectorSaveParameters.declarations



// Class CProjectorRestoreDefaults 


//## Other Operations (implementation)
void CProjectorRestoreDefaults::Set ()
{
  //## begin CProjectorRestoreDefaults::Set%939392274.body preserve=yes
  //## end CProjectorRestoreDefaults::Set%939392274.body
}

void CProjectorRestoreDefaults::Create ()
{
  //## begin CProjectorRestoreDefaults::Create%939392275.body preserve=yes
  CreateRecordBase(sizeof(*this), 0, PROJECTOR_RESTORE_DEFAULTS);
  //## end CProjectorRestoreDefaults::Create%939392275.body
}

// Additional Declarations
  //## begin CProjectorRestoreDefaults.declarations preserve=yes
  //## end CProjectorRestoreDefaults.declarations



//## begin module.epilog preserve=yes

void CProjectorMessageLevel::Set(unsigned char ucMinMessageLevel)
{
  AssertValid();
  ASSERT(GetSize() == sizeof(*this));
  m_ucMinMessageLevel = ucMinMessageLevel;
}

void CProjectorMessageLevel::Create ()
{
  m_ucMinMessageLevel = 0;
  CreateRecordBase(sizeof(*this), 2, PROJECTOR_MESSAGE_LEVEL);
}


// Class CProjectorTestMessage 



//## Other Operations (implementation)
void CProjectorTestMessage::Set ()
{
  //## begin CProjectorTestMessage::Set%937560456.body preserve=yes
  //## end CProjectorTestMessage::Set%937560456.body
}

void CProjectorTestMessage::Create ()
{
  //## begin CProjectorTestMessage::Create%937560457.body preserve=yes
  CreateRecordBase(sizeof(*this), 2, PROJECTOR_TEST_MESSAGE);
  //## end CProjectorTestMessage::Create%937560457.body
}

// Additional Declarations
  //## begin CProjectorTestMessage.declarations preserve=yes
  //## end CProjectorTestMessage.declarations


void CScreenSegmentChainInfo::Set(const char* pszChainID)
{
	SetCVString(&m_sChainID, pszChainID);
	SetSize(sizeof(*this) + m_sChainID.GetExtraSize());
}

void CScreenSegmentChainInfo::Create ()
{
	m_sChainID.Reset();
	CreateRecordBase(sizeof(*this) + m_sChainID.GetExtraSize(), 2, CV_SCREEN_CHAIN_INFO);
}


//## end module.epilog

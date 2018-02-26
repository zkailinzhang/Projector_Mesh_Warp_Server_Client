//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: CVprotocolHandshake; Package specification
//## Subsystem: cvsetup
//	c:\src\graphics\cvsetup
//## Source file: c:\src\graphics\cvsetup\CVprotocolHandshake.h

#ifndef CVprotocolHandshake_h
#define CVprotocolHandshake_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// CVprotocol
#include "CVprotocol.h"
//## begin module.declarations preserve=no
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
#if defined(MEGAWALL2)
#pragma pack(push,1)
#elif defined(CVPROJ) && GCM_VERSION==4
#pragma pack(1)
#else
#pragma pack(push, CVprotocolHandshake)
#pragma pack(1)
#endif
//## end module.additionalDeclarations


//## Class: CRequestProjectorState
//	Request projector state Command
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CRequestProjectorState : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CRequestProjectorState.initialDeclarations preserve=yes
  //## end CRequestProjectorState.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%937312539; C++
      //	Create record in an existing buffer
      static CRequestProjectorState* CreateInBuffer (char* pBuffer);

      //## Operation: Set%937312541
      //	Set data fields of record
      void Set (unsigned short usRequestIdSize, unsigned short usRequestRecordType, const unsigned char *pKey);

      //## Operation: Create%937312540; C++
      //	Initialize data record.
      void Create ();

      //## Operation: GetRequestRecord%937560467
      const CRecordBase* GetRequestRecord () const;

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: usRequestIdSize
      const unsigned short GetusRequestIdSize () const;

      //## Attribute: usRequestRecordType
      const unsigned short GetusRequestRecordType () const;

    // Additional Public Declarations
      //## begin CRequestProjectorState.public preserve=yes
      //## end CRequestProjectorState.public

  protected:
    // Additional Protected Declarations
      //## begin CRequestProjectorState.protected preserve=yes
      //## end CRequestProjectorState.protected

  private:
    // Additional Private Declarations
      //## begin CRequestProjectorState.private preserve=yes
      //## end CRequestProjectorState.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CRequestProjectorState::usRequestIdSize.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usRequestIdSize;
      //## end CRequestProjectorState::usRequestIdSize.attr

      //## begin CRequestProjectorState::usRequestRecordType.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usRequestRecordType;
      //## end CRequestProjectorState::usRequestRecordType.attr

    // Additional Implementation Declarations
      //## begin CRequestProjectorState.implementation preserve=yes
      //## end CRequestProjectorState.implementation

};

//## begin CRequestProjectorState.postscript preserve=yes
//## end CRequestProjectorState.postscript


class CRequestStateList : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CRequestStateList* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set (unsigned short usDT, unsigned short usTimeoutMs);
      void AddRequest (unsigned short usRequestIdSize, unsigned short usRequestRecordType, const unsigned char *pKey);
      void Create ();
      const CRecordBase* GetRequestRecord (const char **ppPrev) const;
      const unsigned short GetusTimeoutMs() const;
      const unsigned short GetusDT () const;

    // Additional Public Declarations
  protected:
    // Additional Protected Declarations
  private:
    // Additional Private Declarations
  private:  //## implementation
    // Data Members for Class Attributes
      CConvLE<unsigned short> m_usTimeoutMs;
      CConvLE<unsigned short> m_usDT;
};



//## Class: CProjectorSerialNumber
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CProjectorSerialNumber : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CProjectorSerialNumber.initialDeclarations preserve=yes
  //## end CProjectorSerialNumber.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%937312542; C++
      //	Create record in an existing buffer
      static CProjectorSerialNumber* CreateInBuffer (char* pBuffer);

      //## Operation: Set%937312543
      //	Set data fields of record
      void Set (const unsigned char *ucSerialNumber, char cSerialFamily, const char *pcTail = NULL);

      //## Operation: Create%937312544; C++
      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: ucSerialNumber
      //	Serial Number
      const unsigned char* GetucSerialNumber () const;

    // Additional Public Declarations
      //## begin CProjectorSerialNumber.public preserve=yes
      //## end CProjectorSerialNumber.public
      char GetcSerialFamily () const;

      const CCVString &GetTail() const;
      
  protected:
    // Additional Protected Declarations
      //## begin CProjectorSerialNumber.protected preserve=yes
      //## end CProjectorSerialNumber.protected

  private:
    // Additional Private Declarations
      //## begin CProjectorSerialNumber.private preserve=yes
      //## end CProjectorSerialNumber.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CProjectorSerialNumber::ucSerialNumber.attr preserve=no  public: unsigned char[8] {U} 
      unsigned char m_ucSerialNumber[8];
      //## end CProjectorSerialNumber::ucSerialNumber.attr

    // Additional Implementation Declarations
      //## begin CProjectorSerialNumber.implementation preserve=yes
      //## end CProjectorSerialNumber.implementation

      char m_cSerialFamily;  // Note:  Not present in old version - check message size!

    // Additional for Megawall 2
    
      CCVString m_sTail;     // Address tail (including leading "."
  };

//## begin CProjectorSerialNumber.postscript preserve=yes
//## end CProjectorSerialNumber.postscript



//## Class: CProjectorErrorMessage
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CProjectorErrorMessage : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CProjectorErrorMessage.initialDeclarations preserve=yes
  //## end CProjectorErrorMessage.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%937398737; C++
      //	Create record in an existing buffer
      static CProjectorErrorMessage* CreateInBuffer (char* pBuffer);

      //## Operation: Set%937398738
      //	Set data fields of record
      void Set (unsigned char ucMessageLevel, unsigned short usMessageNumber, const char *pszText);

      //## Operation: Create%937398739; C++
      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: ucMessageLevel
      const unsigned char GetucMessageLevel () const;

      //## Attribute: usMessageNumber
      const unsigned short GetusMessageNumber () const;

      //## Attribute: sText
      const CCVString& GetsText () const;

    // Additional Public Declarations
      //## begin CProjectorErrorMessage.public preserve=yes
      //## end CProjectorErrorMessage.public

  protected:
    // Additional Protected Declarations
      //## begin CProjectorErrorMessage.protected preserve=yes
      //## end CProjectorErrorMessage.protected

  private:
    // Additional Private Declarations
      //## begin CProjectorErrorMessage.private preserve=yes
      //## end CProjectorErrorMessage.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CProjectorErrorMessage::ucMessageLevel.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucMessageLevel;
      //## end CProjectorErrorMessage::ucMessageLevel.attr

      //## begin CProjectorErrorMessage::usMessageNumber.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usMessageNumber;
      //## end CProjectorErrorMessage::usMessageNumber.attr

      //## begin CProjectorErrorMessage::sText.attr preserve=no  public: CCVString {U} 
      CCVString m_sText;
      //## end CProjectorErrorMessage::sText.attr

    // Additional Implementation Declarations
      //## begin CProjectorErrorMessage.implementation preserve=yes
      //## end CProjectorErrorMessage.implementation

};

//## begin CProjectorErrorMessage.postscript preserve=yes
//## end CProjectorErrorMessage.postscript



class CProjectorHostInfo : public CRecordBase 
{
  public:
      static CProjectorHostInfo* CreateInBuffer (char* pBuffer);
      void Set(const unsigned short usChainAddress, const char *pszHostName);
      void Create ();
      const unsigned short GetusChainAddress() const;
      const CCVString& GetsHostName () const;
  private:
      CConvLE<unsigned short>	m_usChainAddress;
      CCVString			m_sHostName;
};


class CProjectorHostInfo_V2 : public CRecordBase 
{
  public:
#if 0  // Defunct, do not create.  Replaced by _V3
      static CProjectorHostInfo_V2* CreateInBuffer (char* pBuffer);
      void Set(const unsigned long ulAddress, const char *pszHostName, unsigned char tcpConnected);
      void Create ();
#endif
      const unsigned long GetulAddress() const;
      const CCVString& GetsHostName () const;
	    const unsigned char GetucTcpConnected() const;
  private:
      CConvLE<unsigned long>	m_ulAddress;
      CCVString			m_sHostName;
      CConvLE<unsigned char>	m_ucTcpConnected;  // Invalid - overwritten by m_sHostName
};

class CProjectorHostInfo_V3 : public CRecordBase 
{
  public:
      static CProjectorHostInfo_V3* CreateInBuffer (char* pBuffer);
      void Set(const unsigned long ulAddress, const char *pszHostName, unsigned char tcpConnected);
      void Create ();
      const unsigned long GetulAddress() const;
      const CCVString& GetsHostName () const;
	  const unsigned char GetucTcpConnected() const;
  private:
      CConvLE<unsigned long>	m_ulAddress;
      CConvLE<unsigned char>	m_ucTcpConnected;
      CCVString			m_sHostName;
};


class CScreenSegmentChainInfo : public CRecordBase 
{
  public:
      static CScreenSegmentChainInfo* CreateInBuffer (char* pBuffer);
      void Set(const char *pszChainID);
      void Create ();
      const CCVString& GetsChainID() const;
  private:
      CCVString			m_sChainID;
};

inline CScreenSegmentChainInfo* CScreenSegmentChainInfo::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);
  CScreenSegmentChainInfo *pItem = (CScreenSegmentChainInfo *) pBuffer;
  pItem->Create();
  return pItem;
}


inline const CCVString& CScreenSegmentChainInfo::GetsChainID() const
{
  return m_sChainID;
}

//## Class: CProjectorName
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CProjectorName : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CProjectorName.initialDeclarations preserve=yes
  //## end CProjectorName.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%937398740; C++
      //	Create record in an existing buffer
      static CProjectorName* CreateInBuffer (char* pBuffer);

      //## Operation: Set%937398741
      //	Set data fields of record
      void Set (const char *pszName);

      //## Operation: Create%937398742; C++
      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: sName
      const CCVString& GetsName () const;

    // Additional Public Declarations
      //## begin CProjectorName.public preserve=yes
      //## end CProjectorName.public

  protected:
    // Additional Protected Declarations
      //## begin CProjectorName.protected preserve=yes
      //## end CProjectorName.protected

  private:
    // Additional Private Declarations
      //## begin CProjectorName.private preserve=yes
      //## end CProjectorName.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CProjectorName::sName.attr preserve=no  public: CCVString {U} 
      CCVString m_sName;
      //## end CProjectorName::sName.attr

    // Additional Implementation Declarations
      //## begin CProjectorName.implementation preserve=yes
      //## end CProjectorName.implementation

};

//## begin CProjectorName.postscript preserve=yes
//## end CProjectorName.postscript



//## Class: CProjectorVersionInfo
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CProjectorVersionInfo : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CProjectorVersionInfo.initialDeclarations preserve=yes
  //## end CProjectorVersionInfo.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%937398743; C++
      //	Create record in an existing buffer
      static CProjectorVersionInfo* CreateInBuffer (char* pBuffer);

      //## Operation: Set%937398744
      //	Set data fields of record
      void Set (const char *pszVersionText);

      //## Operation: Create%937398745; C++
      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: sVersionText
      const CCVString& GetsVersionText () const;

    // Additional Public Declarations
      //## begin CProjectorVersionInfo.public preserve=yes
      //## end CProjectorVersionInfo.public

  protected:
    // Additional Protected Declarations
      //## begin CProjectorVersionInfo.protected preserve=yes
      //## end CProjectorVersionInfo.protected

  private:
    // Additional Private Declarations
      //## begin CProjectorVersionInfo.private preserve=yes
      //## end CProjectorVersionInfo.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CProjectorVersionInfo::sVersionText.attr preserve=no  public: CCVString {U} 
      CCVString m_sVersionText;
      //## end CProjectorVersionInfo::sVersionText.attr

    // Additional Implementation Declarations
      //## begin CProjectorVersionInfo.implementation preserve=yes
      //## end CProjectorVersionInfo.implementation

};

//## begin CProjectorVersionInfo.postscript preserve=yes
//## end CProjectorVersionInfo.postscript



//## Class: CProjectorSoftwareUpdate
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CProjectorSoftwareUpdate : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CProjectorSoftwareUpdate.initialDeclarations preserve=yes
  //## end CProjectorSoftwareUpdate.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%937560452; C++
      //	Create record in an existing buffer
      static CProjectorSoftwareUpdate* CreateInBuffer (char* pBuffer);

      //## Operation: Set%937560453
      //	Set data fields of record
      void Set (unsigned char ucDelaySeconds);

      //## Operation: Create%937560454; C++
      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: ucDelaySeconds
      const unsigned char GetucDelaySeconds () const;

    // Additional Public Declarations
      //## begin CProjectorSoftwareUpdate.public preserve=yes
      //## end CProjectorSoftwareUpdate.public

  protected:
    // Additional Protected Declarations
      //## begin CProjectorSoftwareUpdate.protected preserve=yes
      //## end CProjectorSoftwareUpdate.protected

  private:
    // Additional Private Declarations
      //## begin CProjectorSoftwareUpdate.private preserve=yes
      //## end CProjectorSoftwareUpdate.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CProjectorSoftwareUpdate::ucDelaySeconds.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucDelaySeconds;
      //## end CProjectorSoftwareUpdate::ucDelaySeconds.attr

    // Additional Implementation Declarations
      //## begin CProjectorSoftwareUpdate.implementation preserve=yes
      //## end CProjectorSoftwareUpdate.implementation

};

//## begin CProjectorSoftwareUpdate.postscript preserve=yes
//## end CProjectorSoftwareUpdate.postscript



//## Class: CProjectorRestart
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CProjectorRestart : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CProjectorRestart.initialDeclarations preserve=yes
  //## end CProjectorRestart.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%937560455; C++
      //	Create record in an existing buffer
      static CProjectorRestart* CreateInBuffer (char* pBuffer);

      //## Operation: Set%937560456
      //	Set data fields of record
      void Set (unsigned char ucDelaySeconds);

      //## Operation: Create%937560457; C++
      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: ucDelaySeconds
      const unsigned char GetucDelaySeconds () const;

    // Additional Public Declarations
      //## begin CProjectorRestart.public preserve=yes
      //## end CProjectorRestart.public

  protected:
    // Additional Protected Declarations
      //## begin CProjectorRestart.protected preserve=yes
      //## end CProjectorRestart.protected

  private:
    // Additional Private Declarations
      //## begin CProjectorRestart.private preserve=yes
      //## end CProjectorRestart.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CProjectorRestart::ucDelaySeconds.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucDelaySeconds;
      //## end CProjectorRestart::ucDelaySeconds.attr

    // Additional Implementation Declarations
      //## begin CProjectorRestart.implementation preserve=yes
      //## end CProjectorRestart.implementation

};

//## begin CProjectorRestart.postscript preserve=yes
//## end CProjectorRestart.postscript



//## Class: CProjectorFlashErase
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CProjectorFlashErase : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CProjectorFlashErase.initialDeclarations preserve=yes
  //## end CProjectorFlashErase.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%937560458; C++
      //	Create record in an existing buffer
      static CProjectorFlashErase* CreateInBuffer (char* pBuffer);

      //## Operation: Set%937560459
      //	Set data fields of record
      void Set (unsigned long ulStartAddress, unsigned long ulBlockSize, unsigned char ucDelaySeconds);

      //## Operation: Create%937560460; C++
      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: ulStartAddress
      const unsigned long GetulStartAddress () const;

      //## Attribute: ulBlockSize
      const unsigned long GetulBlockSize () const;

      //## Attribute: ucDelaySeconds
      const unsigned char GetucDelaySeconds () const;

    // Additional Public Declarations
      //## begin CProjectorFlashErase.public preserve=yes
      //## end CProjectorFlashErase.public

  protected:
    // Additional Protected Declarations
      //## begin CProjectorFlashErase.protected preserve=yes
      //## end CProjectorFlashErase.protected

  private:
    // Additional Private Declarations
      //## begin CProjectorFlashErase.private preserve=yes
      //## end CProjectorFlashErase.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CProjectorFlashErase::ulStartAddress.attr preserve=no  public: unsigned long {U} 
      CConvLE<unsigned long> m_ulStartAddress;
      //## end CProjectorFlashErase::ulStartAddress.attr

      //## begin CProjectorFlashErase::ulBlockSize.attr preserve=no  public: unsigned long {U} 
      CConvLE<unsigned long> m_ulBlockSize;
      //## end CProjectorFlashErase::ulBlockSize.attr

      //## begin CProjectorFlashErase::ucDelaySeconds.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucDelaySeconds;
      //## end CProjectorFlashErase::ucDelaySeconds.attr

    // Additional Implementation Declarations
      //## begin CProjectorFlashErase.implementation preserve=yes
      //## end CProjectorFlashErase.implementation

};

//## begin CProjectorFlashErase.postscript preserve=yes
//## end CProjectorFlashErase.postscript



//## Class: CProjectorFlashData
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CProjectorFlashData : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CProjectorFlashData.initialDeclarations preserve=yes
  //## end CProjectorFlashData.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%937560461; C++
      //	Create record in an existing buffer
      static CProjectorFlashData* CreateInBuffer (char* pBuffer);

      //## Operation: Set%937560462
      //	Set data fields of record
      void Set (unsigned long ulStartAddress, unsigned short usBlockSize, const unsigned char *pData);

      //## Operation: Create%937560463; C++
      //	Initialize data record.
      void Create ();

      //## Operation: GetDataPtr%937572551
      const unsigned char* GetDataPtr () const;

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: ulStartAddress
      const unsigned long GetulStartAddress () const;

      //## Attribute: usBlockSize
      const unsigned short GetusBlockSize () const;

    // Additional Public Declarations
      //## begin CProjectorFlashData.public preserve=yes
      //## end CProjectorFlashData.public

  protected:
    // Additional Protected Declarations
      //## begin CProjectorFlashData.protected preserve=yes
      //## end CProjectorFlashData.protected

  private:
    // Additional Private Declarations
      //## begin CProjectorFlashData.private preserve=yes
      //## end CProjectorFlashData.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CProjectorFlashData::ulStartAddress.attr preserve=no  public: unsigned long {U} 
      CConvLE<unsigned long> m_ulStartAddress;
      //## end CProjectorFlashData::ulStartAddress.attr

      //## begin CProjectorFlashData::usBlockSize.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usBlockSize;
      //## end CProjectorFlashData::usBlockSize.attr

    // Additional Implementation Declarations
      //## begin CProjectorFlashData.implementation preserve=yes
      //## end CProjectorFlashData.implementation

};

//## begin CProjectorFlashData.postscript preserve=yes
//## end CProjectorFlashData.postscript



//## Class: CProjectorRamData
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CProjectorRamData : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CProjectorRamData.initialDeclarations preserve=yes
  //## end CProjectorRamData.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%937560464; C++
      //	Create record in an existing buffer
      static CProjectorRamData* CreateInBuffer (char* pBuffer);

      //## Operation: Set%937560465
      //	Set data fields of record
      void Set (unsigned long ulStartAddress, unsigned short usBlockSize, const unsigned char *pData);

      //## Operation: Create%937560466; C++
      //	Initialize data record.
      void Create ();

      //## Operation: GetDataPtr%937572552
      const unsigned char* GetDataPtr () const;

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: ulStartAddress
      const unsigned long GetulStartAddress () const;

      //## Attribute: usBlockSize
      const unsigned short GetusBlockSize () const;

    // Additional Public Declarations
      //## begin CProjectorRamData.public preserve=yes
      //## end CProjectorRamData.public

  protected:
    // Additional Protected Declarations
      //## begin CProjectorRamData.protected preserve=yes
      //## end CProjectorRamData.protected

  private:
    // Additional Private Declarations
      //## begin CProjectorRamData.private preserve=yes
      //## end CProjectorRamData.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CProjectorRamData::ulStartAddress.attr preserve=no  public: unsigned long {U} 
      CConvLE<unsigned long> m_ulStartAddress;
      //## end CProjectorRamData::ulStartAddress.attr

      //## begin CProjectorRamData::usBlockSize.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usBlockSize;
      //## end CProjectorRamData::usBlockSize.attr

    // Additional Implementation Declarations
      //## begin CProjectorRamData.implementation preserve=yes
      //## end CProjectorRamData.implementation

};

//## begin CProjectorRamData.postscript preserve=yes
//## end CProjectorRamData.postscript



//## Class: CProjectorSaveParameters
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CProjectorSaveParameters : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CProjectorSaveParameters.initialDeclarations preserve=yes
  //## end CProjectorSaveParameters.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%937572553; C++
      //	Create record in an existing buffer
      static CProjectorSaveParameters* CreateInBuffer (char* pBuffer);

      //## Operation: Set%937572554
      //	Set data fields of record
      void Set (unsigned char ucDelaySeconds);

      //## Operation: Create%937572555; C++
      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: ucDelaySeconds
      const unsigned char GetucDelaySeconds () const;

    // Additional Public Declarations
      //## begin CProjectorSaveParameters.public preserve=yes
      //## end CProjectorSaveParameters.public

  protected:
    // Additional Protected Declarations
      //## begin CProjectorSaveParameters.protected preserve=yes
      //## end CProjectorSaveParameters.protected

  private:
    // Additional Private Declarations
      //## begin CProjectorSaveParameters.private preserve=yes
      //## end CProjectorSaveParameters.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CProjectorSaveParameters::ucDelaySeconds.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucDelaySeconds;
      //## end CProjectorSaveParameters::ucDelaySeconds.attr

    // Additional Implementation Declarations
      //## begin CProjectorSaveParameters.implementation preserve=yes
      //## end CProjectorSaveParameters.implementation

};

//## begin CProjectorSaveParameters.postscript preserve=yes
//## end CProjectorSaveParameters.postscript



//## Class: CProjectorRestoreDefaults
//	Restore default settings in projector
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CProjectorRestoreDefaults : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CProjectorRestoreDefaults.initialDeclarations preserve=yes
  //## end CProjectorRestoreDefaults.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%939392273; C++
      //	Create record in an existing buffer
      static CProjectorRestoreDefaults* CreateInBuffer (char* pBuffer);

      //## Operation: Set%939392274
      //	Set data fields of record
      void Set ();

      //## Operation: Create%939392275; C++
      //	Initialize data record.
      void Create ();

    // Additional Public Declarations
      //## begin CProjectorRestoreDefaults.public preserve=yes
      //## end CProjectorRestoreDefaults.public

  protected:
    // Additional Protected Declarations
      //## begin CProjectorRestoreDefaults.protected preserve=yes
      //## end CProjectorRestoreDefaults.protected

  private:
    // Additional Private Declarations
      //## begin CProjectorRestoreDefaults.private preserve=yes
      //## end CProjectorRestoreDefaults.private

  private:  //## implementation
    // Additional Implementation Declarations
      //## begin CProjectorRestoreDefaults.implementation preserve=yes
      //## end CProjectorRestoreDefaults.implementation

};

//## begin CProjectorRestoreDefaults.postscript preserve=yes
//## end CProjectorRestoreDefaults.postscript


class CProjectorMessageLevel : public CRecordBase 
{
  public:
      static CProjectorMessageLevel* CreateInBuffer (char* pBuffer);
      void Set (const unsigned char ucMinMessageLevel);
      void Create ();

      unsigned char GetucMinMessageLevel () const;

  private:
      unsigned char m_ucMinMessageLevel;

};






//## Class: CProjectorTestMessage
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CProjectorTestMessage : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CProjectorTestMessage.initialDeclarations preserve=yes
  //## end CProjectorTestMessage.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%937560455; C++
      //	Create record in an existing buffer
      static CProjectorTestMessage* CreateInBuffer (char* pBuffer);

      //## Operation: Set%937560456
      //	Set data fields of record
      void Set ();

      //## Operation: Create%937560457; C++
      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

    // Additional Public Declarations
      //## begin CProjectorTestMessage.public preserve=yes
      //## end CProjectorTestMessage.public

  protected:
    // Additional Protected Declarations
      //## begin CProjectorTestMessage.protected preserve=yes
      //## end CProjectorTestMessage.protected

  private:
    // Additional Private Declarations
      //## begin CProjectorTestMessage.private preserve=yes
      //## end CProjectorTestMessage.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CProjectorTestMessage::ucDelaySeconds.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucDelaySeconds;
      //## end CProjectorTestMessage::ucDelaySeconds.attr

    // Additional Implementation Declarations
      //## begin CProjectorTestMessage.implementation preserve=yes
      //## end CProjectorTestMessage.implementation

};

//## begin CProjectorTestMessage.postscript preserve=yes
//## end CProjectorTestMessage.postscript




// Class CRequestProjectorState 


//## Other Operations (inline)
inline CRequestProjectorState* CRequestProjectorState::CreateInBuffer (char* pBuffer)
{
  //## begin CRequestProjectorState::CreateInBuffer%937312539.body preserve=yes
  ASSERT(pBuffer);

  CRequestProjectorState *pItem = (CRequestProjectorState *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CRequestProjectorState::CreateInBuffer%937312539.body
}

inline const CRecordBase* CRequestProjectorState::GetRequestRecord () const
{
  //## begin CRequestProjectorState::GetRequestRecord%937560467.body preserve=yes
  return (const CRecordBase *) ((const char *) &m_usRequestIdSize - 2);
  //## end CRequestProjectorState::GetRequestRecord%937560467.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned short CRequestProjectorState::GetusRequestIdSize () const
{
  //## begin CRequestProjectorState::GetusRequestIdSize%.get preserve=no
  return m_usRequestIdSize;
  //## end CRequestProjectorState::GetusRequestIdSize%.get
}

inline const unsigned short CRequestProjectorState::GetusRequestRecordType () const
{
  //## begin CRequestProjectorState::GetusRequestRecordType%.get preserve=no
  return m_usRequestRecordType;
  //## end CRequestProjectorState::GetusRequestRecordType%.get
}



// Class CRequestStateList


//## Other Operations (inline)
inline CRequestStateList* CRequestStateList::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CRequestStateList *pItem = (CRequestStateList *) pBuffer;
  pItem->Create();

  return pItem;
}

inline const CRecordBase* CRequestStateList::GetRequestRecord (const char **ppPrev) const
{
  const char *pReq; 
  if (!*ppPrev)
    pReq = ((const char *) this + sizeof(*this) - 2);
  else
    pReq = *ppPrev + ((CRecordBase *) *ppPrev)->GetIdSize() + 2;

  if (pReq + sizeof(CRecordBase) > (const char *) this + GetSize())
    return NULL;

  *ppPrev = pReq;

  return (const CRecordBase *) pReq;
}



inline const unsigned short CRequestStateList::GetusTimeoutMs() const
{
  return m_usTimeoutMs;
}

inline const unsigned short CRequestStateList::GetusDT () const
{
  return m_usDT;
}




// Class CProjectorSerialNumber 


//## Other Operations (inline)
inline CProjectorSerialNumber* CProjectorSerialNumber::CreateInBuffer (char* pBuffer)
{
  //## begin CProjectorSerialNumber::CreateInBuffer%937312542.body preserve=yes
  ASSERT(pBuffer);

  CProjectorSerialNumber *pItem = (CProjectorSerialNumber *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CProjectorSerialNumber::CreateInBuffer%937312542.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned char* CProjectorSerialNumber::GetucSerialNumber () const
{
  //## begin CProjectorSerialNumber::GetucSerialNumber%.get preserve=no
  return m_ucSerialNumber;
  //## end CProjectorSerialNumber::GetucSerialNumber%.get
}

inline char CProjectorSerialNumber::GetcSerialFamily () const
{
  if (GetSize() >= offsetof(CProjectorSerialNumber, m_cSerialFamily) + sizeof(m_cSerialFamily))
    return m_cSerialFamily;
  else
    return 'V';  // Compatibility mode when family not in message
}

inline const CCVString &CProjectorSerialNumber::GetTail () const
{
  static CCVString empty;

  if (GetSize() >= offsetof(CProjectorSerialNumber, m_sTail) + sizeof(m_sTail))
    return m_sTail;
  else
    return empty;  // Compatibility mode when tail not in message
}




// Class CProjectorHostInfo 


inline CProjectorHostInfo* CProjectorHostInfo::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);
  CProjectorHostInfo *pItem = (CProjectorHostInfo *) pBuffer;
  pItem->Create();
  return pItem;
}

inline const unsigned short CProjectorHostInfo::GetusChainAddress() const
{
  return m_usChainAddress;
}


inline const CCVString& CProjectorHostInfo::GetsHostName() const
{
  return m_sHostName;
}



inline const unsigned long CProjectorHostInfo_V2::GetulAddress() const
{
  return m_ulAddress;
}


inline const CCVString& CProjectorHostInfo_V2::GetsHostName() const
{
  return m_sHostName;
}

inline const unsigned char CProjectorHostInfo_V2::GetucTcpConnected() const
{
  ASSERT(0);   // Not valid in _V2 due to bug
  return false;
}



inline CProjectorHostInfo_V3* CProjectorHostInfo_V3::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);
  CProjectorHostInfo_V3 *pItem = (CProjectorHostInfo_V3 *) pBuffer;
  pItem->Create();
  return pItem;
}

inline const unsigned long CProjectorHostInfo_V3::GetulAddress() const
{
  return m_ulAddress;
}


inline const CCVString& CProjectorHostInfo_V3::GetsHostName() const
{
  return m_sHostName;
}

inline const unsigned char CProjectorHostInfo_V3::GetucTcpConnected() const
{
  return m_ucTcpConnected;
}



// Class CProjectorErrorMessage 


//## Other Operations (inline)
inline CProjectorErrorMessage* CProjectorErrorMessage::CreateInBuffer (char* pBuffer)
{
  //## begin CProjectorErrorMessage::CreateInBuffer%937398737.body preserve=yes
  ASSERT(pBuffer);

  CProjectorErrorMessage *pItem = (CProjectorErrorMessage *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CProjectorErrorMessage::CreateInBuffer%937398737.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned char CProjectorErrorMessage::GetucMessageLevel () const
{
  //## begin CProjectorErrorMessage::GetucMessageLevel%.get preserve=no
  return m_ucMessageLevel;
  //## end CProjectorErrorMessage::GetucMessageLevel%.get
}

inline const unsigned short CProjectorErrorMessage::GetusMessageNumber () const
{
  //## begin CProjectorErrorMessage::GetusMessageNumber%.get preserve=no
  return m_usMessageNumber;
  //## end CProjectorErrorMessage::GetusMessageNumber%.get
}

inline const CCVString& CProjectorErrorMessage::GetsText () const
{
  //## begin CProjectorErrorMessage::GetsText%.get preserve=no
  return m_sText;
  //## end CProjectorErrorMessage::GetsText%.get
}





// Class CProjectorName 


//## Other Operations (inline)
inline CProjectorName* CProjectorName::CreateInBuffer (char* pBuffer)
{
  //## begin CProjectorName::CreateInBuffer%937398740.body preserve=yes
  ASSERT(pBuffer);

  CProjectorName *pItem = (CProjectorName *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CProjectorName::CreateInBuffer%937398740.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const CCVString& CProjectorName::GetsName () const
{
  //## begin CProjectorName::GetsName%.get preserve=no
  return m_sName;
  //## end CProjectorName::GetsName%.get
}





// Class CProjectorVersionInfo 


//## Other Operations (inline)
inline CProjectorVersionInfo* CProjectorVersionInfo::CreateInBuffer (char* pBuffer)
{
  //## begin CProjectorVersionInfo::CreateInBuffer%937398743.body preserve=yes
  ASSERT(pBuffer);

  CProjectorVersionInfo *pItem = (CProjectorVersionInfo *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CProjectorVersionInfo::CreateInBuffer%937398743.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const CCVString& CProjectorVersionInfo::GetsVersionText () const
{
  //## begin CProjectorVersionInfo::GetsVersionText%.get preserve=no
  return m_sVersionText;
  //## end CProjectorVersionInfo::GetsVersionText%.get
}





// Class CProjectorSoftwareUpdate 


//## Other Operations (inline)
inline CProjectorSoftwareUpdate* CProjectorSoftwareUpdate::CreateInBuffer (char* pBuffer)
{
  //## begin CProjectorSoftwareUpdate::CreateInBuffer%937560452.body preserve=yes
  ASSERT(pBuffer);

  CProjectorSoftwareUpdate *pItem = (CProjectorSoftwareUpdate *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CProjectorSoftwareUpdate::CreateInBuffer%937560452.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned char CProjectorSoftwareUpdate::GetucDelaySeconds () const
{
  //## begin CProjectorSoftwareUpdate::GetucDelaySeconds%.get preserve=no
  return m_ucDelaySeconds;
  //## end CProjectorSoftwareUpdate::GetucDelaySeconds%.get
}





// Class CProjectorRestart 


//## Other Operations (inline)
inline CProjectorRestart* CProjectorRestart::CreateInBuffer (char* pBuffer)
{
  //## begin CProjectorRestart::CreateInBuffer%937560455.body preserve=yes
  ASSERT(pBuffer);

  CProjectorRestart *pItem = (CProjectorRestart *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CProjectorRestart::CreateInBuffer%937560455.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned char CProjectorRestart::GetucDelaySeconds () const
{
  //## begin CProjectorRestart::GetucDelaySeconds%.get preserve=no
  return m_ucDelaySeconds;
  //## end CProjectorRestart::GetucDelaySeconds%.get
}





// Class CProjectorFlashErase 


//## Other Operations (inline)
inline CProjectorFlashErase* CProjectorFlashErase::CreateInBuffer (char* pBuffer)
{
  //## begin CProjectorFlashErase::CreateInBuffer%937560458.body preserve=yes
  ASSERT(pBuffer);

  CProjectorFlashErase *pItem = (CProjectorFlashErase *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CProjectorFlashErase::CreateInBuffer%937560458.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned long CProjectorFlashErase::GetulStartAddress () const
{
  //## begin CProjectorFlashErase::GetulStartAddress%.get preserve=no
  return m_ulStartAddress;
  //## end CProjectorFlashErase::GetulStartAddress%.get
}

inline const unsigned long CProjectorFlashErase::GetulBlockSize () const
{
  //## begin CProjectorFlashErase::GetulBlockSize%.get preserve=no
  return m_ulBlockSize;
  //## end CProjectorFlashErase::GetulBlockSize%.get
}

inline const unsigned char CProjectorFlashErase::GetucDelaySeconds () const
{
  //## begin CProjectorFlashErase::GetucDelaySeconds%.get preserve=no
  return m_ucDelaySeconds;
  //## end CProjectorFlashErase::GetucDelaySeconds%.get
}





// Class CProjectorFlashData 


//## Other Operations (inline)
inline CProjectorFlashData* CProjectorFlashData::CreateInBuffer (char* pBuffer)
{
  //## begin CProjectorFlashData::CreateInBuffer%937560461.body preserve=yes
  ASSERT(pBuffer);

  CProjectorFlashData *pItem = (CProjectorFlashData *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CProjectorFlashData::CreateInBuffer%937560461.body
}

inline const unsigned char* CProjectorFlashData::GetDataPtr () const
{
  //## begin CProjectorFlashData::GetDataPtr%937572551.body preserve=yes
  return (unsigned char *) CRecordBase::GetDataPtr();
  //## end CProjectorFlashData::GetDataPtr%937572551.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned long CProjectorFlashData::GetulStartAddress () const
{
  //## begin CProjectorFlashData::GetulStartAddress%.get preserve=no
  return m_ulStartAddress;
  //## end CProjectorFlashData::GetulStartAddress%.get
}

inline const unsigned short CProjectorFlashData::GetusBlockSize () const
{
  //## begin CProjectorFlashData::GetusBlockSize%.get preserve=no
  return m_usBlockSize;
  //## end CProjectorFlashData::GetusBlockSize%.get
}





// Class CProjectorRamData 


//## Other Operations (inline)
inline CProjectorRamData* CProjectorRamData::CreateInBuffer (char* pBuffer)
{
  //## begin CProjectorRamData::CreateInBuffer%937560464.body preserve=yes
  ASSERT(pBuffer);

  CProjectorRamData *pItem = (CProjectorRamData *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CProjectorRamData::CreateInBuffer%937560464.body
}

inline const unsigned char* CProjectorRamData::GetDataPtr () const
{
  //## begin CProjectorRamData::GetDataPtr%937572552.body preserve=yes
  return (unsigned char *) CRecordBase::GetDataPtr();
  //## end CProjectorRamData::GetDataPtr%937572552.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned long CProjectorRamData::GetulStartAddress () const
{
  //## begin CProjectorRamData::GetulStartAddress%.get preserve=no
  return m_ulStartAddress;
  //## end CProjectorRamData::GetulStartAddress%.get
}

inline const unsigned short CProjectorRamData::GetusBlockSize () const
{
  //## begin CProjectorRamData::GetusBlockSize%.get preserve=no
  return m_usBlockSize;
  //## end CProjectorRamData::GetusBlockSize%.get
}





// Class CProjectorSaveParameters 


//## Other Operations (inline)
inline CProjectorSaveParameters* CProjectorSaveParameters::CreateInBuffer (char* pBuffer)
{
  //## begin CProjectorSaveParameters::CreateInBuffer%937572553.body preserve=yes
  ASSERT(pBuffer);

  CProjectorSaveParameters *pItem = (CProjectorSaveParameters *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CProjectorSaveParameters::CreateInBuffer%937572553.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned char CProjectorSaveParameters::GetucDelaySeconds () const
{
  //## begin CProjectorSaveParameters::GetucDelaySeconds%.get preserve=no
  return m_ucDelaySeconds;
  //## end CProjectorSaveParameters::GetucDelaySeconds%.get
}





// Class CProjectorRestoreDefaults 


//## Other Operations (inline)
inline CProjectorRestoreDefaults* CProjectorRestoreDefaults::CreateInBuffer (char* pBuffer)
{
  //## begin CProjectorRestoreDefaults::CreateInBuffer%939392273.body preserve=yes
  ASSERT(pBuffer);

  CProjectorRestoreDefaults *pItem = (CProjectorRestoreDefaults *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CProjectorRestoreDefaults::CreateInBuffer%939392273.body
}



inline CProjectorMessageLevel* CProjectorMessageLevel::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CProjectorMessageLevel *pItem = (CProjectorMessageLevel *) pBuffer;
  pItem->Create();

  return pItem;
}


inline unsigned char CProjectorMessageLevel::GetucMinMessageLevel() const
{
  return m_ucMinMessageLevel;
}

#if defined(MEGAWALL2)
#pragma pack(pop)
#elif defined(CVPROJ) && GCM_VERSION==4
#pragma pack()
#else
#pragma pack(pop, CVprotocolHandshake)
#endif

#endif

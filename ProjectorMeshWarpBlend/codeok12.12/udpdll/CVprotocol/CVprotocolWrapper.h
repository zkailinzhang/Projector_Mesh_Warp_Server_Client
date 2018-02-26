//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: CVprotocolWrapper; Package specification
//## Subsystem: cvsetup
//	c:\src\graphics\cvsetup
//## Source file: c:\src\graphics\cvsetup\CVprotocolWrapper.h

#ifndef CVprotocolWrapper_h
#define CVprotocolWrapper_h 1

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
#pragma pack(push, CVprotocolWrapper)
#pragma pack(1)
#endif


struct SWrapperTail
{
  CConvLE<unsigned short> usCRC;
};

//## end module.additionalDeclarations


//## Class: CWrapperBase
//	Base class for wrapper records
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CWrapperBase : public CRecordBase  //## Inherits: <unnamed>; friend
{
  //## begin CWrapperBase.initialDeclarations preserve=yes
  //## end CWrapperBase.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: RemoveRecords%939291899
      //	Remove contained records (reset wrapper to empty).
      //
      //	Returns true if successful
      bool RemoveRecords ();

      //## Operation: GetNextPos%936176398
      //	Get position of next record to add
      char * GetNextPos ();

      //## Operation: AddRecord%936176399
      //	Add new (created) record to wrapper
      void AddRecord ();

      //## Operation: GetNextDataRecord%936276128
      //	Get next record in wrapper.
      //
      //	Input is pointer to previous record.  If input pointer
      //	is NULL, the first record will be returned (assuming the
      //	first record starts immediately after the end of the ID
      //	field)
      //
      //	Returns NULL if no more records are available.
      const CRecordBase * GetNextDataRecord (const CRecordBase *pPrev) const;

      //## Operation: GetReceivedCRC%939384588
      //	Get the received CRC
      unsigned short GetReceivedCRC () const;

      //## Operation: CalculateCRC%939384589
      //	Calculate CRC for message
      unsigned short CalculateCRC () const;

      //## Operation: CheckCRC%939384590
      //	Check CRC of message
      bool CheckCRC () const;

      //## Operation: AppendRecord%939636217
      //	Append a record to open wrapper
      void AppendRecord (const CRecordBase *pItem);

      //## Operation: AppendEmptyRecord%939636218
      //	Append a record with empty data, given the input id
      //	fields.
      void AppendEmptyRecord (const CRecordBase *pUnknownRequest);

    // Additional Public Declarations
      //## begin CWrapperBase.public preserve=yes
      //## end CWrapperBase.public

  protected:

    //## Other Operations (specified)
      //## Operation: AddTail%936176396;  C++
      //	Add tail:  CRC
      void AddTail ();

      //## Operation: RemoveTail%939031318
      //	Remove tail and check CRC.  Returns TRUE if ok.
      bool RemoveTail ();

    // Additional Protected Declarations
      //## begin CWrapperBase.protected preserve=yes
      //## end CWrapperBase.protected

  private:
    // Additional Private Declarations
      //## begin CWrapperBase.private preserve=yes
      //## end CWrapperBase.private

  private:  //## implementation
    // Additional Implementation Declarations
      //## begin CWrapperBase.implementation preserve=yes
      //## end CWrapperBase.implementation

};


//## begin CWrapperBase.postscript preserve=yes
//## end CWrapperBase.postscript



//## Class: CUDPWrapper
//	UDP wrapper class
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CUDPWrapper : public CWrapperBase  //## Inherits: <unnamed>
{
  //## begin CUDPWrapper.initialDeclarations preserve=yes
  //## end CUDPWrapper.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: Create%936176390;  C++
      //	Initialize data record.
      void Create ();

      //## Operation: CreateInBuffer%936176352;  C++
      //	Create record in an existing buffer
      static CUDPWrapper* CreateInBuffer (char* pBuffer);

      //## Operation: PrepareToSend%936176354;  C++
      //	Prepares message for sending.
      //
      //	Generates a new sequence
      //	counter for transmittal if bIncSeq flag is set (default).
      //
      //	Returns size of record including header and tail (number
      //	of bytes to send)
      unsigned short PrepareToSend (unsigned short *pusLastSequenceCounter);

      //## Operation: SetProjectorAddress%936176355
      void SetProjectorAddress (const char *pszAddress);

      //## Operation: SetSourceIpAddress%939031319
      void SetSourceIpAddress (const unsigned char *pucAddress);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: ucSourceIpAddress
      const unsigned char* GetucSourceIpAddress () const;

      //## Attribute: ulSourcePID
      const unsigned long GetulSourcePID () const;

      //## Attribute: usSequenceCounter
      const unsigned short GetusSequenceCounter () const;

      //## Attribute: ProjectorAddress
      const CCVString& GetProjectorAddress () const;

    // Additional Public Declarations
      //## begin CUDPWrapper.public preserve=yes
      //## end CUDPWrapper.public

  protected:
    // Additional Protected Declarations
      //## begin CUDPWrapper.protected preserve=yes
      //## end CUDPWrapper.protected

  private:
    // Additional Private Declarations
      //## begin CUDPWrapper.private preserve=yes
      //## end CUDPWrapper.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CUDPWrapper::ucSourceIpAddress.attr preserve=no  public: unsigned char[4] {U} 
      unsigned char m_ucSourceIpAddress[4];
      //## end CUDPWrapper::ucSourceIpAddress.attr

      //## begin CUDPWrapper::ulSourcePID.attr preserve=no  public: unsigned long {U} 
      CConvLE<unsigned long> m_ulSourcePID;
      //## end CUDPWrapper::ulSourcePID.attr

      //## begin CUDPWrapper::usSequenceCounter.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usSequenceCounter;
      //## end CUDPWrapper::usSequenceCounter.attr

      //## begin CUDPWrapper::ProjectorAddress.attr preserve=no  public: CCVString {U} 
      CCVString m_ProjectorAddress;
      //## end CUDPWrapper::ProjectorAddress.attr

#if !defined(CVPROJ) && !defined(CVPCI)
      //## Attribute: usLastSequenceCounter
      //## begin CUDPWrapper::usLastSequenceCounter.attr preserve=no  private: static unsigned short {U} 0
      static unsigned short m_usLastSequenceCounter;
      //## end CUDPWrapper::usLastSequenceCounter.attr
#endif

    // Additional Implementation Declarations
      //## begin CUDPWrapper.implementation preserve=yes
      //## end CUDPWrapper.implementation

};

//## begin CUDPWrapper.postscript preserve=yes
//## end CUDPWrapper.postscript


//## Class: CSerialOutboundWrapper
//	Serial comm wrapper class for outbound direction (to
//	projectors)
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSerialOutboundWrapper : public CWrapperBase  //## Inherits: <unnamed>
{
  //## begin CSerialOutboundWrapper.initialDeclarations preserve=yes
  //## end CSerialOutboundWrapper.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: Create%936176333;  C++
      //	Initialize data record.
      void Create ();

      //## Operation: CreateInBuffer%936176400;  C++
      //	Create record in an existing buffer
      static CSerialOutboundWrapper* CreateInBuffer (char* pBuffer);

      //## Operation: SetChainAddress%936176392
      void SetChainAddress (unsigned char ucFirstChainAddress, unsigned char ucLastChainAddress);

      //## Operation: GetChainAddress%939031320
      void GetChainAddress (unsigned char& ucFirstChainAddress, unsigned char& ucLastChainAddress) const;

      //## Operation: PrepareToSend%936176402;  C++
      //	Prepares message for sending.
      //
      //	Generates a new sequence
      //	counter for transmittal if bIncSeq flag is set (default).
      //
      //	Returns size of record including header and tail (number
      //	of bytes to send)
      unsigned short PrepareToSend (unsigned char *pucLastSequenceCounter);

      //## Operation: PrepareToReceive%939031321
      bool PrepareToReceive ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: ucSequenceCounter
      const unsigned char GetucSequenceCounter () const;

    // Additional Public Declarations
      //## begin CSerialOutboundWrapper.public preserve=yes
      //## end CSerialOutboundWrapper.public

  protected:
    // Additional Protected Declarations
      //## begin CSerialOutboundWrapper.protected preserve=yes
      //## end CSerialOutboundWrapper.protected

  private:
    // Additional Private Declarations
      //## begin CSerialOutboundWrapper.private preserve=yes
      //## end CSerialOutboundWrapper.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## Attribute: ucFirstChainAddress
      //	First projector in chain (1..N) to receive message
      //## begin CSerialOutboundWrapper::ucFirstChainAddress.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucFirstChainAddress;
      //## end CSerialOutboundWrapper::ucFirstChainAddress.attr

      //## Attribute: ucLastChainAddress
      //	Last projector in chain (1..N) to receive message
      //## begin CSerialOutboundWrapper::ucLastChainAddress.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucLastChainAddress;
      //## end CSerialOutboundWrapper::ucLastChainAddress.attr

      //## begin CSerialOutboundWrapper::ucSequenceCounter.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucSequenceCounter;
      //## end CSerialOutboundWrapper::ucSequenceCounter.attr

#if !defined(CVPROJ) && !defined(CVPCI)
      //## Attribute: ucLastSequenceCounter
      //## begin CSerialOutboundWrapper::ucLastSequenceCounter.attr preserve=no  private: static unsigned char {U} 0
      static unsigned char m_ucLastSequenceCounter;
      //## end CSerialOutboundWrapper::ucLastSequenceCounter.attr
#endif

    // Additional Implementation Declarations
      //## begin CSerialOutboundWrapper.implementation preserve=yes
      //## end CSerialOutboundWrapper.implementation

};

//## begin CSerialOutboundWrapper.postscript preserve=yes
//## end CSerialOutboundWrapper.postscript



//## Class: CSerialInboundWrapper
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSerialInboundWrapper : public CWrapperBase  //## Inherits: <unnamed>
{
  //## begin CSerialInboundWrapper.initialDeclarations preserve=yes
  //## end CSerialInboundWrapper.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: Create%936176395;  C++
      //	Initialize data record.
      void Create ();

      //## Operation: CreateInBuffer%936176401;  C++
      //	Create record in an existing buffer
      static CSerialInboundWrapper* CreateInBuffer (char* pBuffer);

      //## Operation: SetChainAddress%936176397
      void SetChainAddress (unsigned char ucChainAddress);

      //## Operation: GetChainAddress%939031322
      void GetChainAddress (unsigned char &ucChainAddress) const;

      //## Operation: PrepareToSend%936176403;  C++
      //	Prepares message for sending.
      //
      //	Generates a new sequence
      //	counter for transmittal if bIncSeq flag is set (default).
      //
      //	Returns size of record including header and tail (number
      //	of bytes to send)
      unsigned short PrepareToSend (unsigned char *pucLastSequenceCounter);

      //## Operation: PrepareToReceive%939031323
      bool PrepareToReceive ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: ucSequenceCounter
      const unsigned char GetucSequenceCounter () const;

    // Additional Public Declarations
      //## begin CSerialInboundWrapper.public preserve=yes
      //## end CSerialInboundWrapper.public

  protected:
    // Additional Protected Declarations
      //## begin CSerialInboundWrapper.protected preserve=yes
      //## end CSerialInboundWrapper.protected

  private:
    // Additional Private Declarations
      //## begin CSerialInboundWrapper.private preserve=yes
      //## end CSerialInboundWrapper.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## Attribute: ucChainAddress
      //	First projector in chain (1..N) to receive message
      //## begin CSerialInboundWrapper::ucChainAddress.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucChainAddress;
      //## end CSerialInboundWrapper::ucChainAddress.attr

      //## begin CSerialInboundWrapper::ucSequenceCounter.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucSequenceCounter;
      //## end CSerialInboundWrapper::ucSequenceCounter.attr

#if !defined(CVPROJ) && !defined(CVPCI)
      //## Attribute: ucLastSequenceCounter
      //## begin CSerialInboundWrapper::ucLastSequenceCounter.attr preserve=no  private: static unsigned char {U} 0
      static unsigned char m_ucLastSequenceCounter;
      //## end CSerialInboundWrapper::ucLastSequenceCounter.attr
#endif

    // Additional Implementation Declarations
      //## begin CSerialInboundWrapper.implementation preserve=yes
      //## end CSerialInboundWrapper.implementation

};

//## begin CSerialInboundWrapper.postscript preserve=yes
//## end CSerialInboundWrapper.postscript



//## Class: CUDPAckRecord
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CUDPAckRecord : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CUDPAckRecord.initialDeclarations preserve=yes
  //## end CUDPAckRecord.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: Set%936276129
      //	Set fields in ACK record based on incoming message
      void Set (const class CUDPWrapper *pWrapper);

      //## Operation: Create%936276135
      //	Initialize data record
      void Create ();

      //## Operation: CreateInBuffer%936276136
      //	Create record in an existing buffer
      static class CUDPAckRecord * CreateInBuffer (char *pBuffer);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: ucSourceIpAddress
      const unsigned char* GetucSourceIpAddress () const;

      //## Attribute: ulSourcePID
      const unsigned long GetulSourcePID () const;

      //## Attribute: usSequenceCounter
      const unsigned short GetusSequenceCounter () const;

      //## Attribute: ProjectorAddress
      const CCVString GetProjectorAddress () const;

    // Additional Public Declarations
      //## begin CUDPAckRecord.public preserve=yes
      //## end CUDPAckRecord.public

  protected:
    // Additional Protected Declarations
      //## begin CUDPAckRecord.protected preserve=yes
      //## end CUDPAckRecord.protected

  private:
    // Additional Private Declarations
      //## begin CUDPAckRecord.private preserve=yes
      //## end CUDPAckRecord.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CUDPAckRecord::ucSourceIpAddress.attr preserve=no  public: unsigned char[4] {U} 
      unsigned char m_ucSourceIpAddress[4];
      //## end CUDPAckRecord::ucSourceIpAddress.attr

      //## begin CUDPAckRecord::ulSourcePID.attr preserve=no  public: unsigned long {U} 
      CConvLE<unsigned long> m_ulSourcePID;
      //## end CUDPAckRecord::ulSourcePID.attr

      //## begin CUDPAckRecord::usSequenceCounter.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usSequenceCounter;
      //## end CUDPAckRecord::usSequenceCounter.attr

      //## begin CUDPAckRecord::ProjectorAddress.attr preserve=no  public: CCVString {U} 
      CCVString m_ProjectorAddress;
      //## end CUDPAckRecord::ProjectorAddress.attr

    // Additional Implementation Declarations
      //## begin CUDPAckRecord.implementation preserve=yes
      //## end CUDPAckRecord.implementation

};

//## begin CUDPAckRecord.postscript preserve=yes
//## end CUDPAckRecord.postscript



//## Class: CSerialAckRecord
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSerialAckRecord : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CSerialAckRecord.initialDeclarations preserve=yes
  //## end CSerialAckRecord.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: Set%936276137
      //	Set fields in ACK record based on incoming message
      void Set (const class CSerialInboundWrapper *pWrapper);

      //## Operation: Set%936276138
      //	Set fields in ACK record based on incoming message
      void Set (const class CSerialOutboundWrapper *pWrapper);

      //## Operation: Create%936276139
      //	Initialize data record
      void Create ();

      //## Operation: CreateInBuffer%936276140
      //	Create record in an existing buffer
      static CSerialAckRecord * CreateInBuffer (char *pBuffer);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: ucChainAddress
      //	Projector in chain (1..N) sending acknowledge message
      const unsigned char GetucChainAddress () const;

      //## Attribute: ucSequenceCounter
      const unsigned char GetucSequenceCounter () const;

      //## Attribute: usCRC16
      const unsigned short GetusCRC16 () const;

    // Additional Public Declarations
      //## begin CSerialAckRecord.public preserve=yes
      //## end CSerialAckRecord.public

  protected:
    // Additional Protected Declarations
      //## begin CSerialAckRecord.protected preserve=yes
      //## end CSerialAckRecord.protected

  private:
    // Additional Private Declarations
      //## begin CSerialAckRecord.private preserve=yes
      //## end CSerialAckRecord.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CSerialAckRecord::ucChainAddress.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucChainAddress;
      //## end CSerialAckRecord::ucChainAddress.attr

      //## begin CSerialAckRecord::ucSequenceCounter.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucSequenceCounter;
      //## end CSerialAckRecord::ucSequenceCounter.attr

      //## begin CSerialAckRecord::usCRC16.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usCRC16;
      //## end CSerialAckRecord::usCRC16.attr

    // Additional Implementation Declarations
      //## begin CSerialAckRecord.implementation preserve=yes
      //## end CSerialAckRecord.implementation

};

//## begin CSerialAckRecord.postscript preserve=yes
//## end CSerialAckRecord.postscript



//## Class: CSerialPreamble
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CSerialPreamble 
{
  //## begin CSerialPreamble.initialDeclarations preserve=yes
  //## end CSerialPreamble.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%939038778;  C++
      //	Create record in an existing buffer
      static CSerialPreamble* CreateInBuffer (char* pBuffer);

      static CSerialPreamble* CreateInBuffer (char* pBuffer, unsigned long ulPreambleId);

      //## Operation: GetSize%939038779; C++
      //	Get size of record excluding preamble
      unsigned short GetSize () const;

      //## Operation: GetNextPos%939038780
      //	Get position of next record to add
      char * GetNextPos () const;

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: ulPreamble
      const unsigned long GetulPreamble () const;

    // Additional Public Declarations
      //## begin CSerialPreamble.public preserve=yes
      //## end CSerialPreamble.public

  protected:
    // Additional Protected Declarations
      //## begin CSerialPreamble.protected preserve=yes
      //## end CSerialPreamble.protected

  private:
    // Additional Private Declarations
      //## begin CSerialPreamble.private preserve=yes
      //## end CSerialPreamble.private

  protected:  //## implementation
    // Data Members for Class Attributes

      //## begin CSerialPreamble::ulPreamble.attr preserve=no  public: unsigned long {U} 
      CConvLE<unsigned long> m_ulPreamble;
      //## end CSerialPreamble::ulPreamble.attr

    // Additional Implementation Declarations
      //## begin CSerialPreamble.implementation preserve=yes
      //## end CSerialPreamble.implementation

};

//## begin CSerialPreamble.postscript preserve=yes
//## end CSerialPreamble.postscript

class CTcpPreamble : public CSerialPreamble
{
public:

  static CTcpPreamble* CreateInBuffer (char* pBuffer);

  unsigned short GetSize () const;

  char * GetNextPos () const;

  void SetusSequence(unsigned short* pusSequence); 

  const unsigned short GetusSequence() const;

protected:
    
  CConvLE<unsigned short> m_usSequence;


};

// Class CWrapperBase 


//## Other Operations (inline)
inline const CRecordBase * CWrapperBase::GetNextDataRecord (const CRecordBase *pPrev) const
{
  //## begin CWrapperBase::GetNextDataRecord%936276128.body preserve=yes
  AssertValid();
  const char *pcItem;
  
  if (!pPrev)
    pcItem = (char *) this + (unsigned) GetIdSizeFromStart();
  else
  {
    if (pPrev->GetSize() < sizeof(CRecordBase))
      return NULL;   // Invalid prev record
    pcItem = (char *) pPrev + pPrev->GetSize();
  }

  if (pcItem + sizeof(CRecordBase) > (char *) this + GetSize())
    return NULL;
  else
    return (CRecordBase *) pcItem;
  //## end CWrapperBase::GetNextDataRecord%936276128.body
}

inline unsigned short CWrapperBase::GetReceivedCRC () const
{
  //## begin CWrapperBase::GetReceivedCRC%939384588.body preserve=yes
  unsigned short usOriginalSize = GetSize() - sizeof(SWrapperTail);
  SWrapperTail *pTail = (SWrapperTail *) ((char*)this + usOriginalSize);

  return pTail->usCRC;
  //## end CWrapperBase::GetReceivedCRC%939384588.body
}

inline unsigned short CWrapperBase::CalculateCRC () const
{
  //## begin CWrapperBase::CalculateCRC%939384589.body preserve=yes
  return CalculateCRC16(GetSize() - sizeof(SWrapperTail));
  //## end CWrapperBase::CalculateCRC%939384589.body
}

inline bool CWrapperBase::CheckCRC () const
{
  //## begin CWrapperBase::CheckCRC%939384590.body preserve=yes
  return CalculateCRC() == GetReceivedCRC();
  //## end CWrapperBase::CheckCRC%939384590.body
}





// Class CUDPWrapper 


//## Other Operations (inline)
inline CUDPWrapper* CUDPWrapper::CreateInBuffer (char* pBuffer)
{
  //## begin CUDPWrapper::CreateInBuffer%936176352.body preserve=yes
  ASSERT(pBuffer);

  CUDPWrapper *pItem = (CUDPWrapper *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CUDPWrapper::CreateInBuffer%936176352.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned char* CUDPWrapper::GetucSourceIpAddress () const
{
  //## begin CUDPWrapper::GetucSourceIpAddress%.get preserve=no
  return m_ucSourceIpAddress;
  //## end CUDPWrapper::GetucSourceIpAddress%.get
}

inline const unsigned long CUDPWrapper::GetulSourcePID () const
{
  //## begin CUDPWrapper::GetulSourcePID%.get preserve=no
  return m_ulSourcePID;
  //## end CUDPWrapper::GetulSourcePID%.get
}

inline const unsigned short CUDPWrapper::GetusSequenceCounter () const
{
  //## begin CUDPWrapper::GetusSequenceCounter%.get preserve=no
  return m_usSequenceCounter;
  //## end CUDPWrapper::GetusSequenceCounter%.get
}

inline const CCVString& CUDPWrapper::GetProjectorAddress () const
{
  //## begin CUDPWrapper::GetProjectorAddress%.get preserve=no
  return m_ProjectorAddress;
  //## end CUDPWrapper::GetProjectorAddress%.get
}





// Class CSerialOutboundWrapper 


//## Other Operations (inline)
inline CSerialOutboundWrapper* CSerialOutboundWrapper::CreateInBuffer (char* pBuffer)
{
  //## begin CSerialOutboundWrapper::CreateInBuffer%936176400.body preserve=yes
  ASSERT(pBuffer);

  CSerialOutboundWrapper *pItem = (CSerialOutboundWrapper *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CSerialOutboundWrapper::CreateInBuffer%936176400.body
}

inline void CSerialOutboundWrapper::GetChainAddress (unsigned char& ucFirstChainAddress, unsigned char& ucLastChainAddress) const
{
  //## begin CSerialOutboundWrapper::GetChainAddress%939031320.body preserve=yes
  ucFirstChainAddress = m_ucFirstChainAddress;
  ucLastChainAddress = m_ucLastChainAddress;
  //## end CSerialOutboundWrapper::GetChainAddress%939031320.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned char CSerialOutboundWrapper::GetucSequenceCounter () const
{
  //## begin CSerialOutboundWrapper::GetucSequenceCounter%.get preserve=no
  return m_ucSequenceCounter;
  //## end CSerialOutboundWrapper::GetucSequenceCounter%.get
}





// Class CSerialInboundWrapper 


//## Other Operations (inline)
inline CSerialInboundWrapper* CSerialInboundWrapper::CreateInBuffer (char* pBuffer)
{
  //## begin CSerialInboundWrapper::CreateInBuffer%936176401.body preserve=yes
  ASSERT(pBuffer);

  CSerialInboundWrapper *pItem = (CSerialInboundWrapper *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CSerialInboundWrapper::CreateInBuffer%936176401.body
}

inline void CSerialInboundWrapper::GetChainAddress (unsigned char &ucChainAddress) const
{
  //## begin CSerialInboundWrapper::GetChainAddress%939031322.body preserve=yes
  ucChainAddress = m_ucChainAddress;
  //## end CSerialInboundWrapper::GetChainAddress%939031322.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned char CSerialInboundWrapper::GetucSequenceCounter () const
{
  //## begin CSerialInboundWrapper::GetucSequenceCounter%.get preserve=no
  return m_ucSequenceCounter;
  //## end CSerialInboundWrapper::GetucSequenceCounter%.get
}





// Class CUDPAckRecord 


//## Other Operations (inline)
inline class CUDPAckRecord * CUDPAckRecord::CreateInBuffer (char *pBuffer)
{
  //## begin CUDPAckRecord::CreateInBuffer%936276136.body preserve=yes
  ASSERT(pBuffer);

  CUDPAckRecord *pItem = (CUDPAckRecord *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CUDPAckRecord::CreateInBuffer%936276136.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned char* CUDPAckRecord::GetucSourceIpAddress () const
{
  //## begin CUDPAckRecord::GetucSourceIpAddress%.get preserve=no
  return m_ucSourceIpAddress;
  //## end CUDPAckRecord::GetucSourceIpAddress%.get
}

inline const unsigned long CUDPAckRecord::GetulSourcePID () const
{
  //## begin CUDPAckRecord::GetulSourcePID%.get preserve=no
  return m_ulSourcePID;
  //## end CUDPAckRecord::GetulSourcePID%.get
}

inline const unsigned short CUDPAckRecord::GetusSequenceCounter () const
{
  //## begin CUDPAckRecord::GetusSequenceCounter%.get preserve=no
  return m_usSequenceCounter;
  //## end CUDPAckRecord::GetusSequenceCounter%.get
}

inline const CCVString CUDPAckRecord::GetProjectorAddress () const
{
  //## begin CUDPAckRecord::GetProjectorAddress%.get preserve=no
  return m_ProjectorAddress;
  //## end CUDPAckRecord::GetProjectorAddress%.get
}





// Class CSerialAckRecord 


//## Other Operations (inline)
inline CSerialAckRecord * CSerialAckRecord::CreateInBuffer (char *pBuffer)
{
  //## begin CSerialAckRecord::CreateInBuffer%936276140.body preserve=yes
  ASSERT(pBuffer);

  CSerialAckRecord *pItem = (CSerialAckRecord *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CSerialAckRecord::CreateInBuffer%936276140.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned char CSerialAckRecord::GetucChainAddress () const
{
  //## begin CSerialAckRecord::GetucChainAddress%.get preserve=no
  return m_ucChainAddress;
  //## end CSerialAckRecord::GetucChainAddress%.get
}

inline const unsigned char CSerialAckRecord::GetucSequenceCounter () const
{
  //## begin CSerialAckRecord::GetucSequenceCounter%.get preserve=no
  return m_ucSequenceCounter;
  //## end CSerialAckRecord::GetucSequenceCounter%.get
}

inline const unsigned short CSerialAckRecord::GetusCRC16 () const
{
  //## begin CSerialAckRecord::GetusCRC16%.get preserve=no
  return m_usCRC16;
  //## end CSerialAckRecord::GetusCRC16%.get
}





// Class CSerialPreamble 


//## Other Operations (inline)
inline CSerialPreamble* CSerialPreamble::CreateInBuffer (char* pBuffer)
{
  //## begin CSerialPreamble::CreateInBuffer%939038778.body preserve=yes
  ((CSerialPreamble *) pBuffer)->m_ulPreamble = 0xaaaa5555;
  return (CSerialPreamble *) pBuffer;
  //## end CSerialPreamble::CreateInBuffer%939038778.body
}

inline CSerialPreamble* CSerialPreamble::CreateInBuffer (char* pBuffer, unsigned long ulPreambleId)
{
  //## begin CSerialPreamble::CreateInBuffer%939038778.body preserve=yes
  ((CSerialPreamble *) pBuffer)->m_ulPreamble = ulPreambleId;
  return (CSerialPreamble *) pBuffer;
  //## end CSerialPreamble::CreateInBuffer%939038778.body
}

inline unsigned short CSerialPreamble::GetSize () const
{
  //## begin CSerialPreamble::GetSize%939038779.body preserve=yes
  return sizeof(*this);
  //## end CSerialPreamble::GetSize%939038779.body
}

inline char * CSerialPreamble::GetNextPos () const
{
  //## begin CSerialPreamble::GetNextPos%939038780.body preserve=yes
  return (char *) this + sizeof(*this);
  //## end CSerialPreamble::GetNextPos%939038780.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned long CSerialPreamble::GetulPreamble () const
{
  //## begin CSerialPreamble::GetulPreamble%.get preserve=no
  return m_ulPreamble;
  //## end CSerialPreamble::GetulPreamble%.get
}





inline CTcpPreamble* CTcpPreamble::CreateInBuffer (char* pBuffer)
{
  //## begin CSerialPreamble::CreateInBuffer%939038778.body preserve=yes
  ((CTcpPreamble *) pBuffer)->m_ulPreamble = 0xaaaa5555;
  ((CTcpPreamble *) pBuffer)->m_usSequence = 0;
  return (CTcpPreamble *) pBuffer;
  //## end CSerialPreamble::CreateInBuffer%939038778.body
}


inline unsigned short CTcpPreamble::GetSize () const
{
  //## begin CSerialPreamble::GetSize%939038779.body preserve=yes
  return sizeof(*this);
  //## end CSerialPreamble::GetSize%939038779.body
}


inline char * CTcpPreamble::GetNextPos () const
{
  //## begin CSerialPreamble::GetNextPos%939038780.body preserve=yes
  return (char *) this + sizeof(*this);
  //## end CSerialPreamble::GetNextPos%939038780.body
}


inline void CTcpPreamble::SetusSequence(unsigned short* pusSequence)
{
  if (pusSequence)
    m_usSequence = ++ *pusSequence;
} 


inline const unsigned short CTcpPreamble::GetusSequence() const
{
  return m_usSequence;
}

#if defined(MEGAWALL2)
#pragma pack(pop)
#elif defined(CVPROJ) && GCM_VERSION==4
#pragma pack()
#else
#pragma pack(pop, CVprotocolWrapper)
#endif

#endif

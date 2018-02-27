//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: CVprotocol; Package specification
//	CV protocol classes
//## Subsystem: cvsetup
//	c:\src\graphics\cvsetup
//## Source file: c:\src\graphics\cvsetup\CVprotocol.h

#ifndef CVprotocol_h
#define CVprotocol_h

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include "stdafx.h"   // Common to all modules
#include "CommandTypes.h"

#if !defined(MEGAWALL2) && !defined(CVPROJ) && !defined(CVPCI)
#include "CVUtil.h"
#endif

#include "ConvLE.h"

#if defined(CVPCI) && 00
#define PASSERT(x)
#else
#define PASSERT(x) ASSERT(x)
#endif

//## end module.includes

//## begin module.declarations preserve=no
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes

#if defined(MEGAWALL2)
#include <stddef.h> //for offsetof redefinition
#pragma pack(push, 1)
#elif defined(CVPROJ) && GCM_VERSION==4
#pragma pack(1)
#else
#pragma pack(push, CVprotocol)
#pragma pack(1)
#endif

//## end module.additionalDeclarations


//## Class: CRecordBase
//	Base class for Record based communication
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CRecordBase 
{
  //## begin CRecordBase.initialDeclarations preserve=yes
  //## end CRecordBase.initialDeclarations

  public:

      CRecordBase(){}; //dummy for g++ compiler

      //## Other Operations (specified)
      //## Operation: AssertValid%936176334
      //	Validate header fields
      void AssertValid () const;

      //## Operation: GetIdSizeFromStart%936176350; C++
      //	Get size of ID data (type + key), as offset from start
      //	of record (ie. usIdSize + 4)
      unsigned short GetIdSizeFromStart () const;

      //## Operation: IsCommand%936176327; C++
      //	Returns TRUE if the record is a command record
      bool IsCommand () const;

      //## Operation: IsEmpty%939638205
      //	Returns true if the record has an empty data field
      bool IsEmpty () const;

      //## Operation: GetSize%936176328; C++
      //	Get size of record excluding preamble
      unsigned short GetSize () const;

      //## Operation: GetIdSize%936176329; C++
      //	Get size of ID data (type + key)
      unsigned short GetIdSize () const;

      //## Operation: GetRecordType%936176330; C++
      //	Get Record type
      unsigned short GetRecordType () const;

      //## Operation: SetSize%936176349
      //	Set size field.
      //
      //	usRecordSize is record size excluding preamble
      void SetSize (unsigned short usRecordSize);

      //## Operation: IsEqualId%936176325; C++
      //	Returns TRUE if Id (type + key) of records are identical.
      //
      //	Note:  Commands are considered unequal to everything
      //	else.  If one or both the records are command/action
      //	records, IsEqualId() will return FALSE
      friend bool IsEqualId (const class CRecordBase &R1, const class CRecordBase &R2);

      //## Operation: IsEqualData%936176326; C++
      //	Returns TRUE if value part of record is identical.
      //	Assumes that id (key/value) is identical.
      friend bool IsEqualData (const class CRecordBase &R1, const class CRecordBase &R2);

      //## begin CRecordBase.public preserve=yes
      friend bool IsEqualCommand (const class CRecordBase &R1, const class CRecordBase &R2);

  protected:
      //## begin CRecordBase.public preserve=yes
      CRecordBase (unsigned short usRecordSize, unsigned short usIdSize, unsigned short usRecordType);
      //## end CRecordBase.public


    //## Constructors (specified)
      //## Operation: CRecordBase%936176331; C++
      //	Constructs fixed-size record


    //## Other Operations (specified)
      //## Operation: CreateRecordBase%936176336; C++
      //	Constructor, initializes record type, with unknown size
      //	info
      void CreateRecordBase (unsigned short usRecordSize, unsigned short usIdSize, unsigned short usRecordType);

      //## Operation: GetDataPtr%936176341
      //	Returns pointer to value field
      const char * GetDataPtr () const;

      //## Operation: GetIdPtr%936176342
      //	Get pointer to Id field (starting with usRecordType)
      const char * GetIdPtr () const;

      //## Operation: GetDataSize%936176343
      //	Returns the size of the data part of the record
      unsigned short GetDataSize () const;

      //## Operation: SetIdSizeFromStart%936176359
      //	Set ID size field.
      //
      //	nIdSizeFromStart is offset from start to end of ID field
      //	(ie. usIdSize+4)
      void SetIdSizeFromStart (unsigned short usIdSizeFromStart);

      //## Operation: CalculateCRC16%936276133
      //	Calculate 16-bit CRC of message
  public: //TEST
      unsigned short CalculateCRC16 (unsigned short usBytes) const;

    // Additional Protected Declarations
      //## begin CRecordBase.protected preserve=yes
      //## end CRecordBase.protected

  private:
    // Additional Private Declarations
      //## begin CRecordBase.private preserve=yes
      //## end CRecordBase.private

  private:  //## implementation

    //## Other Operations (specified)
      //## Operation: _AssertValid%936176335
      //	Implementation of AssertValid() operation.  Called only
      //	in DEBUG compile.
      void _AssertValid () const;

    // Data Members for Class Attributes

      //## Attribute: usRecordSize
      //## begin CRecordBase::usRecordSize.attr preserve=no  private: unsigned short {U} 
      CConvLE<unsigned short> m_usRecordSize;
      //## end CRecordBase::usRecordSize.attr

      //## Attribute: usIdSize
      //## begin CRecordBase::usIdSize.attr preserve=no  private: unsigned short {U} 
      CConvLE<unsigned short> m_usIdSize;
      //## end CRecordBase::usIdSize.attr

      //## Attribute: usRecordType
      //## begin CRecordBase::usRecordType.attr preserve=no  private: unsigned short {U} 
      CConvLE<unsigned short> m_usRecordType;
      //## end CRecordBase::usRecordType.attr

    // Additional Implementation Declarations
      //## begin CRecordBase.implementation preserve=yes
      //## end CRecordBase.implementation

  //## begin CRecordBase.friends preserve=no
    friend class CWrapperBase;
  //## end CRecordBase.friends
};

//## begin CRecordBase.postscript preserve=yes
//## end CRecordBase.postscript



//## Class: CCVString
//	String with length.  Note that this cannot be
//	constructed in a normal manner, but must be allocated
//	and then created
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCVString 
{
  //## begin CCVString.initialDeclarations preserve=yes
  //## end CCVString.initialDeclarations

  public:
    //## Constructors (generated)
      CCVString();


    //## Other Operations (specified)
      //## Operation: GetLength%936176339
      //	Returns length of string
      unsigned short GetLength () const;

      //## Operation: GetSize%936176340
      //	Get size of CCVString object (data size + length object)
      unsigned short GetSize () const;

      //## Operation: GetSZ%936176337
      //	Copy the string to a buffer and zero-terminate.  The
      //	buffer must have space for at least GetLength()+1
      //	characters.
      void GetSZ (char *pcBuffer) const;

      //## Operation: SetCVString%936176338
      //	Set buffer using CCVString format
      friend void SetCVString (void *pCVStringBuffer, const char *pszString);

      //## Operation: GetExtraSize%936176348
      //	Get extra size of CCVString object (size difference
      //	between allocated size and sizeof() size)   NOTE:  This may be a negative number
      short GetExtraSize () const;

      //## Operation: Reset%936176360
      //	Reset string to zero length
      void Reset ();

      //## Operation: CopyCVString%936276134
      //	Copy to buffer using CCVString format
      void CopyCVString (const class CCVString *pSourceCVString);

    // Additional Public Declarations
      //## begin CCVString.public preserve=yes
      //## end CCVString.public

  protected:
    // Additional Protected Declarations
      //## begin CCVString.protected preserve=yes
      //## end CCVString.protected

  private:
    // Additional Private Declarations
      //## begin CCVString.private preserve=yes
      //## end CCVString.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## Attribute: usLength
      //## begin CCVString::usLength.attr preserve=no  private: unsigned short {U} 
      CConvLE<unsigned short> m_usLength;
      //## end CCVString::usLength.attr

      //## Attribute: cText
      //## begin CCVString::cText.attr preserve=no  private: char[1] {U} 
      char m_cText[1];
      //## end CCVString::cText.attr

    // Additional Implementation Declarations
      //## begin CCVString.implementation preserve=yes
      //## end CCVString.implementation

};

//## begin CCVString.postscript preserve=yes
//## end CCVString.postscript



// Class CRecordBase 

//## Other Operations (inline)
inline void CRecordBase::CreateRecordBase (unsigned short usRecordSize, unsigned short usIdSize, unsigned short usRecordType)
{
  //## begin CRecordBase::CreateRecordBase%936176336.body preserve=yes
  ASSERT(this);
  PASSERT(usRecordSize >= sizeof(*this));
  PASSERT(usIdSize == 0 || usIdSize >= 2);
  PASSERT(usRecordSize >= usIdSize+4);

  m_usRecordSize = usRecordSize;
  m_usIdSize = usIdSize;
  m_usRecordType = usRecordType;
  //## end CRecordBase::CreateRecordBase%936176336.body
}

inline CRecordBase::CRecordBase (unsigned short usRecordSize, unsigned short usIdSize, unsigned short usRecordType)
  //## begin CRecordBase::CRecordBase%936176331.hasinit preserve=no
  //## end CRecordBase::CRecordBase%936176331.hasinit
  //## begin CRecordBase::CRecordBase%936176331.initialization preserve=yes
  //## end CRecordBase::CRecordBase%936176331.initialization
{
  //## begin CRecordBase::CRecordBase%936176331.body preserve=yes
  CreateRecordBase(usRecordSize, usIdSize, usRecordType);
  //## end CRecordBase::CRecordBase%936176331.body
}

inline void CRecordBase::AssertValid () const
{
  //## begin CRecordBase::AssertValid%936176334.body preserve=yes
#ifdef _DEBUG
  _AssertValid();
#endif
  //## end CRecordBase::AssertValid%936176334.body
}

inline const char * CRecordBase::GetDataPtr () const
{
  //## begin CRecordBase::GetDataPtr%936176341.body preserve=yes
  AssertValid();
  return (const char *) this + m_usIdSize + 4;
  //## end CRecordBase::GetDataPtr%936176341.body
}

inline const char * CRecordBase::GetIdPtr () const
{
  //## begin CRecordBase::GetIdPtr%936176342.body preserve=yes
  AssertValid();
  return (const char *) &m_usRecordType;
  //## end CRecordBase::GetIdPtr%936176342.body
}

inline unsigned short CRecordBase::GetDataSize () const
{
  //## begin CRecordBase::GetDataSize%936176343.body preserve=yes
  AssertValid();
  return m_usRecordSize - m_usIdSize - 4;
  //## end CRecordBase::GetDataSize%936176343.body
}

inline unsigned short CRecordBase::GetIdSizeFromStart () const
{
  //## begin CRecordBase::GetIdSizeFromStart%936176350.body preserve=yes
  AssertValid();
  return m_usIdSize + 4;
  //## end CRecordBase::GetIdSizeFromStart%936176350.body
}

inline bool CRecordBase::IsCommand () const
{
  //## begin CRecordBase::IsCommand%936176327.body preserve=yes
  AssertValid();
  return (m_usIdSize == 0);
  //## end CRecordBase::IsCommand%936176327.body
}

inline unsigned short CRecordBase::GetSize () const
{
  //## begin CRecordBase::GetSize%936176328.body preserve=yes
  AssertValid();
  return m_usRecordSize;
  //## end CRecordBase::GetSize%936176328.body
}

inline bool CRecordBase::IsEmpty () const
{
  //## begin CRecordBase::IsEmpty%939638205.body preserve=yes
  return (GetSize() == GetIdSizeFromStart());
  //## end CRecordBase::IsEmpty%939638205.body
}


inline unsigned short CRecordBase::GetIdSize () const
{
  //## begin CRecordBase::GetIdSize%936176329.body preserve=yes
  AssertValid();
  return m_usIdSize;
  //## end CRecordBase::GetIdSize%936176329.body
}

inline unsigned short CRecordBase::GetRecordType () const
{
  //## begin CRecordBase::GetRecordType%936176330.body preserve=yes
  AssertValid();
  return m_usRecordType;
  //## end CRecordBase::GetRecordType%936176330.body
}





// Class CCVString 

inline CCVString::CCVString()
  //## begin CCVString::CCVString%.hasinit preserve=no
  //## end CCVString::CCVString%.hasinit
  //## begin CCVString::CCVString%.initialization preserve=yes
  //## end CCVString::CCVString%.initialization
{
  //## begin CCVString::CCVString%.body preserve=yes
  m_usLength = 0;
  //## end CCVString::CCVString%.body
}



//## Other Operations (inline)
inline unsigned short CCVString::GetLength () const
{
  //## begin CCVString::GetLength%936176339.body preserve=yes
  return m_usLength;
  //## end CCVString::GetLength%936176339.body
}

inline unsigned short CCVString::GetSize () const
{
  //## begin CCVString::GetSize%936176340.body preserve=yes
  return GetLength() + (sizeof(*this)-1);
  //## end CCVString::GetSize%936176340.body
}

inline short CCVString::GetExtraSize () const
{
  //## begin CCVString::GetExtraSize%936176348.body preserve=yes
  return GetSize() - sizeof(*this);
  //## end CCVString::GetExtraSize%936176348.body
}

inline void CCVString::Reset ()
{
  //## begin CCVString::Reset%936176360.body preserve=yes
  m_usLength = 0;
  //## end CCVString::Reset%936176360.body
}





//## begin module.epilog preserve=yes
#if defined(MEGAWALL2)
#pragma pack(pop)
#elif defined(CVPROJ) && GCM_VERSION==4
#pragma pack()
#else
#pragma pack(pop, CVprotocol)
#endif
//## end module.epilog
#endif

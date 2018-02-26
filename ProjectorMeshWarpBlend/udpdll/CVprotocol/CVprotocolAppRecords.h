//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: CVprotocolAppRecords; Package specification
//## Subsystem: cvsetup
//	c:\src\graphics\cvsetup
//## Source file: c:\src\graphics\cvsetup\CVprotocolAppRecords.h

#ifndef CVprotocolAppRecords_h
#define CVprotocolAppRecords_h 1

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
//## end module.includes

// CVprotocol
#if defined(MEGAWALL2) || defined(CVPROJ) && GCM_VERSION==4
#include "stdafx.h"
#endif

#include "CVprotocol.h"
//## begin module.declarations preserve=no
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes
#if defined(MEGAWALL2)
#pragma pack(push,1)
#elif defined(CVPROJ) && GCM_VERSION==4
#pragma pack(1)
#else
#pragma pack(push, CVprotocolAppRecords)
#pragma pack(1)
#endif
//## end module.additionalDeclarations


//## Class: CCVTestPatternRecord
//	Test pattern record.  Activates the specified test
//	pattern
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCVTestPatternRecord : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CCVTestPatternRecord.initialDeclarations preserve=yes
  //## end CCVTestPatternRecord.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: Create%936176344
      //	Initialize data record
      void Create ();

      //## Operation: CreateInBuffer%936176353
      //	Create record in an existing buffer
      static CCVTestPatternRecord * CreateInBuffer (char *pBuffer);

      //## Operation: Set%936176388
      //	Set data fields of record
      void Set (const char *pszFileName);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: TestPatternFile
      const CCVString& GetTestPatternFile () const;

    // Additional Public Declarations
      //## begin CCVTestPatternRecord.public preserve=yes
      //## end CCVTestPatternRecord.public

  protected:
    // Additional Protected Declarations
      //## begin CCVTestPatternRecord.protected preserve=yes
      //## end CCVTestPatternRecord.protected

  private:
    // Additional Private Declarations
      //## begin CCVTestPatternRecord.private preserve=yes
      //## end CCVTestPatternRecord.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CCVTestPatternRecord::TestPatternFile.attr preserve=no  public: CCVString {U} 
      CCVString m_TestPatternFile;
      //## end CCVTestPatternRecord::TestPatternFile.attr

    // Additional Implementation Declarations
      //## begin CCVTestPatternRecord.implementation preserve=yes
      //## end CCVTestPatternRecord.implementation

};

//## begin CCVTestPatternRecord.postscript preserve=yes
//## end CCVTestPatternRecord.postscript

class CCVDrawFileRecord : public CRecordBase  
{
public:

  //	Initialize data record
  void Create ();
      
  //	Create record in an existing buffer
  static CCVDrawFileRecord * CreateInBuffer (char *pBuffer);

  //	Set data fields of record
  void Set (const char *pszFileName, long lStyle);

	inline long GetStyle() const {return m_lStyle;};

	inline const CCVString& GetFileName () const {return m_FileName;};

private:
  CConvLE<long> m_lStyle;
  CCVString m_FileName;
};

inline CCVDrawFileRecord * CCVDrawFileRecord::CreateInBuffer (char *pBuffer)
{
  ASSERT(pBuffer);

  CCVDrawFileRecord *pItem = (CCVDrawFileRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


class CCVDrawLineRecord : public CRecordBase  
{
  public:

      //	Initialize data record
  void Create ();

      
  //	Create record in an existing buffer
  static CCVDrawLineRecord * CreateInBuffer (char *pBuffer);

  //	Set data fields of record
  void Set (double dPosX, double dPosY, long lStyle);

	inline const double& GetPosX() const {return m_dPosX;} ;

	inline const double& GetPosY() const {return m_dPosY;} ;

	inline long GetStyle() const {return m_lStyle;} ;

  private:

	double m_dPosX;
	double m_dPosY;
	CConvLE<long> m_lStyle;
};

inline CCVDrawLineRecord * CCVDrawLineRecord::CreateInBuffer (char *pBuffer)
{
  ASSERT(pBuffer);

  CCVDrawLineRecord *pItem = (CCVDrawLineRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

class CCVDrawTextRecord : public CRecordBase  
{
public:

  //	Initialize data record
  void Create ();
      
  //	Create record in an existing buffer
  static CCVDrawTextRecord * CreateInBuffer (char *pBuffer);

  //	Set data fields of record
  void Set (double dPosX, double dPosY, const char *pszText, long lStyle);

	inline const double& GetPosX() const {return m_dPosX;};

  inline const double& GetPosY() const {return m_dPosY;};

	inline long GetStyle() const {return m_lStyle;};

	inline const CCVString& GetText () const {return m_Text;};

private:

  double m_dPosX;
  double m_dPosY;
  CConvLE<long> m_lStyle;
  CCVString m_Text;
};

inline CCVDrawTextRecord * CCVDrawTextRecord::CreateInBuffer (char *pBuffer)
{
  ASSERT(pBuffer);

  CCVDrawTextRecord *pItem = (CCVDrawTextRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


class CCVDrawRectRecord : public CRecordBase  
{
public:

  //	Initialize data record
  void Create ();
      
  //	Create record in an existing buffer
  static CCVDrawRectRecord * CreateInBuffer (char *pBuffer);

  //	Set data fields of record
  void Set (double dPosX0, double dPosY0, double dPosX1, double dPosY1, double dR, double dG, double dB);

	inline const double& GetPosX0() const {return m_dPosX0;};

  inline const double& GetPosY0() const {return m_dPosY0;};

	inline const double& GetPosX1() const {return m_dPosX1;};

  inline const double& GetPosY1() const {return m_dPosY1;};

	inline const double& GetR() const {return m_dR;};

	inline const double& GetG() const {return m_dG;};

	inline const double& GetB() const {return m_dB;};

private:

  double m_dPosX0;
  double m_dPosY0;
  double m_dPosX1;
  double m_dPosY1;
  double m_dR;
  double m_dG;
  double m_dB;
};

inline CCVDrawRectRecord * CCVDrawRectRecord::CreateInBuffer (char *pBuffer)
{
  ASSERT(pBuffer);

  CCVDrawRectRecord *pItem = (CCVDrawRectRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


class CCVDrawCtrlRecord : public CRecordBase  
{
public:

  //	Initialize data record
  void Create ();
      
  //	Create record in an existing buffer
  static CCVDrawCtrlRecord * CreateInBuffer (char *pBuffer);

  //	Set data fields of record
  void Set (long lControl);

	inline long GetControl() const {return m_lControl;};

private:
  CConvLE<long> m_lControl;
};

inline CCVDrawCtrlRecord * CCVDrawCtrlRecord::CreateInBuffer (char *pBuffer)
{
  ASSERT(pBuffer);

  CCVDrawCtrlRecord *pItem = (CCVDrawCtrlRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

class CCVTPEncodedRecord : public CRecordBase  
{
public:

  //	Initialize data record
  void Create (unsigned short usDataSize);
      
  //	Create record in an existing buffer
  static CCVTPEncodedRecord * CreateInBuffer(char *pBuffer, unsigned short usDataSize);

  //	Set data fields of record
  void Set(unsigned char* pucEncodedBuff, unsigned short usSequence);

  inline const unsigned short GetSequence() const {return m_usSequence;};

  inline const unsigned short GetDataSize() const {return GetSize() - sizeof(*this) + sizeof(m_ucStartOfEncoded);};

	inline const unsigned char* GetEncodedBuff() const {return &m_ucStartOfEncoded;};

private:
  CConvLE<unsigned short> m_usSequence;
  unsigned char m_ucStartOfEncoded;
};

inline CCVTPEncodedRecord* CCVTPEncodedRecord::CreateInBuffer(char* pBuffer, unsigned short usDataSize)
{
  ASSERT(pBuffer);

  CCVTPEncodedRecord *pItem = (CCVTPEncodedRecord *) pBuffer;
  pItem->Create(usDataSize);

  return pItem;
}

//## Class: CCVGammaRecord
//	Gamma command to projector
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCVGammaRecord : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CCVGammaRecord.initialDeclarations preserve=yes
  //## end CCVGammaRecord.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%936176351; C++
      //	Create record in an existing buffer
      static CCVGammaRecord* CreateInBuffer (char* pBuffer, unsigned short usRecordVersion);

      //## Operation: Set%936176358
      //	Set data fields of record
      void Set (unsigned short usConfiguration, unsigned char ucChannelMask, unsigned short usFirstEntry, unsigned short usNEntries, unsigned short usStep, const unsigned short *pusEntry);

      //## Operation: Create%936176361; C++
      //	Initialize data record.
      void Create(unsigned short usRecordVersion);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: usConfiguration
      const unsigned short GetusConfiguration () const;

      //## Attribute: ucChannelMask
      const unsigned char GetucChannelMask () const;

      //## Attribute: usFirstEntry
      //	Start of Gamma entries (color index)
      const unsigned short GetusFirstEntry () const;

      //## Attribute: usNEntries
      //	Number of Gamma entries (color index)
      const unsigned short GetusNEntries () const;

      //## Attribute: usStep
      //	Step between entries.  I.e. if ucStep is 2, every other
      //	entry is set, starting at ucFirstEntry.
      //
      //	The projector should interpolate to generate
      //	intermediate values.
      const unsigned short GetusStep () const;

      //## Attribute: usEntry
      //	Gamma entry table.  Each entry should be viewed as
      //	FP2.14 with range 0..1, or FP10:6 with range 0.255
      //	(0x4000 equals max color),
      const unsigned short* GetusEntry () const;

    // Additional Public Declarations
      //## begin CCVGammaRecord.public preserve=yes
      //## end CCVGammaRecord.public

  protected:

    //## Other Operations (specified)
      //## Operation: GetExtraSize%942406554
      //	Adjust size for variable-sized array at end
      unsigned short GetExtraSize () const;

    // Additional Protected Declarations
      //## begin CCVGammaRecord.protected preserve=yes
      //## end CCVGammaRecord.protected

  private:
    // Additional Private Declarations
      //## begin CCVGammaRecord.private preserve=yes
      //## end CCVGammaRecord.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CCVGammaRecord::usConfiguration.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usConfiguration;
      //## end CCVGammaRecord::usConfiguration.attr

      //## begin CCVGammaRecord::ucChannelMask.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucChannelMask;
      //## end CCVGammaRecord::ucChannelMask.attr

      //## begin CCVGammaRecord::usFirstEntry.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usFirstEntry;
      //## end CCVGammaRecord::usFirstEntry.attr

      //## begin CCVGammaRecord::usNEntries.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usNEntries;
      //## end CCVGammaRecord::usNEntries.attr

      //## begin CCVGammaRecord::usStep.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usStep;
      //## end CCVGammaRecord::usStep.attr

      //## begin CCVGammaRecord::usEntry.attr preserve=no  public: unsigned short[1] {U} 
      unsigned short m_usEntry[1];  //TODO: TABLE!!
      //## end CCVGammaRecord::usEntry.attr

    // Additional Implementation Declarations
      //## begin CCVGammaRecord.implementation preserve=yes
      //## end CCVGammaRecord.implementation

};

//## begin CCVGammaRecord.postscript preserve=yes
//## end CCVGammaRecord.postscript



//## Class: CCVChannelsRecord
//	Channel mask (on/off) record
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCVChannelsRecord : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CCVChannelsRecord.initialDeclarations preserve=yes
  //## end CCVChannelsRecord.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: Create%936176362; C++
      //	Initialize data record.
      void Create ();

      //## Operation: Set%936176363
      //	Set data fields of record
      void Set (unsigned short usConfiguration, unsigned char ucChannelMask);

      //## Operation: CreateInBuffer%936176364; C++
      //	Create record in an existing buffer
      static CCVChannelsRecord* CreateInBuffer (char* pBuffer);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: usConfiguration
      const unsigned short GetusConfiguration () const;

      //## Attribute: ucChannelMask
      const unsigned char GetucChannelMask () const;

    // Additional Public Declarations
      //## begin CCVChannelsRecord.public preserve=yes
      //## end CCVChannelsRecord.public

  protected:
    // Additional Protected Declarations
      //## begin CCVChannelsRecord.protected preserve=yes
      //## end CCVChannelsRecord.protected

  private:
    // Additional Private Declarations
      //## begin CCVChannelsRecord.private preserve=yes
      //## end CCVChannelsRecord.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CCVChannelsRecord::usConfiguration.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usConfiguration;
      //## end CCVChannelsRecord::usConfiguration.attr

      //## begin CCVChannelsRecord::ucChannelMask.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucChannelMask;
      //## end CCVChannelsRecord::ucChannelMask.attr

    // Additional Implementation Declarations
      //## begin CCVChannelsRecord.implementation preserve=yes
      //## end CCVChannelsRecord.implementation

};

//## begin CCVChannelsRecord.postscript preserve=yes
//## end CCVChannelsRecord.postscript



//## Class: CCVColorBalanceRecord
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCVColorBalanceRecord : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CCVColorBalanceRecord.initialDeclarations preserve=yes
  //## end CCVColorBalanceRecord.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%936176367; C++
      //	Create record in an existing buffer
      static CCVColorBalanceRecord* CreateInBuffer (char* pBuffer);

      //## Operation: Set%936176365
      //	Set data fields of record
      void Set (unsigned short usConfiguration, unsigned char ucChannelMask, double dColor);

      //## Operation: Create%936176366; C++
      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: usConfiguration
      const unsigned short GetusConfiguration () const;

      //## Attribute: ucChannelMask
      const unsigned char GetucChannelMask () const;

      //## Attribute: dColor
#if defined(CVPROJ) && GCM_VERSION==4
      const double GetdColor () const;
#else
      const double& GetdColor () const;
#endif

    // Additional Public Declarations
      //## begin CCVColorBalanceRecord.public preserve=yes
      //## end CCVColorBalanceRecord.public

  protected:
    // Additional Protected Declarations
      //## begin CCVColorBalanceRecord.protected preserve=yes
      //## end CCVColorBalanceRecord.protected

  private:
    // Additional Private Declarations
      //## begin CCVColorBalanceRecord.private preserve=yes
      //## end CCVColorBalanceRecord.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CCVColorBalanceRecord::usConfiguration.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usConfiguration;
      //## end CCVColorBalanceRecord::usConfiguration.attr

      //## begin CCVColorBalanceRecord::ucChannelMask.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucChannelMask;
      //## end CCVColorBalanceRecord::ucChannelMask.attr

      //## begin CCVColorBalanceRecord::dColor.attr preserve=no  public: double {U} 
      double m_dColor;
      //## end CCVColorBalanceRecord::dColor.attr

    // Additional Implementation Declarations
      //## begin CCVColorBalanceRecord.implementation preserve=yes
      //## end CCVColorBalanceRecord.implementation

};

class CCVColorOffsetRecord : public CRecordBase 
{
  public:
      static CCVColorOffsetRecord* CreateInBuffer (char* pBuffer);

      void Set (unsigned short usConfiguration, unsigned char ucChannelMask, double dColor);

      void Create ();

      const unsigned short GetusConfiguration () const;

      const unsigned char GetucChannelMask () const;

#if defined(CVPROJ) && GCM_VERSION==4
      const double GetdColor () const;
#else
      const double& GetdColor () const;
#endif

  private:
      CConvLE<unsigned short> m_usConfiguration;
      unsigned char m_ucChannelMask;
      double m_dColor;
};


//## Class: CCVGeometryRecord_V1
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCVGeometryRecord_V1 : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CCVGeometryRecord_V1.initialDeclarations preserve=yes
  //## end CCVGeometryRecord_V1.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%936176370; C++
      //	Create record in an existing buffer
      static CCVGeometryRecord_V1* CreateInBuffer (char* pBuffer);

      //## Operation: Set%936176368
      //	Set data fields of record
      void Set (unsigned short usConfiguration, unsigned char bOn, unsigned char nControlPointsX, unsigned char nControlPointsY, unsigned char nDegreeX, unsigned char nDegreeY);

      //## Operation: Create%936176369; C++
      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: usConfiguration
      const unsigned short GetusConfiguration () const;

      //## Attribute: ucOn
      const unsigned char GetucOn () const;

      //## Attribute: ucControlPointsX
      const unsigned char GetucControlPointsX () const;

      //## Attribute: ucControlPointsY
      const unsigned char GetucControlPointsY () const;

      //## Attribute: ucDegreeX
      const unsigned char GetucDegreeX () const;

      //## Attribute: ucDegreeY
      const unsigned char GetucDegreeY () const;

      // Additional Public Declarations
      //## begin CCVGeometryRecord_V1.public preserve=yes
      //## end CCVGeometryRecord_V1.public

  protected:
    // Additional Protected Declarations
      //## begin CCVGeometryRecord_V1.protected preserve=yes
      //## end CCVGeometryRecord_V1.protected

  private:
    // Additional Private Declarations
      //## begin CCVGeometryRecord_V1.private preserve=yes
      //## end CCVGeometryRecord_V1.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CCVGeometryRecord_V1::usConfiguration.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usConfiguration;
      //## end CCVGeometryRecord_V1::usConfiguration.attr

      //## begin CCVGeometryRecord_V1::ucOn.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucOn;
      //## end CCVGeometryRecord_V1::ucOn.attr

      //## begin CCVGeometryRecord_V1::ucControlPointsX.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucControlPointsX;
      //## end CCVGeometryRecord_V1::ucControlPointsX.attr

      //## begin CCVGeometryRecord_V1::ucControlPointsY.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucControlPointsY;
      //## end CCVGeometryRecord_V1::ucControlPointsY.attr

      //## begin CCVGeometryRecord_V1::ucDegreeX.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucDegreeX;
      //## end CCVGeometryRecord_V1::ucDegreeX.attr

      //## begin CCVGeometryRecord_V1::ucDegreeY.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucDegreeY;
      //## end CCVGeometryRecord_V1::ucDegreeY.attr

    // Additional Implementation Declarations
      //## begin CCVGeometryRecord_V1.implementation preserve=yes
      //## end CCVGeometryRecord_V1.implementation

};


class CCVGeometryRecord_V2 : public CRecordBase  //## Inherits: <unnamed>
{
  public:

      static CCVGeometryRecord_V2* CreateInBuffer (char* pBuffer, unsigned short usRecordVersion);

      void Set (unsigned short usConfiguration, unsigned long ulHandle, unsigned char bOn, unsigned char nControlPointsX, unsigned char nControlPointsY, unsigned char nDegreeX, unsigned char nDegreeY, unsigned char ucInterpolationMode = 0);

      //	Initialize data record.
      void Create (unsigned short usRecordVersion);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: usConfiguration
      const unsigned short GetusConfiguration () const;

      //## Attribute: ucOn
      const unsigned char GetucOn () const;

      //## Attribute: ucControlPointsX
      const unsigned char GetucControlPointsX () const;

      //## Attribute: ucControlPointsY
      const unsigned char GetucControlPointsY () const;

      //## Attribute: ucDegreeX
      const unsigned char GetucDegreeX () const;

      //## Attribute: ucDegreeY
      const unsigned char GetucDegreeY () const;

      const unsigned long GetulGeometryHandle () const;

      const unsigned char GetucInterpolationMode () const;

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CCVGeometryRecord_V2::usConfiguration.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usConfiguration;
      //## end CCVGeometryRecord_V2::usConfiguration.attr

      CConvLE<unsigned long> m_ulGeometryHandle;

      //## begin CCVGeometryRecord_V2::ucOn.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucOn;
      //## end CCVGeometryRecord_V2::ucOn.attr

      //## begin CCVGeometryRecord_V2::ucControlPointsX.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucControlPointsX;
      //## end CCVGeometryRecord_V2::ucControlPointsX.attr

      //## begin CCVGeometryRecord_V2::ucControlPointsY.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucControlPointsY;
      //## end CCVGeometryRecord_V2::ucControlPointsY.attr

      //## begin CCVGeometryRecord_V2::ucDegreeX.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucDegreeX;
      //## end CCVGeometryRecord_V2::ucDegreeX.attr

      //## begin CCVGeometryRecord_V2::ucDegreeY.attr preserve=no  public: unsigned char {U} 
      unsigned char m_ucDegreeY;
      //## end CCVGeometryRecord_V2::ucDegreeY.attr

      unsigned char m_ucInterpolationMode;
};


class CCVHotSpotRecord : public CRecordBase
{
  public:
    static CCVHotSpotRecord* CreateInBuffer (char* pBuffer);
    void Set (unsigned short usConfiguration, unsigned long ulHandle, unsigned char bOn, unsigned char nControlPointsX, unsigned char nControlPointsY);
    void Create ();

    //## Get and Set Operations for Class Attributes (generated)

    const unsigned short GetusConfiguration () const;
    const unsigned char GetucOn () const;
    const unsigned char GetucControlPointsX () const;
    const unsigned char GetucControlPointsY () const;
    const unsigned long GetulHandle () const;

  private:
    // Data Members for Class Attributes

    CConvLE<unsigned short> m_usConfiguration;
    CConvLE<unsigned long> m_ulHandle;
    unsigned char m_ucOn;
    unsigned char m_ucControlPointsX;
    unsigned char m_ucControlPointsY;
};

class CCVHotSpotControlPointRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
    static CCVHotSpotControlPointRecord* CreateInBuffer (char* pBuffer);
    void Set (unsigned short usConfiguration, unsigned long ulHandle, unsigned char ucIX, unsigned char ucIY, float fVal);
    void Create ();

    // Get and Set Operations for Class Attributes (generated)
    const unsigned short GetusConfiguration () const;
    const unsigned long GetulHandle () const;
    const unsigned char GetucIX () const;
    const unsigned char GetucIY () const;

#if defined(CVPROJ) && GCM_VERSION==4
    float GetfVal() const;
#else
    const float& GetfVal () const;
#endif

  private:
    CConvLE<unsigned short> m_usConfiguration;
    CConvLE<unsigned long> m_ulHandle;
    CConvLE<unsigned char> m_ucIX;
    CConvLE<unsigned char> m_ucIY;
    float m_fVal;
};


class CCVBlackLevelRecord : public CRecordBase
{
  public:
    static CCVBlackLevelRecord* CreateInBuffer (char* pBuffer);
    void Set (unsigned short usConfiguration, unsigned long ulHandle, unsigned char bOn, unsigned char nControlPointsX, unsigned char nControlPointsY, unsigned char nCutouts);
    void Create ();

    //## Get and Set Operations for Class Attributes (generated)

    const unsigned short GetusConfiguration () const;
    const unsigned char GetucOn () const;
    const unsigned char GetucControlPointsX () const;
    const unsigned char GetucControlPointsY () const;
    const unsigned long GetulHandle () const;
    const unsigned char GetucCutouts () const;

  private:
    // Data Members for Class Attributes

    CConvLE<unsigned short> m_usConfiguration;
    CConvLE<unsigned long> m_ulHandle;
    unsigned char m_ucOn;
    unsigned char m_ucControlPointsX;
    unsigned char m_ucControlPointsY;
    unsigned char m_ucCutouts;
};

class CCVBlackLevelControlPointRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
    static CCVBlackLevelControlPointRecord* CreateInBuffer (char* pBuffer);
    void Set (unsigned short usConfiguration, unsigned long ulHandle, unsigned char ucIX, unsigned char ucIY, float fVal);
    void Create ();

    // Get and Set Operations for Class Attributes (generated)
    const unsigned short GetusConfiguration () const;
    const unsigned long GetulHandle () const;
    const unsigned char GetucIX () const;
    const unsigned char GetucIY () const;

#if defined(CVPROJ) && GCM_VERSION==4
    float GetfVal() const;
#else
    const float& GetfVal () const;
#endif

  private:
    CConvLE<unsigned short> m_usConfiguration;
    CConvLE<unsigned long> m_ulHandle;
    CConvLE<unsigned char> m_ucIX;
    CConvLE<unsigned char> m_ucIY;
    float m_fVal;
};



class CCVBlackLevelCutoutRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
    static CCVBlackLevelCutoutRecord* CreateInBuffer (char* pBuffer, unsigned char ucControlPointCount);
    void Set (unsigned short usConfiguration, unsigned long ulHandle, unsigned char ucCutoutNo, unsigned char ucControlPointCount, struct FPOS *pPos);
    void Create (unsigned char ucControlPointCount);

    // Get and Set Operations for Class Attributes (generated)
    const unsigned short GetusConfiguration () const;
    const unsigned long GetulHandle () const;
    const unsigned char GetucCutoutNo () const;
    const unsigned char GetucControlPointCount () const;

#if defined(CVPROJ) && GCM_VERSION==4
    float GetfX(unsigned char ucIndex) const;
    float GetfY(unsigned char ucIndex) const;
#else
    const float& GetfX(unsigned char ucIndex) const;
    const float& GetfY(unsigned char ucIndex) const;
#endif

  private:
    CConvLE<unsigned short> m_usConfiguration;
    CConvLE<unsigned long> m_ulHandle;
    CConvLE<unsigned char> m_ucCutoutNo;
    CConvLE<unsigned char> m_ucControlPointCount;
    float m_fPos[1][2];
};





//## Class: CCVEdgeRecord
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCVEdgeRecord : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CCVEdgeRecord.initialDeclarations preserve=yes
  //## end CCVEdgeRecord.initialDeclarations

  public:

      void AssertValid() const;

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%936176373; C++
      //	Create record in an existing buffer
      static CCVEdgeRecord* CreateInBuffer (char* pBuffer, unsigned short usRecordVersion);

      //## Operation: Set%936176371
      //	Set data fields of record
      void Set (unsigned short usConfiguration, unsigned long ulEdgeHandle, unsigned short usControlPoints, unsigned short usSamples, unsigned char ucCombineMode);

      //## Operation: Create%936176372; C++
      //	Initialize data record.
      void Create (unsigned short usRecordVersion);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: usConfiguration
      const unsigned short GetusConfiguration () const;

      //## Attribute: ulEdgeHandle
      const unsigned long GetulEdgeHandle () const;

      //## Attribute: usControlPoints
      const unsigned short GetusControlPoints () const;

      //## Attribute: usSamples
      const unsigned short GetusSamples () const;

      const unsigned char GetucCombineMode() const;

    // Additional Public Declarations
      //## begin CCVEdgeRecord.public preserve=yes
      //## end CCVEdgeRecord.public

  protected:
    // Additional Protected Declarations
      //## begin CCVEdgeRecord.protected preserve=yes
      //## end CCVEdgeRecord.protected

  private:
    // Additional Private Declarations
      //## begin CCVEdgeRecord.private preserve=yes
      //## end CCVEdgeRecord.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CCVEdgeRecord::usConfiguration.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usConfiguration;
      //## end CCVEdgeRecord::usConfiguration.attr

      //## begin CCVEdgeRecord::ulEdgeHandle.attr preserve=no  public: unsigned long {U} 
      CConvLE<unsigned long> m_ulEdgeHandle;
      //## end CCVEdgeRecord::ulEdgeHandle.attr

      //## begin CCVEdgeRecord::usControlPoints.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usControlPoints;
      //## end CCVEdgeRecord::usControlPoints.attr

      //## begin CCVEdgeRecord::usSamples.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usSamples;
      //## end CCVEdgeRecord::usSamples.attr

      // Combine mode - default (0) or not present is multiply
      unsigned char m_ucCombineMode;
    // Additional Implementation Declarations
      //## begin CCVEdgeRecord.implementation preserve=yes
      //## end CCVEdgeRecord.implementation

};

//## begin CCVEdgeRecord.postscript preserve=yes
//## end CCVEdgeRecord.postscript



//## Class: CCVEdgeSampleRecord
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCVEdgeSampleRecord : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CCVEdgeSampleRecord.initialDeclarations preserve=yes
  //## end CCVEdgeSampleRecord.initialDeclarations

  public:

    //## Other Operations (specified)
      void AssertValid() const;

      //## Operation: CreateInBuffer%936176376; C++
      //	Create record in an existing buffer
      static CCVEdgeSampleRecord* CreateInBuffer (char* pBuffer, unsigned short usRecordVersion);

      //## Operation: Set%936176374
      //	Set data fields of record
      void Set (unsigned short usConfiguration, unsigned long ulEdgeHandle, unsigned short usSample, float fX, float fY, float fLevel);

      //## Operation: Create%936176375; C++
      //	Initialize data record.
      void Create (unsigned short usRecordVersion);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: usConfiguration
      const unsigned short GetusConfiguration () const;

      //## Attribute: ulEdgeHandle
      const unsigned long GetulEdgeHandle () const;

      //## Attribute: usSample
      const unsigned short GetusSample () const;

#if defined(CVPROJ) && GCM_VERSION==4
       //## Attribute: fX
      float GetfX () const;

      //## Attribute: fY
      float GetfY () const;

      //## Attribute: fLevel
      float GetfLevel () const;
#else
      //## Attribute: fX
      const float& GetfX () const;

      //## Attribute: fY
      const float& GetfY () const;

      //## Attribute: fLevel
      const float& GetfLevel () const;
#endif
    // Additional Public Declarations
      //## begin CCVEdgeSampleRecord.public preserve=yes
      //## end CCVEdgeSampleRecord.public

  protected:
    // Additional Protected Declarations
      //## begin CCVEdgeSampleRecord.protected preserve=yes
      //## end CCVEdgeSampleRecord.protected

  private:
    // Additional Private Declarations
      //## begin CCVEdgeSampleRecord.private preserve=yes
      //## end CCVEdgeSampleRecord.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CCVEdgeSampleRecord::usConfiguration.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usConfiguration;
      //## end CCVEdgeSampleRecord::usConfiguration.attr

      //## begin CCVEdgeSampleRecord::ulEdgeHandle.attr preserve=no  public: unsigned long {U} 
      CConvLE<unsigned long> m_ulEdgeHandle;
      //## end CCVEdgeSampleRecord::ulEdgeHandle.attr

      //## begin CCVEdgeSampleRecord::usSample.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usSample;
      //## end CCVEdgeSampleRecord::usSample.attr

      //## begin CCVEdgeSampleRecord::fX.attr preserve=no  public: float {U} 
      float m_fX;
      //## end CCVEdgeSampleRecord::fX.attr

      //## begin CCVEdgeSampleRecord::fY.attr preserve=no  public: float {U} 
      float m_fY;
      //## end CCVEdgeSampleRecord::fY.attr

      //## begin CCVEdgeSampleRecord::fLevel.attr preserve=no  public: float {U} 
      float m_fLevel;
      //## end CCVEdgeSampleRecord::fLevel.attr

    // Additional Implementation Declarations
      //## begin CCVEdgeSampleRecord.implementation preserve=yes
      //## end CCVEdgeSampleRecord.implementation

};

//## begin CCVEdgeSampleRecord.postscript preserve=yes
//## end CCVEdgeSampleRecord.postscript



//## Class: CCVEdgeAlphaRecord
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCVEdgeAlphaRecord : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CCVEdgeAlphaRecord.initialDeclarations preserve=yes
  //## end CCVEdgeAlphaRecord.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%936176382; C++
      //	Create record in an existing buffer
      static CCVEdgeAlphaRecord* CreateInBuffer (char* pBuffer);

      //## Operation: Set%936176380
      //	Set data fields of record
      void Set (unsigned short usConfiguration, unsigned long ulEdgeHandle, unsigned short usFirstEntry, unsigned short usNEntries, unsigned short usStep, const unsigned short *pusEntry);

      //## Operation: Create%936176381; C++
      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: usConfiguration
      const unsigned short GetusConfiguration () const;

      //## Attribute: ulEdgeHandle
      const unsigned long GetulEdgeHandle () const;

      //## Attribute: usFirstEntry
      //	Start of Alpha entries (0..255)
      const unsigned short GetusFirstEntry () const;

      //## Attribute: usNEntries
      //	Number of Alpha entries
      const unsigned short GetusNEntries () const;

      //## Attribute: usStep
      //	Step between entries.  I.e. if ucStep is 2, every other
      //	entry is set, starting at ucFirstEntry.
      //
      //	The projector should interpolate to generate
      //	intermediate values.
      const unsigned short GetusStep () const;

      //## Attribute: usEntry
      //	Alpha entry table.  Each entry should be viewed as
      //	FP2.14 with range 0..1, or FP10:6 with range 0.255
      //	(0x4000 equals max color),
      const unsigned short* GetusEntry () const;

    // Additional Public Declarations
      //## begin CCVEdgeAlphaRecord.public preserve=yes
      //## end CCVEdgeAlphaRecord.public

  protected:

    //## Other Operations (specified)
      //## Operation: GetExtraSize%942659954
      //	Adjust size for variable-sized array at end
      unsigned short GetExtraSize () const;

    // Additional Protected Declarations
      //## begin CCVEdgeAlphaRecord.protected preserve=yes
      //## end CCVEdgeAlphaRecord.protected

  private:
    // Additional Private Declarations
      //## begin CCVEdgeAlphaRecord.private preserve=yes
      //## end CCVEdgeAlphaRecord.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CCVEdgeAlphaRecord::usConfiguration.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usConfiguration;
      //## end CCVEdgeAlphaRecord::usConfiguration.attr

      //## begin CCVEdgeAlphaRecord::ulEdgeHandle.attr preserve=no  public: unsigned long {U} 
      CConvLE<unsigned long> m_ulEdgeHandle;
      //## end CCVEdgeAlphaRecord::ulEdgeHandle.attr

      //## begin CCVEdgeAlphaRecord::usFirstEntry.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usFirstEntry;
      //## end CCVEdgeAlphaRecord::usFirstEntry.attr

      //## begin CCVEdgeAlphaRecord::usNEntries.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usNEntries;
      //## end CCVEdgeAlphaRecord::usNEntries.attr

      //## begin CCVEdgeAlphaRecord::usStep.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usStep;
      //## end CCVEdgeAlphaRecord::usStep.attr

      //## begin CCVEdgeAlphaRecord::usEntry.attr preserve=no  public: unsigned short[1] {U} 
      unsigned short m_usEntry[1];  //TODO TABLE!!!
      //## end CCVEdgeAlphaRecord::usEntry.attr

    // Additional Implementation Declarations
      //## begin CCVEdgeAlphaRecord.implementation preserve=yes
      //## end CCVEdgeAlphaRecord.implementation

};

//## begin CCVEdgeAlphaRecord.postscript preserve=yes
//## end CCVEdgeAlphaRecord.postscript


class CCVValidHandleRecord : public CRecordBase  //## Inherits: <unnamed>
{
public:
  static CCVValidHandleRecord* CreateInBuffer (char* pBuffer);

  void Set (unsigned short usConfiguration, unsigned short usNHandles, unsigned long *pulHandle);
  void Create ();
  const unsigned short GetusConfiguration () const;
  const unsigned short GetusNHandles () const;
  const unsigned long * GetulHandleArray () const;
  const unsigned long GetulHandle (short sIndex) const;

  unsigned short GetExtraSize () const;

private:
  CConvLE<unsigned short> m_usConfiguration;
  CConvLE<unsigned short> m_usNHandles;
  unsigned long m_aulHandle[1];  //TODO: TABLE!!!
};  



//## Class: CCVResetCommand
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCVResetCommand : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CCVResetCommand.initialDeclarations preserve=yes
  //## end CCVResetCommand.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%936176384; C++
      //	Create record in an existing buffer
      static CCVResetCommand* CreateInBuffer (char* pBuffer);

      //## Operation: Set%941641875
      //	Set data fields of record
      void Set (unsigned short usConfiguration);

      //## Operation: Create%936176383; C++
      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: usConfiguration
      const unsigned short GetusConfiguration () const;

    // Additional Public Declarations
      //## begin CCVResetCommand.public preserve=yes
      //## end CCVResetCommand.public

  protected:
    // Additional Protected Declarations
      //## begin CCVResetCommand.protected preserve=yes
      //## end CCVResetCommand.protected

  private:
    // Additional Private Declarations
      //## begin CCVResetCommand.private preserve=yes
      //## end CCVResetCommand.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CCVResetCommand::usConfiguration.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usConfiguration;
      //## end CCVResetCommand::usConfiguration.attr

    // Additional Implementation Declarations
      //## begin CCVResetCommand.implementation preserve=yes
      //## end CCVResetCommand.implementation

};

//## begin CCVResetCommand.postscript preserve=yes
//## end CCVResetCommand.postscript



//## Class: CCVGeometryControlPointRecord
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCVGeometryControlPointRecord : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CCVGeometryControlPointRecord.initialDeclarations preserve=yes
  //## end CCVGeometryControlPointRecord.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: CreateInBuffer%936176387; C++
      //	Create record in an existing buffer
      static CCVGeometryControlPointRecord* CreateInBuffer (char* pBuffer, unsigned short usRecordVersion);

      //## Operation: Set%936176385
      //	Set data fields of record
      void Set (unsigned short usConfiguration, unsigned long ulGeometryHandle, unsigned short usIX, unsigned short usIY, double dX, double dY, unsigned short usMultiplicity);

      //## Operation: Create%936176386; C++
      //	Initialize data record.
      void Create (unsigned short usRecordVersion);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: usConfiguration
      const unsigned short GetusConfiguration () const;

      //## Attribute: ulGeometryHandle
      const unsigned long GetulGeometryHandle () const;

      //## Attribute: usIX
      const unsigned short GetusIX () const;

      //## Attribute: usIY
      const unsigned short GetusIY () const;

#if defined(CVPROJ) && GCM_VERSION==4      
      double GetdX() const;

      double GetdY() const;
#else
      //## Attribute: dX
      const double& GetdX () const;

      //## Attribute: dY
      const double& GetdY () const;
#endif

      //## Attribute: usMultiplicity
      const unsigned short GetusMultiplicity () const;

    // Additional Public Declarations
      //## begin CCVGeometryControlPointRecord.public preserve=yes
      //## end CCVGeometryControlPointRecord.public

  protected:
    // Additional Protected Declarations
      //## begin CCVGeometryControlPointRecord.protected preserve=yes
      //## end CCVGeometryControlPointRecord.protected

  private:
    // Additional Private Declarations
      //## begin CCVGeometryControlPointRecord.private preserve=yes
      //## end CCVGeometryControlPointRecord.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CCVGeometryControlPointRecord::usConfiguration.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usConfiguration;
      //## end CCVGeometryControlPointRecord::usConfiguration.attr

      //## begin CCVGeometryControlPointRecord::ulGeometryHandle.attr preserve=no  public: unsigned long {U} 
      CConvLE<unsigned long> m_ulGeometryHandle;
      //## end CCVGeometryControlPointRecord::ulGeometryHandle.attr

      //## begin CCVGeometryControlPointRecord::usIX.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usIX;
      //## end CCVGeometryControlPointRecord::usIX.attr

      //## begin CCVGeometryControlPointRecord::usIY.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usIY;
      //## end CCVGeometryControlPointRecord::usIY.attr

      //## begin CCVGeometryControlPointRecord::dX.attr preserve=no  public: double {U} 
      double m_dX;
      //## end CCVGeometryControlPointRecord::dX.attr

      //## begin CCVGeometryControlPointRecord::dY.attr preserve=no  public: double {U} 
      double m_dY;
      //## end CCVGeometryControlPointRecord::dY.attr

	  // Additional Implementation Declarations
      //## begin CCVGeometryControlPointRecord.implementation preserve=yes
      //## end CCVGeometryControlPointRecord.implementation

};




//## Class: CCVDisableRecord
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCVDisableRecord : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CCVDisableRecord.initialDeclarations preserve=yes
  //## end CCVDisableRecord.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: Create%936176377; C++
      //	Initialize data record.
      void Create ();

      //## Operation: Set%936176378
      //	Set data fields of record
      void Set (unsigned short usConfiguration, unsigned long ulDisableMask);

      //## Operation: CreateInBuffer%936176379; C++
      //	Create record in an existing buffer
      static CCVDisableRecord* CreateInBuffer (char* pBuffer);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: usConfiguration
      const unsigned short GetusConfiguration () const;

      //## Attribute: ulDisableMask
      const unsigned long GetulDisableMask () const;

    // Additional Public Declarations
      //## begin CCVDisableRecord.public preserve=yes
      //## end CCVDisableRecord.public

  protected:
    // Additional Protected Declarations
      //## begin CCVDisableRecord.protected preserve=yes
      //## end CCVDisableRecord.protected

  private:
    // Additional Private Declarations
      //## begin CCVDisableRecord.private preserve=yes
      //## end CCVDisableRecord.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CCVDisableRecord::usConfiguration.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usConfiguration;
      //## end CCVDisableRecord::usConfiguration.attr

      //## begin CCVDisableRecord::ulDisableMask.attr preserve=no  public: unsigned long {U} 
      CConvLE<unsigned long> m_ulDisableMask;
      //## end CCVDisableRecord::ulDisableMask.attr

    // Additional Implementation Declarations
      //## begin CCVDisableRecord.implementation preserve=yes
      //## end CCVDisableRecord.implementation

};

//## begin CCVDisableRecord.postscript preserve=yes
//## end CCVDisableRecord.postscript



//## Class: CCVRestoreConfigurationRecord
//	Restore specified configuration from FLASH
//## Category: cvsetup
//## Subsystem: cvsetup
//## Persistence: Transient
//## Cardinality/Multiplicity: n

class CCVRestoreConfigurationRecord : public CRecordBase  //## Inherits: <unnamed>
{
  //## begin CCVRestoreConfigurationRecord.initialDeclarations preserve=yes
  //## end CCVRestoreConfigurationRecord.initialDeclarations

  public:

    //## Other Operations (specified)
      //## Operation: Create%943537002; C++
      //	Initialize data record.
      void Create ();

      //## Operation: Set%943537003
      //	Set data fields of record
      void Set (unsigned short usConfiguration);

      //## Operation: CreateInBuffer%943537004; C++
      //	Create record in an existing buffer
      static CCVRestoreConfigurationRecord* CreateInBuffer (char* pBuffer);

    //## Get and Set Operations for Class Attributes (generated)

      //## Attribute: usConfiguration
      const unsigned short GetusConfiguration () const;

    // Additional Public Declarations
      //## begin CCVRestoreConfigurationRecord.public preserve=yes
      //## end CCVRestoreConfigurationRecord.public

  protected:
    // Additional Protected Declarations
      //## begin CCVRestoreConfigurationRecord.protected preserve=yes
      //## end CCVRestoreConfigurationRecord.protected

  private:
    // Additional Private Declarations
      //## begin CCVRestoreConfigurationRecord.private preserve=yes
      //## end CCVRestoreConfigurationRecord.private

  private:  //## implementation
    // Data Members for Class Attributes

      //## begin CCVRestoreConfigurationRecord::usConfiguration.attr preserve=no  public: unsigned short {U} 
      CConvLE<unsigned short> m_usConfiguration;
      //## end CCVRestoreConfigurationRecord::usConfiguration.attr

    // Additional Implementation Declarations
      //## begin CCVRestoreConfigurationRecord.implementation preserve=yes
      //## end CCVRestoreConfigurationRecord.implementation

};

//## begin CCVRestoreConfigurationRecord.postscript preserve=yes
//## end CCVRestoreConfigurationRecord.postscript



// Class CCVTestPatternRecord 


//## Other Operations (inline)
inline CCVTestPatternRecord * CCVTestPatternRecord::CreateInBuffer (char *pBuffer)
{
  //## begin CCVTestPatternRecord::CreateInBuffer%936176353.body preserve=yes
  ASSERT(pBuffer);

  CCVTestPatternRecord *pItem = (CCVTestPatternRecord *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CCVTestPatternRecord::CreateInBuffer%936176353.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const CCVString& CCVTestPatternRecord::GetTestPatternFile () const
{
  //## begin CCVTestPatternRecord::GetTestPatternFile%.get preserve=no
  return m_TestPatternFile;
  //## end CCVTestPatternRecord::GetTestPatternFile%.get
}





// Class CCVGammaRecord 


//## Other Operations (inline)
inline CCVGammaRecord* CCVGammaRecord::CreateInBuffer (char* pBuffer, unsigned short usRecordVersion)
{
  //## begin CCVGammaRecord::CreateInBuffer%936176351.body preserve=yes
  ASSERT(pBuffer);

  CCVGammaRecord *pItem = (CCVGammaRecord *) pBuffer;
  pItem->Create(usRecordVersion);

  return pItem;
}

inline unsigned short CCVGammaRecord::GetExtraSize () const
{
  //## begin CCVGammaRecord::GetExtraSize%942406554.body preserve=yes
  return m_usNEntries * sizeof(m_usEntry[0]) - sizeof(m_usEntry);
  //## end CCVGammaRecord::GetExtraSize%942406554.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned short CCVGammaRecord::GetusConfiguration () const
{
  //## begin CCVGammaRecord::GetusConfiguration%.get preserve=no
  return m_usConfiguration;
  //## end CCVGammaRecord::GetusConfiguration%.get
}

inline const unsigned char CCVGammaRecord::GetucChannelMask () const
{
  //## begin CCVGammaRecord::GetucChannelMask%.get preserve=no
  return m_ucChannelMask;
  //## end CCVGammaRecord::GetucChannelMask%.get
}

inline const unsigned short CCVGammaRecord::GetusFirstEntry () const
{
  //## begin CCVGammaRecord::GetusFirstEntry%.get preserve=no
  return m_usFirstEntry;
  //## end CCVGammaRecord::GetusFirstEntry%.get
}

inline const unsigned short CCVGammaRecord::GetusNEntries () const
{
  //## begin CCVGammaRecord::GetusNEntries%.get preserve=no
  return m_usNEntries;
  //## end CCVGammaRecord::GetusNEntries%.get
}

inline const unsigned short CCVGammaRecord::GetusStep () const
{
  //## begin CCVGammaRecord::GetusStep%.get preserve=no
  return m_usStep;
  //## end CCVGammaRecord::GetusStep%.get
}

inline const unsigned short* CCVGammaRecord::GetusEntry () const
{
  //## begin CCVGammaRecord::GetusEntry%.get preserve=no
  return m_usEntry;
  //## end CCVGammaRecord::GetusEntry%.get
}





// Class CCVChannelsRecord 


//## Other Operations (inline)
inline CCVChannelsRecord* CCVChannelsRecord::CreateInBuffer (char* pBuffer)
{
  //## begin CCVChannelsRecord::CreateInBuffer%936176364.body preserve=yes
  ASSERT(pBuffer);

  CCVChannelsRecord *pItem = (CCVChannelsRecord *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CCVChannelsRecord::CreateInBuffer%936176364.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned short CCVChannelsRecord::GetusConfiguration () const
{
  //## begin CCVChannelsRecord::GetusConfiguration%.get preserve=no
  return m_usConfiguration;
  //## end CCVChannelsRecord::GetusConfiguration%.get
}

inline const unsigned char CCVChannelsRecord::GetucChannelMask () const
{
  //## begin CCVChannelsRecord::GetucChannelMask%.get preserve=no
  return m_ucChannelMask;
  //## end CCVChannelsRecord::GetucChannelMask%.get
}





// Class CCVColorBalanceRecord 


//## Other Operations (inline)
inline CCVColorBalanceRecord* CCVColorBalanceRecord::CreateInBuffer (char* pBuffer)
{
  //## begin CCVColorBalanceRecord::CreateInBuffer%936176367.body preserve=yes
  ASSERT(pBuffer);

  CCVColorBalanceRecord *pItem = (CCVColorBalanceRecord *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CCVColorBalanceRecord::CreateInBuffer%936176367.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned short CCVColorBalanceRecord::GetusConfiguration () const
{
  //## begin CCVColorBalanceRecord::GetusConfiguration%.get preserve=no
  return m_usConfiguration;
  //## end CCVColorBalanceRecord::GetusConfiguration%.get
}

inline const unsigned char CCVColorBalanceRecord::GetucChannelMask () const
{
  //## begin CCVColorBalanceRecord::GetucChannelMask%.get preserve=no
  return m_ucChannelMask;
  //## end CCVColorBalanceRecord::GetucChannelMask%.get
}

#if defined(CVPROJ) && GCM_VERSION==4
inline const double CCVColorBalanceRecord::GetdColor () const
{
  //## begin CCVColorBalanceRecord::GetdColor%.get preserve=no

  ASSERT(sizeof(double) == sizeof(long long));
  
  unsigned long long ullData;
  memcpy(&ullData, &m_dColor, sizeof(ullData));
  
  ullData = CONVERT_FROM_LE64(ullData);

  double dRet;
  memcpy(&dRet, &ullData, sizeof(dRet));

  return dRet;
  //## end CCVColorBalanceRecord::GetdColor%.get
}
#else
inline const double& CCVColorBalanceRecord::GetdColor () const
{
  //## begin CCVColorBalanceRecord::GetdColor%.get preserve=no
  return m_dColor;
  //## end CCVColorBalanceRecord::GetdColor%.get
}
#endif



// Class CCVColorOffsetRecord 

inline CCVColorOffsetRecord* CCVColorOffsetRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVColorOffsetRecord *pItem = (CCVColorOffsetRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

inline const unsigned short CCVColorOffsetRecord::GetusConfiguration () const
{
  return m_usConfiguration;
}

inline const unsigned char CCVColorOffsetRecord::GetucChannelMask () const
{
  return m_ucChannelMask;
}

#if defined(CVPROJ) && GCM_VERSION==4
inline const double CCVColorOffsetRecord::GetdColor () const
{
  ASSERT(sizeof(double) == sizeof(long long));
  
  unsigned long long ullData;
  memcpy(&ullData, &m_dColor, sizeof(ullData));
  
  ullData = CONVERT_FROM_LE64(ullData);

  double dRet;
  memcpy(&dRet, &ullData, sizeof(dRet));

  return dRet;
}
#else
inline const double& CCVColorOffsetRecord::GetdColor () const
{
  return m_dColor;
}
#endif



// Class CCVGeometryRecord_V1


//## Other Operations (inline)
inline CCVGeometryRecord_V1* CCVGeometryRecord_V1::CreateInBuffer (char* pBuffer)
{
  //## begin CCVGeometryRecord_V1::CreateInBuffer%936176370.body preserve=yes
  ASSERT(pBuffer);

  CCVGeometryRecord_V1 *pItem = (CCVGeometryRecord_V1 *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CCVGeometryRecord_V1::CreateInBuffer%936176370.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned short CCVGeometryRecord_V1::GetusConfiguration () const
{
  //## begin CCVGeometryRecord_V1::GetusConfiguration%.get preserve=no
  return m_usConfiguration;
  //## end CCVGeometryRecord_V1::GetusConfiguration%.get
}

inline const unsigned char CCVGeometryRecord_V1::GetucOn () const
{
  //## begin CCVGeometryRecord_V1::GetucOn%.get preserve=no
  return m_ucOn;
  //## end CCVGeometryRecord_V1::GetucOn%.get
}

inline const unsigned char CCVGeometryRecord_V1::GetucControlPointsX () const
{
  //## begin CCVGeometryRecord_V1::GetucControlPointsX%.get preserve=no
  return m_ucControlPointsX;
  //## end CCVGeometryRecord_V1::GetucControlPointsX%.get
}

inline const unsigned char CCVGeometryRecord_V1::GetucControlPointsY () const
{
  //## begin CCVGeometryRecord_V1::GetucControlPointsY%.get preserve=no
  return m_ucControlPointsY;
  //## end CCVGeometryRecord_V1::GetucControlPointsY%.get
}

inline const unsigned char CCVGeometryRecord_V1::GetucDegreeX () const
{
  //## begin CCVGeometryRecord_V1::GetucDegreeX%.get preserve=no
  return m_ucDegreeX;
  //## end CCVGeometryRecord_V1::GetucDegreeX%.get
}

inline const unsigned char CCVGeometryRecord_V1::GetucDegreeY () const
{
  //## begin CCVGeometryRecord_V1::GetucDegreeY%.get preserve=no
  return m_ucDegreeY;
  //## end CCVGeometryRecord_V1::GetucDegreeY%.get
}



inline CCVGeometryRecord_V2* CCVGeometryRecord_V2::CreateInBuffer (char* pBuffer, unsigned short usRecordVersion)
{
  ASSERT(pBuffer);

  CCVGeometryRecord_V2 *pItem = (CCVGeometryRecord_V2 *) pBuffer;
  pItem->Create(usRecordVersion);

  return pItem;
}


//## Get and Set Operations for Class Attributes (inline)

inline const unsigned short CCVGeometryRecord_V2::GetusConfiguration () const
{
  return m_usConfiguration;
}

inline const unsigned char CCVGeometryRecord_V2::GetucOn () const
{
  return m_ucOn;
}

inline const unsigned char CCVGeometryRecord_V2::GetucControlPointsX () const
{
  return m_ucControlPointsX;
}

inline const unsigned char CCVGeometryRecord_V2::GetucControlPointsY () const
{
  return m_ucControlPointsY;
}

inline const unsigned char CCVGeometryRecord_V2::GetucDegreeX () const
{
  return m_ucDegreeX;
}

inline const unsigned char CCVGeometryRecord_V2::GetucDegreeY () const
{
  return m_ucDegreeY;
}


inline const unsigned long CCVGeometryRecord_V2::GetulGeometryHandle () const
{
  return m_ulGeometryHandle;
}


inline const unsigned char CCVGeometryRecord_V2::GetucInterpolationMode () const
{
  if (GetSize() >= offsetof(CCVGeometryRecord_V2, m_ucInterpolationMode) + sizeof(m_ucInterpolationMode))
    return m_ucInterpolationMode;
  else
    return 0; //INTERPOLATIONMODE_NURBS;  // Default if not present in record
}




inline CCVHotSpotRecord* CCVHotSpotRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVHotSpotRecord *pItem = (CCVHotSpotRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


inline const unsigned short CCVHotSpotRecord::GetusConfiguration () const
{
  return m_usConfiguration;
}

inline const unsigned char CCVHotSpotRecord::GetucOn () const
{
  return m_ucOn;
}

inline const unsigned char CCVHotSpotRecord::GetucControlPointsX () const
{
  return m_ucControlPointsX;
}

inline const unsigned char CCVHotSpotRecord::GetucControlPointsY () const
{
  return m_ucControlPointsY;
}


inline const unsigned long CCVHotSpotRecord::GetulHandle () const
{
  return m_ulHandle;
}


// Class CCVHotSpotControlPointRecord 


//## Other Operations (inline)
inline CCVHotSpotControlPointRecord* CCVHotSpotControlPointRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);
  CCVHotSpotControlPointRecord *pItem = (CCVHotSpotControlPointRecord *) pBuffer;
  pItem->Create();
  return pItem;
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned short CCVHotSpotControlPointRecord::GetusConfiguration () const
{
  return m_usConfiguration;
}

inline const unsigned long CCVHotSpotControlPointRecord::GetulHandle () const
{
  return m_ulHandle;
}

inline const unsigned char CCVHotSpotControlPointRecord::GetucIX () const
{
  return m_ucIX;
}

inline const unsigned char CCVHotSpotControlPointRecord::GetucIY () const
{
  return m_ucIY;
}

#if defined(CVPROJ) && GCM_VERSION==4
inline float CCVHotSpotControlPointRecord::GetfVal () const
{
  ASSERT(sizeof(float) == sizeof(long));
  
  unsigned long ulData;
  memcpy(&ulData, &m_fVal, sizeof(ulData));
  
  ulData = CONVERT_FROM_LE32(ulData);
  float fRet;
  memcpy(&fRet, &ulData, sizeof(fRet));

  return fRet;
}

#else //defined(CVPROJ) && GCM_VERSION==4

inline const float& CCVHotSpotControlPointRecord::GetfVal () const
{
  return m_fVal;
}

#endif //defined(CVPROJ) && GCM_VERSION==4




inline CCVBlackLevelRecord* CCVBlackLevelRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVBlackLevelRecord *pItem = (CCVBlackLevelRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


inline const unsigned short CCVBlackLevelRecord::GetusConfiguration () const
{
  return m_usConfiguration;
}

inline const unsigned char CCVBlackLevelRecord::GetucOn () const
{
  return m_ucOn;
}

inline const unsigned char CCVBlackLevelRecord::GetucControlPointsX () const
{
  return m_ucControlPointsX;
}

inline const unsigned char CCVBlackLevelRecord::GetucControlPointsY () const
{
  return m_ucControlPointsY;
}


inline const unsigned long CCVBlackLevelRecord::GetulHandle () const
{
  return m_ulHandle;
}


inline const unsigned char CCVBlackLevelRecord::GetucCutouts () const
{
  return m_ucCutouts;
}


// Class CCVBlackLevelControlPointRecord 


//## Other Operations (inline)
inline CCVBlackLevelControlPointRecord* CCVBlackLevelControlPointRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);
  CCVBlackLevelControlPointRecord *pItem = (CCVBlackLevelControlPointRecord *) pBuffer;
  pItem->Create();
  return pItem;
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned short CCVBlackLevelControlPointRecord::GetusConfiguration () const
{
  return m_usConfiguration;
}

inline const unsigned long CCVBlackLevelControlPointRecord::GetulHandle () const
{
  return m_ulHandle;
}

inline const unsigned char CCVBlackLevelControlPointRecord::GetucIX () const
{
  return m_ucIX;
}

inline const unsigned char CCVBlackLevelControlPointRecord::GetucIY () const
{
  return m_ucIY;
}

#if defined(CVPROJ) && GCM_VERSION==4
inline float CCVBlackLevelControlPointRecord::GetfVal () const
{
  ASSERT(sizeof(float) == sizeof(long));
  
  unsigned long ulData;
  memcpy(&ulData, &m_fVal, sizeof(ulData));
  
  ulData = CONVERT_FROM_LE32(ulData);
  float fRet;
  memcpy(&fRet, &ulData, sizeof(fRet));

  return fRet;
}

#else //defined(CVPROJ) && GCM_VERSION==4

inline const float& CCVBlackLevelControlPointRecord::GetfVal () const
{
  return m_fVal;
}

#endif //defined(CVPROJ) && GCM_VERSION==4



// Class CCVBlackLevelCutoutRecord 


//## Other Operations (inline)
inline CCVBlackLevelCutoutRecord* CCVBlackLevelCutoutRecord::CreateInBuffer (char* pBuffer, unsigned char ucControlPointCount)
{
  ASSERT(pBuffer);
  CCVBlackLevelCutoutRecord *pItem = (CCVBlackLevelCutoutRecord *) pBuffer;
  pItem->Create(ucControlPointCount);
  return pItem;
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned short CCVBlackLevelCutoutRecord::GetusConfiguration () const
{
  return m_usConfiguration;
}

inline const unsigned long CCVBlackLevelCutoutRecord::GetulHandle () const
{
  return m_ulHandle;
}

inline const unsigned char CCVBlackLevelCutoutRecord::GetucCutoutNo () const
{
  return m_ucCutoutNo;
}

inline const unsigned char CCVBlackLevelCutoutRecord::GetucControlPointCount () const
{
  return m_ucControlPointCount;
}

#if defined(CVPROJ) && GCM_VERSION==4
inline float CCVBlackLevelCutoutRecord::GetfX (unsigned char ucIndex) const
{
  ASSERT(sizeof(float) == sizeof(long));
  ASSERT(ucIndex < m_ucControlPointCount);

  unsigned long ulTmp = *(unsigned long *) &m_fPos[ucIndex][0];
  ulTmp = CONVERT_FROM_LE32(ulTmp);
  float fRet = *(float *) &ulTmp;

  return fRet;
}

inline float CCVBlackLevelCutoutRecord::GetfY (unsigned char ucIndex) const
{
  ASSERT(sizeof(float) == sizeof(long));
  ASSERT(ucIndex < m_ucControlPointCount);

  unsigned long ulTmp = *(unsigned long *) &m_fPos[ucIndex][1];
  ulTmp = CONVERT_FROM_LE32(ulTmp);
  float fRet = *(float *) &ulTmp;

  return fRet;
}
#else //defined(CVPROJ) && GCM_VERSION==4

inline const float& CCVBlackLevelCutoutRecord::GetfX (unsigned char ucIndex) const
{
  ASSERT(ucIndex < m_ucControlPointCount);
  return m_fPos[ucIndex][0];
}

inline const float& CCVBlackLevelCutoutRecord::GetfY (unsigned char ucIndex) const
{
  ASSERT(ucIndex < m_ucControlPointCount);
  return m_fPos[ucIndex][1];
}

#endif //defined(CVPROJ) && GCM_VERSION==4




// Class CCVEdgeRecord 


//## Other Operations (inline)

inline void CCVEdgeRecord::AssertValid () const
{
#ifdef _DEBUG
  CRecordBase::AssertValid();

  if (GetRecordType() == CV_EDGE_V1)
  {
    ASSERT(m_usSamples <= 2);
    ASSERT(m_usControlPoints <= 2);
  }
  else
  {
    ASSERT(GetRecordType() == CV_EDGE_V2 || GetRecordType() == CV_MASK || GetRecordType() == CV_BLACKLEVELMASK);
    ASSERT(m_usSamples <= 2);
    ASSERT(m_usControlPoints <= 17);
  }
#endif
}


inline CCVEdgeRecord* CCVEdgeRecord::CreateInBuffer (char* pBuffer, unsigned short usRecordVersion)
{
  //## begin CCVEdgeRecord::CreateInBuffer%936176373.body preserve=yes
  ASSERT(pBuffer);

  CCVEdgeRecord *pItem = (CCVEdgeRecord *) pBuffer;
  pItem->Create(usRecordVersion);

  return pItem;
  //## end CCVEdgeRecord::CreateInBuffer%936176373.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned short CCVEdgeRecord::GetusConfiguration () const
{
  //## begin CCVEdgeRecord::GetusConfiguration%.get preserve=no
  return m_usConfiguration;
  //## end CCVEdgeRecord::GetusConfiguration%.get
}

inline const unsigned long CCVEdgeRecord::GetulEdgeHandle () const
{
  //## begin CCVEdgeRecord::GetulEdgeHandle%.get preserve=no
  return m_ulEdgeHandle;
  //## end CCVEdgeRecord::GetulEdgeHandle%.get
}

inline const unsigned short CCVEdgeRecord::GetusControlPoints () const
{
  //## begin CCVEdgeRecord::GetusControlPoints%.get preserve=no
  return m_usControlPoints;
  //## end CCVEdgeRecord::GetusControlPoints%.get
}

inline const unsigned short CCVEdgeRecord::GetusSamples () const
{
  //## begin CCVEdgeRecord::GetusSamples%.get preserve=no
  return m_usSamples;
  //## end CCVEdgeRecord::GetusSamples%.get
}

inline const unsigned char CCVEdgeRecord::GetucCombineMode () const
{
  if (GetSize() >= offsetof(CCVEdgeRecord, m_ucCombineMode) + sizeof(m_ucCombineMode))
    return m_ucCombineMode;
  else
    return EDGECOMBINE_MULTIPLY;  // Default if not present in record
}






// Class CCVEdgeSampleRecord 


//## Other Operations (inline)
inline void CCVEdgeSampleRecord::AssertValid () const
{
#ifdef _DEBUG
  CRecordBase::AssertValid();

  if (GetRecordType() == CV_EDGESAMPLE_V1)
  {
    ASSERT(m_usSample < 2*2);
  }
  else
  {
    ASSERT(GetRecordType() == CV_EDGESAMPLE_V2 || GetRecordType() == CV_MASKSAMPLE || GetRecordType() == CV_BLACKLEVELMASKSAMPLE);
    ASSERT(m_usSample < 2*17);
  }
#endif
}


inline CCVEdgeSampleRecord* CCVEdgeSampleRecord::CreateInBuffer (char* pBuffer, unsigned short usRecordVersion)
{
  //## begin CCVEdgeSampleRecord::CreateInBuffer%936176376.body preserve=yes
  ASSERT(pBuffer);

  CCVEdgeSampleRecord *pItem = (CCVEdgeSampleRecord *) pBuffer;
  pItem->Create(usRecordVersion);

  return pItem;
  //## end CCVEdgeSampleRecord::CreateInBuffer%936176376.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned short CCVEdgeSampleRecord::GetusConfiguration () const
{
  //## begin CCVEdgeSampleRecord::GetusConfiguration%.get preserve=no
  return m_usConfiguration;
  //## end CCVEdgeSampleRecord::GetusConfiguration%.get
}

inline const unsigned long CCVEdgeSampleRecord::GetulEdgeHandle () const
{
  //## begin CCVEdgeSampleRecord::GetulEdgeHandle%.get preserve=no
  return m_ulEdgeHandle;
  //## end CCVEdgeSampleRecord::GetulEdgeHandle%.get
}

inline const unsigned short CCVEdgeSampleRecord::GetusSample () const
{
  //## begin CCVEdgeSampleRecord::GetusSample%.get preserve=no
  return m_usSample;
  //## end CCVEdgeSampleRecord::GetusSample%.get
}

#if defined(CVPROJ) && GCM_VERSION==4
inline float CCVEdgeSampleRecord::GetfX () const
{
  ASSERT(sizeof(float) == sizeof(long));
  
  unsigned long ulData;
  memcpy(&ulData, &m_fX, sizeof(ulData));
  
  ulData = CONVERT_FROM_LE32(ulData);

  float fRet;
  memcpy(&fRet, &ulData, sizeof(fRet));

  return fRet;
}

inline float CCVEdgeSampleRecord::GetfY () const
{
  ASSERT(sizeof(float) == sizeof(long));
  
  unsigned long ulData;
  memcpy(&ulData, &m_fY, sizeof(ulData));
  
  ulData = CONVERT_FROM_LE32(ulData);

  float fRet;
  memcpy(&fRet, &ulData, sizeof(fRet));

  return fRet;
}

inline float CCVEdgeSampleRecord::GetfLevel () const
{
  //## begin CCVEdgeSampleRecord::GetfLevel%.get preserve=no
  ASSERT(sizeof(float) == sizeof(long));
  
  unsigned long ulData;
  memcpy(&ulData, &m_fLevel, sizeof(ulData));
  
  ulData = CONVERT_FROM_LE32(ulData);

  float fRet;
  memcpy(&fRet, &ulData, sizeof(fRet));

  return fRet;
  //## end CCVEdgeSampleRecord::GetfLevel%.get
}

#else
inline const float& CCVEdgeSampleRecord::GetfX () const
{
  //## begin CCVEdgeSampleRecord::GetfX%.get preserve=no
  return m_fX;
  //## end CCVEdgeSampleRecord::GetfX%.get
}

inline const float& CCVEdgeSampleRecord::GetfY () const
{
  //## begin CCVEdgeSampleRecord::GetfY%.get preserve=no
  return m_fY;
  //## end CCVEdgeSampleRecord::GetfY%.get
}

inline const float& CCVEdgeSampleRecord::GetfLevel () const
{
  //## begin CCVEdgeSampleRecord::GetfLevel%.get preserve=no
  return m_fLevel;
  //## end CCVEdgeSampleRecord::GetfLevel%.get
}
#endif




// Class CCVEdgeAlphaRecord 


//## Other Operations (inline)
inline CCVEdgeAlphaRecord* CCVEdgeAlphaRecord::CreateInBuffer (char* pBuffer)
{
  //## begin CCVEdgeAlphaRecord::CreateInBuffer%936176382.body preserve=yes
  ASSERT(pBuffer);

  CCVEdgeAlphaRecord *pItem = (CCVEdgeAlphaRecord *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CCVEdgeAlphaRecord::CreateInBuffer%936176382.body
}

inline unsigned short CCVEdgeAlphaRecord::GetExtraSize () const
{
  //## begin CCVEdgeAlphaRecord::GetExtraSize%942659954.body preserve=yes
  return m_usNEntries * sizeof(m_usEntry[0]) - sizeof(m_usEntry);
  //## end CCVEdgeAlphaRecord::GetExtraSize%942659954.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned short CCVEdgeAlphaRecord::GetusConfiguration () const
{
  //## begin CCVEdgeAlphaRecord::GetusConfiguration%.get preserve=no
  return m_usConfiguration;
  //## end CCVEdgeAlphaRecord::GetusConfiguration%.get
}

inline const unsigned long CCVEdgeAlphaRecord::GetulEdgeHandle () const
{
  //## begin CCVEdgeAlphaRecord::GetulEdgeHandle%.get preserve=no
  return m_ulEdgeHandle;
  //## end CCVEdgeAlphaRecord::GetulEdgeHandle%.get
}

inline const unsigned short CCVEdgeAlphaRecord::GetusFirstEntry () const
{
  //## begin CCVEdgeAlphaRecord::GetusFirstEntry%.get preserve=no
  return m_usFirstEntry;
  //## end CCVEdgeAlphaRecord::GetusFirstEntry%.get
}

inline const unsigned short CCVEdgeAlphaRecord::GetusNEntries () const
{
  //## begin CCVEdgeAlphaRecord::GetusNEntries%.get preserve=no
  return m_usNEntries;
  //## end CCVEdgeAlphaRecord::GetusNEntries%.get
}

inline const unsigned short CCVEdgeAlphaRecord::GetusStep () const
{
  //## begin CCVEdgeAlphaRecord::GetusStep%.get preserve=no
  return m_usStep;
  //## end CCVEdgeAlphaRecord::GetusStep%.get
}

inline const unsigned short* CCVEdgeAlphaRecord::GetusEntry () const
{
  //## begin CCVEdgeAlphaRecord::GetusEntry%.get preserve=no
  return m_usEntry;
  //## end CCVEdgeAlphaRecord::GetusEntry%.get
}



inline CCVValidHandleRecord* CCVValidHandleRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVValidHandleRecord *pItem = (CCVValidHandleRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

inline unsigned short CCVValidHandleRecord::GetExtraSize () const
{
  return m_usNHandles * sizeof(m_aulHandle[0]) - sizeof(m_aulHandle);
}


inline const unsigned short CCVValidHandleRecord::GetusConfiguration () const
{
  return m_usConfiguration;
}


inline const unsigned short CCVValidHandleRecord::GetusNHandles () const
{
  return m_usNHandles;
}


inline const unsigned long * CCVValidHandleRecord::GetulHandleArray () const
{
  return m_aulHandle;
}


inline const unsigned long CCVValidHandleRecord::GetulHandle (short sIndex) const
{
  ASSERT((unsigned short) sIndex < m_usNHandles);
  return m_aulHandle[sIndex];
}



// Class CCVResetCommand 


//## Other Operations (inline)
inline CCVResetCommand* CCVResetCommand::CreateInBuffer (char* pBuffer)
{
  //## begin CCVResetCommand::CreateInBuffer%936176384.body preserve=yes
  ASSERT(pBuffer);

  CCVResetCommand *pItem = (CCVResetCommand *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CCVResetCommand::CreateInBuffer%936176384.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned short CCVResetCommand::GetusConfiguration () const
{
  //## begin CCVResetCommand::GetusConfiguration%.get preserve=no
  return m_usConfiguration;
  //## end CCVResetCommand::GetusConfiguration%.get
}





// Class CCVGeometryControlPointRecord 


//## Other Operations (inline)
inline CCVGeometryControlPointRecord* CCVGeometryControlPointRecord::CreateInBuffer (char* pBuffer, unsigned short usRecordVersion)
{
  //## begin CCVGeometryControlPointRecord::CreateInBuffer%936176387.body preserve=yes
  ASSERT(pBuffer);

  CCVGeometryControlPointRecord *pItem = (CCVGeometryControlPointRecord *) pBuffer;
  pItem->Create(usRecordVersion);

  return pItem;
  //## end CCVGeometryControlPointRecord::CreateInBuffer%936176387.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned short CCVGeometryControlPointRecord::GetusConfiguration () const
{
  //## begin CCVGeometryControlPointRecord::GetusConfiguration%.get preserve=no
  return m_usConfiguration;
  //## end CCVGeometryControlPointRecord::GetusConfiguration%.get
}

inline const unsigned long CCVGeometryControlPointRecord::GetulGeometryHandle () const
{
  //## begin CCVGeometryControlPointRecord::GetulGeometryHandle%.get preserve=no
  return m_ulGeometryHandle;
  //## end CCVGeometryControlPointRecord::GetulGeometryHandle%.get
}

inline const unsigned short CCVGeometryControlPointRecord::GetusIX () const
{
  //## begin CCVGeometryControlPointRecord::GetusIX%.get preserve=no
  return m_usIX;
  //## end CCVGeometryControlPointRecord::GetusIX%.get
}

inline const unsigned short CCVGeometryControlPointRecord::GetusIY () const
{
  //## begin CCVGeometryControlPointRecord::GetusIY%.get preserve=no
  return m_usIY;
  //## end CCVGeometryControlPointRecord::GetusIY%.get
}

#if defined(CVPROJ) && GCM_VERSION==4
inline double CCVGeometryControlPointRecord::GetdX () const
{
  //## begin CCVGeometryControlPointRecord::GetdX%.get preserve=no

  ASSERT(sizeof(double) == sizeof(long long));
  
  unsigned long long ullData;
  memcpy(&ullData, &m_dX, sizeof(ullData));
  
  ullData = CONVERT_FROM_LE64(ullData);

  double dRet;
  memcpy(&dRet, &ullData, sizeof(dRet));

  return dRet;
  //## end CCVGeometryControlPointRecord::GetdX%.get
}

inline double CCVGeometryControlPointRecord::GetdY () const
{
  //## begin CCVGeometryControlPointRecord::GetdY%.get preserve=no
  ASSERT(sizeof(double) == sizeof(long long));
  
  unsigned long long ullData;
  memcpy(&ullData, &m_dY, sizeof(ullData));
  
  ullData = CONVERT_FROM_LE64(ullData);

  double dRet;
  memcpy(&dRet, &ullData, sizeof(dRet));

  return dRet;
  //## end CCVGeometryControlPointRecord::GetdY%.get
}

#else //defined(CVPROJ) && GCM_VERSION==4

inline const double& CCVGeometryControlPointRecord::GetdX () const
{
  //## begin CCVGeometryControlPointRecord::GetdX%.get preserve=no
  return m_dX;
  //## end CCVGeometryControlPointRecord::GetdX%.get
}

inline const double& CCVGeometryControlPointRecord::GetdY () const
{
  //## begin CCVGeometryControlPointRecord::GetdY%.get preserve=no
  return m_dY;
  //## end CCVGeometryControlPointRecord::GetdY%.get
}
#endif //defined(CVPROJ) && GCM_VERSION==4

// Class CCVDisableRecord 


//## Other Operations (inline)
inline CCVDisableRecord* CCVDisableRecord::CreateInBuffer (char* pBuffer)
{
  //## begin CCVDisableRecord::CreateInBuffer%936176379.body preserve=yes
  ASSERT(pBuffer);

  CCVDisableRecord *pItem = (CCVDisableRecord *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CCVDisableRecord::CreateInBuffer%936176379.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned short CCVDisableRecord::GetusConfiguration () const
{
  //## begin CCVDisableRecord::GetusConfiguration%.get preserve=no
  return m_usConfiguration;
  //## end CCVDisableRecord::GetusConfiguration%.get
}

inline const unsigned long CCVDisableRecord::GetulDisableMask () const
{
  //## begin CCVDisableRecord::GetulDisableMask%.get preserve=no
  return m_ulDisableMask;
  //## end CCVDisableRecord::GetulDisableMask%.get
}





// Class CCVRestoreConfigurationRecord 


//## Other Operations (inline)
inline CCVRestoreConfigurationRecord* CCVRestoreConfigurationRecord::CreateInBuffer (char* pBuffer)
{
  //## begin CCVRestoreConfigurationRecord::CreateInBuffer%943537004.body preserve=yes
  ASSERT(pBuffer);

  CCVRestoreConfigurationRecord *pItem = (CCVRestoreConfigurationRecord *) pBuffer;
  pItem->Create();

  return pItem;
  //## end CCVRestoreConfigurationRecord::CreateInBuffer%943537004.body
}

//## Get and Set Operations for Class Attributes (inline)

inline const unsigned short CCVRestoreConfigurationRecord::GetusConfiguration () const
{
  //## begin CCVRestoreConfigurationRecord::GetusConfiguration%.get preserve=no
  return m_usConfiguration;
  //## end CCVRestoreConfigurationRecord::GetusConfiguration%.get
}





//## begin module.epilog preserve=yes

class CCVContrastRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CCVContrastRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set (unsigned short usConfiguration, unsigned char ucLightLevel, unsigned char ucValue);

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      const unsigned short GetusConfiguration () const;
      const unsigned char GetucLightLevel () const {return m_ucLightLevel; };
      const unsigned char GetucValue () const { return m_ucValue; };

  private:  //## implementation
      CConvLE<unsigned short> m_usConfiguration;
      unsigned char m_ucLightLevel;
      unsigned char m_ucValue;
};

inline CCVContrastRecord* CCVContrastRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVContrastRecord *pItem = (CCVContrastRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

inline const unsigned short CCVContrastRecord::GetusConfiguration () const
{
  return m_usConfiguration;
}

class CCVBrightnessRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CCVBrightnessRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set (unsigned short usConfiguration, unsigned char ucLightLevel, unsigned char ucValue);

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      const unsigned short GetusConfiguration () const;
      const unsigned char GetucLightLevel () const {return m_ucLightLevel; };
      const unsigned char GetucValue () const { return m_ucValue; };

  private:  //## implementation
      CConvLE<unsigned short> m_usConfiguration;
      unsigned char m_ucLightLevel;
      unsigned char m_ucValue;
};

inline CCVBrightnessRecord* CCVBrightnessRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVBrightnessRecord *pItem = (CCVBrightnessRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

inline const unsigned short CCVBrightnessRecord::GetusConfiguration () const
{
  return m_usConfiguration;
}


class CCVHueRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CCVHueRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set (unsigned short usConfiguration, unsigned char ucLightLevel, unsigned char ucValue);

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      const unsigned short GetusConfiguration () const;
      const unsigned char GetucLightLevel () const;
      const unsigned char GetucValue () const { return m_ucValue; };

  private:  //## implementation
      CConvLE<unsigned short> m_usConfiguration;
      unsigned char m_ucLightLevel;
      unsigned char m_ucValue;
};


inline CCVHueRecord* CCVHueRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVHueRecord *pItem = (CCVHueRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


class CCVSaturationRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CCVSaturationRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set (unsigned short usConfiguration, unsigned char ucLightLevel, unsigned char ucValue);

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      const unsigned short GetusConfiguration () const;
      const unsigned char GetucLightLevel () const;
      const unsigned char GetucValue () const { return m_ucValue; };

  private:  //## implementation
      CConvLE<unsigned short> m_usConfiguration;
      unsigned char m_ucLightLevel;
      unsigned char m_ucValue;
};


inline CCVSaturationRecord* CCVSaturationRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVSaturationRecord *pItem = (CCVSaturationRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


class CCVPhaseRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CCVPhaseRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set (unsigned short usConfiguration, unsigned short usValue);

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      const unsigned short GetusConfiguration () const;
      const unsigned short GetusValue () const { return m_usValue; };


  private:  //## implementation
      CConvLE<unsigned short> m_usConfiguration;
      CConvLE<unsigned short> m_usValue;
};


inline CCVPhaseRecord* CCVPhaseRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVPhaseRecord *pItem = (CCVPhaseRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


class CCVFrequencyRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CCVFrequencyRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set (unsigned short usConfiguration, unsigned short usValue);

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      const unsigned short GetusConfiguration () const;
      const unsigned short GetusValue () const { return m_usValue; };

  private:  //## implementation
      CConvLE<unsigned short> m_usConfiguration;
      CConvLE<unsigned short> m_usValue;
};


inline CCVFrequencyRecord* CCVFrequencyRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVFrequencyRecord *pItem = (CCVFrequencyRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


class CCVHorPositionRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CCVHorPositionRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set (unsigned short usConfiguration, unsigned short usValue);

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      const unsigned short GetusConfiguration () const;
      const unsigned short GetusValue () const { return m_usValue; };

  private:  //## implementation
      CConvLE<unsigned short> m_usConfiguration;
      CConvLE<unsigned short> m_usValue;
};


inline CCVHorPositionRecord* CCVHorPositionRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVHorPositionRecord *pItem = (CCVHorPositionRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


class CCVVertPositionRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CCVVertPositionRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set (unsigned short usConfiguration, unsigned short usValue);

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      const unsigned short GetusConfiguration () const;
      const unsigned short GetusValue () const { return m_usValue; };

  private:  //## implementation
      CConvLE<unsigned short> m_usConfiguration;
      CConvLE<unsigned short> m_usValue;
};


inline CCVVertPositionRecord* CCVVertPositionRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVVertPositionRecord *pItem = (CCVVertPositionRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


class CCVSourceRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CCVSourceRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set (unsigned short usConfiguration, char cValue);

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      const unsigned short GetusConfiguration () const { return m_usConfiguration;};
      const char GetcValue () const { return m_cValue; };

  private:  //## implementation
      CConvLE<unsigned short> m_usConfiguration;
      char m_cValue;
};


inline CCVSourceRecord* CCVSourceRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVSourceRecord *pItem = (CCVSourceRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


class CCVStandbyRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CCVStandbyRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set (unsigned short usConfiguration, char cValue);

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      const unsigned short GetusConfiguration () const { return m_usConfiguration;};
      const char GetcValue () const { return m_cValue; };

  private:  //## implementation
      CConvLE<unsigned short> m_usConfiguration;
      char m_cValue;
};


inline CCVStandbyRecord* CCVStandbyRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVStandbyRecord *pItem = (CCVStandbyRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

class CCVAutoSetupRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CCVAutoSetupRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set ();

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

  private:  //## implementation
};


inline CCVAutoSetupRecord* CCVAutoSetupRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVAutoSetupRecord *pItem = (CCVAutoSetupRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


//Version 2 of autosetup
class CCVAutoSetupRecord_V2 : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CCVAutoSetupRecord_V2* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set (unsigned short usConfiguration);

      //	Initialize data record.
      void Create ();

      const unsigned short GetusConfiguration() const {return m_usConfiguration;};

    //## Get and Set Operations for Class Attributes (generated)

  private:  //## implementation
    CConvLE<unsigned short> m_usConfiguration;
};


inline CCVAutoSetupRecord_V2* CCVAutoSetupRecord_V2::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVAutoSetupRecord_V2 *pItem = (CCVAutoSetupRecord_V2 *) pBuffer;
  pItem->Create();

  return pItem;
}


class CCVOrientationRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CCVOrientationRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set (unsigned short usConfiguration, char cValue);

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      const unsigned short GetusConfiguration () const { return m_usConfiguration;};
      const char GetcValue () const { return m_cValue; };

  private:  //## implementation
      CConvLE<unsigned short> m_usConfiguration;
      char m_cValue;
};


inline CCVOrientationRecord* CCVOrientationRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVOrientationRecord *pItem = (CCVOrientationRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

class CCVUpscaleRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CCVUpscaleRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set (unsigned short usConfiguration, char cValue);

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      const unsigned short GetusConfiguration () const;
      const char GetcValue () const { return m_cValue; };

  private:  //## implementation
      CConvLE<unsigned short> m_usConfiguration;
      char m_cValue;
};


inline CCVUpscaleRecord* CCVUpscaleRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVUpscaleRecord *pItem = (CCVUpscaleRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

class CCVSourceScanRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CCVSourceScanRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set (unsigned short usConfiguration, char cValue);

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      const unsigned short GetusConfiguration () const { return m_usConfiguration;};
      const char GetcValue () const { return m_cValue; };

  private:  //## implementation
      CConvLE<unsigned short> m_usConfiguration;
      char m_cValue;
};

//inline CCVSourceScanRecord::CreateInBuffer causes the 386ex linker to crash
//moved to CVprotocolAppRecords2.cpp


class CCVVideoModeRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CCVVideoModeRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set (unsigned short usConfiguration, char cValue);

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      const unsigned short GetusConfiguration () const;
      const char GetcValue () const { return m_cValue; };

  private:  //## implementation
      CConvLE<unsigned short> m_usConfiguration;
      char m_cValue;
};


inline CCVVideoModeRecord* CCVVideoModeRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVVideoModeRecord *pItem = (CCVVideoModeRecord *) pBuffer;
  pItem->Create();

  return pItem;
}



class CCVAutoContrastRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CCVAutoContrastRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set (unsigned short usConfiguration, char cValue);

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      const unsigned short GetusConfiguration () const;
      const char GetcValue () const { return m_cValue; };

  private:  //## implementation
      CConvLE<unsigned short> m_usConfiguration;
      char m_cValue;
};


inline CCVAutoContrastRecord* CCVAutoContrastRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVAutoContrastRecord *pItem = (CCVAutoContrastRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


class CCVLockSetupRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CCVLockSetupRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set (unsigned short usConfiguration, char cValue);

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      const unsigned short GetusConfiguration () const;
      const char GetcValue () const { return m_cValue; };

  private:  //## implementation
      CConvLE<unsigned short> m_usConfiguration;
      char m_cValue;
};


inline CCVLockSetupRecord* CCVLockSetupRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVLockSetupRecord *pItem = (CCVLockSetupRecord *) pBuffer;
  pItem->Create();

  return pItem;
}
inline const unsigned short CCVLockSetupRecord::GetusConfiguration() const
{
  return m_usConfiguration;
}


class CCVLampStateRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CCVLampStateRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set (char cLampState, short sLampTime);

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

      const char GetcLampState () const { return m_cLampState; };
      const short GetsLampTime () const { return m_sLampTime; };

  private:  //## implementation
      char m_cLampState;
      CConvLE<short> m_sLampTime;
};


inline void CCVLampStateRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2, CV_LAMPSTATE);
}



inline CCVLampStateRecord* CCVLampStateRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVLampStateRecord *pItem = (CCVLampStateRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


inline void CCVLampStateRecord::Set (char cLampState, short sLampTime)
{
  AssertValid();
  m_cLampState = cLampState;
  m_sLampTime = sLampTime;
}


class CDavisSoftwareUpdateRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CDavisSoftwareUpdateRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set ();

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

  private:  //## implementation
};


inline CDavisSoftwareUpdateRecord* CDavisSoftwareUpdateRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CDavisSoftwareUpdateRecord *pItem = (CDavisSoftwareUpdateRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


class CDavisCommandRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      static CDavisCommandRecord* CreateInBuffer (char* pBuffer);
      void Set (unsigned short usSequenceNo, unsigned short usBlockSize, const unsigned char *pData);
      void Create ();
      const unsigned char* GetDataPtr () const;
      const unsigned short GetusSequenceNo () const;
      const unsigned short GetusBlockSize () const;

  private:
      CConvLE<unsigned short> m_usSequenceNo;
      CConvLE<unsigned short> m_usBlockSize;
};


inline CDavisCommandRecord* CDavisCommandRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CDavisCommandRecord *pItem = (CDavisCommandRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


inline const unsigned char* CDavisCommandRecord::GetDataPtr () const
{
  return (unsigned char *) &m_usBlockSize + sizeof(m_usBlockSize);
}

inline const unsigned short CDavisCommandRecord::GetusSequenceNo () const
{
  return m_usSequenceNo;
}

inline const unsigned short CDavisCommandRecord::GetusBlockSize () const
{
  return m_usBlockSize;
}

class CPDSoftwareUpdateRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CPDSoftwareUpdateRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set ();

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

  private:  //## implementation
};


inline CPDSoftwareUpdateRecord* CPDSoftwareUpdateRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CPDSoftwareUpdateRecord *pItem = (CPDSoftwareUpdateRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

class CPDCommandRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      static CPDCommandRecord* CreateInBuffer (char* pBuffer);
      void Set (unsigned short usSequenceNo, unsigned short usBlockSize, unsigned short usCheckSum, const unsigned char *pData);
      void Create ();
      const unsigned char* GetDataPtr () const;
      const unsigned short GetusSequenceNo () const;
      const unsigned short GetusBlockSize () const;
      const unsigned short GetusCheckSum() const;

  private:
      CConvLE<unsigned short> m_usSequenceNo;
      CConvLE<unsigned short> m_usCheckSum;
      CConvLE<unsigned short> m_usBlockSize;
};


inline CPDCommandRecord* CPDCommandRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CPDCommandRecord *pItem = (CPDCommandRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


inline const unsigned char* CPDCommandRecord::GetDataPtr () const
{
  return (unsigned char *) &m_usBlockSize + sizeof(m_usBlockSize);
}

inline const unsigned short CPDCommandRecord::GetusSequenceNo () const
{
  return m_usSequenceNo;
}

inline const unsigned short CPDCommandRecord::GetusBlockSize () const
{
  return m_usBlockSize;
}

inline const unsigned short CPDCommandRecord::GetusCheckSum () const
{
  return m_usCheckSum;
}

class CPDSoftwareEndRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      //	Create record in an existing buffer
      static CPDSoftwareEndRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set ();

      //	Initialize data record.
      void Create ();

    //## Get and Set Operations for Class Attributes (generated)

  private:  //## implementation
};


inline CPDSoftwareEndRecord* CPDSoftwareEndRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CPDSoftwareEndRecord *pItem = (CPDSoftwareEndRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

class CFilterCoeffRecord : public CRecordBase  //## Inherits: <unnamed>
{
  public:
      static CFilterCoeffRecord* CreateInBuffer (char* pBuffer);
      void Set (const unsigned char *pucH, const unsigned char *pucV, const unsigned char *pucVH, const unsigned char *pucVS);
      void Create ();
      const unsigned char GetH (int i) const;
      const unsigned char GetV (int i) const;
      const unsigned char GetVH (int i) const;
      const unsigned char GetVS (int i) const;

  private:
      unsigned char m_ucH[8];
      unsigned char m_ucV[8];
      unsigned char m_ucVH[8];
      unsigned char m_ucVS[8];
};


inline CFilterCoeffRecord* CFilterCoeffRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CFilterCoeffRecord *pItem = (CFilterCoeffRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


inline const unsigned char CFilterCoeffRecord::GetH (int i) const
{
  ASSERT((unsigned) i < 8);
  return m_ucH[i];
}

inline const unsigned char CFilterCoeffRecord::GetV (int i) const
{
  ASSERT((unsigned) i < 8);
  return m_ucV[i];
}

inline const unsigned char CFilterCoeffRecord::GetVH (int i) const
{
  ASSERT((unsigned) i < 8);
  return m_ucVH[i];
}

inline const unsigned char CFilterCoeffRecord::GetVS (int i) const
{
  ASSERT((unsigned) i < 8);
  return m_ucVS[i];
}


class CResolutionRecord : public CRecordBase
{
public:
  //	Create record in an existing buffer
  inline static CResolutionRecord* CreateInBuffer (char* pBuffer);

  //	Set data fields of record
  void Set(unsigned short usConfiguration, unsigned short usHres, unsigned short usVres);

  //	Initialize data record.
  void Create ();

  const unsigned short GetusConfiguration () const { return m_usConfiguration; };

  // Get horizontal resolution (columns)
  const unsigned short GetusHres()  { return m_usHres; };

  // Get vertical resolution (lines/rows)
  const unsigned short GetusVres()  { return m_usVres; };

private:
  CConvLE<unsigned short> m_usConfiguration;
  CConvLE<unsigned short> m_usHres;
  CConvLE<unsigned short> m_usVres;
};


inline CResolutionRecord* CResolutionRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CResolutionRecord *pItem = (CResolutionRecord *) pBuffer;
  pItem->Create();

  return pItem;
}




class CFrequencyValRecord : public CRecordBase
{
  // Hold the frequency (htot) value as an absolute number
public:
  //	Create record in an existing buffer
  inline static CFrequencyValRecord* CreateInBuffer (char* pBuffer);

  //	Set data fields of record
  void Set(unsigned short usConfiguration, unsigned short usFreqVal);

  //	Initialize data record.
  void Create ();

  const unsigned short GetusConfiguration () const { return m_usConfiguration; };

  // Get frequency value
  const unsigned short GetusFreqVal()  { return m_usFreqVal; };

private:
  CConvLE<unsigned short> m_usConfiguration;
  CConvLE<unsigned short> m_usFreqVal;
};


inline CFrequencyValRecord* CFrequencyValRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CFrequencyValRecord *pItem = (CFrequencyValRecord *) pBuffer;
  pItem->Create();

  return pItem;
}



class CPhaseValRecord : public CRecordBase
{
  // Hold the phase value
public:
  //	Create record in an existing buffer
  inline static CPhaseValRecord* CreateInBuffer (char* pBuffer);

  //	Set data fields of record
  void Set(unsigned short usConfiguration, unsigned short usPhaseVal, unsigned short usPhaseValMax);

  //	Initialize data record.
  void Create ();

  const unsigned short GetusConfiguration () const  { return m_usConfiguration; };

  // Get phase value
  const unsigned short GetusPhaseVal()  { return m_usPhaseVal; };
  inline const unsigned short GetusValueMax ();

private:
  CConvLE<unsigned short> m_usConfiguration;
  CConvLE<unsigned short> m_usPhaseVal; // 0..m_usPhaseValMax
  CConvLE<unsigned short> m_usPhaseValMax;

};


inline CPhaseValRecord* CPhaseValRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CPhaseValRecord *pItem = (CPhaseValRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

inline unsigned short const CPhaseValRecord::GetusValueMax()
{
  if (GetSize() >= offsetof(CPhaseValRecord, m_usPhaseValMax) + sizeof(m_usPhaseValMax))
    return m_usPhaseValMax;
  else
    return 31;  // Compatibility value when max value not in message (old format)
}


class CVertPosValRecord : public CRecordBase
{
  // Stores the vertical posistion. The value represents the Vertical Back Porch (VBP)
  // expressed in number of lines
public:
  //	Create record in an existing buffer
  inline static CVertPosValRecord* CreateInBuffer (char* pBuffer);

  //	Set data fields of record
  void Set(unsigned short usConfiguration, unsigned short usVertPosVal);

  //	Initialize data record.
  void Create ();

  const unsigned short GetusConfiguration () const { return m_usConfiguration; };

  // Get vertical position
  const unsigned short GetusVertPosVal()  { return m_usVertPosVal; };

private:
  CConvLE<unsigned short> m_usConfiguration;
  CConvLE<unsigned short> m_usVertPosVal;    // VBP unit: Number of lines
};


inline CVertPosValRecord* CVertPosValRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CVertPosValRecord *pItem = (CVertPosValRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


class CHoriPosValRecord : public CRecordBase
{
  // Stores the horizontal posistion. The value represents the Horizontal Back Porch (HBP)
  // expressed in number of pixel clocks
public:
  //	Create record in an existing buffer
  inline static CHoriPosValRecord* CreateInBuffer (char* pBuffer);

  //	Set data fields of record
  void Set(unsigned short usConfiguration, unsigned short usHoriPosVal);

  //	Initialize data record.
  void Create ();

  const unsigned short GetusConfiguration () const { return m_usConfiguration; };

  // Get horizontal posisition
  const unsigned short GetusHoriPosVal()  { return m_usHoriPosVal; };

private:
  CConvLE<unsigned short> m_usConfiguration;
  CConvLE<unsigned short> m_usHoriPosVal;    // HBP unit: Number of pixel clocks
};


inline CHoriPosValRecord* CHoriPosValRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CHoriPosValRecord *pItem = (CHoriPosValRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


class CPllValRecord : public CRecordBase
{
public:
  //	Create record in an existing buffer
  inline static CPllValRecord* CreateInBuffer (char* pBuffer);

  //	Set data fields of record
  void Set(unsigned short usConfiguration, unsigned short usPllVal);

  //	Initialize data record.
  void Create ();

  const unsigned short GetusConfiguration () const;

  const unsigned short GetusPllVal()  { return m_usPllVal; };

private:
  CConvLE<unsigned short> m_usConfiguration;
  CConvLE<unsigned short> m_usPllVal;
};


inline CPllValRecord* CPllValRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CPllValRecord *pItem = (CPllValRecord *) pBuffer;
  pItem->Create();

  return pItem;
}
inline const unsigned short CPllValRecord::GetusConfiguration() const
{
  return m_usConfiguration;
}


class CHsyncTriggerRecord : public CRecordBase
{
public:
  //	Create record in an existing buffer
  inline static CHsyncTriggerRecord* CreateInBuffer (char* pBuffer);

  //	Set data fields of record
  void Set(unsigned short usConfiguration, unsigned short usHsyncTrigger);

  //	Initialize data record.
  void Create ();

  const unsigned short GetusConfiguration () const;

  const unsigned short GetusHsyncTrigger()  { return m_usHsyncTrigger; };

private:
  CConvLE<unsigned short> m_usConfiguration;
  CConvLE<unsigned short> m_usHsyncTrigger;
};


inline CHsyncTriggerRecord* CHsyncTriggerRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CHsyncTriggerRecord *pItem = (CHsyncTriggerRecord *) pBuffer;
  pItem->Create();

  return pItem;
}



class CAdFilterRRecord : public CRecordBase
{
public:
  //	Create record in an existing buffer
  inline static CAdFilterRRecord* CreateInBuffer (char* pBuffer);

  //	Set data fields of record
  void Set(unsigned short usConfiguration, unsigned short usAdFilterR);

  //	Initialize data record.
  void Create ();

  const unsigned short GetusConfiguration () const;

  const unsigned short GetusAdFilterR()  { return m_usAdFilterR; };

private:
  CConvLE<unsigned short> m_usConfiguration;
  CConvLE<unsigned short> m_usAdFilterR;
};


inline CAdFilterRRecord* CAdFilterRRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CAdFilterRRecord *pItem = (CAdFilterRRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


class CAdFilterCRecord : public CRecordBase
{
public:
  //	Create record in an existing buffer
  inline static CAdFilterCRecord* CreateInBuffer (char* pBuffer);

  //	Set data fields of record
  void Set(unsigned short usConfiguration, unsigned short usAdFilterC);

  //	Initialize data record.
  void Create ();

  const unsigned short GetusConfiguration () const;

  const unsigned short GetusAdFilterC()  { return m_usAdFilterC; };

private:
  CConvLE<unsigned short> m_usConfiguration;
  CConvLE<unsigned short> m_usAdFilterC;
};


inline CAdFilterCRecord* CAdFilterCRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CAdFilterCRecord *pItem = (CAdFilterCRecord *) pBuffer;
  pItem->Create();

  return pItem;
}



// Defines related to the class CPrivateSetupDataRecord 
#define SIZE_OF_PRIVATE_SETUP_DATA   100    // Number of bytes to store

class CPrivateSetupDataRecord : public CRecordBase
{
  // Stores different data needed for setup of the hardware. Only the driver
  // software should interpret these data 
  
public:
  //	Create record in an existing buffer
  inline static CPrivateSetupDataRecord* CreateInBuffer (char* pBuffer);

  //  Set data fields of record
  //  Arguments:
  //  usStart  : Index for where the data will be copied to
  //             Value range 0..SIZE_OF_AD_DATA-1
  //  pData    : Pointer to the data which will be copied
  //  usCount  : Number of bytes to copy
  //  usHres   :
  //  usVres   : Optional parameters, will be used as part of record ID in case
  //             we want to store one AD data record for each resolution
  //
  void Set(unsigned short usConfiguration, unsigned short usStart, unsigned char* pData,
           unsigned char usCount, unsigned short usHres = 0, unsigned short usVres = 0);

  //	Initialize data record.
  void Create ();

  const unsigned short GetusConfiguration () const;

  // Get pointer to buffer with the data
  const unsigned char* GetData() const { return m_pData; };

  const unsigned short GetusHres() const { return m_usHres;}; 
  const unsigned short GetusVres() const { return m_usVres;};

private:
  CConvLE<unsigned short> m_usConfiguration;
  unsigned char m_pData[SIZE_OF_PRIVATE_SETUP_DATA];
  CConvLE<unsigned short> m_usHres;
  CConvLE<unsigned short> m_usVres;
};


inline CPrivateSetupDataRecord* CPrivateSetupDataRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CPrivateSetupDataRecord *pItem = (CPrivateSetupDataRecord *) pBuffer;
  pItem->Create();

  return pItem;
}
inline const unsigned short CPrivateSetupDataRecord::GetusConfiguration() const
{
  return m_usConfiguration;
}


class CUtmSignalInfoRecord : public CRecordBase
{
  // Stores sampled properties of the Utm input signal
  
public:
  //	Create record in an existing buffer
  inline static CUtmSignalInfoRecord* CreateInBuffer (char* pBuffer);
  //
  void Set(unsigned short usConfiguration, unsigned short usSource,     
	  unsigned long ulHfreq, unsigned short usVfreq, 
	  unsigned short usSyncPolarity, unsigned short usHsyncTime, unsigned short usHFP, 
    unsigned short usVsyncTime, unsigned short usVFP, unsigned short usVtot, unsigned short usSyncType);

  //	Initialize data record.
  void Create ();

  const unsigned short GetusConfiguration () const;
  const unsigned short GetusSource () { return m_usSource;}
  const unsigned long GetulHfreq() { return m_ulHfreq;}
  const unsigned short GetusVfreq() { return m_usVfreq;}
  const unsigned short GetusSyncPolarity() { return m_usSyncPolarity;}
  const unsigned short GetusHsyncTime() { return m_usHsyncTime; }
  const unsigned short GetusHFP() { return m_usHFP; }
  const unsigned short GetusVsyncTime() { return m_usVsyncTime; }
  const unsigned short GetusVFP() { return m_usVFP; }
  const unsigned short GetusVtot() { return m_usVtot; }
  const unsigned short GetSyncType() { return m_usSyncType; };
  
  const bool IsVsyncPosPol() { return !!(m_usSyncPolarity & SYNC_POL_VSYNC_POS); };
  const bool IsHsyncPosPol() { return !!(m_usSyncPolarity & SYNC_POL_HSYNC_POS); };

private:
  CConvLE<unsigned short> m_usConfiguration;
  CConvLE<unsigned short> m_usSource;
  CConvLE<unsigned long> m_ulHfreq;
  CConvLE<unsigned short> m_usVfreq;
  CConvLE<unsigned short> m_usSyncPolarity;
  CConvLE<unsigned short> m_usHsyncTime;   // Length of sync time in pixels
  CConvLE<unsigned short> m_usHFP;         // Length of horizontal front porch (calculated)
  CConvLE<unsigned short> m_usVsyncTime;   // Length of vsync pulse in pixles
  CConvLE<unsigned short> m_usVFP;         // Length of vertical front porch (calculated)
  CConvLE<unsigned short> m_usVtot;        // Total number of lines between two hsync pulses
  CConvLE<unsigned short> m_usSyncType;    // Active sync type, defined in CommandTypes.h
};

inline CUtmSignalInfoRecord* CUtmSignalInfoRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CUtmSignalInfoRecord *pItem = (CUtmSignalInfoRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

inline const unsigned short CUtmSignalInfoRecord::GetusConfiguration() const
{
  return m_usConfiguration;
}


class CHresDefaultRecord : public CRecordBase
{
  // Set the default HRES if several possibilities, e.g. 1280x1024 and 1365x1024
  
public:
  //	Create record in an existing buffer
  inline static CHresDefaultRecord* CreateInBuffer (char* pBuffer);
  //
  void Set(unsigned short usConfiguration, unsigned short usVres,     
	  unsigned short usHres);

  //	Initialize data record.
  void Create ();

  const unsigned short GetusVres() const { return m_usVres; };
  const unsigned short GetusHres() const { return m_usHres; };


private:
  CConvLE<unsigned short> m_usConfiguration;
  CConvLE<unsigned short> m_usVres;

  CConvLE<unsigned short> m_usHres;
};

inline CHresDefaultRecord* CHresDefaultRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CHresDefaultRecord *pItem = (CHresDefaultRecord *) pBuffer;
  pItem->Create();

  return pItem;
}



class CSyncTypeRecord : public CRecordBase
{
  // Sync type record. The types are defined in CommandTypes.h

public:
  //	Create record in an existing buffer
  inline static CSyncTypeRecord* CreateInBuffer (char* pBuffer);
  void Set(unsigned short usConfiguration, unsigned short usSyncType);

  //	Initialize data record.
  void Create ();

  const unsigned short GetusSyncType() const { return m_usSyncType; };

private:
  CConvLE<unsigned short> m_usConfiguration;
  CConvLE<unsigned short> m_usSyncType;
};

inline CSyncTypeRecord* CSyncTypeRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CSyncTypeRecord *pItem = (CSyncTypeRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

class CCoastCtrlRecord : public CRecordBase
{
  // Coast control record
  // May be used for both setting and reading coast control
  // 

public:
  //	Create record in an existing buffer
  inline static CCoastCtrlRecord* CreateInBuffer (char* pBuffer);
  // bCoastAuto = true : bCoastActive ignored/report current coast state
  // bCoastAuto = false: force Coast according to bCoastActive
  void Set(unsigned short usConfiguration, bool bCoastAuto, bool bCoastActive);

  //	Initialize data record.
  void Create ();

  const bool GetbCoastAuto() const { return m_bCoastAuto; };
  const bool GetbCoastActive() const { return m_bCoastActive; };
  inline const unsigned short GetusConfiguration();

private:
  CConvLE<unsigned short> m_usConfiguration;
  bool m_bCoastAuto;
  bool m_bCoastActive;
};

inline CCoastCtrlRecord* CCoastCtrlRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCoastCtrlRecord *pItem = (CCoastCtrlRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

inline const unsigned short CCoastCtrlRecord::GetusConfiguration()
{
  return m_usConfiguration;
}


class CEDIDCtrlRecord : public CRecordBase
{
  // EDID control record
  // May be used for both setting and reading EDID options
  // 

public:
  //	Create record in an existing buffer
  inline static CEDIDCtrlRecord* CreateInBuffer (char* pBuffer);

  void Set(unsigned short usConfiguration, unsigned char usIgnoreProjector, bool bEDIDauto, unsigned short usEDIDtype);
  void Set(unsigned short usConfiguration, bool bIgnoreProjector, bool bEDIDauto, unsigned short usEDIDtype);

  //	Initialize data record.
  void Create ();

  const unsigned char GetusIgnoreProjector() const { return m_ucIgnoreProjector; };
  const bool GetbIgnoreProjector() const { return m_ucIgnoreProjector?true:false; };
  const bool GetbEDIDauto() const { return m_bEDIDauto; };
  const unsigned short GetusEDIDtype() const { return m_usEDIDtype; };
  inline const unsigned short GetusConfiguration();

private:
  CConvLE<unsigned short> m_usConfiguration;
  unsigned char m_ucIgnoreProjector;
  bool m_bEDIDauto;
  CConvLE<unsigned short> m_usEDIDtype;
};

inline CEDIDCtrlRecord* CEDIDCtrlRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CEDIDCtrlRecord *pItem = (CEDIDCtrlRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

inline const unsigned short CEDIDCtrlRecord::GetusConfiguration()
{
  return m_usConfiguration;
}

class COutputCtrlRecord : public CRecordBase
{

public:
  //	Create record in an existing buffer
  inline static COutputCtrlRecord* CreateInBuffer (char* pBuffer);

  void Set(unsigned short usConfiguration, unsigned short usOutputState);

  //	Initialize data record.
  void Create ();

  const unsigned short GetusOutputState() const { return m_usOutputState; };
// #if 0
  const bool IsDataEnabled() { return !!(m_usOutputState & OUTPUT_ENABLE_DATA); };
  const bool IsSyncEnabled() { return !!(m_usOutputState & OUTPUT_ENABLE_SYNC); };
  const bool IsDDV5VEnabled() { return !!(m_usOutputState & OUTPUT_ENABLE_DDC5V); };  
// #endif

  inline const unsigned short GetusConfiguration();

private:
  CConvLE<unsigned short> m_usConfiguration;
  CConvLE<unsigned short> m_usOutputState;
};

inline COutputCtrlRecord* COutputCtrlRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  COutputCtrlRecord *pItem = (COutputCtrlRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

inline const unsigned short COutputCtrlRecord::GetusConfiguration()
{
  return m_usConfiguration;
}


class CGenericOpRecord : public CRecordBase
{

public:
  //	Create record in an existing buffer
  inline static CGenericOpRecord* CreateInBuffer (char* pBuffer, bool bCommand = false);

  // usOperationId = Operation identifier as specified in PWConfig output file ConfigEnum.h
  // ulOperationId = Operation target as specified in PWConfig output file ConfigEnum.h
  // ulOperationValue = Value to set
  void Set(unsigned short usConfiguration, unsigned short usOperationId, unsigned long ulOperationTarget, 
           unsigned long ulValue);

  //	Initialize data record.
  void Create ();

  void CreateCommand();

  inline const unsigned short GetusConfiguration();
  unsigned short GetusOperationId() { return m_usOperationId; };
  unsigned long GetulOperationTarget() { return m_ulOperationTarget; };
  unsigned long GetulValue() { return m_ulValue; };

private:
  CConvLE<unsigned short> m_usConfiguration;   // Part of id
  CConvLE<unsigned short> m_usOperationId;     // Part of id
  long m_ulOperationTarget;            // Part of id
  long m_ulValue;
};

inline CGenericOpRecord* CGenericOpRecord::CreateInBuffer (char* pBuffer, bool bCommand)
{
  ASSERT(pBuffer);

  CGenericOpRecord *pItem = (CGenericOpRecord *) pBuffer;

  if(bCommand)
  {
	  pItem->CreateCommand();
  }
  else
  {
	  pItem->Create();
  }  

  return pItem;
}

inline const unsigned short CGenericOpRecord::GetusConfiguration()
{
  return m_usConfiguration;
}



class CGenericReqRecord : public CRecordBase
{

public:
  //	Create record in an existing buffer
  inline static CGenericReqRecord* CreateInBuffer (char* pBuffer);

  // usOperationId = Operation identifier as specified in PWConfig output file ConfigEnum.h
  // ulOperationId = Operation target as specified in PWConfig output file ConfigEnum.h
  // ulOperationValue = Return value
  void Set(unsigned short usOperationId, unsigned long ulOperationTarget,unsigned long ulValue);

  //	Initialize data record.
  void Create();

  unsigned short GetusOperationId() { return m_usOperationId; };
  unsigned long GetulOperationTarget() { return m_ulOperationTarget; };
  unsigned long GetulValue() { return m_ulValue; };
  void SetValue(unsigned long ulValue) { m_ulValue = ulValue; };

private:
  CConvLE<unsigned short> m_usOperationId;
  CConvLE<unsigned long> m_ulOperationTarget;
  CConvLE<unsigned long> m_ulValue;
};

inline CGenericReqRecord* CGenericReqRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CGenericReqRecord *pItem = (CGenericReqRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


class CGenericSetVarRecord : public CRecordBase
{

public:
  //	Create record in an existing buffer
  inline static CGenericSetVarRecord* CreateInBuffer (char* pBuffer);

  // ucVarType = Variable type, vt_USER or vt_SYSTEM as defined in ??.h
  // usVar = Variable to change
  // usValue = Value to set
  void Set(unsigned short usConfiguration, unsigned char ucVarType, unsigned short usVar, 
           unsigned short usValue);

  //	Initialize data record.
  void Create ();

  inline const unsigned short GetusConfiguration();
  unsigned char GetucVarType() { return m_ucVarType; };
  unsigned short GetusVar() { return m_usVar; };
  unsigned short GetusValue() { return m_usValue; };

private:
  CConvLE<unsigned short> m_usConfiguration;   // Part of id
  unsigned char m_ucVarType;          // Part of id
  CConvLE<unsigned short> m_usVar;             // Part of id
  CConvLE<unsigned short> m_usValue;
};

inline CGenericSetVarRecord* CGenericSetVarRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CGenericSetVarRecord *pItem = (CGenericSetVarRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

inline const unsigned short CGenericSetVarRecord::GetusConfiguration()
{
  return m_usConfiguration;
}



class CGenericReqVarRecord : public CRecordBase
{

public:
  //	Create record in an existing buffer
  inline static CGenericReqVarRecord* CreateInBuffer (char* pBuffer);

  // ucVarType = Variable type, vt_USER or vt_SYSTEM as defined in ??.h
  // usVar = Variable to change
  // usValue = Value to set
  void Set(unsigned char ucVarType, unsigned short usVar, unsigned short usValue);


  //	Initialize data record.
  void Create ();

  unsigned char GetucVarType() { return m_ucVarType; };
  unsigned short GetusVar() { return m_usVar; };
  unsigned short GetusValue() { return m_usValue; };
  void SetValue(unsigned short usValue) { m_usValue = usValue; };

private:
  unsigned char m_ucVarType;
  CConvLE<unsigned short> m_usVar;
  CConvLE<unsigned short> m_usValue;
};

inline CGenericReqVarRecord* CGenericReqVarRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CGenericReqVarRecord *pItem = (CGenericReqVarRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


class CCommStatRecord : public CRecordBase
{
public:
  // Create record in an existing buffer
  static CCommStatRecord* CreateInBuffer(char* pBuffer);

  // Set data fields of record
  void Set(unsigned short usBytesSent, unsigned short usPacketsSent,
           unsigned short usBytesReceived, unsigned short usPacketsReceived,
           unsigned short usPendingSend, unsigned short usPendingReceive);

  // Initialize data record
  void Create();

  // Get values
  const unsigned short GetBytesSent() const { return m_usBytesSent; };
  const unsigned short GetPacketsSent() const { return m_usPacketsSent; };
  const unsigned short GetBytesReceived() const { return m_usBytesReceived; };
  const unsigned short GetPacketsReceived() const { return m_usPacketsReceived; };
  const unsigned short GetPendingSend() const { return m_usPendingSend; };
  const unsigned short GetPendingReceive() const { return m_usPendingReceive; };

private:
  CConvLE<unsigned short> m_usBytesSent;
  CConvLE<unsigned short> m_usPacketsSent;
  CConvLE<unsigned short> m_usBytesReceived;
  CConvLE<unsigned short> m_usPacketsReceived;
  CConvLE<unsigned short> m_usPendingSend;
  CConvLE<unsigned short> m_usPendingReceive;
};

inline CCommStatRecord* CCommStatRecord::CreateInBuffer(char* pBuffer)
{
  ASSERT(pBuffer);

  CCommStatRecord* pItem = (CCommStatRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


class CCVBrightnessRGBRecord : public CRecordBase
{
  public:
      //	Create record in an existing buffer
      static CCVBrightnessRGBRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      // Value range 0..100 for ucValue
      void Set (unsigned short usConfiguration, unsigned char ucColour, unsigned char ucValue);

      //	Initialize data record.
      void Create ();

      const unsigned short GetusConfiguration () const { return m_usConfiguration;};
      const unsigned char GetucColour () const { return m_ucColour; };
      const unsigned char GetucValue () const { return m_ucValue; };

  private:  //## implementation
      CConvLE<unsigned short> m_usConfiguration;
      unsigned char m_ucColour;
      unsigned char m_ucValue;
};

inline CCVBrightnessRGBRecord* CCVBrightnessRGBRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVBrightnessRGBRecord *pItem = (CCVBrightnessRGBRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

class CCVContrastRGBRecord : public CRecordBase
{
  public:
      //	Create record in an existing buffer
      static CCVContrastRGBRecord* CreateInBuffer (char* pBuffer);

      // Set data fields of record
      // Value range 0..100 for ucValue
      void Set (unsigned short usConfiguration, unsigned char ucColour, unsigned char ucValue);

      //	Initialize data record.
      void Create ();

      const unsigned short GetusConfiguration () const { return m_usConfiguration;};
      const unsigned char GetucColour () const { return m_ucColour; };
      const unsigned char GetucValue () const { return m_ucValue; };

  private:
      CConvLE<unsigned short> m_usConfiguration;
      unsigned char m_ucColour;
      unsigned char m_ucValue;
};

inline CCVContrastRGBRecord* CCVContrastRGBRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVContrastRGBRecord *pItem = (CCVContrastRGBRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


class CCVColourSpaceRecord : public CRecordBase
{
  public:
      //	Create record in an existing buffer
      static CCVColourSpaceRecord* CreateInBuffer (char* pBuffer);

      // Set data fields of record
      // Value range 0..0.25 for float parameters
      void Set(unsigned short usConfiguration, float fGreenInRed, float fBlueInRed, float fRedInGreen, float fBlueInGreen, float fRedInBlue, float fGreenInBlue);

      //	Initialize data record.
      void Create ();

      const unsigned short GetusConfiguration () const { return m_usConfiguration;};

      const float& GetGreenInRed() const { return m_fValue[0]; };
      const float& GetBlueInRed() const { return m_fValue[1]; };
      const float& GetRedInGreen() const { return m_fValue[2]; };
      const float& GetBlueInGreen() const { return m_fValue[3]; };
      const float& GetRedInBlue() const { return m_fValue[4]; };
      const float& GetGreenInBlue() const { return m_fValue[5]; };

  private:
      void AssertValid() const;

      CConvLE<unsigned short> m_usConfiguration;
      float m_fValue[6];
};

inline CCVColourSpaceRecord* CCVColourSpaceRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVColourSpaceRecord *pItem = (CCVColourSpaceRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

inline void CCVColourSpaceRecord::AssertValid() const
{
#ifdef _DEBUG
  CRecordBase::AssertValid();

  ASSERT(m_fValue[0] <= 0.25);
  ASSERT(m_fValue[1] <= 0.25);
  ASSERT(m_fValue[2] <= 0.25);
  ASSERT(m_fValue[3] <= 0.25);
  ASSERT(m_fValue[4] <= 0.25);
  ASSERT(m_fValue[5] <= 0.25);

#endif
}


class CCVCompactDesignerDataRecord : public CRecordBase
{
  public:
      //	Create record in an existing buffer
      // THIS IS THE ONLY WAY TO CREATE THIS RECORD
      static CCVCompactDesignerDataRecord* CreateInBuffer (char* pBuffer, unsigned short usDataSize);

      // Set data fields of record
      // Value range 0..100 for ucValue
      void Set(unsigned short usId, unsigned char* pData);

      //	Initialize data record.
      void Create (unsigned short usDataSize);

      unsigned char* GetData() { return &m_ucStartOfData; };
      // Return size of user data, given in usDataSize
      unsigned short GetDataSize() { return GetSize() - sizeof(*this) + sizeof(m_ucStartOfData);};

  private:
      CConvLE<unsigned short> m_usId;
      unsigned char m_ucStartOfData;  // Start of data, NOTE: The record MUST BE created in an existing buffer
                                      // Use GetDataSize() to read the size of the data
                                      // (Motivation not to have a private buffer: Save RAM in GCM card)
};

inline CCVCompactDesignerDataRecord* CCVCompactDesignerDataRecord::CreateInBuffer (char* pBuffer, unsigned short usDataSize)
{
  ASSERT(pBuffer);

  CCVCompactDesignerDataRecord *pItem = (CCVCompactDesignerDataRecord *) pBuffer;
  pItem->Create(usDataSize);

  return pItem;
}


class CFunctionAvailableRecord : public CRecordBase
{
  public:
      static CFunctionAvailableRecord* CreateInBuffer (char* pBuffer);

      //
      // usFunction = one of CV_XX constants defined in commandTypes.h
      // bAvailable: true if the function is available,
      //          false if it is unavaliable due to current source, current signal characteristics, 
      //          current SW version etc.
      void Set(unsigned short usFunction, bool bAvailable);
      //	Initialize data record.
      void Create ();

      unsigned short GetusFunction() { return m_usFunction;};
      bool GetbAvailable() { return m_bAvailable;};

  private:  //## implementation
      CConvLE<unsigned short> m_usFunction;
      bool m_bAvailable;
};


inline CFunctionAvailableRecord* CFunctionAvailableRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CFunctionAvailableRecord *pItem = (CFunctionAvailableRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


class CFunctionsAvailableRecord : public CRecordBase
{
public:
  static CFunctionsAvailableRecord* CreateInBuffer (char* pBuffer);

  void Set(unsigned short usConfiguration, unsigned char ucVersion, unsigned short usNFunctions, unsigned short *pusFunctionList);
      
  void Create ();

  const unsigned short GetusConfiguration () const;
  const unsigned short GetusNFunctions () const;
  const unsigned short * GetusFunctionList () const;
  const unsigned short GetusFunction(short sIndex) const;
  const unsigned char GetucVersion() const;

  unsigned short GetExtraSize () const;

private:
  CConvLE<unsigned short> m_usConfiguration;
  unsigned char m_ucVersion;
  CConvLE<unsigned short> m_usNFunctions;
  unsigned short m_usFunction[1]; // //TODO: LIST usFunction = one of CV_X constants defined in commandTypes.h
};


inline CFunctionsAvailableRecord* CFunctionsAvailableRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CFunctionsAvailableRecord *pItem = (CFunctionsAvailableRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


inline unsigned short CFunctionsAvailableRecord::GetExtraSize () const
{
  return m_usNFunctions * sizeof(m_usFunction[0]) - sizeof(m_usFunction);
}


inline const unsigned short CFunctionsAvailableRecord::GetusConfiguration () const
{
  return m_usConfiguration;
}


inline const unsigned short CFunctionsAvailableRecord::GetusNFunctions () const
{
  return m_usNFunctions;
}


inline const unsigned short * CFunctionsAvailableRecord::GetusFunctionList () const
{
  return m_usFunction;
}


inline const unsigned short CFunctionsAvailableRecord::GetusFunction (short sIndex) const
{
  ASSERT((unsigned short) sIndex < m_usNFunctions);
  return m_usFunction[sIndex];
}

inline const unsigned char CFunctionsAvailableRecord::GetucVersion() const
{
  return m_ucVersion;
}

class CScalingFormatRecord : public CRecordBase
{
public:
  static CScalingFormatRecord* CreateInBuffer(char* pBuffer);

  void Set(unsigned short usConfiguration, unsigned short usVRefreshRate,
           unsigned short usHRes, unsigned short usVRes,   
           unsigned short usHSyncLength, unsigned short usVSyncLength,
           unsigned short usHBackPorch, unsigned short usVBackPorch,
           unsigned short usHTotal, unsigned short usVTotal);

  void Create();

  const unsigned short GetusConfiguration() const  {return m_usConfiguration;};
  const unsigned short GetusVRefreshRate() const {return m_usVRefreshRate;};
  const unsigned short GetusHRes() const {return m_usHRes;};
  const unsigned short GetusVRes() const {return m_usVRes;};
  const unsigned short GetusHSyncLength() const {return m_usHSyncLength;};
  const unsigned short GetusVSyncLength() const {return m_usVSyncLength;};
  const unsigned short GetusHBackPorch() const {return m_usHBackPorch;};
  const unsigned short GetusVBackPorch() const {return m_usVBackPorch;};
  const unsigned short GetusHTotal() const {return m_usHTotal;};
  const unsigned short GetusVTotal() const {return m_usVTotal;};

private:
  void AssertValid() const;

  CConvLE<unsigned short> m_usConfiguration;
  CConvLE<unsigned short> m_usVRefreshRate;
  CConvLE<unsigned short> m_usHRes;
  CConvLE<unsigned short> m_usVRes;
  CConvLE<unsigned short> m_usHSyncLength;
  CConvLE<unsigned short> m_usVSyncLength;
  CConvLE<unsigned short> m_usHBackPorch;
  CConvLE<unsigned short> m_usVBackPorch;
  CConvLE<unsigned short> m_usHTotal;
  CConvLE<unsigned short> m_usVTotal;
};

inline CScalingFormatRecord* CScalingFormatRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CScalingFormatRecord *pItem = (CScalingFormatRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

inline void CScalingFormatRecord::AssertValid() const
{
#ifdef _DEBUG
  CRecordBase::AssertValid();
  ASSERT((m_usHRes + m_usHSyncLength + m_usHBackPorch) < m_usHTotal);
  ASSERT((m_usVRes + m_usVSyncLength + m_usVBackPorch) < m_usVTotal);
#endif
}


class CScalingModeRecord : public CRecordBase
{
public:
  static CScalingModeRecord* CreateInBuffer(char* pBuffer);

  void Set(unsigned short usConfiguration, unsigned char ucOn,
           unsigned char ucMode, unsigned char ucAlignment, 
           unsigned short usUserDefScaleX, unsigned short usUserDefScaleY);

  void Create();

  const unsigned short GetusConfiguration() const {return m_usConfiguration;};
  const unsigned char GetucOn() const {return m_ucOn;};
  const unsigned short GetucMode() const {return m_ucMode;};
  const unsigned short GetucAlignment() const {return m_ucAlignment;};
  const unsigned short GetusUserDefScaleX() const {return m_usUserDefScaleX;};
  const unsigned short GetusUserDefScaleY() const {return m_usUserDefScaleY;};

private:
  CConvLE<unsigned short> m_usConfiguration;
  unsigned char m_ucOn;
  unsigned char m_ucMode;
  unsigned char m_ucAlignment;
  CConvLE<unsigned short> m_usUserDefScaleX;
  CConvLE<unsigned short> m_usUserDefScaleY;
};

inline CScalingModeRecord* CScalingModeRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CScalingModeRecord *pItem = (CScalingModeRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

class CAnalyzeVideoRecord : public CRecordBase
{
public:
  static CAnalyzeVideoRecord* CreateInBuffer(char* pBuffer, unsigned short usVideoSize);

  void Set(unsigned char ucColour, unsigned char* pucVideo, unsigned char ucSampleMode, unsigned char ucBitPerUnit);

  void Create(unsigned short usVideoSize);

  const unsigned char GetucColour() const {return m_ucColour;};
  const unsigned char GetucBitPerUnit() const {return m_ucBitPerUnit;};
  const unsigned char GetucSampleMode() const {return m_ucSampleMode;};
  const unsigned char* GetpucVideo() const {return &m_ucStartOfVideo;};
  const unsigned short GetusDataSize() const { return GetSize() - sizeof(*this) + sizeof(m_ucStartOfVideo);};
 
private:
  unsigned char m_ucColour;
  unsigned char m_ucSampleMode;
  unsigned char m_ucBitPerUnit;
  unsigned char m_ucStartOfVideo;
};

inline CAnalyzeVideoRecord* CAnalyzeVideoRecord::CreateInBuffer (char* pBuffer, unsigned short usVideoSize)
{
  ASSERT(pBuffer);

  CAnalyzeVideoRecord *pItem = (CAnalyzeVideoRecord *) pBuffer;
  pItem->Create(usVideoSize);

  return pItem;
}


//version 2 with configuration
class CAnalyzeVideoRecord_V2 : public CRecordBase
{
public:
  static CAnalyzeVideoRecord_V2* CreateInBuffer(char* pBuffer, unsigned short usVideoSize);

  void Set(unsigned short usConfiguration, unsigned char ucColour, unsigned char* pucVideo, unsigned char ucSampleMode, unsigned char ucBitPerUnit);

  void Create(unsigned short usVideoSize);

  const unsigned short GetusConfiguration() const {return m_usConfiguration;};
  const unsigned char GetucColour() const {return m_ucColour;};
  const unsigned char GetucBitPerUnit() const {return m_ucBitPerUnit;};
  const unsigned char GetucSampleMode() const {return m_ucSampleMode;};
  const unsigned char* GetpucVideo() const {return &m_ucStartOfVideo;};
  const unsigned short GetusDataSize() const { return GetSize() - sizeof(*this) + sizeof(m_ucStartOfVideo);};
 
private:
  CConvLE<unsigned short> m_usConfiguration;
  unsigned char m_ucColour;
  unsigned char m_ucSampleMode;
  unsigned char m_ucBitPerUnit;
  unsigned char m_ucStartOfVideo;
};

inline CAnalyzeVideoRecord_V2* CAnalyzeVideoRecord_V2::CreateInBuffer (char* pBuffer, unsigned short usVideoSize)
{
  ASSERT(pBuffer);

  CAnalyzeVideoRecord_V2 *pItem = (CAnalyzeVideoRecord_V2 *) pBuffer;
  pItem->Create(usVideoSize);

  return pItem;
}

class CAnalyzeHistogramRecord : public CRecordBase
{
public:
  static CAnalyzeHistogramRecord* CreateInBuffer(char* pBuffer, unsigned short usHistogramSize);

  void Set(unsigned char ucColour, unsigned char* pucHistogram, unsigned char ucSampleMode, unsigned char ucBitPerUnit);

  void Create(unsigned short usHistogramSize);

  const unsigned char GetucColour() const {return m_ucColour;};
  const unsigned char GetucBitPerUnit() const {return m_ucBitPerUnit;};
  const unsigned char GetucSampleMode() const {return m_ucSampleMode;};
  const unsigned char* GetpucHistogram() const {return &m_ucStartOfHistogram;};
  const unsigned short GetusDataSize() const {return GetSize() - sizeof(*this) + sizeof(m_ucStartOfHistogram);};

private:
  unsigned char m_ucColour;
  unsigned char m_ucSampleMode;
  unsigned char m_ucBitPerUnit;
  unsigned char m_ucStartOfHistogram;
};

inline CAnalyzeHistogramRecord* CAnalyzeHistogramRecord::CreateInBuffer (char* pBuffer, unsigned short usHistogramSize)
{
  ASSERT(pBuffer);

  CAnalyzeHistogramRecord *pItem = (CAnalyzeHistogramRecord *) pBuffer;
  pItem->Create(usHistogramSize);

  return pItem;
}

//version 2 with configuration
class CAnalyzeHistogramRecord_V2 : public CRecordBase
{
public:
  static CAnalyzeHistogramRecord_V2* CreateInBuffer(char* pBuffer, unsigned short usHistogramSize);

  void Set(unsigned short usConfiguration, unsigned char ucColour, unsigned char* pucHistogram, unsigned char ucSampleMode, unsigned char ucBitPerUnit);

  void Create(unsigned short usHistogramSize);

  const unsigned short GetusConfiguration() const {return m_usConfiguration;};
  const unsigned char GetucColour() const {return m_ucColour;};
  const unsigned char GetucBitPerUnit() const {return m_ucBitPerUnit;};
  const unsigned char GetucSampleMode() const {return m_ucSampleMode;};
  const unsigned char* GetpucHistogram() const {return &m_ucStartOfHistogram;};
  const unsigned short GetusDataSize() const {return GetSize() - sizeof(*this) + sizeof(m_ucStartOfHistogram);};

private:
  CConvLE<unsigned short> m_usConfiguration;
  unsigned char m_ucColour;
  unsigned char m_ucSampleMode;
  unsigned char m_ucBitPerUnit;
  unsigned char m_ucStartOfHistogram;
};

inline CAnalyzeHistogramRecord_V2* CAnalyzeHistogramRecord_V2::CreateInBuffer (char* pBuffer, unsigned short usHistogramSize)
{
  ASSERT(pBuffer);

  CAnalyzeHistogramRecord_V2 *pItem = (CAnalyzeHistogramRecord_V2 *) pBuffer;
  pItem->Create(usHistogramSize);

  return pItem;
}


class CStereoControlRecord : public CRecordBase
{
public:
  static CStereoControlRecord* CreateInBuffer(char* pBuffer);

  void Set(unsigned short usConfiguration, unsigned char ucOn, 
           unsigned short usDelayLines, unsigned char ucSwapFrames);

  void Create();

  const unsigned short GetusConfiguration() const {return m_usConfiguration;};
  const unsigned char GetucOn() const {return m_ucOn;};
  const unsigned short GetusDelayLines() const {return m_usDelayLines;};
  const unsigned char GetucSwapFrames() const {return m_ucSwapFrames;};

private:
  CConvLE<unsigned short> m_usConfiguration;
  unsigned char m_ucOn;
  CConvLE<unsigned short> m_usDelayLines;
  unsigned char m_ucSwapFrames;
};

inline CStereoControlRecord* CStereoControlRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CStereoControlRecord *pItem = (CStereoControlRecord *) pBuffer;
  pItem->Create();

  return pItem;
}



class CColorMeasurementRecord : public CRecordBase
{
public:
  static CColorMeasurementRecord* CreateInBuffer(char* pBuffer);

  void Set(unsigned short usInstrumentID, unsigned short usFlags, const double &dLuminance, 
           const double &dChromaX, const double &dChromaY, const char *pcStatusText);

  void Create();

  const unsigned short GetusFlags() const {return m_usFlags;};
  const double &GetdLuminance() const {return m_dLuminance;};
  const double &GetdChromaX() const {return m_dChromaX;};
  const double &GetdChromaY() const {return m_dChromaY;};
  const CCVString& GetsStatusText () const {return m_sStatusText;};

private:
  CConvLE<unsigned short> m_usInstrumentID;
  CConvLE<unsigned short> m_usFlags;
  double         m_dLuminance;
  double         m_dChromaX;
  double         m_dChromaY;

  CCVString      m_sStatusText;
};

inline CColorMeasurementRecord* CColorMeasurementRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CColorMeasurementRecord *pItem = (CColorMeasurementRecord *) pBuffer;
  pItem->Create();

  return pItem;
}



class CFrameInputBlockRecord : public CRecordBase
{
public:
  static CFrameInputBlockRecord* CreateInBuffer(char* pBuffer);

  void Set(unsigned short usConfiguration, unsigned short usBlockNumber, bool bActive, 
           unsigned long ulPositionX, unsigned long ulPositionY);

  void Create();

  const unsigned short GetusConfiguration() const {return m_usConfiguration;};
  const unsigned short GetusBlockNumber() const {return m_usBlockNumber;};
  const bool GetbActive() const {return m_bActive;};
  const unsigned long GetulPositionX() const {return m_ulPositionX;};
  const unsigned long GetulPositionY() const {return m_ulPositionY;};

private:
  CConvLE<unsigned short> m_usConfiguration;
  CConvLE<unsigned short> m_usBlockNumber;
  bool m_bActive;
  CConvLE<unsigned long> m_ulPositionX;
  CConvLE<unsigned long> m_ulPositionY;
};

inline CFrameInputBlockRecord* CFrameInputBlockRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CFrameInputBlockRecord *pItem = (CFrameInputBlockRecord *) pBuffer;
  pItem->Create();

  return pItem;
}



class CFrameOutputBlockRecord : public CRecordBase
{
public:
  static CFrameOutputBlockRecord* CreateInBuffer(char* pBuffer);

  void Set(unsigned short usConfiguration, unsigned short usBlockNumber, bool bActive,
           unsigned long ulPositionX, unsigned long ulPositionY, unsigned long ulSizeX, unsigned long ulSizeY);

  void Create();

  const unsigned short GetusConfiguration() const {return m_usConfiguration;};
  const unsigned short GetusBlockNumber() const {return m_usBlockNumber;};
  const bool GetbActive() const {return m_bActive;};
  const unsigned long GetulPositionX() const {return m_ulPositionX;};
  const unsigned long GetulPositionY() const {return m_ulPositionY;};
  const unsigned long GetulSizeX() const {return m_ulSizeX;};
  const unsigned long GetulSizeY() const {return m_ulSizeY;};

private:
  CConvLE<unsigned short> m_usConfiguration;
  CConvLE<unsigned short> m_usBlockNumber;
  bool m_bActive;
  CConvLE<unsigned long> m_ulPositionX;
  CConvLE<unsigned long> m_ulPositionY;
  CConvLE<unsigned long> m_ulSizeX;
  CConvLE<unsigned long> m_ulSizeY;
};

inline CFrameOutputBlockRecord* CFrameOutputBlockRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CFrameOutputBlockRecord *pItem = (CFrameOutputBlockRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

class CFrameEnableRecord : public CRecordBase
{
public:
  static CFrameEnableRecord* CreateInBuffer(char* pBuffer);

  void Set(unsigned short usConfiguration, bool bInput, bool bEnable);

  void Create();

  const unsigned short GetusConfiguration() const {return m_usConfiguration;};
  const bool IsInput() const {return m_bInput;};
  const bool IsEnabled() const {return m_bEnable;};
  
private:
  CConvLE<unsigned short> m_usConfiguration;
  bool m_bInput;
  bool m_bEnable;
};

inline CFrameEnableRecord* CFrameEnableRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CFrameEnableRecord *pItem = (CFrameEnableRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

class CCardsConnectedRecord : public CRecordBase
{
public:
  static CCardsConnectedRecord* CreateInBuffer(char* pBuffer);

  void Set(unsigned short usConfiguration, unsigned char *ucMCMSerialNumber,
           unsigned char *ucGCM1SerialNumber, unsigned char *ucGCM2SerialNumber);

  void Create();

  const unsigned short GetusConfiguration() const {return m_usConfiguration;};
  const unsigned char* GetucMCMSerialNumber () const {return m_ucMCMSerialNumber;};
  const unsigned char* GetucGCM1SerialNumber () const {return m_ucGCM1SerialNumber;};
  const unsigned char* GetucGCM2SerialNumber () const {return m_ucGCM2SerialNumber;};
  
private:
  CConvLE<unsigned short> m_usConfiguration;
  unsigned char m_ucMCMSerialNumber[8];
  unsigned char m_ucGCM1SerialNumber[8];
  unsigned char m_ucGCM2SerialNumber[8];
};

inline CCardsConnectedRecord* CCardsConnectedRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCardsConnectedRecord *pItem = (CCardsConnectedRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

class CWhiteBoostRecord : public CRecordBase
{
public:
  static CWhiteBoostRecord* CreateInBuffer(char* pBuffer);

  void Set(unsigned short usConfiguration, short sWhiteBoost);

  void Create();

  const unsigned short GetusConfiguration() const {return m_usConfiguration;};
  const short GetsWhiteBoost() const {return m_sWhiteBoost;};
  
private:
  CConvLE<unsigned short> m_usConfiguration;
  CConvLE<short> m_sWhiteBoost;
};

inline CWhiteBoostRecord* CWhiteBoostRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CWhiteBoostRecord *pItem = (CWhiteBoostRecord*) pBuffer;
  pItem->Create();

  return pItem;
}

class CIpPropertiesRecord : public CRecordBase
{
public:
  static CIpPropertiesRecord* CreateInBuffer(char* pBuffer);

  void SetpucIpAddress(const unsigned char *pucAddress);

  void SetpucSubnetMask(const unsigned char *pucMask);

  void SetucDhcp(const unsigned char);

  void Create();

  const unsigned char* GetpucIpAddress() const {return m_pucIpAddress;};
  const unsigned char* GetpucSubnetMask() const {return m_pucSubnetMask;};
  const unsigned char GetucDhcp() const {return m_ucDhcp;};
  
private:
  unsigned char m_pucIpAddress[4];
  unsigned char m_pucSubnetMask[4];
  unsigned char m_ucDhcp;
};

inline CIpPropertiesRecord* CIpPropertiesRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CIpPropertiesRecord *pItem = (CIpPropertiesRecord*) pBuffer;
  pItem->Create();

  return pItem;
}


class CKeyChallengeRecord : public CRecordBase
{
public:
  static CKeyChallengeRecord* CreateInBuffer(char* pBuffer);

  void Set(unsigned short usKeyIndex, unsigned long ulChallenge, unsigned long ulTimeStamp);

  void Create();

  const unsigned short GetusKeyIndex() const { return m_usKeyIndex; };
  const unsigned long GetulChallenge() const { return m_ulChallenge; };
  const unsigned long GetulTimeStamp() const { return m_ulTimeStamp; };
  
private:
  CConvLE<unsigned short> m_usKeyIndex;
  CConvLE<unsigned long> m_ulChallenge;
  CConvLE<unsigned long> m_ulTimeStamp;
};

inline CKeyChallengeRecord* CKeyChallengeRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CKeyChallengeRecord *pItem = (CKeyChallengeRecord*) pBuffer;
  pItem->Create();

  return pItem;
}


class CDynamicLicenseRecord : public CRecordBase
{
public:
  static CDynamicLicenseRecord* CreateInBuffer(char* pBuffer);

  void Set(unsigned short usKeyIndex, unsigned long ulLicenseKey);

  void Create();

  const unsigned short GetusKeyIndex() const { return m_usKeyIndex; };
  const unsigned long GetulLicenseKey() const { return m_ulLicenseKey; };
  
private:
  CConvLE<unsigned short> m_usKeyIndex;
  CConvLE<unsigned long> m_ulLicenseKey;
};

inline CDynamicLicenseRecord* CDynamicLicenseRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CDynamicLicenseRecord *pItem = (CDynamicLicenseRecord*) pBuffer;
  pItem->Create();

  return pItem;
}


class CTotalLampTimeRecord : public CRecordBase
{
public:
  static CTotalLampTimeRecord* CreateInBuffer(char* pBuffer);

  void SetsTotalLampTime(const short sTotalLampTime);

  void Create();

  const short GetsTotalLampTime() const {return m_sTotalLampTime;};
  
private:
  CConvLE<short> m_sTotalLampTime;
};

inline CTotalLampTimeRecord* CTotalLampTimeRecord::CreateInBuffer(char* pBuffer)
{
  ASSERT(pBuffer);

  CTotalLampTimeRecord *pItem = (CTotalLampTimeRecord*) pBuffer;
  pItem->Create();

  return pItem;
}


class CResetLampTimeRecord : public CRecordBase
{
public:
  static CResetLampTimeRecord* CreateInBuffer(char* pBuffer);

  void Create();
  
private:
};

inline CResetLampTimeRecord* CResetLampTimeRecord::CreateInBuffer(char* pBuffer)
{
  ASSERT(pBuffer);

  CResetLampTimeRecord *pItem = (CResetLampTimeRecord*) pBuffer;
  pItem->Create();

  return pItem;
}


class CCwIndexDelayRecord : public CRecordBase
{
public:
  static CCwIndexDelayRecord* CreateInBuffer(char* pBuffer);

  void SetusIndexDelay(const unsigned short usIndexDelay);

  void Create();

  const unsigned short GetusIndexDelay() const {return m_usIndexDelay;};
  
private:
  CConvLE<unsigned short> m_usIndexDelay;
};


inline CCwIndexDelayRecord* CCwIndexDelayRecord::CreateInBuffer(char* pBuffer)
{
  ASSERT(pBuffer);

  CCwIndexDelayRecord *pItem = (CCwIndexDelayRecord*) pBuffer;
  pItem->Create();

  return pItem;
}

class CCwStoreRecord : public CRecordBase
{
public:
  static CCwStoreRecord* CreateInBuffer(char* pBuffer);

  void Create();
};

inline CCwStoreRecord* CCwStoreRecord::CreateInBuffer(char* pBuffer)
{
  ASSERT(pBuffer);

  CCwStoreRecord *pItem = (CCwStoreRecord*) pBuffer;
  pItem->Create();

  return pItem;
}

class CLicenseKeyRecord : public CRecordBase
{
public:
  static CLicenseKeyRecord* CreateInBuffer(char* pBuffer);

  void Set(const char *pszLicenseKey);

  void Create();

  const CCVString& GetLicenseKey() const;

private:
  CCVString m_LicenseKey;
};


inline CLicenseKeyRecord* CLicenseKeyRecord::CreateInBuffer(char* pBuffer)
{
  ASSERT(pBuffer);

  CLicenseKeyRecord *pItem = (CLicenseKeyRecord*)pBuffer;
  pItem->Create();

  return pItem;
}

inline const CCVString& CLicenseKeyRecord::GetLicenseKey() const
{
  return m_LicenseKey;
}

class CLampPowerRecord : public CRecordBase
{
public:
  static CLampPowerRecord* CreateInBuffer(char* pBuffer);

  void Set(unsigned char ucLampPower);

  void Create();

  inline unsigned char GetucLampPower() const {return m_ucLampPower;} ;

private:
  unsigned char m_ucLampPower;
};

inline CLampPowerRecord* CLampPowerRecord::CreateInBuffer(char* pBuffer)
{
  ASSERT(pBuffer);

  CLampPowerRecord *pItem = (CLampPowerRecord*)pBuffer;
  pItem->Create();

  return pItem;
}

class CWirelessNameRecord : public CRecordBase
{
public:
  static CWirelessNameRecord* CreateInBuffer(char* pBuffer);

  void Set(const char* pszWirelessName);

  void Create();

  const CCVString& GetWirelessName() const;

private:

  CCVString m_WirelessName;
};

inline CWirelessNameRecord* CWirelessNameRecord::CreateInBuffer(char* pBuffer)
{
  ASSERT(pBuffer);

  CWirelessNameRecord *pItem = (CWirelessNameRecord*)pBuffer;
  pItem->Create();

  return pItem;
}

inline const CCVString& CWirelessNameRecord::GetWirelessName() const 
{
  return m_WirelessName;
}


class CWepRecord : public CRecordBase
{
public:
  static CWepRecord* CreateInBuffer(char* pBuffer);

  void Set_128(unsigned char ucFlags, unsigned short usDefaultKeyId,
               unsigned char ucKey1[13], unsigned char ucKey2[13], 
               unsigned char ucKey3[13], unsigned char ucKey4[13]);

  void Set_64(unsigned char ucFlags, unsigned short usDefaultKeyId,
              unsigned char ucKey1[5], unsigned char ucKey2[5], 
              unsigned char ucKey3[5], unsigned char ucKey4[5]);

  void Create();

  unsigned char GetucFlags();

  unsigned short GetusDefaultKeyId();

  bool Is128BitKeys();

  void GetKey1_128(unsigned char ucKey[13]);
  void GetKey2_128(unsigned char ucKey[13]);
  void GetKey3_128(unsigned char ucKey[13]);
  void GetKey4_128(unsigned char ucKey[13]);

  void GetKey1_64(unsigned char ucKey[5]);
  void GetKey2_64(unsigned char ucKey[5]);
  void GetKey3_64(unsigned char ucKey[5]);
  void GetKey4_64(unsigned char ucKey[5]);

private:
  unsigned char m_ucFlags;
  CConvLE<unsigned short> m_usDefaultKeyId;
  bool m_bUse128BitKeys;
  unsigned char m_ucKey1[13];
  unsigned char m_ucKey2[13];
  unsigned char m_ucKey3[13];
  unsigned char m_ucKey4[13];
};


inline CWepRecord* CWepRecord::CreateInBuffer(char* pBuffer)
{
  ASSERT(pBuffer);

  CWepRecord *pItem = (CWepRecord*)pBuffer;
  pItem->Create();

  return pItem;
}

inline bool CWepRecord::Is128BitKeys()
{
  return m_bUse128BitKeys;
}

inline void CWepRecord::GetKey1_128(unsigned char ucKey[13])
{
  if(m_bUse128BitKeys)
  {
    memcpy(ucKey, m_ucKey1, 13); 
  }
}

inline void CWepRecord::GetKey2_128(unsigned char ucKey[13])
{
  if(m_bUse128BitKeys)
  {
    memcpy(ucKey, m_ucKey2, 13); 
  }
}

inline void CWepRecord::GetKey3_128(unsigned char ucKey[13])
{
  if(m_bUse128BitKeys)
  {
    memcpy(ucKey, m_ucKey3, 13); 
  }
}

inline void CWepRecord::GetKey4_128(unsigned char ucKey[13])
{
  if(m_bUse128BitKeys)
  {
    memcpy(ucKey, m_ucKey4, 13); 
  }
}

inline void CWepRecord::GetKey1_64(unsigned char ucKey[13])
{
  if(!m_bUse128BitKeys)
  {
    memcpy(ucKey, m_ucKey1, 5); 
  }
}

inline void CWepRecord::GetKey2_64(unsigned char ucKey[13])
{
  if(!m_bUse128BitKeys)
  {
    memcpy(ucKey, m_ucKey2, 5); 
  }
}

inline void CWepRecord::GetKey3_64(unsigned char ucKey[13])
{
  if(!m_bUse128BitKeys)
  {
    memcpy(ucKey, m_ucKey3, 5); 
  }
}

inline void CWepRecord::GetKey4_64(unsigned char ucKey[13])
{
  if(!m_bUse128BitKeys)
  {
    memcpy(ucKey, m_ucKey4, 5); 
  }
}


class CManualResolutionRecord : public CRecordBase
{
  public:
      //	Create record in an existing buffer
      static CManualResolutionRecord* CreateInBuffer (char* pBuffer);

      //	Set data fields of record
      void Set (unsigned short usConfiguration, char cValue);

      //	Initialize data record.
      void Create ();

      const unsigned short GetusConfiguration () const;
      const char GetcValue () const { return m_cValue; };

  private:
      CConvLE<unsigned short> m_usConfiguration;
      char m_cValue;
};


inline CManualResolutionRecord* CManualResolutionRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CManualResolutionRecord *pItem = (CManualResolutionRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

inline const unsigned short CManualResolutionRecord::GetusConfiguration() const
{
  return m_usConfiguration;
}


class CProjectorConnectedRecord : public CRecordBase
{
  public:
      //	Create record in an existing buffer
      static CProjectorConnectedRecord* CreateInBuffer(char* pBuffer);

      //	Set data fields of record
      void Set(unsigned short usConfiguration, char cFamily);

      //	Initialize data record.
      void Create ();

      const unsigned short GetusConfiguration () const;
      const char GetcFamily () const { return m_cFamily; };

  private:
      CConvLE<unsigned short> m_usConfiguration;
      char m_cFamily;
};


inline CProjectorConnectedRecord* CProjectorConnectedRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CProjectorConnectedRecord *pItem = (CProjectorConnectedRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

inline const unsigned short CProjectorConnectedRecord::GetusConfiguration() const
{
  return m_usConfiguration;
}


class CVScreenAnalyseRecord : public CRecordBase
{
public:
  // Create record in an existing buffer
  static CVScreenAnalyseRecord* CreateInBuffer(char* pBuffer);

  void Create();

  void Set(short sVersion, unsigned short usTimeout, unsigned short usFrameRate, unsigned short usStatusMask, unsigned short usFeedbackTimeMS = 3000, unsigned char ucAnalyseId = 0);

  short GetsVersion() const;

  unsigned short GetusTimeout() const;

  unsigned short GetusFrameRate() const;

  unsigned short GetusStatusMask() const;

  unsigned short GetusFeedbackTimeMS() const;

  unsigned char GetucAnalyseId() const;

private:
  CConvLE<short> m_sVersion;
  CConvLE<unsigned short> m_usTimeout;
  CConvLE<unsigned short> m_usFrameRate;
  CConvLE<unsigned short> m_usStatusMask;
  CConvLE<unsigned short> m_usFeedbackTimeMS;
  unsigned char           m_ucAnalyseId;
};


inline CVScreenAnalyseRecord* CVScreenAnalyseRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CVScreenAnalyseRecord *pItem = (CVScreenAnalyseRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

inline short CVScreenAnalyseRecord::GetsVersion() const
{
  return m_sVersion;
}


inline unsigned short CVScreenAnalyseRecord::GetusTimeout() const
{
  return m_usTimeout;
}


inline unsigned short CVScreenAnalyseRecord::GetusFrameRate() const 
{
  return m_usFrameRate;
}


inline unsigned short CVScreenAnalyseRecord::GetusStatusMask() const 
{
  return m_usStatusMask;
}


inline unsigned short CVScreenAnalyseRecord::GetusFeedbackTimeMS() const
{
  if (GetSize() >= offsetof(CVScreenAnalyseRecord, m_usFeedbackTimeMS) + sizeof(m_usFeedbackTimeMS))
    return m_usFeedbackTimeMS;
  else
    return 3000;  // Default 3 seconds
}


inline unsigned char CVScreenAnalyseRecord::GetucAnalyseId() const
{
  if (GetSize() >= offsetof(CVScreenAnalyseRecord, m_ucAnalyseId) + sizeof(m_ucAnalyseId))
    return m_ucAnalyseId;
  else
    return 0;   // No value
}




class CVScreenResultRecord : public CRecordBase
{
public:
  static CVScreenResultRecord* CreateInBuffer(char* pBuffer);

  void Create();

  void Set(unsigned char ucSensor, unsigned long ulHPos, unsigned long ulVPos, unsigned char ucAnalyseId);

  unsigned char GetucSensor() const;

  unsigned long GetulHPos() const;

  unsigned long GetulVPos() const;

  unsigned char GetucAnalyseId() const;

private:
  unsigned char m_ucSensor;
  CConvLE<unsigned long> m_ulHPos;
  CConvLE<unsigned long> m_ulVPos;
  unsigned char m_ucAnalyseId;
};


inline CVScreenResultRecord* CVScreenResultRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CVScreenResultRecord *pItem = (CVScreenResultRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

inline unsigned char CVScreenResultRecord::GetucSensor() const
{
  return m_ucSensor; 
}


inline unsigned long CVScreenResultRecord::GetulHPos() const
{
  return m_ulHPos;
}


inline unsigned long CVScreenResultRecord::GetulVPos() const
{
  return m_ulVPos;
}


inline unsigned char CVScreenResultRecord::GetucAnalyseId() const
{
  if (GetSize() >= offsetof(CVScreenResultRecord, m_ucAnalyseId) + sizeof(m_ucAnalyseId))
    return m_ucAnalyseId;
  else
    return 0;
}


//version 2 with configuration
class CScreenHistogramRecord : public CRecordBase
{
public:
  static CScreenHistogramRecord* CreateInBuffer(char* pBuffer, unsigned short usHistogramSize);

  void Set(unsigned char ucSensorNo, unsigned short usRangeMin, unsigned char ucStep, unsigned char ucBitPerUnit, unsigned char* pucData);

  void Create(unsigned short usHistogramSize);

  const unsigned char GetucSensorNo() const {return m_ucSensorNo;};
  const unsigned char GetucBitPerUnit() const {return m_ucBitPerUnit;};
  const unsigned short GetusRangeMin() const {return m_usRangeMin;};
  const unsigned char GetucStep() const {return m_ucStep;};
  const unsigned char* GetpucData() const {return &m_ucData[0];};
  const unsigned short GetusDataSize() const {return GetSize() - sizeof(*this) + sizeof(m_ucData);};

private:
  unsigned char m_ucSensorNo;
  unsigned char m_ucBitPerUnit;
  CConvLE<unsigned short> m_usRangeMin;
  unsigned char m_ucStep;
  unsigned char m_ucData[1];
};

inline CScreenHistogramRecord* CScreenHistogramRecord::CreateInBuffer (char* pBuffer, unsigned short usHistogramSize)
{
  ASSERT(pBuffer);

  CScreenHistogramRecord *pItem = (CScreenHistogramRecord *) pBuffer;
  pItem->Create(usHistogramSize);

  return pItem;
}


class CVScreenThresholdRecord : public CRecordBase
{
public:
  static CVScreenThresholdRecord* CreateInBuffer(char* pBuffer);

  void Create();

  void Set(unsigned short usThreshold);

  unsigned short GetusThreshold() const;

private:
  CConvLE<unsigned short> m_usThreshold;
};


inline CVScreenThresholdRecord* CVScreenThresholdRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CVScreenThresholdRecord *pItem = (CVScreenThresholdRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

inline unsigned short CVScreenThresholdRecord::GetusThreshold() const
{
  return m_usThreshold;
}


class CVScreenLedPatternRecord : public CRecordBase
{
public:
  static CVScreenLedPatternRecord* CreateInBuffer(char* pBuffer);

  void Create();

  void Set(unsigned char ucPattern, unsigned short usGreenMask = 0, unsigned short usRedMask = 0);

  unsigned char GetucPattern() const;
  unsigned short GetusGreenMask() const;
  unsigned short GetusRedMask() const;

private:
  unsigned char m_ucPattern;
  CConvLE<unsigned short> m_usGreenMask;
  CConvLE<unsigned short> m_usRedMask;
};


inline CVScreenLedPatternRecord* CVScreenLedPatternRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CVScreenLedPatternRecord *pItem = (CVScreenLedPatternRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


inline unsigned char CVScreenLedPatternRecord::GetucPattern() const
{
  return m_ucPattern; 
}


inline unsigned short CVScreenLedPatternRecord::GetusGreenMask() const
{
  return m_usGreenMask;
}


inline unsigned short CVScreenLedPatternRecord::GetusRedMask() const
{
  return m_usRedMask;
}


class CVDynamicTestPatternRecord : public CRecordBase
{
public:
  static CVDynamicTestPatternRecord* CreateInBuffer(char* pBuffer);
  void Create();
  void Set(short sTestPatternVersion, unsigned short usMode, unsigned short usFlags);

  short GetsTestPatternVersion() const;
  unsigned short GetusMode() const;
  unsigned short GetusFlags() const;

private:
  CConvLE<short>          m_sTestPatternVersion;
  CConvLE<unsigned short> m_usMode;
  CConvLE<unsigned short> m_usFlags;
};


inline CVDynamicTestPatternRecord* CVDynamicTestPatternRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);
  CVDynamicTestPatternRecord *pItem = (CVDynamicTestPatternRecord *) pBuffer;
  pItem->Create();
  return pItem;
}

inline short CVDynamicTestPatternRecord::GetsTestPatternVersion() const
{
  return m_sTestPatternVersion;
}

inline unsigned short CVDynamicTestPatternRecord::GetusMode() const
{
  return m_usMode;
}

inline unsigned short CVDynamicTestPatternRecord::GetusFlags() const
{
  return m_usFlags;
}



class CVStereoInputEnableRecord : public CRecordBase
{
public:
  static CVStereoInputEnableRecord* CreateInBuffer(char* pBuffer);
  void Create();
  void Set(unsigned short usConfiguration, bool bEnable);
  unsigned short GetusConfiguration() const {return m_usConfiguration;};;
  bool IsEnabled() const {return m_bEnable;};

private:
  CConvLE<unsigned short> m_usConfiguration;
  bool m_bEnable;
};

inline CVStereoInputEnableRecord* CVStereoInputEnableRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);
  CVStereoInputEnableRecord *pItem = (CVStereoInputEnableRecord *) pBuffer;
  pItem->Create();
  return pItem;
}


class CVStereoInputSwapRecord : public CRecordBase
{
public:
  static CVStereoInputSwapRecord* CreateInBuffer(char* pBuffer);
  void Create();
  void Set(unsigned short usConfiguration, bool bSwap);
  unsigned short GetusConfiguration()  const {return m_usConfiguration;};;
  bool IsSwapped() const {return m_bSwap;};

private:
  CConvLE<unsigned short> m_usConfiguration;
  bool m_bSwap;
};


inline CVStereoInputSwapRecord* CVStereoInputSwapRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);
  CVStereoInputSwapRecord *pItem = (CVStereoInputSwapRecord *) pBuffer;
  pItem->Create();
  return pItem;
}


class CVStereoOutputRightRecord : public CRecordBase
{
public:
  static CVStereoOutputRightRecord* CreateInBuffer(char* pBuffer);
  void Create();
  void Set(unsigned short usConfiguration, bool bRight);
  unsigned short GetusConfiguration() const {return m_usConfiguration;};
  bool IsRight() const {return m_bRight;};

private:
  CConvLE<unsigned short> m_usConfiguration;
  bool m_bRight;
};


inline CVStereoOutputRightRecord* CVStereoOutputRightRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);
  CVStereoOutputRightRecord *pItem = (CVStereoOutputRightRecord *) pBuffer;
  pItem->Create();
  return pItem;
}


class CVSyncSourceRecord : public CRecordBase
{
public:
  static CVSyncSourceRecord* CreateInBuffer(char* pBuffer);
  void Create();
  void Set(unsigned short usConfiguration, unsigned short usSyncSource);
  unsigned short GetusConfiguration() const {return m_usConfiguration;};
  unsigned short GetusSyncSource() const {return m_usSyncSource;};

private:
  CConvLE<unsigned short> m_usConfiguration;
  CConvLE<unsigned short> m_usSyncSource;
};

inline CVSyncSourceRecord* CVSyncSourceRecord::CreateInBuffer(char* pBuffer)
{
  ASSERT(pBuffer);
  CVSyncSourceRecord *pItem = (CVSyncSourceRecord*) pBuffer;
  pItem->Create();
  return pItem;
}


class CVUserdefSettingRecord : public CRecordBase
{
public:
  static CVUserdefSettingRecord* CreateInBuffer(char* pBuffer);
  void Create();
  void Set(unsigned long ulUserSetting, double dValue);
  unsigned long GetulUserSetting() const {return m_ulUserSetting;};

#if defined(CVPROJ) && GCM_VERSION==4
  const double GetdValue() const;
#else
  const double& GetdValue() const;
#endif

private:
  CConvLE<unsigned long> m_ulUserSetting;
  double m_dValue;
};


#if defined(CVPROJ) && GCM_VERSION==4
inline const double CVUserdefSettingRecord::GetdValue () const
{
  ASSERT(sizeof(double) == sizeof(long long));
  
  unsigned long long ullData;
  memcpy(&ullData, &m_dValue, sizeof(ullData));
  
  ullData = CONVERT_FROM_LE64(ullData);

  double dRet;
  memcpy(&dRet, &ullData, sizeof(dRet));

  return dRet;
}
#else
inline const double& CVUserdefSettingRecord::GetdValue () const
{
  return m_dValue;
}
#endif

inline CVUserdefSettingRecord* CVUserdefSettingRecord::CreateInBuffer(char* pBuffer)
{
  ASSERT(pBuffer);
  CVUserdefSettingRecord *pItem = (CVUserdefSettingRecord*) pBuffer;
  pItem->Create();
  return pItem;
}

#if defined(MEGAWALL2)
#pragma pack(pop)
#elif defined(CVPROJ) && GCM_VERSION==4
#pragma pack()
#else
#pragma pack(pop, CVprotocolAppRecords)
#endif
//## end module.epilog
#endif



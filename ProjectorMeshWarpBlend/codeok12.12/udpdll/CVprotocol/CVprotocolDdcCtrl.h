// CVprotocolDdcCtrl.h: interface for the CCVprotocolDdcCtrl class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CVPROTOCOLDDCCTRL_H__625A439B_058D_4D05_832B_8EBCEB9C61B9__INCLUDED_)
#define AFX_CVPROTOCOLDDCCTRL_H__625A439B_058D_4D05_832B_8EBCEB9C61B9__INCLUDED_


#include "CVprotocolWrapper.h"


#if defined(CVPROJ) && GCM_VERSION==4
#else
#pragma pack(push, CVprotocolWrapper)
#endif

#pragma pack(1)


/////////////////////////////////////////////////////////////

//CDdcCtrlWrapper

/////////////////////////////////////////////////////////////
class CDdcCtrlWrapper : public CWrapperBase
{
  public:
    void Create ();
    static CDdcCtrlWrapper* CreateInBuffer (char* pBuffer);
    unsigned short PrepareToSend (unsigned char *pucLastSequenceCounter);
    bool PrepareToReceive ();
    const unsigned char GetucSequenceCounter () const;

  private:
    unsigned char m_ucSequenceCounter;
};


inline CDdcCtrlWrapper* CDdcCtrlWrapper::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CDdcCtrlWrapper *pItem = (CDdcCtrlWrapper *) pBuffer;
  pItem->Create();

  return pItem;
}


inline const unsigned char CDdcCtrlWrapper::GetucSequenceCounter () const
{
  return m_ucSequenceCounter;
}


/////////////////////////////////////////////////////////////

//CDdcCtrlAckRecord

/////////////////////////////////////////////////////////////
class CDdcCtrlAckRecord : public CRecordBase
{
  public:
    void Create();

    void Set (const class CDdcCtrlWrapper *pWrapper);

    static CDdcCtrlAckRecord * CreateInBuffer (char *pBuffer);

    const unsigned char GetucSequenceCounter () const;

    const unsigned short GetusCRC16 () const;

  private:
    unsigned char m_ucSequenceCounter;
    CConvLE<unsigned short> m_usCRC16;
};


inline CDdcCtrlAckRecord * CDdcCtrlAckRecord::CreateInBuffer (char *pBuffer)
{
  ASSERT(pBuffer);

  CDdcCtrlAckRecord *pItem = (CDdcCtrlAckRecord *) pBuffer;
  pItem->Create();

  return pItem;
}


inline const unsigned char CDdcCtrlAckRecord::GetucSequenceCounter () const
{
  return m_ucSequenceCounter;
}


inline const unsigned short CDdcCtrlAckRecord::GetusCRC16 () const
{
  return m_usCRC16;
}



/////////////////////////////////////////////////////////////

//CDdcCtrlWrapperRequest

/////////////////////////////////////////////////////////////
class CDdcCtrlWrapperRequest : public CWrapperBase
{
  public:
    void Create ();
    static CDdcCtrlWrapperRequest* CreateInBuffer (char* pBuffer);
    unsigned short PrepareToSend (unsigned char *pucLastSequenceCounter);
    bool PrepareToReceive ();
    const unsigned char GetucSequenceCounter () const;

  private:
    unsigned char m_ucSequenceCounter;
};


inline CDdcCtrlWrapperRequest* CDdcCtrlWrapperRequest::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CDdcCtrlWrapperRequest *pItem = (CDdcCtrlWrapperRequest *) pBuffer;
  pItem->Create();

  return pItem;
}


inline const unsigned char CDdcCtrlWrapperRequest::GetucSequenceCounter () const
{
  return m_ucSequenceCounter;
}


#if defined(CVPROJ) && GCM_VERSION==4
#pragma pack()
#else
#pragma pack(pop, CVprotocolWrapper)
#endif

#endif // !defined(AFX_CVPROTOCOLDDCCTRL_H__625A439B_058D_4D05_832B_8EBCEB9C61B9__INCLUDED_)

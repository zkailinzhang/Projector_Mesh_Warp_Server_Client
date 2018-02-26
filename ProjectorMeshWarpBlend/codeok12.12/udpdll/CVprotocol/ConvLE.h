// ConvLE.h: interface for the CConvLE class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONVLE_H__77312B41_10DA_4A0C_A64C_BB59EA1A2E2E__INCLUDED_)
#define AFX_CONVLE_H__77312B41_10DA_4A0C_A64C_BB59EA1A2E2E__INCLUDED_


#if defined(CVPROJ) && GCM_VERSION==4

#include "Endian.h"

template<typename base_t>
class CConvLE  
{
public:
  CConvLE() {};
  ~CConvLE() {};


inline void operator= (const base_t Value)
{
  switch (sizeof(base_t))
  {
  case 1:
    m_Val = (unsigned short)Value;
    break;
  case 2: 
    m_Val = CONVERT_TO_LE16((unsigned short)Value);
    break;
  case 4:
    m_Val = CONVERT_TO_LE32((unsigned long)Value);
    break;
  case 8:
    m_Val = CONVERT_TO_LE64((unsigned long long)Value);
    break;
  default:
    break;
  }
};


inline operator base_t() const
{
  base_t ret;

  switch (sizeof(base_t))
  {
  case 1:
    ret = (base_t)m_Val;
    break;
  case 2:
    ret = (base_t)CONVERT_FROM_LE16(m_Val);
    break;
  case 4:
    ret =  (base_t)CONVERT_FROM_LE32(m_Val);
    break;
  case 8:
    ret =  (base_t)CONVERT_FROM_LE64(m_Val);
    break;
  default:
    ret = (base_t)m_Val;
    break;
  }

  return ret;
};

private:
  base_t m_Val;
};

#else //defined(CVPROJ) && GCM_VERSION==4

template<typename base_t>
class CConvLE  
{
public:
  CConvLE() {};
  ~CConvLE() {};
  inline void operator= (const base_t Value) { m_Val = Value;};
  inline operator base_t() const { return m_Val; };

private:
  base_t m_Val;
};

#endif  //defined(CVPROJ) && GCM_VERSION==4

#endif // !defined(AFX_CONVLE_H__77312B41_10DA_4A0C_A64C_BB59EA1A2E2E__INCLUDED_)



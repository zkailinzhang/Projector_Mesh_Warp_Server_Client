//## begin module.cm preserve=no
//	  %X% %Q% %Z% %W%
//## end module.cm

//## begin module.cp preserve=no
//## end module.cp

//## Module: CVprotocolAppRecords; Package body
//## Subsystem: cvsetup
//	c:\src\graphics\cvsetup
//## Source file: c:\src\graphics\cvsetup\CVprotocolAppRecords.cpp

//## begin module.additionalIncludes preserve=no
//## end module.additionalIncludes

//## begin module.includes preserve=yes
#include "stdafx.h"
//## end module.includes

// CVprotocolAppRecords
#include "CVprotocolAppRecords.h"
//## begin module.declarations preserve=no
//## end module.declarations

//## begin module.additionalDeclarations preserve=yes


//## end module.additionalDeclarations



void CFrequencyValRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_SET_FREQUENCY);
}

void CFrequencyValRecord::Set(unsigned short usConfiguration, unsigned short usFreqVal)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_usFreqVal = usFreqVal;
}


void CPhaseValRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_SET_PHASE);
}

void CPhaseValRecord::Set(unsigned short usConfiguration, unsigned short usPhaseVal, unsigned short usPhaseValMax)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_usPhaseVal = usPhaseVal;

  // CPhaseValRecord upgraded with m_usPhaseValMax, only set this value if space is provided
    if (GetSize() >= offsetof(CPhaseValRecord, m_usPhaseValMax) + sizeof(m_usPhaseValMax))
      m_usPhaseValMax = usPhaseValMax;
}


void CHoriPosValRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_SET_HORPOSITION);
}

void CHoriPosValRecord::Set(unsigned short usConfiguration, unsigned short usHoriPosVal)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_usHoriPosVal = usHoriPosVal;
}

void CVertPosValRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_SET_VERTPOSITION);
}

void CVertPosValRecord::Set(unsigned short usConfiguration, unsigned short usVertPosVal)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_usVertPosVal = usVertPosVal;
}


void CResolutionRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_SET_RESOLUTION);
}

void CResolutionRecord::Set(unsigned short usConfiguration, unsigned short usHres, unsigned short usVres)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_usHres = usHres;
  m_usVres = usVres;
}


void CPllValRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_SET_PLL);
}

void CPllValRecord::Set(unsigned short usConfiguration, unsigned short usPllVal)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_usPllVal = usPllVal;
}


void CHsyncTriggerRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_SET_HSYNC_TRIGGER);
}

void CHsyncTriggerRecord::Set(unsigned short usConfiguration, unsigned short usHsyncTrigger)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_usHsyncTrigger = usHsyncTrigger;
}


void CAdFilterRRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_SET_AD_FILTER_R);
}

void CAdFilterRRecord::Set(unsigned short usConfiguration, unsigned short usAdFilterR)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_usAdFilterR = usAdFilterR;
}


void CAdFilterCRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_SET_AD_FILTER_C);
}

void CAdFilterCRecord::Set(unsigned short usConfiguration, unsigned short usAdFilterC)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_usAdFilterC = usAdFilterC;
}



void CPrivateSetupDataRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_PRIVATE_SETUP_DATA);
}

void CPrivateSetupDataRecord::Set(unsigned short usConfiguration, unsigned short usStart, unsigned char* pData,
           unsigned char usCount, unsigned short usHres, unsigned short usVres)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  ASSERT(SIZE_OF_PRIVATE_SETUP_DATA >= usStart + usCount);
  memcpy(&m_pData[usStart], pData, usCount);
  m_usHres = usHres;
  m_usVres = usVres;

}

void CUtmSignalInfoRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_SIGNAL_INFO);
}

void CUtmSignalInfoRecord::Set(unsigned short usConfiguration, unsigned short usSource,     
	  unsigned long ulHfreq, unsigned short usVfreq, 
    unsigned short usSyncPolarity, unsigned short usHsyncTime, unsigned short usHFP, 
    unsigned short usVsyncTime, unsigned short usVFP, unsigned short usVtot, unsigned short usSyncType)
{
  AssertValid();
  m_usSource = usSource;
  m_usConfiguration = usConfiguration;
  m_ulHfreq = ulHfreq;
  m_usVfreq = usVfreq;
  m_usSyncPolarity = usSyncPolarity;  // The bits are defined in CommandTypes.h
  m_usHsyncTime = usHsyncTime;
  m_usHFP = usHFP;
  m_usVsyncTime = usVsyncTime;
  m_usVFP = usVFP;
  m_usVtot = usVtot;
  m_usSyncType = usSyncType;
}


void CHresDefaultRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration)+sizeof(m_usVres), CV_SET_HRES_DEFAULT);
}

void CHresDefaultRecord::Set(unsigned short usConfiguration, unsigned short usVres,     
	  unsigned short usHres)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_usVres = usVres;
  m_usHres = usHres;
}

void CSyncTypeRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_SYNCTYPE);
}

void CSyncTypeRecord::Set(unsigned short usConfiguration, unsigned short usSyncType)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  ASSERT(usSyncType == SYNC_TYPE_SEPARATE || usSyncType == SYNC_TYPE_COMPOSITE || usSyncType == SYNC_TYPE_SOG || usSyncType == SYNC_TYPE_AUTO);
  m_usSyncType = usSyncType;
}


void CCoastCtrlRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_COASTCTRL);
}

void CCoastCtrlRecord::Set(unsigned short usConfiguration, bool bCoastAuto, bool bCoastActive)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_bCoastAuto = bCoastAuto;
  m_bCoastActive = bCoastActive;
}


void CEDIDCtrlRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_EDIDCTRL);
}


void CEDIDCtrlRecord::Set(unsigned short usConfiguration, unsigned char ucIgnoreProjector, bool bEDIDauto, unsigned short usEDIDtype)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_ucIgnoreProjector = ucIgnoreProjector;
  m_bEDIDauto = bEDIDauto;
  m_usEDIDtype = usEDIDtype;
}


void CEDIDCtrlRecord::Set(unsigned short usConfiguration, bool bIgnoreProjector, bool bEDIDauto, unsigned short usEDIDtype)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_ucIgnoreProjector = bIgnoreProjector?1:0;
  m_bEDIDauto = bEDIDauto;
  m_usEDIDtype = usEDIDtype;
}


void CGenericOpRecord::Set(unsigned short usConfiguration, unsigned short usOperationId, unsigned long ulOperationTarget, unsigned long ulValue)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_usOperationId = usOperationId;
  m_ulOperationTarget = ulOperationTarget;
  m_ulValue = ulValue;
}


void CGenericOpRecord::Create()
{
  CreateRecordBase(sizeof(*this), 2 + sizeof(m_usConfiguration) + sizeof(m_usOperationId) + sizeof(m_ulOperationTarget), CV_GENERIC_OP);
}


void CGenericOpRecord::CreateCommand()
{
  //to aviod that records are merged together, needed for some records
  CreateRecordBase(sizeof(*this), 0, CV_GENERIC_OP);
}


void CGenericReqRecord::Set(unsigned short usOperationId, unsigned long ulOperationTarget,unsigned long ulValue)
{
  AssertValid();
  m_usOperationId = usOperationId;
  m_ulOperationTarget = ulOperationTarget;
  m_ulValue = ulValue;
}


void CGenericReqRecord::Create()
{
  CreateRecordBase(sizeof(*this), 2 + sizeof(m_usOperationId) + sizeof(m_ulOperationTarget), CV_GENERIC_REQ);
}


void CGenericReqVarRecord::Set(unsigned char ucVarType, unsigned short usVar, unsigned short usValue)
{
  AssertValid();
  ucVarType = m_ucVarType;
  usVar = m_usVar;
  usValue = m_usValue;
}

void CGenericReqVarRecord::Create()
{
  CreateRecordBase(sizeof(*this), 2 + sizeof(m_ucVarType) + sizeof(m_usVar), CV_GENERIC_REQVAR);
}


void CCommStatRecord::Set(unsigned short usBytesSent, unsigned short usPacketsSent,
                          unsigned short usBytesReceived, unsigned short usPacketsReceived,
                          unsigned short usPendingSend, unsigned short usPendingReceive)
{
  m_usBytesSent = usBytesSent;
  m_usPacketsSent = usPacketsSent;
  m_usBytesReceived = usBytesReceived;
  m_usPacketsReceived  = usPacketsReceived;
  m_usPendingSend = usPendingSend;
  m_usPendingReceive = usPendingReceive;
}

void CCommStatRecord::Create()
{
  CreateRecordBase(sizeof(*this), 2, CV_COMM_STAT);
}

void CCVSourceRecord::Set (unsigned short usConfiguration, char cValue)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_cValue = cValue;
}

void CCVSourceRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_SOURCE);
}


void CCVBrightnessRecord::Set (unsigned short usConfiguration, unsigned char ucLightLevel, unsigned char ucValue)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_ucLightLevel = ucLightLevel;
  m_ucValue = ucValue;
}


void CCVBrightnessRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration)+sizeof(m_ucLightLevel), CV_BRIGHTNESS);
}


void CCVContrastRecord::Set (unsigned short usConfiguration, unsigned char ucLightLevel, unsigned char ucValue)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_ucLightLevel = ucLightLevel;
  m_ucValue = ucValue;
}


void CCVContrastRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration)+sizeof(m_ucLightLevel), CV_CONTRAST);
}


void CCVBrightnessRGBRecord::Create()
{
  CreateRecordBase(sizeof(*this), 2 + sizeof(m_usConfiguration) + sizeof(m_ucColour), CV_BRIGHTNESS_RGB);
}


void CCVBrightnessRGBRecord::Set(unsigned short usConfiguration, unsigned char ucColour, unsigned char ucValue)
{
  AssertValid();
  ASSERT(ucColour == BLUE_CHANNEL || ucColour == RED_CHANNEL || ucColour == GREEN_CHANNEL);
  m_usConfiguration = usConfiguration;
  m_ucColour = ucColour;
  m_ucValue = ucValue;
}

void CCVContrastRGBRecord::Create()
{
  CreateRecordBase(sizeof(*this), 2 + sizeof(m_usConfiguration) + sizeof(m_ucColour), CV_CONTRAST_RGB);
}


void CCVContrastRGBRecord::Set(unsigned short usConfiguration, unsigned char ucColour, unsigned char ucValue)
{
  AssertValid();
  ASSERT(ucColour == BLUE_CHANNEL || ucColour == RED_CHANNEL || ucColour == GREEN_CHANNEL);
  m_usConfiguration = usConfiguration;
  m_ucColour = ucColour;
  m_ucValue = ucValue;
}


void CCVCompactDesignerDataRecord::Create(unsigned short usDataSize)
{
  CreateRecordBase(sizeof(*this) - sizeof(m_ucStartOfData) + usDataSize, 2 + sizeof(m_usId), CV_COMPACTDESIGNER_DATA);
}


void CCVCompactDesignerDataRecord::Set(unsigned short usId, unsigned char* pData)
{
  AssertValid();
  m_usId = usId;

  // We copy the data into the pos. for the variable m_ucStartOfData, and will then
  // overwrite the following data. 
  // This will be ok as long as we use CreateInBuffer to create the record
  memcpy(&m_ucStartOfData, pData, GetDataSize());
}

void CCVOrientationRecord::Set (unsigned short usConfiguration, char cValue)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_cValue = cValue;
}

void CCVOrientationRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_ORIENTATION);
}

CCVSourceScanRecord* CCVSourceScanRecord::CreateInBuffer (char* pBuffer)
{
  ASSERT(pBuffer);

  CCVSourceScanRecord *pItem = (CCVSourceScanRecord *) pBuffer;
  pItem->Create();

  return pItem;
}

void CCVUpscaleRecord::Set (unsigned short usConfiguration, char cValue)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_cValue = cValue;
}

void CCVUpscaleRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_UPSCALE);
}

void CCVSourceScanRecord::Set (unsigned short usConfiguration, char cValue)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_cValue = cValue;
}

void CCVSourceScanRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_SOURCE_SCAN);
}

void CCVStandbyRecord::Set (unsigned short usConfiguration, char cValue)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_cValue = cValue;
}

void CCVStandbyRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_STANDBY);
}

void CCVLockSetupRecord::Set (unsigned short usConfiguration, char cValue)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_cValue = cValue;
}

void CCVLockSetupRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_LOCKSETUP);
}

void CFunctionAvailableRecord::Set(unsigned short usFunction, bool bAvailable)
{
  AssertValid();
  ASSERT(GetSize() == (unsigned short) sizeof(*this));
  m_usFunction = usFunction;
  m_bAvailable = bAvailable;
}

void CFunctionAvailableRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2 + sizeof(m_usFunction), CV_FUNC_AVAILABLE);
}

void CFunctionsAvailableRecord::Create ()
{
  m_usNFunctions = 0;
  m_usFunction[0] = 0;
  CreateRecordBase(sizeof(*this) + GetExtraSize(), 2+sizeof(m_usConfiguration), CV_FUNCS_AVAILABLE);
}

void CFunctionsAvailableRecord::Set(unsigned short usConfiguration, unsigned char ucVersion, unsigned short usNFunctions, unsigned short *pusFunctionList)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_ucVersion = ucVersion;

  m_usNFunctions = usNFunctions;
  for (unsigned short i = 0; i < usNFunctions; i++)
    m_usFunction[i] = pusFunctionList[i];

  SetSize(sizeof(*this) + GetExtraSize());
}


void CAnalyzeVideoRecord::Set(unsigned char ucColour, unsigned char* pucVideo, unsigned char ucSampleMode, unsigned char ucBitPerUnit)
{
  AssertValid();
  ASSERT(ucColour & (BLUE_CHANNEL|RED_CHANNEL|GREEN_CHANNEL));
  m_ucColour = ucColour;
  m_ucSampleMode = ucSampleMode;
  m_ucBitPerUnit = ucBitPerUnit;
  
  memcpy(&m_ucStartOfVideo, pucVideo, GetDataSize());
}

void CAnalyzeVideoRecord::Create(unsigned short usDataSize)
{
  CreateRecordBase(sizeof(*this) - sizeof(m_ucStartOfVideo) + usDataSize, 
    2 + sizeof(m_ucColour) + sizeof(m_ucSampleMode), CV_ANALYZE_VIDEO);
}

void CAnalyzeVideoRecord_V2::Set(unsigned short usConfiguration, unsigned char ucColour, unsigned char* pucVideo, unsigned char ucSampleMode, unsigned char ucBitPerUnit)
{
  AssertValid();
  ASSERT(ucColour & (BLUE_CHANNEL|RED_CHANNEL|GREEN_CHANNEL));
  m_usConfiguration = usConfiguration;
  m_ucColour = ucColour;
  m_ucSampleMode = ucSampleMode;
  m_ucBitPerUnit = ucBitPerUnit;
  
  memcpy(&m_ucStartOfVideo, pucVideo, GetDataSize());
}

void CAnalyzeVideoRecord_V2::Create(unsigned short usDataSize)
{
  CreateRecordBase(sizeof(*this) - sizeof(m_ucStartOfVideo) + usDataSize, 
    2 + sizeof(m_usConfiguration) + sizeof(m_ucColour) + sizeof(m_ucSampleMode), CV_ANALYZE_VIDEO_V2);
}


void CAnalyzeHistogramRecord::Set(unsigned char ucColour, unsigned char* pucHistogram, unsigned char ucSampleMode, unsigned char ucBitPerUnit)
{
  AssertValid();
  ASSERT(ucColour & (BLUE_CHANNEL|RED_CHANNEL|GREEN_CHANNEL));
  m_ucColour = ucColour;
  m_ucSampleMode = ucSampleMode;
  m_ucBitPerUnit = ucBitPerUnit;
  
  memcpy(&m_ucStartOfHistogram, pucHistogram, GetDataSize());
}



void CAnalyzeHistogramRecord::Create(unsigned short usDataSize)
{
 CreateRecordBase(sizeof(*this) - sizeof(m_ucStartOfHistogram) + usDataSize, 
   2 + sizeof(m_ucColour) + sizeof(m_ucSampleMode), CV_ANALYZE_HISTOGRAM);
}
  
void CAnalyzeHistogramRecord_V2::Set(unsigned short usConfiguration, unsigned char ucColour, unsigned char* pucHistogram, unsigned char ucSampleMode, unsigned char ucBitPerUnit)
{
  AssertValid();
  ASSERT(ucColour & (BLUE_CHANNEL|RED_CHANNEL|GREEN_CHANNEL));
  m_usConfiguration = usConfiguration;
  m_ucColour = ucColour;
  m_ucSampleMode = ucSampleMode;
  m_ucBitPerUnit = ucBitPerUnit;
  
  memcpy(&m_ucStartOfHistogram, pucHistogram, GetDataSize());
}

void CAnalyzeHistogramRecord_V2::Create(unsigned short usDataSize)
{
 CreateRecordBase(sizeof(*this) - sizeof(m_ucStartOfHistogram) + usDataSize, 
   2 + sizeof(m_usConfiguration) + sizeof(m_ucColour) + sizeof(m_ucSampleMode), CV_ANALYZE_HISTOGRAM_V2);
}


void CCardsConnectedRecord::Set(unsigned short usConfiguration, unsigned char *ucMCMSerialNumber,
           unsigned char *ucGCM1SerialNumber, unsigned char *ucGCM2SerialNumber)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  memcpy(m_ucMCMSerialNumber, ucMCMSerialNumber, sizeof(m_ucMCMSerialNumber));
  memcpy(m_ucGCM1SerialNumber, ucGCM1SerialNumber, sizeof(m_ucGCM1SerialNumber));
  memcpy(m_ucGCM2SerialNumber, ucGCM2SerialNumber, sizeof(m_ucGCM2SerialNumber));
}

  
void CCardsConnectedRecord::Create()
{
  CreateRecordBase(sizeof(*this), 2 + sizeof(m_usConfiguration), CV_CARDS_CONNECTED);
}


void CIpPropertiesRecord::SetpucIpAddress(const unsigned char *pucAddress)
{
  AssertValid();
  for (unsigned short i = 0; i < 4; i++)
		m_pucIpAddress[i] = pucAddress[i];
}

void CIpPropertiesRecord::SetpucSubnetMask(const unsigned char *pucMask)
{
  AssertValid();
  for (unsigned short i = 0; i < 4; i++)
		m_pucSubnetMask[i] = pucMask[i];
}

void CIpPropertiesRecord::SetucDhcp(const unsigned char ucDhcp)
{
  AssertValid();
  m_ucDhcp = ucDhcp;
}

void CIpPropertiesRecord::Create()
{
  CreateRecordBase(sizeof(*this), 2, CV_IPPROPERTIES);
}



void CKeyChallengeRecord::Set(unsigned short usKeyIndex, unsigned long ulChallenge, unsigned long ulTimeStamp)
{
  AssertValid();
  m_usKeyIndex = usKeyIndex;
  m_ulChallenge = ulChallenge;
  m_ulTimeStamp = ulTimeStamp;
}

void CKeyChallengeRecord::Create()
{
  CreateRecordBase(sizeof(*this), 2, CV_KEYCHALLENGE);
}



void CTotalLampTimeRecord::SetsTotalLampTime(const short sTotalLampTime)
{
  AssertValid();
  m_sTotalLampTime = sTotalLampTime;
}

void CTotalLampTimeRecord::Create()
{
  CreateRecordBase(sizeof(*this), 2, CV_TOTALLAMPTIME);
}



void CCwIndexDelayRecord::SetusIndexDelay(const unsigned short usIndexDelay)
{
  AssertValid();
  m_usIndexDelay = usIndexDelay;
}

void CCwIndexDelayRecord::Create()
{
  CreateRecordBase(sizeof(*this), 2, CV_CWINDEXDELAY);
}

void CWirelessNameRecord::Create()
{
  m_WirelessName.Reset();
  CreateRecordBase(sizeof(*this) + m_WirelessName.GetExtraSize(), 2, CV_WIRELESSNAME);
}

void CWirelessNameRecord::Set(const char *pszWirelessName)
{
  AssertValid();
  ASSERT(GetSize() == sizeof(*this) + m_WirelessName.GetExtraSize());
  SetCVString(&m_WirelessName, pszWirelessName);
  SetSize(sizeof(*this) + m_WirelessName.GetExtraSize());
}


void CWepRecord::Set_128(unsigned char ucFlags, unsigned short usDefaultKeyId,
               unsigned char ucKey1[13], unsigned char ucKey2[13], 
               unsigned char ucKey3[13], unsigned char ucKey4[13])
{
  AssertValid();
  m_bUse128BitKeys = true;
 
  m_ucFlags = ucFlags;
  m_usDefaultKeyId = usDefaultKeyId;
  memcpy(m_ucKey1, ucKey1, 13);
  memcpy(m_ucKey2, ucKey2, 13);
  memcpy(m_ucKey3, ucKey3, 13);
  memcpy(m_ucKey4, ucKey4, 13);
}

void CWepRecord::Set_64(unsigned char ucFlags, unsigned short usDefaultKeyId,
              unsigned char ucKey1[5], unsigned char ucKey2[5], 
              unsigned char ucKey3[5], unsigned char ucKey4[5])
{
  AssertValid();
  m_bUse128BitKeys = false;

  m_ucFlags = ucFlags;
  m_usDefaultKeyId = usDefaultKeyId;
  memcpy(m_ucKey1, ucKey1, 5);
  memcpy(m_ucKey2, ucKey2, 5);
  memcpy(m_ucKey3, ucKey3, 5);
  memcpy(m_ucKey4, ucKey4, 5);
}

void CWepRecord::Create()
{
  CreateRecordBase(sizeof(*this), 2, CV_WEP);
}


void CWhiteBoostRecord::Set(unsigned short usConfiguration, short sWhiteBoost)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_sWhiteBoost = sWhiteBoost;
}

void CWhiteBoostRecord::Create()
{
  CreateRecordBase(sizeof(*this), 2 + sizeof(m_usConfiguration), CV_WHITEBOOST);
}

void CLampPowerRecord::Set(unsigned char ucLampPower)
{
  AssertValid();
  m_ucLampPower = ucLampPower;
}

void CLampPowerRecord::Create()
{
  CreateRecordBase(sizeof(*this), 2, CV_LAMPPOWER);
}

void CManualResolutionRecord::Set (unsigned short usConfiguration, char cValue)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_cValue = cValue;
}

void CManualResolutionRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_MANUAL_RESOLUTION);
}


void CProjectorConnectedRecord::Set (unsigned short usConfiguration, char cFamily)
{
  AssertValid();
  m_usConfiguration = usConfiguration;
  m_cFamily = cFamily;
}


void CProjectorConnectedRecord::Create ()
{
  CreateRecordBase(sizeof(*this), 2+sizeof(m_usConfiguration), CV_PROJECTOR_CONNECTED);
}


void CVScreenResultRecord::Create()
{
  CreateRecordBase(sizeof(*this), 2 + sizeof(m_ucSensor), CV_SCREEN_RESULT); 
}


void CVScreenResultRecord::Set(unsigned char ucSensor, unsigned long ulHPos, unsigned long ulVPos, unsigned char ucAnalyseId)
{
  AssertValid();
  m_ucSensor = ucSensor;
  m_ulHPos = ulHPos;
  m_ulVPos = ulVPos;
  m_ucAnalyseId = ucAnalyseId;
}


void CScreenHistogramRecord::Create(unsigned short usHistogramSize)
{
  CreateRecordBase(sizeof(*this)-sizeof(m_ucData)+usHistogramSize, 2 + sizeof(m_ucSensorNo), CV_SCREEN_HISTOGRAM); 
}

void CScreenHistogramRecord::Set(unsigned char ucSensorNo, unsigned short usRangeMin, unsigned char ucStep, unsigned char ucBitPerUnit, unsigned char* pucData)
{
  AssertValid();
  m_ucSensorNo = ucSensorNo;
  m_usRangeMin = usRangeMin;
  m_ucStep = ucStep;
  m_ucBitPerUnit = ucBitPerUnit;

  memcpy(m_ucData, pucData, GetDataSize());
}


void CVScreenThresholdRecord::Create()
{
  CreateRecordBase(sizeof(*this), 2, CV_SCREEN_THRESHOLD); 
}


void CVScreenThresholdRecord::Set(unsigned short usThreshold)
{
  AssertValid();
  m_usThreshold = usThreshold;
}




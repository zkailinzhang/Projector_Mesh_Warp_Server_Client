#define CV_TESTPATTERN          10
#define CV_GAMMA                11    // Rename to CV_GAMMA_V1
#define CV_CHANNELS             12
#define CV_COLORBALANCE         13
#define OBSOLETE1               14
#define CV_EDGE_V1              15    // Old version limited to 4 samples
#define CV_EDGEALPHA            16
#define CV_GEOMETRY_V1          17
#define CV_GEOMETRYCONTROLPOINT_V1 18
#define CV_EDGESAMPLE_V1        19

#define CV_DISABLE               20
#define CV_RESET                 21
#define CV_RESTORE_CONFIGURATION 22

#define CV_EDGE_V2              23    // New version allows >4 samples
#define CV_EDGESAMPLE_V2        24
#define CV_VALIDHANDLES         25    // Valid handles for geometry and edge

#define CV_GEOMETRY_V2          26    // New version includes geometry handle, used for multi-geometry
#define CV_GEOMETRYCONTROLPOINT_V2  27    // New version used for multi-geometry

#define CV_CONTRAST             50
#define CV_BRIGHTNESS           51
#define CV_HUE                  52
#define CV_SATURATION           53
#define CV_FREQUENCY            54
#define CV_PHASE                55
#define CV_AUTOSETUP            56
#define CV_SOURCE               57    // Set active source, see constants at end of file
#define CV_STANDBY              58
#define CV_ORIENTATION          59
#define CV_UPSCALE              60
#define CV_VIDEOMODE            61
#define CV_AUTOCONTRAST         62
#define CV_LOCKSETUP            63
#define CV_LAMPSTATE            64
#define CV_HORPOSITION          65
#define CV_VERTPOSITION         66

#define CV_FILTERCOEFF          67


#define CV_SET_FREQUENCY				68
#define CV_SET_PHASE					  69
#define CV_SET_HORPOSITION			70
#define CV_SET_VERTPOSITION			71
#define CV_SET_RESOLUTION				72
#define CV_SET_PLL						  73
#define OBSOLETE2         			74  // Reserved, not used
#define CV_SIGNAL_INFO					75
#define CV_PRIVATE_SETUP_DATA   76
#define CV_SET_AD_FILTER_R      77
#define CV_SET_AD_FILTER_C      78
#define CV_SET_HSYNC_TRIGGER    79

#define CV_SET_HRES_DEFAULT     80

#define CV_SYNCTYPE             81
#define CV_COASTCTRL            82
#define CV_EDIDCTRL             83
#define CV_OUTPUTCTRL           84  // See constants at end of file

#define CV_GENERIC_OP           85    // Generic projector operation, based on PixelWorks protocol
#define CV_GENERIC_REQ          86    // Generic request, read value from projector, based on PixelWorks protocol
#define CV_GENERIC_SETVAR       87    // Generic set variable in projector, based on PixelWorks protocol
#define CV_GENERIC_REQVAR       88    // Generic request, read variable from projector, based on PixelWorks protocol


#define CV_COMM_STAT            89    // Read communication statistics for the link UTM - Projector

// #define CV_SET_SOURCE           90    // Set active source, see constants at end of file
#define OBSOLETE3               90    // Command already existed, see CV_SOURCE

#define CV_BRIGHTNESS_RGB       91    // Set brightness for R, G or B. Use BLUE_CHANNEL etc. to specify colour
#define CV_CONTRAST_RGB         92    // Set contrast for R, G or B. Use BLUE_CHANNEL etc. to specify colour

#define CV_COMPACTDESIGNER_DATA 93    // Compact Designer private data record for storage only

#define CV_FUNC_AVAILABLE       94    // Check if a particular function is available

#define CV_MASK                 95    // Used with edge record
#define CV_MASKSAMPLE           96    // Used with edgesample record

#define CV_SOURCE_SCAN          97    // Set source searching on/off

#define CV_GEOMETRY_V3          98      // Extended geometry mesh, up to 30x30 points
#define CV_GEOMETRYCONTROLPOINT_V3  99

#define CV_SCALING_FORMAT       100   //Defines the scaling signal format output: res, bp, synclen, tot 
#define CV_SCALING_MODE         101   //Defines the scaling setup

#define CV_ANALYZE_VIDEO        102   //Get active 
#define CV_ANALYZE_HISTOGRAM    103

#define CV_STEREO_CONTROL       104

#define CV_COLOUR_SPACE         105   

#define CV_DRAWLINE				      106
#define CV_DRAWTEXT				      107
#define CV_DRAWFILE             108
#define CV_TPENCODED            109
#define CV_DRAWCTRL             110
#define CV_DRAWRECT				      111
// Space for new TP draw commands

#define CV_COLOR_MEASUREMENT    120    // CompactDesigner internal use only

#define CV_FUNCS_AVAILABLE      121    // Get list of particular function that is available

#define CV_ANALYZE_VIDEO_V2     122    //Possible to specify channel/source
#define CV_ANALYZE_HISTOGRAM_V2 123    //Possible to specify channel/source

#define CV_AUTOSETUP_V2         124    //Possible to specify channel/source

#define CV_FRAME_INPUT_BLOCK    125    //Possible to specify channel
#define CV_FRAME_OUTPUT_BLOCK   126    //Possible to specify channel

#define CV_CARDS_CONNECTED      127    //Card adresses connected to the MCM card

#define CV_INVALIDDATA         0x80    // = 128 Invalid value for projector controls

#define CV_FRAME_ENABLE         129

#define CV_GAMMA_V2             130    // Gamma with embedded degamma

#define CV_WHITEBOOST           131

#define CV_IPPROPERTIES         132

#define CV_TOTALLAMPTIME        133

#define CV_RESETLAMPTIME        134

#define CV_CWINDEXDELAY         135
#define CV_CWSTORE              136

#define CV_LICENSEKEY           137
#define CV_KEYCHALLENGE         138
#define CV_DYNAMICLICENSE       139

#define CV_HOTSPOT              140
#define CV_HOTSPOTCONTROLPOINT  141

#define CV_LAMPPOWER            142

#define CV_WIRELESSNAME         143

#define CV_WEP                  144

#define CV_COLOROFFSET          145

#define CV_MANUAL_RESOLUTION    146

#define CV_PROJECTOR_CONNECTED  147

#define CV_SCREEN_ANALYSE       148
#define CV_SCREEN_RESULT        149
#define CV_SCREEN_LEDPATTERN    150
#define CV_DYNAMICTESTPATTERN   151
#define CV_SCREEN_THRESHOLD     152
#define CV_SCREEN_CHAIN_INFO    153


#define CV_STEREO_INPUT_ENABLE  154
#define CV_STEREO_INPUT_SWAP    155
#define CV_STEREO_OUTPUT_RIGHT  156

#define CV_SYNC_SOURCE          157

#define CV_USERDEF_SETTING      158

#define CV_SCREEN_HISTOGRAM     159

#define CV_BLACKLEVEL             160
#define CV_BLACKLEVELCONTROLPOINT 161
#define CV_BLACKLEVELCUTOUT       162

#define CV_GEOMETRYCONTROLPOINT_NOMINALPOS   163   // Used with geometry control point record to set nominal position for point

#define CV_BLACKLEVELMASK         164
#define CV_BLACKLEVELMASKSAMPLE   165

#define CV_SCREEN_MEASURE_COLOR		166 // For color measurement




#define CURRENT_CONFIGURATION   0       //obsolete
#define ANY_CONFIGURATION       0xffff

//Valid configuration settings, specifies level of decoding for GCM and MCM drivers 
//uses bit 4-7 of configuration word.
#define CONFIG_UNDEF            0x0000     //so driver can detect old config commands
#define CONFIG_SYSTEM           0x0010     //System: Global decoding
#define CONFIG_CHANNEL1         0x0020     //May be ORed with specified input source if relevant, see CV_SOURCE related constants below
#define CONFIG_CHANNEL2         0x0040     //May be ORed with specified input source if relevant, see CV_SOURCE related constants below
#define CONFIG_CHANNELB         0x0080     //For board to board channel, input source never relevant 

#define CONFIG_ANY_CHANNEL      0x00f0
#define CONFIG_ANY_SOURCE       0x000f

#define REQUEST_PROJECTOR_STATE 40001
#define PROJECTOR_SERIAL_NUMBER 40002
#define PROJECTOR_NAME          40003
#define PROJECTOR_VERSION_INFO  40004
#define PROJECTOR_HOST_INFO     40005
#define REQUEST_STATE_LIST      40006
#define PROJECTOR_HOST_INFO_V2  40007
#define PROJECTOR_HOST_INFO_V3  40008


#define PROJECTOR_SOFTWARE_UPDATE  41001
#define PROJECTOR_RESTART          41002
#define PROJECTOR_FLASH_ERASE      41003
#define PROJECTOR_FLASH_DATA       41004
#define PROJECTOR_RAM_DATA         41005
#define PROJECTOR_ERROR_MESSAGE    41006
#define PROJECTOR_SAVE_PARAMETERS  41007
#define PROJECTOR_RESTORE_DEFAULTS 41008
#define PROJECTOR_MESSAGE_LEVEL    41009
#define PROJECTOR_TEST_MESSAGE     41010

#define PROJ_DAVIS_SW_UPDATE       42001
#define PROJ_DAVIS_COMMAND         42002
#define PROJ_PD_SW_UPDATE          42003
#define PROJ_PD_COMMAND            42004
#define PROJ_PD_SW_END             42005

#define UDP_WRAPPER             50000
#define UDP_ACK                 50010

#define SERIAL_OUTBOUND_WRAPPER 51000
#define SERIAL_INBOUND_WRAPPER  51001

#define SERIAL_ACK              51010

#define DEVICE_WRAPPER          52000
#define DEVICE_ACK              52010

#define DDCCTRL_WRAPPER         53000
#define DDCCTRL_ACK             53010
#define DDCCTRL_WRAPPER_REQUEST 53020

#define MAX_MESSAGE_SIZE      1536    // Max. size of any message
#define MAX_MESSAGE_BODY_SIZE 1530    // Size - preamble - CRC (for safety)
#define MSG_BUFFER_SIZE       (MAX_MESSAGE_SIZE + 8)  // Size for padding (0xdeaddead in _DEBUG)
#define MAX_LANTOSERIAL_SIZE   580    // Not in use//Max message size for LAN communication in SX+ (through LAN to Serial Module)
#define MAX_DDCCTRL_SIZE       (256-2) //-2 is read and write counter

#define DEBUG_MESSAGE         1
#define INFO_MESSAGE          2
#define WARNING_MESSAGE       3
#define ERROR_MESSAGE         4
#define UNKNOWN_MESSAGE       5
#define CLEAR_MESSAGE         6

//
// Protocol constants
//

#define MESSAGE_FLAG_TIMEOUT  0x8000


#define BLUE_CHANNEL          0x01
#define GREEN_CHANNEL         0x02
#define RED_CHANNEL           0x04
#define BLUE_DEGAMMA_CHANNEL  0x08
#define GREEN_DEGAMMA_CHANNEL 0x10
#define RED_DEGAMMA_CHANNEL   0x20
#define WHITE_CHANNEL					0x40 /// Color measurement only.


#define DISABLE_EDGE        1
#define DISABLE_GAMMA       2
#define DISABLE_GEOMETRY    4
#define DISABLE_HOTSPOT     8
#define DISABLE_COLOR       0x10
#define DISABLE_BLANKING    0x20
#define DISABLE_DITHER      0x40
#define DISABLE_YUVMODE     0x80
#define DISABLE_SCALING     0x100
#define DISABLE_MASK        0x200
#define DISABLE_STEREO      0x400
#define DISABLE_BLACKLEVEL  0x800

#define DISABLE_NONE        0
#define DISABLE_ALL     0xfff

#define POR_NORMAL          0
#define POR_MIRROR          1
#define POR_MIRROR_ROTATE   2
#define POR_ROTATE          3

#define AHANDLE_GAMMAADJUSTMENT       0xffffff00
#define AHANDLE_COLORADJUSTMENT       0xffffff01
#define AHANDLE_NURBSMESHADJUSTMENT   0xffffff02    // Used in CCVGeometryRecord_V1 only
#define AHANDLE_CALCULATEDGEOMETRY    0xffffff03
#define AHANDLE_SCALINGADJUSTMENT     0xffffff04
#define AHANDLE_STEREOADJUSTMENT      0xffffff05
#define AHANDLE_HOTSPOTADJUSTMENTCALC 0xffffff06
#define AHANDLE_HOTSPOTADJUSTMENTELLIPSE 0xffffff07
#define AHANDLE_LENSGEOMETRY          0xffffff08
#define AHANDLE_FILEGEOMETRY          0xffffff09

#define AHANDLE_EDGE_BASEHANDLE       0x00001000    // 4096 handles available for edges
#define AHANDLE_NURBSMESH_BASEHANDLE  0x00002000
#define AHANDLE_HOTSPOT_BASEHANDLE    0x00003000
#define AHANDLE_BLACKLEVEL_BASEHANDLE 0x00004000
#define AHANDLE_BLACKLEVELMASK_BASEHANDLE 0x00005000

// Interpolation mode for geometry (CCVGeometryRecord_V2)
#define INTERPOLATIONMODE_NURBS       0    // Original - NURBS mesh with regular xy spacing
#define INTERPOLATIONMODE_POLYNOMIAL  1    // Second order polynomial ensures smooth mesh through control points (calculated geometry)
#define INTERPOLATIONMODE_LINEARARRAY 2    // Linear array with nonequal point spacing in x and y (load from file)

#define LAMPSTATE_UNKNOWN -1
#define LAMPSTATE_OFF      0
#define LAMPSTATE_WARMUP   1
#define LAMPSTATE_ON       2
#define LAMPSTATE_COOLING  3

// These constants are used in the record CUtmSignalInfoRecord

// Valid inputs:
#define INPUT_NO_INPUT      0 //No sync found
#define INPUT_DVI           1 //Digital DVI input
#define INPUT_RGB           2 //Analog RGB input sync
#define INPUT_MCM           3 //For input of the mcm-card 

// Sync info in CUtmSignalInfoRecord:
#define SYNC_POL_VSYNC_POS  0x01  // Bit0 is 1 if vsync has positive polarity
#define SYNC_POL_HSYNC_POS  0x02  // Bit1 is 1 if hsync has positive polarity

// For CSyncTypeRecord and Sync type in UtmSignalInfoRecord
#define SYNC_TYPE_SEPARATE      0
#define SYNC_TYPE_COMPOSITE     1
#define SYNC_TYPE_SOG           2   // SyncOnGreen
#define SYNC_TYPE_AUTO          3

// For CEDIDCtrlRecord
#define EDID_TYPE_ANALOG        0
#define EDID_TYPE_DIGITAL       1

// For COutputCtrl (CV_OUTPUTCTRL)
// The values can be combined, e.g disable SYNC, enable DATA and DDC 5V:
// ~OUTPUT_ENABLE_SYNC & (OUTPUT_ENABLE_DATA | OUTPUT_ENABLE_DDC5V)  
#define OUTPUT_ENABLE_SYNC      0x01
#define OUTPUT_ENABLE_DATA      0x02
#define OUTPUT_ENABLE_DDC5V     0x04


// Valid sources for CV_SOURCE
#define SOURCE_NO_SOURCE    0  //No sync detected, only read
//CompactClan sources:
#define SOURCE_DVI1         1
#define SOURCE_RGB1         2        
#define SOURCE_RGB2         3
#define SOURCE_SVIDEO1      4   // Super video
#define SOURCE_VIDEO1       5   // Composite video
#define SOURCE_COMP_VIDEO1  6   // Component video
//Utm sources (GCM and MCM):
#define SOURCE_DVI_RGB1     7
#define SOURCE_MCM          8
#define SOURCE_ADDON_RGB1   9
#define SOURCE_ADDON_RGB2   10  //only for GCM card
#define SOURCE_DVI_RGB2     11  //only for MCM card

// Valid scaling modes for CV_SCALING_MODE
#define SCALING_NO_SCALING 0
#define SCALING_FILL_ALL 1
#define SCALING_ONE_TO_ONE 2
#define SCALING_ASPECT_RATIO 3
#define SCALING_16_9 4
#define SCALING_USER_DEFINED 5


//Valid align modes for CV_SCALING_MODE
#define ALIGN_LEFT_TOP 0
#define ALIGN_MIDDLE_TOP 1
#define ALIGN_RIGHT_TOP 2
#define ALIGN_LEFT_MIDDLE 3
#define ALIGN_MIDDLE_MIDDLE 4
#define ALIGN_RIGHT_MIDDLE 5
#define ALIGN_LEFT_BOTTOM 6
#define ALIGN_MIDDLE_BOTTOM 7
#define ALIGN_RIGHT_BOTTOM 8

//Valid sample modes for CV_ANALYZE_VIDEO
#define VIDEO_SAMPLE_HORIZONTAL 0
#define VIDEO_SAMPLE_VERTICAL 1

// CV_DRAWCTRL flags
#define DRAWCTRL_DISABLE	0x00000001
#define DRAWCTRL_START	  0x00000002
#define DRAWCTRL_FINISH	  0x00000004

// CV_COLOR_MEASUREMENT flags
#define COLOR_LUMINANCE_OVERFLOW    0x0001
#define COLOR_LUMINANCE_UNDERFLOW   0x0002
#define COLOR_LUMINANCE_VALID       0x0004
#define COLOR_CHROMA_OVERFLOW       0x0010
#define COLOR_CHROMA_UNDERFLOW      0x0020
#define COLOR_CHROMA_VALID          0x0040


#define DEVICE_WRAPPER_SET  0x00
#define DEVICE_WRAPPER_GET  0x01
#define DEVICE_WRAPPER_INFO 0x02

// CV_WEP flags
#define WEP_FLAGS_ACTIVE            0x01
#define WEP_FLAGS_DENY_UNENCRYPTED  0x02


// Edge combine mode flags
#define EDGECOMBINE_MULTIPLY        0x00  // Default mode
#define EDGECOMBINE_MINMAX          0x01  // Combine by min/max
#define EDGECOMBINE_CUTOUTMASK      0x1e  // Combine as screen cutout
#define EDGECOMBINE_CUTOUTMODE(ucIndex)  (((ucIndex) << 1) & EDGECOMBINE_CUTOUTMASK)
#define EDGECOMBINE_CUTOUTINDEX(ucMode)  (((ucMode) & EDGECOMBINE_CUTOUTMASK) >> 1)   // Mask for cutout index
#define EDGECOMBINE_BLACKLEVELMASK  0x10000    // Virtual flag: use as black level mask


#define SCREEN_LEDPATTERN_OFF       0
#define SCREEN_LEDPATTERN_GREEN     1
#define SCREEN_LEDPATTERN_RED       2
#define SCREEN_LEDPATTERN_5DEG      3
#define SCREEN_LEDPATTERN_PAINTMODE 4
#define SCREEN_LEDPATTERN_BITMASK   5
#define SCREEN_LEDPATTERN_INFOMASK  6

#define EDID_DISPLAY_FILTER         0
#define EDID_DISPLAY_IGNORE         1
#define EDID_DISPLAY_ONLY           2

#define EDID_DISPLAY_VALID          2


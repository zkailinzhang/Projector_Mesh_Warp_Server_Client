#ifndef INCLUDED_PWDEFS_H
#define INCLUDED_PWDEFS_H

//
// PwDefs.h  Constants for the Pixelworks protocol used towards the 
// Projectiondesign projectors
//
#define op_LAMPTIME_RESET          4613     // Execute command for resetting the lamp time counter 
#define op_HORZ_FREQUENCY_KHZ       543     // Horz Frequency range 0-256
#define op_HORZ_FREQUENCY_FRACTION_KHZ 544  // Horz Frequency range 0-999
#define op_HORZ_KEYSTONE            545	    // Horz Keystone
#define op_PASSWORD_ENTRY           564	    // Password Entry
#define op_NEW_PASSWORD_ENTRY       565	    // New Password Entry
#define op_CURRENT_SOURCE           581     // Use this to get source. GET only
#define op_DLPIMAGEORIENT           593     // Image oritentation
#define op_TMPSREADTEMPT0           599     // Read temperature from sensor, do not use often, heavy load on projector
#define op_TMPSREADTEMPT1           601     // Read temperature from sensor, do not use often, heavy load on projector
#define op_AUDIO_VOLUME             614	    // AUDIOVOLUME
#define op_AUDIO_TREBLE             615	    // AUDIOTREBLE
#define op_AUDIO_BASS               616	    // AUDIOBASS
#define op_AUDIO_MUTE               617	    // AUDIOMUTE
#define op_TEMPERATUREWATCHDOGREAD  627     // Read Watchdog temperature
#define op_TMPSTEMPERATURE0         633     // Read temperature from copy in RAM
#define op_TMPSTEMPERATURE1         634     // Read temperature from copy in RAM
#define op_SERVICE_PASSWORD         649	    // ServicePassword
#define op_SERVICE_PASSWORD_DUM     651	    // ServiceDummyPassword
#define op_GAMMA_DATA               656     // Gamma mode table for data input
#define op_GAMMA_VIDEO              657     // Gamma mode table for video input
#define op_FORCE_POWER              668	    // force power
#define op_SYSTEMINFO               672     // Software version in decimal
#define op_LAMPSTATE                674     // Read current lamp state
#define op_LOGOWHILESEARCHING       678     // Logo status when no source
#define op_WHITE_BOOST_VIDEO        699		  // White boost for video sources, for SX+ only
#define op_WHITE_BOOST_DATA         700     // White boost for data sources, for SX+ only
#define op_RIMICOMMCHANNEL          725     // Enable LAN on RIMI connector, for SX+ only
#define op_ECO_MODE                 726		  // Eco mode, for SX+/SX60
#define op_LAMPSTATE2               800     // Read current lamp state for 2nd lamp, SX60
#define op_LAMP_POWER               860		  // Lamp power, for SX+/SX60
#define op_RESTOREFACTORY           850     // Restore to factory defaults, execute command
#define op_LENS_CONTROLA            870     // Close the iris, speed 1-3. See comment below!!
#define op_LENS_CONTROLB            871     // Open the iris, speed 1-3. See comment below!!
#define op_SHUTTER                  872     // Close/Open shutter for SX60  
#define op_LOCKSYNCSTATUS           1026    // Set lock sync
#define op_LIGHT_ON_TIME_HOURS2     1073    // Current lamp time, for 2nd lamp, SX60
#define op_LAMP_MODE                1145    // Set lamp mode, single or dual, for SX60
#define op_LAMP_SINGLE              1146    // Select sigle lamp, for SX60 
#define op_LCD_BACKLIGHT            1594    // Dim the backlight, for SX60
#define op_SW_VER_REV               1700    // Software version above 100
#define op_LAMP_POWER2              3000    // Lamp power, SX60 only
#define op_LIGHT_ON_TIME_HOURS      4100    // Current lamp time
#define op_UNIT_ON_TIME_HOURS       4098    // Unit On Time Hours
#define op_UNIT_ON_TIME_MIN         4099    // Unit On Time minutes
#define op_BRIGHTNESS               16387	  // Brightness
#define op_CONTRAST                 16388	  // Contrast
#define op_RED_BRIGHTNESS           16389	  // Red Brightness
#define op_RED_CONTRAST             16390	  // Red Contrast
#define op_GREEN_BRIGHTNESS         16391	  // Green Brightness
#define op_GREEN_CONTRAST           16392	  // Green Contrast
#define op_BLUE_BRIGHTNESS          16393	  // Blue Brightness
#define op_BLUE_CONTRAST            16394	  // Blue Contrast
#define op_HUE                      16395	  // Hue
#define op_SATURATION               16396	  // Saturation
#define op_SHARPNESS                16397	  // Sharpness
#define op_HORZ_POSITION            16398	  // Horizontal Position
#define op_VERT_POSITION            16399	  // Vertical Position
#define op_PHASE                    16400	  // Phase
#define op_HORZ_RESOLUTION          16401   // Horizontal resolution
#define op_VERT_RESOLUTION          16402   // Vertical resolution
#define op_VERT_FREQUENCY           16403   // Vertical frequency (ok to get)
#define op_HORZ_TOTAL               16404   // Horizontal Total (ok to get)
#define op_RED_TEMP                 16406	  // Red Temperature
#define op_GREEN_TEMP               16407	  // Green Temperature
#define op_BLUE_TEMP                16408	  // Blue Temperature
#define op_SELECT_SOURCE            17409   // Select Source. SET only
#define op_KEYSTONE                 16412	  // Keystone
#define op_AUTO_ADJUST              16899   // Forced Auto Adjustment
#define op_AUTO_PHASE_DISABLE       17420   // Disable auto setup phase adjustment
#define op_AUTO_FREQ_DISABLE        17421   // Disable auto setup frequency adjustment
#define op_AUTO_POS_DISABLE         17422   // Disable auto setup position adjustment
#define op_AUTO_BRIGHT_CONTRAST_DISABLE 17423 
#define op_AUTO_SYNC_MONITOR_DISABLE 17438  // Disable auto setup mode search
#define op_SCALER_MODE              17430   // Scaler Mode
#define op_SOURCE_SCAN              17443	  // Source Scan


// Valid sources for op_SELECT_SOURCE
#define PW_SOURCE_RGB1          0
#define PW_SOURCE_RGB2          1
#define PW_SOURCE_DVI1          2
#define PW_SOURCE_COMPVIDEO     3   // Component video
#define PW_SOURCE_SVIDEO1       4
#define PW_SOURCE_VIDEO1        5


// Valid window targets
#define wnWIN_MAIN           0
#define wnWIN_PIP            1
#define wnWINDOW_COUNT       2
#define wnCURRENT_WINDOW     3
#define wnINVALID_WINDOW     4

// Valid scale modes for op_SCALER_MODE
#define smONE_TO_ONE            0
#define smFILL_ALL              1
#define smFILL_TO_ASPECT_RATIO  2
#define smFILL_TO_16X9_LINEAR   3
#define smFILL_NL_LETTERBOXED   4
#define sm4X3LB_TO_4X3          5
#define sm4X3LBST_TO_4X3        6
#define sm4X3A_TO_4X3           7
#define sm4X3_TO_16X9           8
#define sm4X3LB_TO_16X9         9
#define sm4X3LBST_TO_16X9       10
#define smNORMAL                11
#define smWIDE                  12
#define smZOOM                  13
#define smANAMORPHIC            14
#define smZOOM2                 15

//  Valid image orientation modes for op_DLPIMAGEORIENT
#define orFRONT                 0
#define orCEILING_MIRROR        1
#define orMIRROR                2
#define orCEILING               3

// Valid lamp states for op_LAMPSTATE
#define lmpBROKEN               0
#define lmpWARMING_UP           1
#define lmpON                   2
#define lmpOFF                  3
#define lmpCOOLING              4

// Valid "logo while searching" modes for op_LOGOWHILESEARCHING
#define lsOFF                   0
#define lsLOGO                  1
#define lsBLUE                  2
#define lsWHITE                 3


// Valid modes for op_AUTO_SYNC_MONITOR_DISABLE
#define dsNotDisabled           0
#define dsDisabled              1
#define dsToggleDisable         2


//Valid values for op_LOCKSYNCSTATUS
#define enNotEnable 0
#define enEnable 1

//Valid values for op_SOURCE_SCAN
#define ssOFF                   2  
#define ssON                    0

//Valid values for op_GAMMA_DATA/opGAMMA_VIDEO for X and SX
#define gaVIDEO					1
#define gaPHOTO					2
#define gaHIGHBRIGHTNESS		3

//Valid values for op_GAMMA_DATA/opGAMMA_VIDEO for SX+
#define gaFILM1					0
#define gaFILM2					1
#define gaVIDEO1				2
#define gaVIDEO2				3
#define gaCOMPUTER1		  7
#define gaCOMPUTER2			8

//Valid values for op_ECO_MODE
#define emOFF					0
#define emON					1

//Valid values for op_LAMP_MODE
#define lmDUAL        0         
#define lmSINGLE      1

//Valid values for op_LAMP_SINGLE
#define lsFIRST       0
#define lsSECOND      1

//Valid values for op_SHUTTER
#define shOPEN        0
#define shCLOSE       1

/*Comments for op_LENS_CONTROLA/op_LENS_CONTROLB
op_LENS_CONTROLA is used for 

  Iris open - w/ target 6
  Zoom in - w/ target 3
  Focus out - w/ target 2
  Shift up - w/ target 0
  Shift right - w/ target 1

op_LENS_CONTROLB us used for 
  Iris close - w/ target 6
  Zoom out - w/ target 3
  Focus out - w/ target 2
  Shift down - w/ target 0
  Shift left - w/ target 1 
*/

//Targets for op_LENS_CONTROLA/op_LENS_CONTROLB
#define lcTargetShiftV 0
#define lcTargetShiftH 1
#define lcTargetFocus  2
#define lcTargetZoom   3
#define lcTargetIris   6

//Values for op_LENS_CONTROLA/op_LENS_CONTROLB
#define lcSlow       1
#define lcMedium     2
#define lcFast       3

//Targets for op_SW_VER_REV
#define svrVERSION   0 
#define svrREVISION  1

#endif

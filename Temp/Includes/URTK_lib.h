/* Automation Studio generated header file */
/* Do not edit ! */
/* URTK_lib  */

#ifndef _URTK_LIB_
#define _URTK_LIB_
#ifdef __cplusplus
extern "C" 
{
#endif

#include <bur/plctypes.h>

#ifndef _BUR_PUBLIC
#define _BUR_PUBLIC
#endif
/* Datatypes and datatypes of function blocks */
typedef enum TURTKHomingState
{	ST_IDLE,
	ST_MOVE_FAST,
	ST_MOVE_SLOW
} TURTKHomingState;

typedef enum TURTKMovePos
{	ST_IDLE_POS,
	ST_MOVE_POS
} TURTKMovePos;

typedef enum ERROR
{	ERR_URTK_NO_ERROR = 0,
	ERR_URTK_UNDERVOLTAGE = 1,
	ERR_URTK_VOLTAGEWARNING = 3,
	ERR_URTK_OVERVOLTAGE = 4,
	ERR_URTK_OVERTEMPERATURE = 5,
	ERR_URTK_PWM01 = 6,
	ERR_URTK_CURRENT01 = 7,
	ERR_URTK_OVERCURRENT01 = 8,
	ERR_URTK_PWM02 = 9,
	ERR_URTK_CURRENT02 = 10,
	ERR_URTK_OVERCURRENT02 = 11,
	ERR_URTK_PWM03 = 12,
	ERR_URTK_CURRENT03 = 13,
	ERR_URTK_OVERCURRENT03 = 14
} ERROR;

typedef enum URTKCtrl
{	ST_URTK_IDLE,
	ST_URTK_MANUAL,
	ST_URTK_ERROR,
	ST_URTK_HOMING,
	ST_URTK_MOVE_POS,
	ST_POS1,
	ST_POS2,
	ST_POS3
} URTKCtrl;

typedef struct TURTKAxisMonitor
{	float Position;
	plcbit LimitN;
	plcbit LimitP;
	float Iact;
	float Uact;
} TURTKAxisMonitor;

typedef struct TURTKAxicCtrl
{	float U;
	float ILim;
	plcbit ClearError;
} TURTKAxicCtrl;

typedef struct TURTKAxisError
{	plcbit OverCurrent;
} TURTKAxisError;

typedef struct TURTKAxisHardware
{	unsigned short PeriodDurationPWM;
	plcbit StatusInputP;
	plcbit StatusInputN;
	signed short PulseWidthCurrentPWM;
	plcbit ShowMeanCurrent;
	signed short Counter;
	signed short CounterLatch;
} TURTKAxisHardware;

typedef struct TURTKHardware
{	unsigned short PWMDuration;
	signed short PWMX;
	plcbit Error;
	plcbit Grip;
	plcbit UnderVoltageError;
	plcbit VoltageWarning;
	plcbit OverVoltageError;
	plcbit OverTemperatureError;
	plcbit PWMError01;
	plcbit CurrentError01;
	plcbit OverCurrentError01;
	plcbit PWMError02;
	plcbit CurrentError02;
	plcbit OverCurrentError02;
	plcbit PWMError03;
	plcbit CurrentError03;
	plcbit OverCurrentError03;
} TURTKHardware;

typedef struct FB_URTKAxisHome
{
	/* VAR_INPUT (analog) */
	float U_fast;
	float U_low;
	/* VAR_OUTPUT (analog) */
	float U;
	enum TURTKHomingState State;
	/* VAR_INPUT (digital) */
	plcbit pos_direction;
	plcbit LimitP;
	plcbit LimitN;
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit done;
	plcbit ResetCounter;
	/* VAR (digital) */
	plcbit p_dir;
} FB_URTKAxisHome_typ;

typedef struct TURTKMonitor
{	float PositionX;
	float PositionY;
	float PositionZ;
	plcbit LimitX_N;
	plcbit LimitX_P;
	plcbit LimitY_N;
	plcbit LimitY_P;
	plcbit LimitZ_N;
	plcbit LimitZ_P;
	plcbit Grip;
	struct FB_URTKAxisHome HomingX;
	struct FB_URTKAxisHome HomingY;
	struct FB_URTKAxisHome HomingZ;
	plcbit HomingOK;
	plcbit InPosition;
} TURTKMonitor;

typedef struct TURTKError
{	enum ERROR Type;
	plcbit Error;
	plcbit CLearError;
	plcbit ConfigIun;
	plcbit prevCLearError;
} TURTKError;

typedef struct TURTKControl
{	plcbit ManualCtrl;
	plcbit StartHoming;
	plcbit MovPos;
	float X;
	float Y;
	float Z;
	plcbit ManBtnXPos;
	plcbit ManBtnXNeg;
	plcbit ManBtnYPos;
	plcbit ManBtnYNeg;
	plcbit ManBtnZPos;
	plcbit ManBtnZNeg;
	plcbit Grip;
} TURTKControl;

typedef struct FBURTKAxis
{
	/* VAR_INPUT (analog) */
	struct TURTKAxicCtrl control;
	struct TURTKAxisMonitor monitor;
	struct TURTKAxisError error;
	struct TURTKAxisHardware hardware;
} FBURTKAxis_typ;

typedef struct FBURTKAxisMovePos
{
	/* VAR_INPUT (analog) */
	float set_position;
	float set_position1;
	float set_position2;
	float act_position;
	float K;
	/* VAR_OUTPUT (analog) */
	float U;
	enum TURTKMovePos State;
	/* VAR_INPUT (digital) */
	plcbit homing_done;
	plcbit enable;
	/* VAR_OUTPUT (digital) */
	plcbit done;
	plcbit done1;
	plcbit done2;
	plcbit done3;
} FBURTKAxisMovePos_typ;

typedef struct FBURTKCtrl
{
	/* VAR_INPUT (analog) */
	struct TURTKHardware Hardware;
	struct TURTKMonitor Monitor;
	struct TURTKError Error;
	struct TURTKControl Control;
	struct FBURTKAxis AxisX;
	struct FBURTKAxis AxisY;
	struct FBURTKAxis AxisZ;
	struct FB_URTKAxisHome FBHomingX;
	struct FB_URTKAxisHome FBHomingY;
	struct FB_URTKAxisHome FBHomingZ;
	struct FBURTKAxisMovePos FBMovePosX;
	struct FBURTKAxisMovePos FBMovePosY;
	struct FBURTKAxisMovePos FBMovePosZ;
	signed short Ustator;
	/* VAR_OUTPUT (analog) */
	enum URTKCtrl State;
	/* VAR_INPUT (digital) */
	plcbit Grip;
	plcbit enable;
} FBURTKCtrl_typ;



/* Prototyping of functions and function blocks */
_BUR_PUBLIC void FBURTKAxis(struct FBURTKAxis* inst);
_BUR_PUBLIC void FB_URTKAxisHome(struct FB_URTKAxisHome* inst);
_BUR_PUBLIC void FBURTKAxisMovePos(struct FBURTKAxisMovePos* inst);
_BUR_PUBLIC void FBURTKCtrl(struct FBURTKCtrl* inst);


#ifdef __cplusplus
};
#endif
#endif /* _URTK_LIB_ */


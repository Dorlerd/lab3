/* Automation Studio generated header file */
/* Do not edit ! */

#ifndef _BUR_1702041223_4_
#define _BUR_1702041223_4_

#include <bur/plctypes.h>

/* Constants */
#ifdef _REPLACE_CONST
#else
#endif


/* Variables */
_BUR_LOCAL signed short integ;
_BUR_LOCAL struct FB_PD pd;
_BUR_LOCAL float pos_ust;
_BUR_LOCAL plcbit homing;
_BUR_LOCAL struct FB_Controller pid;
_BUR_LOCAL float I_ust;
_BUR_LOCAL plcbit flag;
_BUR_LOCAL signed short cnt;
_BUR_LOCAL enum TState_led State_led;
_BUR_LOCAL signed short PageNum;
_BUR_LOCAL plcbit BtnS;
_BUR_LOCAL struct FBURTKCtrl URTK_Ctrl;
_BUR_LOCAL plcbit led1;
_BUR_LOCAL plcbit led2;
_BUR_LOCAL plcbit led3;
_BUR_LOCAL plcbit led4;
_BUR_LOCAL float pos_last;
_BUR_LOCAL float pos_new;
_BUR_LOCAL float speed;





__asm__(".section \".plc\"");

/* Used IEC files */
__asm__(".ascii \"iecfile \\\"Logical/RobotControl/Variables.var\\\" scope \\\"local\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/Library/Library.fun\\\" scope \\\"global\\\"\\n\"");
__asm__(".ascii \"iecfile \\\"Logical/Libraries/URTK_lib/URTK_lib.fun\\\" scope \\\"global\\\"\\n\"");

/* Exported library functions and function blocks */

__asm__(".previous");


#endif /* _BUR_1702041223_4_ */


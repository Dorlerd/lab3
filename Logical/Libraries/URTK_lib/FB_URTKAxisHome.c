
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "URTK_lib.h"
#ifdef __cplusplus
	};
#endif
/* функциональный блок */
void FB_URTKAxisHome(struct FB_URTKAxisHome* inst)
{
	switch (inst->State){
		case ST_IDLE:
			inst->U=0;
			inst->ResetCounter=0;
			if(inst->enable){
				inst->p_dir=inst->pos_direction;
				inst->State=ST_MOVE_FAST;
				inst->done=0;
			}
			
		case ST_MOVE_FAST:
			if(!inst->enable){
				inst->U=0;
				inst->ResetCounter=0;
				inst->State=ST_IDLE;
			}

			if(inst->p_dir){
			inst->ResetCounter = 0;
			inst->U=inst->U_fast;
			}
			else{
			inst->ResetCounter = 0;
			inst->U=-inst->U_fast;
			}

			if(inst->LimitN||inst->LimitP){
			inst->U=0;
			inst->ResetCounter=0;
			inst->State=ST_MOVE_SLOW;
			}
			break;
			
		case ST_MOVE_SLOW:
			if(!inst->enable){
				inst->U=0;
				inst->ResetCounter=0;
				inst->State=ST_IDLE;
			}
			
			
	/*		if(inst->ResetCounter == (!inst->LimitP))
				inst->U=-inst->U_low;
			
			if(inst->ResetCounter == (!inst->LimitN))
				inst->U=8;
*/
			if(inst->p_dir=1){
			inst->ResetCounter = (!inst->LimitP);
			inst->U = 6;
				
			}
				
			if(inst->p_dir=0){
				
				inst->ResetCounter = (!inst->LimitN);
				inst->U = inst->U_low;
			}
		/*	else{
				
				inst->ResetCounter = (!inst->LimitN);
				inst->U = inst->U_low;
					
			}*/

			if(!(inst->LimitN||inst->LimitP)){
			inst->State=ST_IDLE;
			inst->enable=0;
			inst->done=1;
			}
			break;
			
	
	}
}

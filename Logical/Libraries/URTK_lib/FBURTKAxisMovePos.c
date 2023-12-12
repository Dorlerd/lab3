
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "URTK_lib.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FBURTKAxisMovePos(struct FBURTKAxisMovePos* inst)
{
	inst->done=(inst->set_position==inst->act_position);
	switch (inst->State){
		case ST_IDLE_POS:
			inst->U=0;
		//	inst->act_position=0; //где мы есть
			if(inst->enable){
				inst->State=ST_MOVE_POS;
				if(!inst->homing_done){
					inst->State=ST_IDLE_POS;
					inst->enable=0;
				}
			}
			break;
		case ST_MOVE_POS: 
			if(!inst->enable){ 
				inst->U=0; 
				inst->State=ST_IDLE_POS; 
			} 
			inst->U=inst->K*((inst->set_position)-(inst->act_position)); 
			if(inst->U > 14)
			{
				inst->U = 14;
			}
			if(inst->done){ 
				inst->State=ST_IDLE_POS; 
				inst->enable=0;
			} 
			break; 
	} 
}
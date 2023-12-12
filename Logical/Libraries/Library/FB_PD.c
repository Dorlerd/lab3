
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "Library.h"
#ifdef __cplusplus
	};
#endif
/* TODO: Add your comment here */
void FB_PD(struct FB_PD* inst)
{
	inst->out = inst->k_p*inst->in + inst->k_d*(inst->in-inst->prev_in)*inst->dt;
	//inst->out = inst->k_p*inst->in + inst->k_d*(inst->dt * inst->in + inst->prev_in)*inst->dt;
	inst->out = inst->out > inst->max_abs_value ? inst->max_abs_value : inst->out;
	inst->out = inst->out < -inst->max_abs_value ? -inst->max_abs_value : inst->out;
	inst->prev_in = inst->in;	
}

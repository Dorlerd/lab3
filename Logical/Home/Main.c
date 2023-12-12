
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	FB_URTKAxisHome(&ST_IDLE);
}

void _CYCLIC ProgramCyclic(void)
{

	
	if(BntC)
	{
		U_fast=24.0;
		
	}
	
}

void _EXIT ProgramExit(void)
{
	// Insert code here 

}


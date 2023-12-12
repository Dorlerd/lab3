 
#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramInit(void)
{
	// Insert code here 
	
		
	URTK_Ctrl.AxisX.control.ILim=2.5;
	URTK_Ctrl.AxisY.control.ILim=2.5;
	URTK_Ctrl.AxisZ.control.ILim=2.5;
//	URTKAxisHome.State=ST_IDLE;
	
	URTK_Ctrl.FBHomingX.U_fast=18.0;
	URTK_Ctrl.FBHomingX.U_low=6.0;
	URTK_Ctrl.FBHomingX.pos_direction=0;
	
//	URTKAxisHomeY.State=ST_IDLE;
	URTK_Ctrl.FBHomingY.U_fast=18.0;
	URTK_Ctrl.FBHomingY.U_low=6.0;
	URTK_Ctrl.FBHomingY.pos_direction=0;
	
//	URTKAxisHomeZ.State=ST_IDLE;
	URTK_Ctrl.FBHomingZ.U_fast=18.0;
	URTK_Ctrl.FBHomingZ.U_low=6.0;
	URTK_Ctrl.FBHomingZ.pos_direction=0;
	
	URTK_Ctrl.FBMovePosX.U=0; 
	URTK_Ctrl.FBMovePosX.K=18;
	URTK_Ctrl.FBMovePosY.U=0; 
	URTK_Ctrl.FBMovePosY.K=18;
	URTK_Ctrl.FBMovePosZ.U=0; 
	URTK_Ctrl.FBMovePosZ.K=18;
	
	URTK_Ctrl.Monitor.HomingOK=0;
	URTK_Ctrl.Ustator=0;
	
	URTK_Ctrl.FBMovePosX.set_position=0;
	URTK_Ctrl.FBMovePosY.set_position=0;
	URTK_Ctrl.FBMovePosZ.set_position=0;
	
	pd.k_p = 90;
	pd.k_d = 10;
	pd.dt = 0.01;
	pid.k_p = 37;
	pid.k_i = 80;
	pid.k_d = 2;
	pid.dt = 0.01;
	

}

void _CYCLIC ProgramCyclic(void)
{
	
	//	URTKAx.control.U=0;
	//	URTKAy.control.U=0;
	//	URTKAz.control.U=0;



	/*	if(BtnS){
	Ustator=32767;
	}
	if(BtnP){
	URTKAx.control.U=18.0;		//переменна€ управлени€ движком
	}
	if(BtnN){
	URTKAx.control.U=-18.0;
	}

	if(BtnPY){
	URTKAy.control.U=18.0;
	}
	if(BtnNY){
	URTKAy.control.U=-18.0;
	}

	if(BtnPZ){
	URTKAz.control.U=18.0;
	}
	if(BtnNZ){
	URTKAz.control.U=-18.0;
	}



	URTKAxisHome.LimitN = URTKAx.hardware.StatusInputN; //калибровка начало
	URTKAxisHome.LimitP = URTKAx.hardware.StatusInputP; //проверка на концевой датчик
	FB_URTKAxisHome(&URTKAxisHome); 		//вызов функции калибровки
	if(URTKAxisHome.enable)					//проверка на энейбл сработал или нет
	URTKAx.control.U = URTKAxisHome.U; //запуск мотора через ”–“ х

	URTKAxisHomeY.LimitN = URTKAy.hardware.StatusInputN; 
	URTKAxisHomeY.LimitP = URTKAy.hardware.StatusInputP; 
	FB_URTKAxisHome(&URTKAxisHomeY); 
	if(URTKAxisHomeY.enable)
	URTKAy.control.U = URTKAxisHomeY.U;

	URTKAxisHomeZ.LimitN = URTKAz.hardware.StatusInputN; 
	URTKAxisHomeZ.LimitP = URTKAz.hardware.StatusInputP; 
	FB_URTKAxisHome(&URTKAxisHomeZ); 
	if(URTKAxisHomeZ.enable)
	URTKAz.control.U = URTKAxisHomeZ.U; //калибровка конец

	FBURTKAxisMovePos(&URTKAxisMovePos);
	FBURTKAxisMovePos(&URTKAxisMovePosY);
	FBURTKAxisMovePos(&URTKAxisMovePosZ);

	FBURTKAxis(&URTKAx);
	FBURTKAxis(&URTKAy);
	FBURTKAxis(&URTKAz);
	FBURTKAxis(&URTKAt);

	URTKAxisMovePos.homing_done=URTKAxisHome.done;  			//присвоение homing_done заначени€ done служит дл€ последующего запуска ‘Ѕ
	URTKAxisMovePos.act_position=URTKAx.monitor.Position; 		//сн€тие данных с монитора и запись оных в переменную нынешнего положени€
	FBURTKAxisMovePos(&URTKAxisMovePos); 						//вызов функционального блока на переменную
	if(URTKAxisMovePos.enable) 									//проверка на энейбл
	URTKAx.control.U = URTKAxisMovePos.U; 					//запуск двигател€ через ”–“ х

	URTKAxisMovePosY.homing_done=URTKAxisHomeY.done; 
	URTKAxisMovePosY.act_position=URTKAy.monitor.Position; 
	FBURTKAxisMovePos(&URTKAxisMovePosY); 
	if(URTKAxisMovePosY.enable) 
	URTKAy.control.U = URTKAxisMovePosY.U; 

	URTKAxisMovePosZ.homing_done=URTKAxisHomeZ.done; 
	URTKAxisMovePosZ.act_position=URTKAz.monitor.Position; 
	FBURTKAxisMovePos(&URTKAxisMovePosZ); 
	if(URTKAxisMovePosZ.enable) 
	URTKAz.control.U = URTKAxisMovePosZ.U; 


	FBURTKAxis(&URTKAx); 
	FBURTKAxis(&URTKAy); 
	FBURTKAxis(&URTKAz);
	*/
	URTK_Ctrl.Ustator=0;
	//FBURTKCtrl(&URTK_Ctrl);
	if(BtnS){
		URTK_Ctrl.Ustator=32767;
		//URTK_Ctrl.AxisZ.hardware.PulseWidthCurrentPWM = 24575;
	}
	//
	if (!homing)
	{
		URTK_Ctrl.AxisY.hardware.PulseWidthCurrentPWM = 32000;
		if (URTK_Ctrl.AxisY.hardware.StatusInputP)
		{
			homing = 1;
			URTK_Ctrl.FBHomingY.ResetCounter = 1;
		}
	}
	else
		
	{
		URTK_Ctrl.FBHomingY.ResetCounter = 0;
		pos_new = URTK_Ctrl.AxisY.hardware.Counter/24*3;
		speed = (pos_new - pos_last)/0.01;
		
		pd.in = pos_ust - pos_new;
		FB_PD(&pd);
		
		pid.in = pd.out - speed;
		FB_Controller(&pid);
		
		integ = (INT)pid.out;
		
		URTK_Ctrl.AxisY.hardware.PulseWidthCurrentPWM = -integ;
		

		//URTK_Ctrl.Control.ManualCtrl = 1;
	
		if (URTK_Ctrl.AxisY.hardware.StatusInputN)
		{ 
			URTK_Ctrl.AxisY.hardware.PulseWidthCurrentPWM = 0;
			URTK_Ctrl.AxisY.hardware.StatusInputP = 0;
			flag = 0;
		}
	
		//FBURTKCtrl(&URTK_Ctrl);
		pos_last=pos_new;
	}
	
	

	
}

void _EXIT ProgramExit(void)
{
	// Insert code here 
}


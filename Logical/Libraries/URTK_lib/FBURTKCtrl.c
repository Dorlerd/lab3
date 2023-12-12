
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
void FBURTKCtrl(struct FBURTKCtrl* inst)
{
	FBURTKAxis(&inst->AxisX);
	FBURTKAxis(&inst->AxisY);
	FBURTKAxis(&inst->AxisZ);
//	FBERROR(&inst->Error1);
	
	
	
	
	
	if(inst->Hardware.UnderVoltageError){
		inst->Error.Error=1;
		inst->Error.Type=ERR_URTK_UNDERVOLTAGE;	
		inst->Ustator=0;
	}
	if(inst->Hardware.VoltageWarning){
		inst->Error.Error=1;
		inst->Error.Type=ERR_URTK_VOLTAGEWARNING;
		inst->Ustator=0;
	}
	if(inst->Hardware.OverVoltageError){
		inst->Error.Error=1;
		inst->Error.Type=ERR_URTK_OVERVOLTAGE;
		inst->Ustator=0;
	}
	if(inst->Hardware.OverTemperatureError){
		inst->Error.Error=1;
		inst->Error.Type=ERR_URTK_OVERTEMPERATURE;
		inst->Ustator=0;
	}
	if(inst->Hardware.PWMError01){
		inst->Error.Error=1;
		inst->Error.Type=ERR_URTK_PWM01;
		inst->Ustator=0;
	}
	if(inst->Hardware.CurrentError01){
		inst->Error.Error=1;
		inst->Error.Type=ERR_URTK_CURRENT01;
		inst->Ustator=0;
	}
	if(inst->Hardware.OverCurrentError01){
		inst->Error.Error=1;
		inst->Error.Type=ERR_URTK_OVERCURRENT01;
		inst->Ustator=0;
	}
	if(inst->Hardware.PWMError02){
		inst->Error.Error=1;
		inst->Error.Type=ERR_URTK_PWM02;
		inst->Ustator=0;
	}
	if(inst->Hardware.CurrentError02){
		inst->Error.Error=1;
		inst->Error.Type=ERR_URTK_CURRENT02;
		inst->Ustator=0;
	}
	if(inst->Hardware.OverCurrentError02){
		inst->Error.Error=1;
		inst->Error.Type=ERR_URTK_OVERCURRENT02;
		inst->Ustator=0;
	}
	if(inst->Hardware.PWMError03){
		inst->Error.Error=1;
		inst->Error.Type=ERR_URTK_PWM03;
		inst->Ustator=0;
	}
	if(inst->Hardware.CurrentError03){
		inst->Error.Error=1;
		inst->Error.Type=ERR_URTK_CURRENT03;
		inst->Ustator=0;
	}
	if(inst->Hardware.OverCurrentError03){
		inst->Error.Error=1;
		inst->Error.Type=ERR_URTK_OVERCURRENT03;
		inst->Ustator=0;
	}
	if(!inst->Error.Error){//if(!inst->Hardware.Error)
		inst->Error.Error=0;// не было
		inst->Error.Type=ERR_URTK_NO_ERROR;
		inst->Error.CLearError=0;
	}
	
	
	
	if(inst->Error.CLearError&(!inst->Error.prevCLearError)){
		switch (inst->Error.Type){
			case ERR_URTK_UNDERVOLTAGE:
				inst->Error.Error=0;
				inst->Error.Type=ERR_URTK_NO_ERROR;
				break;
			
			case ERR_URTK_VOLTAGEWARNING:
				inst->Error.Error=0;
				inst->Error.Type=ERR_URTK_NO_ERROR;
				break;
			
			case ERR_URTK_OVERVOLTAGE:
				inst->Error.Error=0;
				inst->Error.Type=ERR_URTK_NO_ERROR;
				break;
			
			case ERR_URTK_OVERTEMPERATURE:
				inst->Error.Error=0;
				inst->Error.Type=ERR_URTK_NO_ERROR;
				break;
			
			case ERR_URTK_PWM01:
				inst->Error.Error=0;
				inst->Error.Type=ERR_URTK_NO_ERROR;
				break;
			
			case ERR_URTK_CURRENT01:
				inst->Error.Error=0;
				inst->Error.Type=ERR_URTK_NO_ERROR;
				break;
			
			case ERR_URTK_OVERCURRENT01:
				inst->Error.Error=0;
				inst->Error.Type=ERR_URTK_NO_ERROR;
				break;
			
			case ERR_URTK_PWM02:
				inst->Error.Error=0;
				inst->Error.Type=ERR_URTK_NO_ERROR;
				break;
			
			case ERR_URTK_CURRENT02: 
				inst->Error.Error=0;
				inst->Error.Type=ERR_URTK_NO_ERROR;
				break;
			
			case ERR_URTK_OVERCURRENT02:
				inst->Error.Error=0;
				inst->Error.Type=ERR_URTK_NO_ERROR;
				break;
			
			case ERR_URTK_PWM03:
				inst->Error.Error=0;
				inst->Error.Type=ERR_URTK_NO_ERROR;
				break;
			
			case ERR_URTK_CURRENT03:
				inst->Error.Error=0;
				inst->Error.Type=ERR_URTK_NO_ERROR;
				break;
			
			case ERR_URTK_OVERCURRENT03:
				inst->Error.Error=0;
				inst->Error.Type=ERR_URTK_NO_ERROR;
				break;
		}
				
	}
	
	switch (inst->State){
		case ST_URTK_IDLE:
			
			//	inst->AxisX.hardware.PeriodDurationPWM = 32767;
			
			inst->enable=1;
			
			inst->Ustator=0;
			
			
			inst->AxisX.control.U=0;
			inst->AxisY.control.U=0;
			inst->AxisZ.control.U=0;
			
			//		inst->FBMovePosX.set_position=10;  //задание точек
			//		inst->FBMovePosY.set_position=15;
			//		inst->FBMovePosZ.set_position=30;
			//		inst->FBMovePosX.set_position1=70;
			//		inst->FBMovePosY.set_position1=60;
			//		inst->FBMovePosZ.set_position1=60;
			//		inst->FBMovePosX.set_position2=30;
			//		inst->FBMovePosY.set_position2=40;
			//		inst->FBMovePosZ.set_position2=25;
			
			//	inst->FBMovePosX.set_position=inst->Control.X;
			//	inst->FBMovePosY.set_position=inst->Control.Y;
			//	inst->FBMovePosZ.set_position=inst->Control.Z;
			
			if(inst->Control.MovPos){
				inst->FBMovePosX.set_position=10;  //задание точек
				inst->FBMovePosY.set_position=15;
				inst->FBMovePosZ.set_position=30;
				inst->FBMovePosX.act_position=0;
				inst->FBMovePosY.act_position=0;
				inst->FBMovePosZ.act_position=0;
				inst->FBMovePosX.enable=inst->enable;
				inst->FBMovePosY.enable=inst->enable;
				inst->FBMovePosZ.enable=inst->enable;
				inst->FBMovePosX.homing_done=1;
				inst->FBMovePosY.homing_done=1;
				inst->FBMovePosZ.homing_done=1;
				//	inst->Ustator=32767;
				inst->State=ST_URTK_MOVE_POS;
				break;
			/*	if(inst->Monitor.HomingOK){
					inst->FBMovePosX.set_position=10;  //задание точек
					inst->FBMovePosY.set_position=15;
					inst->FBMovePosZ.set_position=30;
					inst->FBMovePosX.act_position=0;
					inst->FBMovePosY.act_position=0;
					inst->FBMovePosZ.act_position=0;
					inst->FBMovePosX.enable=inst->enable;
					inst->FBMovePosY.enable=inst->enable;
					inst->FBMovePosZ.enable=inst->enable;
					inst->FBMovePosX.homing_done=1;
					inst->FBMovePosY.homing_done=1;
					inst->FBMovePosZ.homing_done=1;
				//	inst->Ustator=32767;
					inst->State=ST_URTK_MOVE_POS;
					break;
				}*/
			}
			if(inst->Control.StartHoming){
				inst->FBHomingX.enable=inst->enable;
				inst->FBHomingY.enable=inst->enable;
				inst->FBHomingZ.enable=inst->enable;
				//		inst->Ustator=32767;
				inst->State=ST_URTK_HOMING; 
				break;
			}
			if(inst->Control.ManualCtrl){
				//		inst->Ustator=32767;
				inst->State=ST_URTK_MANUAL;
				break;
			}
			break;
		
		case ST_URTK_MANUAL: 
			
			inst->AxisX.control.U=0;
			inst->AxisY.control.U=0;
			inst->AxisZ.control.U=0;
			
			if(inst->Control.ManBtnXPos){
				inst->AxisX.control.U=18.0;		//переменная управления движком
			}
			if(inst->Control.ManBtnXNeg){
				inst->AxisX.control.U=-18.0;
			}
	
			if(inst->Control.ManBtnYPos){
				inst->AxisY.control.U=18.0;
			}
			if(inst->Control.ManBtnYNeg){
				inst->AxisY.control.U=-18.0;
			}
	
			if(inst->Control.ManBtnZPos){
				inst->AxisZ.control.U=18.0;
			}
			if(inst->Control.ManBtnZNeg){
				inst->AxisZ.control.U=-18.0;
			}
			
			if(!inst->Control.ManualCtrl){
				inst->Ustator=0;
				inst->State=ST_URTK_IDLE;
				break;
			}
			break;
		
		
		case ST_URTK_HOMING: 
			inst->FBHomingX.LimitN = inst->AxisX.hardware.StatusInputN;
			inst->FBHomingX.LimitP = inst->AxisX.hardware.StatusInputP;
			if(!inst->FBHomingX.done){	
				inst->AxisX.control.U = inst->FBHomingX.U;
			} 
			
			inst->FBHomingY.LimitN = inst->AxisY.hardware.StatusInputN;
			inst->FBHomingY.LimitP = inst->AxisY.hardware.StatusInputP;		
			if(!inst->FBHomingY.done){
				inst->AxisY.control.U = inst->FBHomingY.U;
			}
			
			inst->FBHomingZ.LimitN = inst->AxisZ.hardware.StatusInputN;
			inst->FBHomingZ.LimitP = inst->AxisZ.hardware.StatusInputP;						
			if(!inst->FBHomingZ.done){
				inst->AxisZ.control.U = inst->FBHomingZ.U;
			}
			
			if(inst->FBHomingX.done){
				inst->AxisX.control.U = 0;
				inst->FBHomingX.enable=0;
				//		inst->FBHomingX.done=inst->Monitor.HomingX.done;//
			}
			if(inst->FBHomingY.done){
				inst->AxisY.control.U = 0;
				inst->FBHomingY.enable=0;
				//		inst->FBHomingY.done=inst->Monitor.HomingY.done;//
			}
			if(inst->FBHomingZ.done){
				inst->AxisZ.control.U = 0;
				inst->FBHomingZ.enable=0;
				//	inst->FBHomingZ.done=inst->Monitor.HomingZ.done;//
			
			}
			 
			if(inst->FBHomingX.done){
				if(inst->FBHomingY.done){
					if(inst->FBHomingZ.done){
						inst->Monitor.HomingOK=1;
						inst->Ustator=0;
						inst->State=ST_URTK_IDLE;
						inst->Control.StartHoming=!inst->Control.StartHoming;
						inst->FBHomingX.done=0;
						inst->FBHomingY.done=0;
						inst->FBHomingZ.done=0;
					}
				}
			}
			
			
			if(!inst->Control.StartHoming){
				inst->Ustator=0;
				inst->State=ST_URTK_IDLE;
				break;
			}
				
			break;
		
		case ST_URTK_MOVE_POS: 
				
			if(!inst->FBMovePosX.enable){
				if(!inst->FBMovePosY.enable){
					if(!inst->FBMovePosZ.enable){
						inst->FBMovePosX.enable=inst->enable;
						inst->FBMovePosY.enable=inst->enable;
						inst->FBMovePosZ.enable=inst->enable;
						inst->FBMovePosX.act_position=10;
						inst->FBMovePosY.act_position=15;
						inst->FBMovePosZ.act_position=30;
						inst->State=ST_POS1;
						//					inst->FBMovePosX.U=0;
						//					inst->FBMovePosY.U=0;
						//					inst->FBMovePosZ.U=0;
						inst->FBMovePosX.set_position=70;
						inst->FBMovePosY.set_position=60;
						inst->FBMovePosZ.set_position=60;
						//					inst->FBMovePosX.homing_done=0;
						//					inst->FBMovePosY.homing_done=0;
						//					inst->FBMovePosZ.homing_done=0;
						//					inst->Ustator=0;
						//					inst->Control.MovPos=!inst->Control.MovPos;
						
					}
				}
			}
			if(!inst->Control.MovPos){
				inst->State=ST_URTK_IDLE;
				inst->FBMovePosX.homing_done=0;
				inst->FBMovePosY.homing_done=0;
				inst->FBMovePosZ.homing_done=0;
				inst->Ustator=0;
			
				break;
			}
				
			
			inst->FBMovePosX.act_position=inst->AxisX.monitor.Position;
			if(inst->FBMovePosX.set_position==10){
				inst->AxisX.control.U = inst->FBMovePosX.U; 
			}
			
			
			inst->FBMovePosY.act_position=inst->AxisY.monitor.Position;
			if(inst->FBMovePosY.set_position==15){
				inst->AxisY.control.U = inst->FBMovePosY.U;
			}
			
			
			inst->FBMovePosZ.act_position=inst->AxisZ.monitor.Position;
			if(inst->FBMovePosZ.set_position==30){
				inst->AxisZ.control.U = -inst->FBMovePosZ.U;
			}
		
			break;
		
		case ST_POS1: 
			if(!inst->FBMovePosX.enable){
				if(!inst->FBMovePosY.enable){
					if(!inst->FBMovePosZ.enable){
						inst->FBMovePosX.enable=inst->enable;
						inst->FBMovePosY.enable=inst->enable;
						inst->FBMovePosZ.enable=inst->enable;
						inst->FBMovePosX.set_position=30;
						inst->FBMovePosY.set_position=40;
						inst->FBMovePosZ.set_position=40;
						inst->FBMovePosX.act_position=70;
						inst->FBMovePosY.act_position=60;
						inst->FBMovePosZ.act_position=60;
						inst->State=ST_POS2;
						//					inst->FBMovePosX.U=0;
						//					inst->FBMovePosY.U=0;
						//					inst->FBMovePosZ.U=0;
						
						//					inst->FBMovePosX.homing_done=0;
						//					inst->FBMovePosY.homing_done=0;
						//					inst->FBMovePosZ.homing_done=0;
						//					inst->Ustator=0;
						//					inst->Control.MovPos=!inst->Control.MovPos;
						
					}
				}
			}
			if(!inst->Control.MovPos){
				inst->State=ST_URTK_IDLE;
				inst->FBMovePosX.homing_done=0;
				inst->FBMovePosY.homing_done=0;
				inst->FBMovePosZ.homing_done=0;
				inst->Ustator=0;
			
				break;
			}
				
			
			inst->FBMovePosX.act_position=inst->AxisX.monitor.Position;
			if(inst->FBMovePosX.set_position==70){
				inst->AxisX.control.U = inst->FBMovePosX.U; 
			}
			
			inst->FBMovePosY.act_position=inst->AxisY.monitor.Position;
			if(inst->FBMovePosY.set_position==60){
				inst->AxisY.control.U = inst->FBMovePosY.U;
			}
			
			inst->FBMovePosZ.act_position=inst->AxisZ.monitor.Position;
			if(inst->FBMovePosZ.set_position==60){
				inst->AxisZ.control.U = -inst->FBMovePosZ.U;
			}
			
			break;
		
		case ST_POS2: 
			
			if(!inst->FBMovePosX.enable){
				if(!inst->FBMovePosY.enable){
					if(!inst->FBMovePosZ.enable){
						inst->FBMovePosX.enable=inst->enable;
						inst->FBMovePosY.enable=inst->enable;
						inst->FBMovePosZ.enable=inst->enable;
						inst->FBMovePosX.set_position=10;  //задание точек
						inst->FBMovePosY.set_position=15;
						inst->FBMovePosZ.set_position=30;
						inst->FBMovePosX.act_position=30;
						inst->FBMovePosY.act_position=40;
						inst->FBMovePosZ.act_position=40;
						inst->State=ST_POS3;
						//				inst->FBMovePosX.U=0;
						//				inst->FBMovePosY.U=0;
						//				inst->FBMovePosZ.U=0;
						//	inst->FBMovePosX.homing_done=0;
						//	inst->FBMovePosY.homing_done=0;
						//	inst->FBMovePosZ.homing_done=0;
						//	inst->Ustator=0;
						//	inst->Control.MovPos=!inst->Control.MovPos;
						
					}
				}
			}
			if(!inst->Control.MovPos){
				inst->State=ST_URTK_IDLE;
				inst->FBMovePosX.homing_done=0;
				inst->FBMovePosY.homing_done=0;
				inst->FBMovePosZ.homing_done=0;
				inst->Ustator=0;
			
				break;
			}
				
			
			inst->FBMovePosX.act_position=inst->AxisX.monitor.Position;
			if(inst->FBMovePosX.set_position==30){
				inst->AxisX.control.U = -inst->FBMovePosX.U; 
			}
			
			
			inst->FBMovePosY.act_position=inst->AxisY.monitor.Position;
			if(inst->FBMovePosY.set_position==40){
				inst->AxisY.control.U = -inst->FBMovePosY.U;
			}
		
			
			inst->FBMovePosZ.act_position=inst->AxisZ.monitor.Position;
			if(inst->FBMovePosZ.set_position==40){
				inst->AxisZ.control.U = inst->FBMovePosZ.U;
			}
			
		
			break;
		
		case ST_POS3:
			
			inst->FBMovePosX.enable=1;
			inst->FBMovePosY.enable=1;
			inst->FBMovePosZ.enable=1;
		
			if(!inst->FBMovePosX.enable){
				if(!inst->FBMovePosY.enable){
					if(!inst->FBMovePosZ.enable){
						inst->FBMovePosX.enable=inst->enable;
						inst->FBMovePosY.enable=inst->enable;
						inst->FBMovePosZ.enable=inst->enable;
						inst->FBMovePosX.set_position=70;  //задание точек
						inst->FBMovePosY.set_position=60;
						inst->FBMovePosZ.set_position=60;
						inst->FBMovePosX.act_position=10;
						inst->FBMovePosY.act_position=15;
						inst->FBMovePosZ.act_position=30;
						inst->State=ST_POS1;
						//				inst->FBMovePosX.U=0;
						//				inst->FBMovePosY.U=0;
						//				inst->FBMovePosZ.U=0;
						//	inst->FBMovePosX.homing_done=0;
						//	inst->FBMovePosY.homing_done=0;
						//	inst->FBMovePosZ.homing_done=0;
						//	inst->Ustator=0;
						//	inst->Control.MovPos=!inst->Control.MovPos;
						
					}
				}
			}
			if(!inst->Control.MovPos){
				inst->State=ST_URTK_IDLE;
				inst->FBMovePosX.homing_done=0;
				inst->FBMovePosY.homing_done=0;
				inst->FBMovePosZ.homing_done=0;
				inst->Ustator=0;
			
				break;
			}
				
			
			inst->FBMovePosX.act_position=inst->AxisX.monitor.Position;
			if(inst->FBMovePosX.set_position==10){
				inst->AxisX.control.U = -inst->FBMovePosX.U; 
			}
			
			
			inst->FBMovePosY.act_position=inst->AxisY.monitor.Position;
			if(inst->FBMovePosY.set_position==15){
				inst->AxisY.control.U = -inst->FBMovePosY.U;
			}
			
			inst->FBMovePosZ.act_position=inst->AxisZ.monitor.Position;
			if(inst->FBMovePosZ.set_position==30){
				inst->AxisZ.control.U = inst->FBMovePosZ.U;
			}
			
			break;
		
	}	

			
			
	FB_URTKAxisHome(&inst->FBHomingX); 
	FB_URTKAxisHome(&inst->FBHomingY); 
	FB_URTKAxisHome(&inst->FBHomingZ);
	FBURTKAxisMovePos(&inst->FBMovePosX);
	FBURTKAxisMovePos(&inst->FBMovePosY);
	FBURTKAxisMovePos(&inst->FBMovePosZ);
	FBURTKAxis(&inst->AxisX);
	FBURTKAxis(&inst->AxisY);
	FBURTKAxis(&inst->AxisZ);
	
	inst->Error.prevCLearError=inst->Error.CLearError;
	
}
	



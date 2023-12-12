
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "URTK_lib.h"
#ifdef __cplusplus
	};
#endif
/* функциональный блок управления одной степенью  */
void FBURTKAxis(struct FBURTKAxis* inst)
{
	//Обработка переменных мониторинга
	inst->hardware.PeriodDurationPWM=20;//Устанавливаем период ШИМ 20 мкс
	inst->hardware.ShowMeanCurrent=1;   //Включаем измерение тока
	inst->monitor.Iact=inst->hardware.CounterLatch;
	inst->monitor.Iact=inst->monitor.Iact/32767*10;
	inst->monitor.Position=inst->hardware.Counter;
	inst->monitor.Position=inst->monitor.Position/24*3; // 3 мм/об / 24 метки/об   
	inst->monitor.LimitN=inst->hardware.StatusInputN;
	inst->monitor.LimitP=inst->hardware.StatusInputP;
	
	
	//Обработка ошибок
	if(((inst->monitor.Iact>0)&&(inst->monitor.Iact>inst->control.ILim))||
	   ((inst->monitor.Iact<0)&&(inst->monitor.Iact<-inst->control.ILim)))
		inst->error.OverCurrent=1;
	if(inst->control.ClearError)
		inst->error.OverCurrent=0;
	
	//Проверка ограничений
	inst->monitor.Uact=inst->control.U; 
	if(inst->error.OverCurrent) 
		inst->monitor.Uact = 0; 
	if(inst->monitor.LimitN&&(inst->monitor.Uact<=0)) 
		inst->monitor.Uact = 0; 
	if(inst->monitor.LimitP&&(inst->monitor.Uact>=0)) 
		inst->monitor.Uact = 0; 
	if(inst->monitor.Uact>24.0) 
		inst->monitor.Uact=24.0; 
	if(inst->monitor.Uact<-24.0) 
		inst->monitor.Uact=-24.0;
	
	//Формирование выходного сигнала
	inst->hardware.PulseWidthCurrentPWM=inst->monitor.Uact/24.0*32767.0;
	
}

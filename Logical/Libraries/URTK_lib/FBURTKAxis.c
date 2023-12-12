
#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif
	#include "URTK_lib.h"
#ifdef __cplusplus
	};
#endif
/* �������������� ���� ���������� ����� ��������  */
void FBURTKAxis(struct FBURTKAxis* inst)
{
	//��������� ���������� �����������
	inst->hardware.PeriodDurationPWM=20;//������������� ������ ��� 20 ���
	inst->hardware.ShowMeanCurrent=1;   //�������� ��������� ����
	inst->monitor.Iact=inst->hardware.CounterLatch;
	inst->monitor.Iact=inst->monitor.Iact/32767*10;
	inst->monitor.Position=inst->hardware.Counter;
	inst->monitor.Position=inst->monitor.Position/24*3; // 3 ��/�� / 24 �����/��   
	inst->monitor.LimitN=inst->hardware.StatusInputN;
	inst->monitor.LimitP=inst->hardware.StatusInputP;
	
	
	//��������� ������
	if(((inst->monitor.Iact>0)&&(inst->monitor.Iact>inst->control.ILim))||
	   ((inst->monitor.Iact<0)&&(inst->monitor.Iact<-inst->control.ILim)))
		inst->error.OverCurrent=1;
	if(inst->control.ClearError)
		inst->error.OverCurrent=0;
	
	//�������� �����������
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
	
	//������������ ��������� �������
	inst->hardware.PulseWidthCurrentPWM=inst->monitor.Uact/24.0*32767.0;
	
}

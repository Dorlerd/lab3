
TYPE
	TURTKAxisMonitor : 	STRUCT 
		Position : REAL;
		LimitN : BOOL;
		LimitP : BOOL;
		Iact : REAL; (*Измеряемый ток в амперах*)
		Uact : REAL; (*Фактически формируемое напряжение*)
	END_STRUCT;
	TURTKAxicCtrl : 	STRUCT 
		U : REAL; (*напряжение в вольтах*)
		ILim : REAL; (*ограничение тока в Амперах*)
		ClearError : BOOL;
	END_STRUCT;
	TURTKAxisError : 	STRUCT 
		OverCurrent : BOOL;
	END_STRUCT;
	TURTKAxisHardware : 	STRUCT 
		PeriodDurationPWM : UINT := 20;
		StatusInputP : BOOL;
		StatusInputN : BOOL;
		PulseWidthCurrentPWM : INT;
		ShowMeanCurrent : BOOL;
		Counter : INT;
		CounterLatch : INT;
	END_STRUCT;
	TURTKHomingState : 
		(
		ST_IDLE,
		ST_MOVE_FAST,
		ST_MOVE_SLOW
		);
	TURTKMovePos : 
		(
		ST_IDLE_POS,
		ST_MOVE_POS
		);
	TURTKHardware : 	STRUCT 
		PWMDuration : UINT;
		PWMX : INT;
		Error : BOOL;
		Grip : BOOL;
		UnderVoltageError : BOOL;
		VoltageWarning : BOOL;
		OverVoltageError : BOOL;
		OverTemperatureError : BOOL;
		PWMError01 : BOOL;
		CurrentError01 : BOOL;
		OverCurrentError01 : BOOL;
		PWMError02 : BOOL;
		CurrentError02 : BOOL;
		OverCurrentError02 : BOOL;
		PWMError03 : BOOL;
		CurrentError03 : BOOL;
		OverCurrentError03 : BOOL;
	END_STRUCT;
	ERROR : 
		(
		ERR_URTK_NO_ERROR := 0,
		ERR_URTK_UNDERVOLTAGE := 1,
		ERR_URTK_VOLTAGEWARNING := 3,
		ERR_URTK_OVERVOLTAGE := 4,
		ERR_URTK_OVERTEMPERATURE := 5,
		ERR_URTK_PWM01 := 6,
		ERR_URTK_CURRENT01 := 7,
		ERR_URTK_OVERCURRENT01 := 8,
		ERR_URTK_PWM02 := 9,
		ERR_URTK_CURRENT02 := 10,
		ERR_URTK_OVERCURRENT02 := 11,
		ERR_URTK_PWM03 := 12,
		ERR_URTK_CURRENT03 := 13,
		ERR_URTK_OVERCURRENT03 := 14
		);
	TURTKMonitor : 	STRUCT 
		PositionX : REAL;
		PositionY : REAL;
		PositionZ : REAL;
		LimitX_N : BOOL;
		LimitX_P : BOOL;
		LimitY_N : BOOL;
		LimitY_P : BOOL;
		LimitZ_N : BOOL;
		LimitZ_P : BOOL;
		Grip : BOOL;
		HomingX : FB_URTKAxisHome;
		HomingY : FB_URTKAxisHome;
		HomingZ : FB_URTKAxisHome;
		HomingOK : BOOL;
		InPosition : BOOL;
	END_STRUCT;
	TURTKError : 	STRUCT 
		Type : ERROR;
		Error : BOOL;
		CLearError : BOOL;
		ConfigIun : BOOL;
		prevCLearError : BOOL;
	END_STRUCT;
	TURTKControl : 	STRUCT 
		ManualCtrl : BOOL;
		StartHoming : BOOL;
		MovPos : BOOL;
		X : REAL;
		Y : REAL;
		Z : REAL;
		ManBtnXPos : BOOL;
		ManBtnXNeg : BOOL;
		ManBtnYPos : BOOL;
		ManBtnYNeg : BOOL;
		ManBtnZPos : BOOL;
		ManBtnZNeg : BOOL;
		Grip : BOOL;
	END_STRUCT;
	URTKCtrl : 
		(
		ST_URTK_IDLE,
		ST_URTK_MANUAL,
		ST_URTK_ERROR,
		ST_URTK_HOMING,
		ST_URTK_MOVE_POS,
		ST_POS1,
		ST_POS2,
		ST_POS3
		);
END_TYPE

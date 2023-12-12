
FUNCTION_BLOCK FBURTKAxis (*функциональный блок управления одной степенью *) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		control : TURTKAxicCtrl;
		monitor : TURTKAxisMonitor;
		error : TURTKAxisError;
		hardware : TURTKAxisHardware;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK FB_URTKAxisHome (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		U_fast : REAL;
		U_low : REAL;
		pos_direction : BOOL;
		LimitP : BOOL;
		LimitN : BOOL;
		enable : BOOL;
	END_VAR
	VAR_OUTPUT
		U : REAL;
		done : BOOL;
		ResetCounter : BOOL;
		State : TURTKHomingState;
	END_VAR
	VAR
		p_dir : BOOL;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK FBURTKAxisMovePos (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		set_position : REAL;
		set_position1 : REAL;
		set_position2 : REAL;
		act_position : REAL;
		homing_done : BOOL;
		K : REAL;
		enable : BOOL;
	END_VAR
	VAR_OUTPUT
		done : BOOL;
		U : REAL;
		State : TURTKMovePos;
		done1 : BOOL;
		done2 : BOOL;
		done3 : BOOL;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK FBURTKCtrl (*TODO: Add your comment here*) (*$GROUP=User,$CAT=User,$GROUPICON=User.png,$CATICON=User.png*)
	VAR_INPUT
		Grip : BOOL;
		Hardware : TURTKHardware;
		Monitor : TURTKMonitor;
		Error : TURTKError;
		Control : TURTKControl;
		enable : BOOL;
		AxisX : FBURTKAxis;
		AxisY : FBURTKAxis;
		AxisZ : FBURTKAxis;
		FBHomingX : FB_URTKAxisHome;
		FBHomingY : FB_URTKAxisHome;
		FBHomingZ : FB_URTKAxisHome;
		FBMovePosX : FBURTKAxisMovePos;
		FBMovePosY : FBURTKAxisMovePos;
		FBMovePosZ : FBURTKAxisMovePos;
		Ustator : INT;
	END_VAR
	VAR_OUTPUT
		State : URTKCtrl;
	END_VAR
END_FUNCTION_BLOCK

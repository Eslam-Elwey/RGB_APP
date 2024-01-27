
#include "StdTypes.h"
#include "DIO_Int.h"
#include "MOTOR_Cfg.h"
#include "MOTOR_Int.h"

void MOTOR_Init(void) 
{
	
}


void MOTOR_Rotate_CW(motor_t motor_no) 
{
	DIO_WritePin(motor_arr[motor_no].MOTOR_ENABLE_1,HIGH);
	DIO_WritePin(motor_arr[motor_no].MOTOR_ENABLE_2,LOW);
}

void MOTOR_Rotate_Counter_CW(motor_t motor_no) 
{
	DIO_WritePin(motor_arr[motor_no].MOTOR_ENABLE_1,LOW);
	DIO_WritePin(motor_arr[motor_no].MOTOR_ENABLE_2,HIGH);
}

void MOTOR_Stop(motor_t motor_no) 
{
	DIO_WritePin(motor_arr[motor_no].MOTOR_ENABLE_1,LOW);
	DIO_WritePin(motor_arr[motor_no].MOTOR_ENABLE_2,LOW);
}

void MOTOR_Set_Speed(u8 speed_Percentage)
{
	
}
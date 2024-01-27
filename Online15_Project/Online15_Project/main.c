
/*********************** Macros *************************************/
#define F_CPU		8000000UL

/************************** Includes *********************************/

#include <util/delay.h>
#include "StdTypes.h"
#include "LED_Int.h"
#include "BUTTON_Int.h"
#include "SEVEN_SEG_Int.h"
#include "STOP_WATCH_Int.h"
#include "MOTOR_Int.h"
#include "CAR_MOVE_Int.h"
#include "Stepper_Int.h"
#include "LCD_Int.h"
#include "KeyPad_Int.h"
#include "Calculator_Int.h"
#include "Number_Converter_Int.h"
#include "StepperAPP_Int.h"
#include "ADC_Int.h"
#include "LCD_Game_Int.h"
#include "SENSORS_Int.h"
#include "EEPROM_Int.h"
#include "Fire_System_Int.h"
#include "TEMP_Filter_Int.h"
#include "EXI_Int.h"
#include "Timers_Int.h"
#include "Timers_Services_Int.h"
#include "RGB_Int.h"
#include "RGB_APP_Int.h"


int main(void)
{ 
	
	DIO_Init();
	LCD_Init() ;
	RGB_Init() ;
	EXI_Init();
	EXT_INT_ENABLE(EXT_INT1,INTERRUPT_FALLING_EDGE);
	Timer0_Init(TIMER0_FAST_PWM_MODE,Timer0_PRESCALER_CLK_8) ;
	Timer1_Init(TIMER1_FAST_PWM_8_BIT_TOP,TIMER1_PRESCALER_CLK_8);
	Timer2_Init(TIMER2_NORMAL_MODE,TIMER2_PRESCALER_CLK_1024);
	
	GLOBAL_INTERRUPT_ENABLE();
	
	
	RGB_APP_Init() ;

	
	while (1)
	{
		
		RGB_APP_Runnable() ;
		
		
		
	}



}



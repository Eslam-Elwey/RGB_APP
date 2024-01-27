
#include "StdTypes.h"
#include "Timers_Int.h"
#include "Timers_Services_Int.h"
#include "EXI_Int.h"

static void Fun_Call_Interrrupt (void) ;
static void Fun_Timer2_Call_Interrrupt (void) ;
static void measure_timer0_no_interrupts (void) ;
static void EXI0_Measure_Func (void);

static u32 time_interrupt ;
static void (*pfunc) (void);
static u32 repeat ; 
static u32 reminder ;

static u32 time2_interrupt ;
static void (*pfunc2) (void);
static u32 repeat2 ;
static u32 reminder2 ;

static volatile u32 t1 , t2 , press_time , counter ; 
static u8 finish_flag = 0 ;

/*Use Timer0 Normal Mode (Over Flow Interrupt)
 Timer0_Init(TIMER0_NORMAL_MODE,Timer0_PRESCALER_CLK_8)  */
void Set_Function_Call_Interrupt_Time_us (u32 time , void (*pf) (void))
{
	pfunc = pf ;
	time_interrupt = time ;
	
	if (time_interrupt <= 255)
	{
		TIMER0_WRITE_VALUE (256-time_interrupt);
	}
	else 
	{
		reminder = time_interrupt % 256 ;
		repeat = (time_interrupt / 256) + 1 ;
		TIMER0_WRITE_VALUE (256-reminder);
	}
	Timer0_SET_OVF_Call_Back(Fun_Call_Interrrupt);
}


static void Fun_Call_Interrrupt (void) 
{
	
	if (time_interrupt <= 255)
	{
		TIMER0_WRITE_VALUE (256-time_interrupt);
		pfunc();
	}
	
	else 
	{
		static u16 counter = 0 ;
		
		counter++ ;
		
		if (counter==repeat)
		{
			counter = 0 ;
			TIMER0_WRITE_VALUE (256-reminder);
			pfunc();
		}
	
	}
}

void Set_Call_Timer2_Interrupt_Time_ms (u32 time , void (*pf) (void))
{
	pfunc2 = pf ;
	time2_interrupt = time*1000 ;
	
	if (time2_interrupt <= 32768)
	{
		TIMER2_WRITE_VALUE (256-(time2_interrupt/128));
	}
	else
	{
		reminder2 = time2_interrupt % 32768 ;
		repeat2 = (time2_interrupt / 32768) + 1 ;
		TIMER2_WRITE_VALUE (256-(reminder2/128));
	}
	Timer2_SET_OVF_Call_Back(Fun_Timer2_Call_Interrrupt);
}


static void Fun_Timer2_Call_Interrrupt (void)
{
	if (time2_interrupt <= 32768)
	{
		TIMER2_WRITE_VALUE (256-(time2_interrupt/128));
		pfunc2();
	}
	
	else
	{
		static u16 counter = 0 ;
		
		counter++ ;
		
		if (counter==repeat2)
		{
			counter = 0 ;
			TIMER2_WRITE_VALUE (256-(reminder2/128));
			pfunc2();
		}
		
	}
}

void Measure_Button_Pressing_Time (void) 
{
	Timer0_SET_OVF_Call_Back(measure_timer0_no_interrupts);
	EXT_INT_Set_Call_Back(EXT_INT0,EXI0_Measure_Func);
}

u8 Get_press_time_val (u32 *ptime) 
{
	u8 ret_state = 0 ; 
	if (1==finish_flag)
	{
		press_time = t2 - t1 + (counter*256) ; 
		counter = 0 ;
		*ptime = press_time ;
		finish_flag = 0 ;
		ret_state = 1 ;
	}
	
	return ret_state ;
}

/*Use Timer 0*/
static void EXI0_Measure_Func (void)
{
	static flag = 0 ;
	if (0==flag)
	{
		TIMER0_READ_VALUE(&t1) ;
		flag = 1 ;
	}
	else if (1==flag)
	{
		TIMER0_READ_VALUE(&t2) ;
		
		finish_flag = 1 ;
		flag = 0 ;
	}
}
static void measure_timer0_no_interrupts (void)
{
	counter++ ; 
}
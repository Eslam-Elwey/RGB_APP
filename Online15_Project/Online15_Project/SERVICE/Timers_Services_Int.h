
#ifndef TIMERS_SERVICES_INT_H_
#define TIMERS_SERVICES_INT_H_

/* Set Timer0 Normal Mode Prescaler 8*/
void Set_Function_Call_Interrupt_Time_us (u32 time , void (*pf) (void));


/* Set Timer2 Normal Mode Prescaler 1024*/
void Set_Call_Timer2_Interrupt_Time_ms (u32 time , void (*pf) (void));


/*Timer
Set EXI On Any Change 
Take 2 Reads From Timer 
on Falling Edge And Rising Edge 
time = t2 - t1 + c * I.T*/
void Measure_Button_Pressing_Time (void) ;
u8 Get_press_time_val (u32 *ptime) ;

#endif /* TIMERS_SERVICES_INT_H_ */
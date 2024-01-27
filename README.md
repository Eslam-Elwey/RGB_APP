# RGB_APP
Usiing MCU ATMEGA32  
HAL : RGB / LCD
MCAL : Timers / External Interrupts 
Services : Timer Services 
APP : RGB_APP

Timer0 Operates In Fast PWM Mode (Scaler 8)
Timer1 Operates In FAST PWM 8 BIT Mode (Scaler 8)
TImer2 Operates In Normal Mode to Set Interrupt Time (Scaler 1024)
Button1 : Change Colours 
Button2 : Change Mode

There Are 2 Modes 
1. Normal Mode : Change Colours When Pressing Button1 Which Cause Falling Edge On EXI0
  and Print Color Name on LCD
3. Showroom Mode : Change Between Colours Gradually When Pressing Button2 

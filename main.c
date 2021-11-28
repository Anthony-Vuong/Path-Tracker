#include "msp.h"
#include "Delay.h"
#include "LCD.h"


void main(void)
{
    WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;     // stop watchdog timer

    configureTimerA0();
    configureTimerA1();
    configureLCD_Pins();
    configureLCD();

    while(1){

    }



}


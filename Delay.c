#include "msp.h"
#include "Delay.h"


//1ms Delay = SMLK_FREQ x delay = 3000000 x .001
void configureTimerA1(){
    TIMER_A1->CTL = 0x02D1;
    TIMER_A1->EX0 = 7;
    TIMER_A1->CCR[0] = 3000 - 1;
}

void delay_milliSec(int time){

    while((TIMER_A1->CCTL[0] &1)==0);
    TIMER_A1->CCTL[0] &= ~1;

}

//1us Delay = SMLK_FREQ x delay = 3000000 x .000001
void configureTimerA0(){
    TIMER_A0->CTL = 0x02D1;
    TIMER_A0->EX0 = 7;
    TIMER_A0->CCR[0] = 3 - 1;
}

void delay_microSec(int time){

    while((TIMER_A0->CCTL[0] &1)==0);
    TIMER_A0->CCTL[0] &= ~1;

}

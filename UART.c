#include "msp.h"
#include "Delay.h"

void UART0_init(void){
    EUSCI_A0->CTLW0 |= 1;
    EUSCI_A0->MCTLW = 1;

    EUSCI_A0->CTLW0 = 0x0081;
    EUSCI_A0->BRW = 26;

    P1->SEL0 |= 0x0C;
    P1->SEL1 &= ~0x0C;

    EUSCI_A0->CTLW0 &= ~1;

}

void transmit(){
    while(!(EUSCI_A0->IFG & 0x02)){}
    EUSCI_A0->TXBUF = 'Y';
    while(!(EUSCI_A0->IFG & 0x02)){}
    EUSCI_A0->TXBUF = 'E';
    while(!(EUSCI_A0->IFG & 0x02)){}
    EUSCI_A0->TXBUF = 'S';
    delay_milliSec(2);
}

void receive(){
    while(!(EUSCI_A0->IFG & 0x01)){}
    P2->OUT = EUSCI_A0->RXBUF;
}





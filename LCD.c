/*
 * LCD.c
 *
 *  Created on: Nov 27, 2021
 *      Author: peter
 */

//LCD Commands

#include "msp.h"
#include "Delay.h"
#include "LCD.h"

#define clear_display 0x01
#define return_home 0x02
#define function_set 0x28
#define wake_up 0x30
#define Bit4_mode 0x20
#define cursor_right 0x06
#define display_on 0x0F

//Control Bits
#define RS BIT0
#define RW BIT1
#define EN BIT2

//Data Bits
#define D7 BIT3
#define D6 BIT2
#define D5 BIT1
#define D4 BIT0

#define dataBits D7|D6|D5|D4
#define ctrlBits EN|RW|RS


void configureLCD_Pins(){

    //Data Pins - 4.0-4.3
    P4->SEL0 &= ~(dataBits);
    P4->SEL1 &= ~(dataBits);

    //Control Pins - 5.0-5.2
    P5->SEL0 &= ~(ctrlBits);
    P5->SEL1 &= ~(ctrlBits);

    //Setup all pins as output
    P4->DIR |= dataBits;
    P5->DIR |= ctrlBits;

}

void configureLCD(){

    delay_milliSec(30);

    write_command(wake_up);

    delay_milliSec(10);

    write_command(wake_up);

    delay_milliSec(1);

    write_command(wake_up);

    delay_milliSec(1);

    write_command(Bit4_mode);

    delay_milliSec(1);

    write_command(function_set);
    write_command(cursor_right);
    write_command(clear_display);
    write_command(display_on);


}

void nibble(unsigned char data){
    P4->OUT &= 0x00;
    P4->OUT |= data;

    P5->OUT |= EN;

    delay_microSec(500);

    P5->OUT &= ~EN;

}


void write_data(unsigned char cmd){


    P5->OUT &= ~RW;
    P5->OUT |= RS;

    nibble((cmd >> 4) & 0x0F);

    delay_milliSec(10);

    nibble(cmd & 0x0F);

    delay_milliSec(10);

}

void write_command(unsigned char cmd){

    P5->OUT &= 0x00;
    P5->OUT &= ~(RW|RS);

    nibble((cmd >> 4) & 0x0F);

    delay_milliSec(2);

    nibble(cmd & 0x0F);

    delay_milliSec(2);

}





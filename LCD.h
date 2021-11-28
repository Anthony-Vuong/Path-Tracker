/*
 * LCD.h
 *
 *  Created on: Nov 27, 2021
 *      Author: peter
 */

#ifndef LCD_H_
#define LCD_H_

void nibble(unsigned char data);
void configureLCD_Pins();
void write_command(unsigned char cmd);
void write_data(unsigned char cmd);
void configureLCD();

#endif /* LCD_H_ */

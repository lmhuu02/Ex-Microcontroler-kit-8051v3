
/*
******************************************************
*time: 2023 
*embedded 8051 by langauge c.
*ex2: show f NE555 in display lcd 16x2
Pin output NE555: P3_4.

Tinh tan so giao dong, xung ne555:
giai thuat:
	su dung timer delay trong 1 giay.
	trong mot giay su dung counter dem xem co bao nhieu lan dao trang thai chan P3_4 (output ne555)
	tinh tan so giao dong: f = 	chinh bang so giao dong trong 1 giay.

*******************************************************

*/
//#include <reg51.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <REGX51.H>
#include "lcd16_02.h"

int i,dem;
unsigned char dt[3];

void delay_1s(){
	for(i = 0; i < 97;i++){  
		TMOD = 0x01; //timer 0 che do 1
		TL0 = 0xf0; //10ms, 1s = 1000ms
		TH0 = 0xd8;
		TR0 = 1;
		while(!TF0);
		TF0 = 0;
		TR0 = 0;
	}
}


void main(){
	LCD_Init();
	LCD_gotoxy(0,0);
	LCD_puts("DO AN ICTU 2023");
	delay_ms(500);
	LCD_clear();
	LCD_gotoxy(0,0);
	LCD_puts("SO XUNG NE555");
	delay_ms(500);
	LCD_gotoxy(0,1);
	LCD_puts("TAN SO: ");
	delay_ms(500);
	dem = 0;
	while(1){
		//dem = 0;
		//while(1){
			if(P3_4 == 0){
				//delay(10);
				dem++;
			}
			//delay_1s();
			//dem = dem + 10;
			//break;
		//}
	//LCD_gotoxy(8,1); 
		//dem = 210;
  sprintf(dt,"%d",dem);
	LCD_gotoxy(8,1); 
			LCD_puts(dt);
		//delay_1s();
	}
}
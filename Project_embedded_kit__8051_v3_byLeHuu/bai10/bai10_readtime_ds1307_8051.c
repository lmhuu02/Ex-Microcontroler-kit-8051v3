/*
DO AN TOT NGHIEP: KIT 8051 V3.
NAME: REALTIME DS1307 display on lcd16x2 in chip 8051.
TIME: 2/2023	- ICTU.
*/
/*---------------------------INCLUDE AND DEFINE-----------------------------------*/
#include <REGX51.H>
#include <lcd16x2.h>
#include <ds1307.h>
#include <stdio.h> 	//su dung sprintf()

/*-------------------------------MAIN FUNCTION-------------------------------*/
void main(){
	unsigned char hour,min,sec,date,month,year;
	lcd1602_init();
	lcd1602_clear();
	lcd1602_gotoxy(0,0);
	lcd1602_puts("DO AN TOT NGHIEP");
	lcd1602_gotoxy(0,1);
	delay_ms(3000);
	lcd1602_puts("  KIT 8051 V3");
	delay_ms(2000);
	lcd1602_gotoxy(0,0);
	lcd1602_puts("TEST DS1307");
	delay_ms(1000);
	lcd1602_clear();
	DS1307_Write(SEC,0);
	DS1307_Write(MIN,30);
	DS1307_Write(HOUR,10);
	DS1307_Write(DATE,30);
	DS1307_Write(MONTH,02);
	DS1307_Write(YEAR,23);
	while(1)
		{  
			hour=DS1307_get(HOUR);
			min=DS1307_get(MIN);
			sec=DS1307_get(SEC);
			date=DS1307_get(DATE);
			month=DS1307_get(MONTH);
			year=DS1307_get(YEAR);
			sprintf(Lcd_Buff,"%bu:%bu:%bu ",hour,min,sec);
			lcd1602_gotoxy(0,0);
			lcd1602_puts("TIME:");
			lcd1602_puts(Lcd_Buff);
			sprintf(Lcd_Buff,"DATE:%bu:%bu:20%bu ",date,month,year);
			lcd1602_gotoxy(0,1);
			lcd1602_puts(Lcd_Buff);
		}
}
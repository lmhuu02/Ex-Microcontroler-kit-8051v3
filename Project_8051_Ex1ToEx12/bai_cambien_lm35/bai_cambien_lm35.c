/*
DO AN TOT NGHIEP: KIT 8051 V3.
bai tap hien thi nhiet do LM35 len lcd 16x2 chip 8051, ADC PCF8591
TIME: 2/2023	- ICTU.
*/
/*--------------------------------------------------------------*/
//include cac thu vien lien quan: regx51.h, adc: pcf8591.h, lcd16x2.h, stdio.h de su dung: sprintf()
#include <REGX51.H>
#include <pcf8591.h>
#include <lcd16x2.h>
#include <stdio.h>

/*----------------------------MAIN FUNCTION----------------------------------*/
void main(){
	//INIT lcd, pcf8591.
	lcd1602_init();
	PCF8591_Init();
	lcd1602_clear();
	lcd1602_gotoxy(0,0);
	lcd1602_puts(" DO AN TOT NGHIEP");
	lcd1602_gotoxy(0,1);
	delay_ms(3000);
	lcd1602_puts("  KIT 8051 V3");
	delay_ms(2000);
	lcd1602_clear();
	lcd1602_gotoxy(0,0);
	lcd1602_puts("TEST LM35");
	while(1)
		{
			//DOC GIA TRI LM35 QUA IC PCF8591
			adc_value=PCF8591_Read(1);
			value_lm35=(float)adc_value*5000;
			value_lm35=(float)value_lm35/2550;
			sprintf(Lcd_Buff,"value = %.2f  ",value_lm35);
			//HIEN THI GIA TRI TINH TOAN LEN LCD 1602
			lcd1602_gotoxy(0,1);
			lcd1602_puts(Lcd_Buff);
			delay_ms(300);
		}
}
/*----------------------------END FILE----------------------------------*/
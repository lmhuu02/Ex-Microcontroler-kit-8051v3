/*
DO AN TOT NGHIEP: KIT 8051 V3.
NAME: EEPROM AT24C08 SHOW DATA on lcd16x2 in chip 8051.
TIME: 2/2023	- ICTU.
*/
/*---------------------------INCLUDE AND DEFINE-----------------------------------*/
#include <REGX51.H>
#include <lcd16x2.h>
#include <eeprom24c08.h>
#include <stdio.h> 	//su dung sprintf()

float Nhiet_Do;							// DS18b20

/*-------------------------------MAIN FUNCTION-------------------------------*/
void main(){
	//EEP_24CXX_Init();
	EEP_24CXX_Init();
	//INIT LCD 16X2
	lcd1602_init();
	lcd1602_clear();
	lcd1602_gotoxy(0,0);
	lcd1602_puts("DO AN TOT NGHIEP");
	lcd1602_gotoxy(0,1);
	delay_ms(2000);
	lcd1602_puts("  KIT 8051 V3");
	delay_ms(1000);
	lcd1602_clear();
	lcd1602_gotoxy(0,0);
	lcd1602_puts("TEST AT24C08");
	//sprintf(Lcd_Buff,"embedded_c_ICTU ");
	sprintf(Lcd_Buff,"eme ");
	EEP_24CXX_WriteS(0x20,Lcd_Buff);
	delay_ms(10);
	EEPROM_24CXX_ReadS(0x20,16,Lcd_Buff);
	lcd1602_gotoxy(0,1);
	lcd1602_puts(Lcd_Buff);
		while(1)
			{
			}
}
/*------------------------------END FILE--------------------------------*/
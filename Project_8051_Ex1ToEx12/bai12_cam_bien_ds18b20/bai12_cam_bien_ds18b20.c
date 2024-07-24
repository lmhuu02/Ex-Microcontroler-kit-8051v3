/*
DO AN TOT NGHIEP: KIT 8051 V3.
NAME: READ SENSOR DS18B20 display on lcd16x2 in chip 8051.
TIME: 2/2023	- ICTU.
*/
/*---------------------------INCLUDE AND DEFINE-----------------------------------*/
#include <REGX51.H>
#include <lcd16x2.h>
#include <ds18b20.h>
#include <stdio.h> 	//su dung sprintf()

float Nhiet_Do;							// DS18b20

/*-------------------------------MAIN FUNCTION-------------------------------*/
void main(){
	//INIT LCD 16X2
	lcd1602_init();
	lcd1602_clear();
	lcd1602_gotoxy(0,0);
	lcd1602_puts("DO AN TOT NGHIEP");
	lcd1602_gotoxy(0,1);
	delay_ms(3000);
	lcd1602_puts("  KIT 8051 V3");
	delay_ms(2000);
	lcd1602_clear();
	lcd1602_gotoxy(0,0);
	lcd1602_puts("TEST DS18B20");
	while(1)
	{
		//READ DATA DS18B20
		Nhiet_Do = ds18b20_readtemp();		
		sprintf(Lcd_Buff," value: %2.2f^C",Nhiet_Do); 		//EP TU KIEU FLOAT SANG STRING
		//SHOW IN LCD 16X2
		lcd1602_gotoxy(0,1);
		lcd1602_puts(Lcd_Buff);
		delay_ms(300);
	}
}
/*------------------------------END FILE--------------------------------*/
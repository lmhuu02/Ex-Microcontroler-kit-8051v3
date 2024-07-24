/*
DO AN TOT NGHIEP: KIT 8051 V3.
NAME: SHOW DATA on lcd16x2 in chip 8051.
TIME: 2/2023	- ICTU.
*/
/*---------------------------INCLUDE AND DEFINE-----------------------------------*/
#include <REGX51.H>
#include <lcd16x2.h>
#include <stdio.h>

unsigned int number = 0;

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
	while(1){
		lcd1602_gotoxy(0,0);
		lcd1602_puts("DO AN TOT NGHIEP");
		lcd1602_gotoxy(0,1);
		sprintf(Lcd_Buff," value: %d",number); 		//EP TU KIEU FLOAT SANG STRING
		lcd1602_puts(Lcd_Buff);
		delay_ms(1000);
		number++;
	}
}
/*------------------------------END FILE--------------------------------*/
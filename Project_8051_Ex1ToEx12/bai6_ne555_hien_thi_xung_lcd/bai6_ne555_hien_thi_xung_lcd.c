/*
DO AN TOT NGHIEP: KIT 8051 V3.
NAME: NE555 COUNT HZ SHOW LCD 16X2 in chip 8051.
TIME: 3/2023	- ICTU.
*/
/*---------------------------INCLUDE AND DEFINE-----------------------------------*/
#include <REGX51.H>
#include <lcd16x2.h>
#include <stdio.h> 	//su dung sprintf()

typedef   unsigned  long   int  uint32_t;
float f;
uint32_t t, value_timer0;

/*-------------------------------FUNCTION-------------------------------*/
void ngat_timer_0	() interrupt 1
{
	value_timer0+=0xffff;
}

/*-------------------------------MAIN FUNCTION-------------------------------*/
void main(){
	lcd1602_init();
	lcd1602_clear();
	lcd1602_gotoxy(0,0);
	lcd1602_puts("DO AN TOT NGHIEP");
	delay_ms(1000);
	lcd1602_gotoxy(0,1);
	lcd1602_puts(" KIT 8051 V3");
	delay_ms(1000);
	lcd1602_clear();
	lcd1602_gotoxy(0,0);
	lcd1602_puts("DO TAN SO");
	TMOD=0x01;
	EA=1;
	ET0=1;
	while(1)
	{
	TH0 = 0;
	TL0 = 0;

	while(INT0);	// Bo qua muc 1 dau tien
	while(!INT0);   // Bo qua muc 0
	TR0 = 1;
	while(INT0);
	TR0 = 0;

	t = TH0;
	t <<= 8;
	t |= TL0;
	t=t+value_timer0;
	value_timer0=0;
	t*=2;	
	f=(float)1000000/t;
	sprintf(Lcd_Buff,"F=%.2f Hz",f);
	lcd1602_gotoxy(0,1);
	lcd1602_puts(Lcd_Buff);
	delay_ms(500);
	}
}
/*------------------------------END FILE--------------------------------*/
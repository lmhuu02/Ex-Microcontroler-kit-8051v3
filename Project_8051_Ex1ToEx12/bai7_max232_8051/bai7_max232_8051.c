/*
DO AN TOT NGHIEP: KIT 8051 V3.
NAME: UART - MAX RS232 SHOW DATA on lcd16x2 in chip 8051.
TIME: 3/2023	- ICTU.
*/
/*---------------------------INCLUDE AND DEFINE-----------------------------------*/
//#include <REGX51.H>
#include <AT89X52.h>
#include <lcd16x2.h>
#include <uart.h>
#include <stdio.h> 	//su dung sprintf()


/*-------------------------------MAIN FUNCTION-------------------------------*/
void main(){
	//INIT UART IN 8051
	UART_Init();
	EA=1;
	UART_Puts("EMBEDDED AT ICTU");
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
	lcd1602_puts("TEST UART");
	
	while(1){
		Uart_char = UART_GetChar();
		if(Uart_char){
		//UART_PutChar(Uart_char);
		lcd1602_gotoxy(0,1);
		lcd1602_puts("RECEIVER:");
		lcd1602_gotoxy(10,1);
		lcd1602_putchar(Uart_char);
		}
	}
}
/*------------------------------END FILE--------------------------------*/
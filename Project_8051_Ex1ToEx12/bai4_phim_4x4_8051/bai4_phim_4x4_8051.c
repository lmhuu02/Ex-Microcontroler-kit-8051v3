/*
DO AN TOT NGHIEP: KIT 8051 V3.
NAME: BUTTON MATRIX 4X4 SHOW DATA on lcd16x2 in chip 8051.
TIME: 2/2023	- ICTU.
*link: https://www.electronicwings.com/8051/glcd-128x64-interfacing-with-at89s51-microcontroller
*link2: https://exploreembedded.com/wiki/Interfacing_glcd_with_8051
*/
/*---------------------------INCLUDE AND DEFINE-----------------------------------*/
#include <REGX51.H>
#include <lcd16x2.h>
#include <matrix_bt.h>
#include <stdio.h> 	//su dung sprintf()


/*-------------------------------MAIN FUNCTION-------------------------------*/

void main(){  //Chuong trinh chinh
	unsigned char but;
	//INIT LCD 16X2
	LCD_Init();
	delay_ms(200);
	LCD_Puts("Quet phim 4x4..");
	delay_ms(500);
	LCD_Clear();
	LCD_Gotoxy(0,0);
	LCD_Puts("DO AN TOT NGHIEP");
	delay_ms(1000);
	LCD_Gotoxy(0,1);
	LCD_Puts(" KIT 8051 V3");
	delay_ms(1000);
	LCD_Clear();
	LCD_Gotoxy(0,0);
	LCD_Puts("DO AN TOT NGHIEP");
	while(1){
	 	 LCD_Gotoxy(0,1);
		 but=get_key();
		//CALL FUNCTION CHECK BUTTON MATRIX.
		 if(but>0)show_button(but);
	 	 //else LCD_Puts("No key");
		 delay_ms(200);
	 }

}



/*******************************************************************
  *	@file 		glcd.c
  * @author  	MinhHaGroup
  * @version 	V1.0.0
  * @date   
  * @brief  	File cac ham de dieu khien LCD 128x64 mode 8 bit
********************************************************************/
#include "main.h"

void lcd_enable()
{
	LCD_E = 1;
	delay_us(50);
	LCD_E = 0;
	delay_us(30);
}
// ==============================================================================

void write_data_lcd(unsigned char WDLCD)
{
	delay_us(200);						// LUU Y SU CAN THIET CUA KHOANG THOI GIAN DELAY NAY 
	LCD_RS = 1;
	LCD_RW = 0;
	LCD_Data = WDLCD;
	lcd_enable();
}

// ==============================================================================

void write_command_lcd(unsigned char WCLCD) 
{
	delay_us(200);						// LUU Y SU CAN THIET CUA KHOANG THOI GIAN DELAY NAY 
	LCD_RS = 0;
	LCD_RW = 0; 
	LCD_Data = WCLCD;
	lcd_enable();
}

// ==============================================================================
	
// HAM KHOI TAO LCD ------------------------------------------------
// MODE 8 bit ------------------------------------------------------
void lcd_init(void)
{
	// Function set
	write_command_lcd(0x30); 					// Chon che do truyen 8 bit
	delay_us(150);											// delay > 100us
	write_command_lcd(0x30); 					// Chon che do truyen 8 bit
	delay_us(50);												// delay > 37us
	
	// Display ON/OFF control
	write_command_lcd(0x0C); 					// Cho phep hien thi ra LCD 128x64
	delay_us(120);											// delay > 100us
	
	// Clear LCD
	write_command_lcd(0x01); 					// Xoa man hinh			
	delay_ms(40);												// delay > 10ms
	
	// Entry mode set
	write_command_lcd(0x06); 					// Chon che do hien thi ki tu ra man hinh LCD 128x64 (Ki tu sau xuat hien ben phai ki tu truoc)
}
// ==============================================================================

void lcd_clear(void) 
{
	write_command_lcd(0x01);
}

// ==============================================================================
void lcd_putchar(unsigned char X, unsigned char Y, unsigned char DData)
{
	if(Y<1)
		Y=1;
	if(Y>4)
		Y=4;
	X &= 0x0F; 
	switch(Y)
	{
		case 1:X|=0X80;break;
		case 2:X|=0X90;break;
		case 3:X|=0X88;break;
		case 4:X|=0X98;break;
	}
	write_command_lcd(X); 
	write_data_lcd(DData);
}
// ==============================================================================
void lcd_puts(unsigned char X, unsigned char Y, unsigned char *DData)
{
	unsigned char ListLength,X2;

	ListLength = 0;
	X2=X;
	if(Y<1)
		Y=1;
	if(Y>4)
		Y=4;
	X &= 0x0F; 
	switch(Y)
	{
		case 1:X2|=0X80;break;	
		case 2:X2|=0X90;break;
		case 3:X2|=0X88;break;
		case 4:X2|=0X98;break;
	}
	write_command_lcd(X2); 
	while (DData[ListLength]>=0x20) 
	{
		if (X <= 0x0F) 
		{
			write_data_lcd(DData[ListLength]);
			ListLength++;
			X++;
			delay_ms(5);
		}
	}
}
// ==============================================================================
/*
void lcd_display_image  (unsigned char *DData)
{
	unsigned char x,y,i;
	unsigned int tmp=0;
	for(i=0;i<9;)
	{		
		for(x=0;x<32;x++)
		{				
			write_command_lcd(0x34);
			write_command_lcd((0x80+x));
			write_command_lcd((0x80+i));	
			write_command_lcd(0x30);		
			for(y=0;y<16;y++)	
				write_data_lcd(DData[tmp+y]);
			tmp+=16;		
		}
		i+=8;
	}
		write_command_lcd(0x36);	
		write_command_lcd(0x30);
}
*/
/* -----------------END OF FILE---------------------------- */


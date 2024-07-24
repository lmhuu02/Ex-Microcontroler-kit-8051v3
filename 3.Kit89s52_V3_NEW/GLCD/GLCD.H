/*******************************************************************
  *	@file 		glcd.h
  * @author  	MinhHaGroup
  * @version 	V1.0.0
  * @date   
  * @brief  	File thu vien khai bao ham cho file  glcd.c
********************************************************************/
#ifndef __GLCD_
#define __GLCD_

#include <main.h>

void lcd_enable();

// Ham cho phep viet 1 byte du lieu vao LCD ---------------------------------------
void write_data_lcd(unsigned char WDLCD);	

// Ham cho phep viet 1 byte lenh dieu khien vao LCD -------------------------------
void write_command_lcd(unsigned char WCLCD);

// Ham cho phep khoi tao de su dung  LCD ------------------------------------------
void lcd_init(void);

// Ham cho phep xoa toan bo man hinh LCD ------------------------------------------
void lcd_clear(void);

// Ham cho phep ON/OFF hien thi ra man hinh LCD -----------------------------------
void lcd_flash(void);

// Ham cho phep viet 1 ki tu ra man hinh LCD --------------------------------------
void lcd_putchar(unsigned char X, unsigned char Y, unsigned char DData);

// Ham cho phep viet 1 chuoi ki tu ra man hinh LCD --------------------------------
void lcd_puts(unsigned char X, unsigned char Y, unsigned char *DData);

// Ham cho phep hien thi hinh anh ra man hinh LCD ----------------------------------
void lcd_display_image (unsigned char *DData);

#endif
/* -----------------END OF FILE--------------------------- */
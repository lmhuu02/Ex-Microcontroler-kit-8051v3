/**
  ******************************************************************************
  * Ten Tep      :        main.h
  * Tac Gia      :        Nguyen Quy Nhat
  * Cong Ty      :        MinhHaGroup
  * Website      :        BanLinhKien.Vn
  * Phien Ban    :        V1.0.0
  * Ngay         :        31-08-2012
  * Tom Tat      :        Khai bao cac thu vien.
  *                       Cau hinh mot so chuc nang cho trinh bien dich.
  *                       Cau hinh mot so chuc nang cho CHIP.
  *                       Dinh nghia I/O.
  *                         
  ******************************************************************************
  */
#ifndef __MAIN_H
#define __MAIN_H
#define PRO_DATA 	code
/*	Kieu So Nguyen Co Dau	*/
typedef   signed           char int8_t;
typedef   signed 	       int int16_t;
typedef   signed long      int int32_t;

/*	Kieu So Nguyen Khong Dau */
typedef   unsigned         char uint8_t;
typedef   unsigned 	       int  uint16_t;
typedef   unsigned long    int  uint32_t;
/*	Kieu So Thuc */
typedef   float            float32_t;
/////////////////////////////////////////
typedef struct FONT_DEF 
{
	uint8_t u8Width;     	/* Character width for storage         */
	uint8_t u8Height;  		/* Character height for storage        */
	uint8_t *au8FontTable;       /* Font table start address in memory  */
} FONT_DEF;

extern code FONT_DEF Font_System3x6;
extern code FONT_DEF Font_System5x8;
extern code FONT_DEF Font_System7x8;
extern code FONT_DEF Font_Courrier8x12;

extern code uint8_t au8FontSystem3x6[];
extern code uint8_t au8FontSystem5x8[];
extern code uint8_t au8FontSystem7x8[];
extern code uint8_t au8FontCourrier8x12[];
/*********** HW ************/
#include "AT89X52.h"
#include "DEF_8051.h"
#include <intrins.h>
#include "stdio.h"
#include <regx52.h>
#include <DELAY\delay.h>
#include <LCD1602\lcd1602.h>
//#include <GLCD\glcd.h>
#include <LED7\led7.h>
#include <MTP\mtp4x4.h>
#include <DS1820\ds18b20.h>
#include <UART\uart.h>
//#include <ds1302\ds1302.h>
#include <KEY\key.h>
#include <stdio.h>
#include <string.h>
#include <ds1307/ds1307.h>
#include "EPP_24C08/24c08.h"
#include "PCF8591/PCF8591.H"
#include "tdef.h"
#include "TIMER/timer.h"
//#include "lcd_ks0108/lcd_ks0108.h"

//#include <i2c/i2c.h>
#define INT0	P3_4
//------------------CAU HINH I/O------------------
// PORT0 -----------------------------------------
// Cac chan du lieu cua LCD ----------------------
#define LCD_D4 P0_4
#define LCD_D5 P0_5
#define LCD_D6 P0_6
#define LCD_D7 P0_7
//#define LCD_DATA P0
#define LED7_DATA P0

//=============================================================================	
// PORT1 -----------------------------------------
// Ma tran phim 4x4 ------------------------------
// Cac hang cua ma tran phim duoc noi voi 4 bit thap P1_[0..3]
// Cac cot cua ma tran phim duoc noi voi 4 bit cao P1_[4..7]

// 8 LED don -------------------------------------
#define LED_DON P1

// Chan du lieu cua DS18b20 ----------------------
#define DQ P1_2

// Chan dieu khien RELAY -------------------------
#define RELAY P1_0

// Chan dieu khien COI CHIP ----------------------
#define COI P1_3

//#define SCL P1_7

//=============================================================================	
// PORT2 -----------------------------------------
// Cac chan dieu khien cua LCD -------------------
#define LCD_RS 				 P2_2
#define LCD_RW 				 P2_3
#define LCD_E 				 P2_4
// Cac chan dieu khien LED 7 thanh ---------------
#define LED7_SEG P2
#define DS1302_DATA_IN       P3_3
#define DS1302_DATA_OUT      P3_3
#define DS1302_DDR_DATA      P3_3
#define DS1302_CLK           P1_7
#define DS1302_RST           P3_2

//=============================================================================	
// PORT3 -----------------------------------------
// Cac nut bam -----------------------------------
#define KEY0 P3_2
#define KEY1 P3_3
#define KEY2 P3_4
#define KEY3 P3_5

#endif
/******************************KET THUC FILE******************************
______________________________NGUYEN QUY NHAT______________________________*/
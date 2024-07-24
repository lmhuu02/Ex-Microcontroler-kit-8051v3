/**
  ******************************************************************************
  * Ten Tep		:		  var.h
  * Tac Gia		:	  	LE ANH QUANG
  * Cong Ty		:			MinhHaGroup
  *	Website 	:			MinhHaGroup.com
  * Phien Ban	:			V1.0.0
  * Ngay			:    	19-10-2012
  * Tom Tat   :     Khai bao cac bien toan cuc
  *           
  *
  ******************************************************************************
  * Chu Y		:
  *							 
  ******************************************************************************
  */
	

#ifndef __VAR_H
#define __VAR_H

//unsigned char hour,minute,second;
float Nhiet_Do;							// DS18b20
unsigned  char Lcd_Buff[16];//,str[16];	// LCD1602
unsigned char KEY,i;				// MA TRAN PHIM 4x4, PHIM BAM
unsigned char Uart_char;		// UART
uint8_t adc_value, dac_value=0;
float value_lm35;
uint16_t Code=0;
uint32_t t,value_timer0;
float f;


 
#endif
// ------------------END OF FILE--------------------
// -------------------------------------------------
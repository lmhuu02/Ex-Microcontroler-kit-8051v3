/**
  ******************************************************************************
  * Ten Tep		:		  ds18b20.h
  * Tac Gia		:	  	LE ANH QUANG
  * Cong Ty		:			MinhHaGroup
  *	Website 	:			MinhHaGroup.com
  * Phien Ban	:			V1.0.0
  * Ngay			:    	20-09-2012
  * Tom Tat   :     Khai bao cac ham xu ly DS18b20
  *           
  *
  ******************************************************************************
  * Chu Y		:
  *							 
  ******************************************************************************
  */
	
#ifndef __DS18B20_H
#define __DS18B20_H

#include <main.h>

bit DS18B20_Init();														// Ham khoi tao DS18B20
unsigned char ds18b20_readbyte(void);					// Ham doc 1 byte tu DS18b20 ra ngoai
void ds18b20_writebyte(unsigned char Data);		// Ham viet 1 byte vao DS18b20
float ds18b20_readtemp(void);									// Ham chuyen doi va tra ve gia tri nhiet do

#endif
// ------------------END OF FILE--------------------
// -------------------------------------------------
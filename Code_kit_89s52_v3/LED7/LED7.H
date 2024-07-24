/**
  ******************************************************************************
  * Ten Tep		:		  Led7.h
  * Tac Gia		:	  	Nguyen Quy Nhat
  * Cong Ty		:			MinhHaGroup
  *	Website 	:			BanLinhKien.Vn
  * Phien Ban	:			V1.0.0
  * Ngay			:    	31-07-2012
  * Tom Tat   :     Khai bao cac ham dieu khien man hinh led 7.
  *           
  *
  ******************************************************************************
  * Chu Y		:
  *							 
  ******************************************************************************
  */		
#ifndef __LED7_H
#define	__LED7_H
#include "main.h"

void LED7_display(unsigned long int number);
void LED7_OnLed(unsigned char addr);
void LED7_ChuyenDoi(unsigned long int number);

#ifndef PORT_ADDR
#define PORT_ADDR P2
#endif

#ifndef PORT_DATA
#define PORT_DATA	P0
#endif

#endif

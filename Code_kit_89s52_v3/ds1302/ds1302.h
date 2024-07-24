/**
  ******************************************************************************
  * Ten Tep      :        ds1302.h
  * Tac Gia      :        Nguyen Quy Nhat
  * Cong Ty      :        MinhHaGroup
  * Website      :        BanLinhKien.Vn
  * Phien Ban    :        V1.0.0
  * Ngay         :        31-07-2012
  * Tom Tat      :        Khai bao cac ham dieu khien ds1302.
  *           
  *
  ******************************************************************************
  * Chu Y        :   Phai dinh nghia cac chan su dung cho DS1302 vao ham main.h
  *                  DS1302_DATA_IN_DS1302_DATA_OUT,DS1302_CLK,DS1302_RST.
                                   PIC       AVR       8051
#define         DS1302_DATA_IN     PINB0     PINB.0    P2_0
#define         DS1302_DATA_OUT    PORTB0    PORTB.0   P2_0
#define         DS1302_CLK         PORTB1    PORTB.1   P2_1
#define         DS1302_RST         PORTB2    PORTB.2   P2_2
               Voi PIC va AVR can dinh nghia them huong du lieu.
                                   PIC       AVR       8051
#define         DS1302_DDR_DATA    DDRB0     DDRB.0    P2_0                       
  ******************************************************************************
  */
#ifndef __DS1302_H
#define __DS1302_H
#include "main.h"
void DS1302_WriteByte(uint8_t Data);
void DS1302_Write(uint8_t Addr, uint8_t Data); 
uint8_t DS1302_Read(uint8_t cmd);
void DS1302_Init();	
void DS1302_SetTime(uint8_t hour,uint8_t minute,uint8_t second);
void DS1302_SetDate(uint8_t day, uint8_t date, uint8_t month, uint8_t year);
void DS1302_GetTime(uint8_t *hour,uint8_t *minute,uint8_t *second);
void DS1302_GetDate(uint8_t *day, uint8_t *date, uint8_t *month, uint8_t *year);
#endif

/**
  ******************************************************************************
  * Ten Tep      :        ds1302.c
  * Tac Gia      :        Nguyen Quy Nhat
  * Cong Ty      :        MinhHaGroup
  * Website      :        BanLinhKien.Vn
  * Phien Ban    :        V1.0.0
  * Ngay         :        31-07-2012
  * Tom Tat      :        Dinh nghia cac ham dieu khien ds1302.
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
/*********************************** VI DU ************************************
    uint8_t hour,minute,second,day,date,month,year;
    DS1302_Init();
	DS1302_SetTime(hour,minute,second);
	DS1302_SetDate(day,date,month,year);
	........
    DS1302_GetTime(&hour),&minute,&second);
	DS1302_GetDate(&day,&date,&month,&year);
*******************************************************************************/  

#include "ds1302.h"
void DS1302_WriteByte(uint8_t Data) 
{ 
    uint8_t i;
   //SET Chan DS1302_IO la cong ra de viet du lieu
	DS1302_DDR_DATA=DDROUT;
    delay_us(10);
    for(i=0; i<8;i++)
    {
      DS1302_DATA_OUT=Data&0x01;
      Data>>=1;
      DS1302_CLK=1;
      DS1302_CLK=0;
    } 
}
void DS1302_Write(uint8_t Addr, uint8_t Data)
{
    Data=(Data/10)*16|(Data%10);
    DS1302_RST = 1;
    DS1302_WriteByte(Addr);      
    DS1302_WriteByte(Data);       
    DS1302_RST = 0;
} 
uint8_t DS1302_Read(uint8_t  cmd) {
   uint8_t i=0,Data=0,temp=0;
   DS1302_RST=1;
   DS1302_WriteByte(cmd);
   //SET Chan DS1302_IO la cong vao de doc du lieu
   DS1302_DDR_DATA=DDRIN;
   temp=DS1302_DATA_IN;
   delay_us(1);       
   for(i=0;i<=7;++i) 
   {
   temp=DS1302_DATA_IN;
   Data|=(temp<<i);
    DS1302_CLK=1;
    delay_us(2);
    DS1302_CLK=0;
    delay_us(2);
   }
   DS1302_RST=0;
   Data=(Data/16)*10+(Data&0x0f);
   return(Data);
}
void DS1302_Init()
{
   uint8_t x;
   DS1302_RST=0;
   delay_us(2);
   DS1302_CLK=0;
   DS1302_Write(0x8e,0);
   DS1302_Write(0x90,0xa4);
   x=DS1302_Read(0x81);
   if((x & 0x80)!=0)
   DS1302_Write(0x80,0);
}

void DS1302_SetTime(uint8_t hour,uint8_t minute,uint8_t second)
{
   DS1302_Write(0x80,second);
   DS1302_Write(0x82,minute);
   DS1302_Write(0x84,hour);
}
void DS1302_SetDate(uint8_t day, uint8_t date, uint8_t month, uint8_t year)
{
   DS1302_Write(0x86,date);
   DS1302_Write(0x88,month);
   DS1302_Write(0x8A,day);
   DS1302_Write(0x8C,year);
}
void DS1302_GetTime(uint8_t *hour,uint8_t *minute,uint8_t *second)
{
   *second=DS1302_Read(0x81);
   *minute=DS1302_Read(0x83);
   *hour=DS1302_Read(0x85);
}
void DS1302_GetDate(uint8_t *day, uint8_t *date, uint8_t *month, uint8_t *year)
{
   *date=DS1302_Read(0x87);
   *month=DS1302_Read(0x89);
   *day=DS1302_Read(0x8B);
   *year=DS1302_Read(0x8D);
}

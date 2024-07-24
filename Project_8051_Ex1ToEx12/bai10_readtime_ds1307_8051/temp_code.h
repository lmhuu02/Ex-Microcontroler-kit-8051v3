
#define LCD_DATA P0
sbit  LCD_RS = P2^2;
sbit  LCD_RW = P2^3;
sbit  LCD_EN = P2^4;

unsigned char buff[32];
void lcd_int(void);
void write_cmd(unsigned char cmd);
void write_data(unsigned char dat);

void delay_us(unsigned int a)
{
 unsigned int i,j;
 for (i=0;i < a;i++)
 {
  for(j=0; j < 120; j++);
 };
}
void lcd_init(void)
{
 write_cmd(0x02);
 write_cmd(0x28);
 write_cmd(0x06);
 write_cmd(0x0C);
 write_cmd(0x01);
 delay_us(300);
}
void write_cmd(unsigned char cmd)
{
    LCD_DATA &= 0x0f;
    LCD_DATA |= cmd&0xf0;
 LCD_RW = 0;                     
 LCD_RS = 0;
 delay_us(3);
 LCD_EN = 1;                     
 LCD_EN = 0;
 LCD_DATA &= 0x0f;
    LCD_DATA |= (cmd<<4)&0xf0;
 delay_us(3);
 LCD_EN = 1;                     
 delay_us(3);
 LCD_EN = 0;
 delay_us(1);
 return; 
}
void write_data(unsigned char dat)
{
    LCD_DATA &= 0x0f;
    LCD_DATA |= dat & 0xf0;
 LCD_RW = 0;                     
 LCD_RS = 1;
 delay_us(1);
 LCD_EN = 1;                      
 delay_us(1);
 LCD_EN = 0;
 
 LCD_DATA &= 0x0f;
    LCD_DATA |= (dat<<4)&0xf0;
 delay_us(1);
 LCD_EN = 1;                      
 delay_us(1);
 LCD_EN = 0;
 delay_us(1);
 return;
}
void write_str(char *s)
{
 while(*s)
 {
  write_data(*s);
  s++;
 }
}
void hienthi(unsigned char ht)
{
 write_data((ht/10)+48);
 write_data((ht%10)+48); 
}























//#include <regx51.h>
/*--------------------------------------------------------------------------
DS1307.H
--------------------------------------------------------------------------*/

#ifndef __DS1307_H__
#define __DS1307_H__

sbit SCL  = P3^3;
sbit SDA  = P3^2;

#pragma SAVE
#pragma REGPARMS
void batdau(void)
{
 SCL=0;
 SDA=1;
 SCL=1;
 SCL=1;
 SDA=0;
 SCL=0;
}
//----------------
void ketthuc(void)
{ 
 SCL=0;
 SDA=0;
 SCL=1;
 SDA=1;
}
//----------------
bit ghi_I2C(char x)
{ 
  char i,ack;
  for(i=0;i<8;i++)
    { 
   SDA = (x&0x80) ? 1:0;
      SCL=1;
      SCL=0;
      x*=2;
    }
   SDA=1;
   SCL=1;
   ack=SDA;
   SCL=0;
   return(ack);
}
//----------------
char doc_I2C(void)
{ 
  char i,n=0;
  for(i=0;i<8;i++)
    { 
  SCL=1;
     n*=2;
     n=n|SDA;
     SCL=0;
    }
  return(n);        
}
//----------------
void ghi_ds(char diachi,char dulieu)
{ 
  bit kiemtra;
  batdau();
  ghi_I2C(0xD0);
  ghi_I2C(diachi);
  ghi_I2C((dulieu/10<<4)|(dulieu%10&0x0F));
  ketthuc();
  batdau();
  kiemtra=ghi_I2C(0xD0);
  while(kiemtra)  
       { 
     batdau();
        kiemtra=ghi_I2C(0xd0);
       }   
}
char doc_ds(char diachi)
{ 
   char k;
   batdau();
   ghi_I2C(0xD0);
   ghi_I2C(diachi);
   batdau();
   ghi_I2C(0xD1);
   k=doc_I2C();
   ketthuc();
   return ((k>>4)*10+(k&0x0F));
}
#pragma RESTORE

#endif























#include <REGX51.H>
#include <ds1307.h>
#include "lcd16x2.h"

/********************************************
Dong ho thoi gian thuc hien thi LCD
********************************************/

//#include <reg52.h>
#include <stdio.h>
#include <string.h>
//#include "DS1307.h"

unsigned char gio,phut,giay;

// chuong trinh chinh
void main(void)
{
 P3 = 0xFF; 
 lcd_init();
 ghi_ds(0x07,0x90);
 while(1)
 {
  giay = doc_ds(0x00);
  phut = doc_ds(0x01);
  gio  = doc_ds(0x02);
  write_cmd(0x80);
  write_str("7segone test");
  write_cmd(0xC0);
  hienthi(gio);
  write_data(':');
  hienthi(phut);
  write_data(':');
  hienthi(giay);    
 }
}
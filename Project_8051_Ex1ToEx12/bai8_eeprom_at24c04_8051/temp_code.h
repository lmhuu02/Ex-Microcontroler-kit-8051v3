#include <REGX51.H>

#define LCD_RS P2_2	//chan RS chon thanh ghi
#define LCD_RW P2_3	//chan RW doc ghi du lieu
#define LCD_EN P2_4	//chan E cho phep chon mo dun
#define LCD_D4 P0_4	//chan tin hieu 2.4
#define LCD_D5 P0_5	//chan tin hieu 2.5
#define LCD_D6 P0_6	//chan tin hieu 2.6
#define LCD_D7 P0_7	//chan tin hieu 2.7

//ham delay us giay
void delay_us(unsigned int t){
unsigned int i;
for (i=0;i<t;i++);	
}
//ham delay mili day
void delay_ms(unsigned int t){
	unsigned int i,j;
	for (i=0;i<t;i++){
		for (j=0;j<125;j++);
	}
}
//ham delay thong thuong time--
void delay(int time){
	while(time--);
}

//timer delay 
void delay_timer(int timer){
	while(timer--){
		TMOD = 0x01;	//timer 0 che do 1
		TH0 = 0xfc;
		TL0	= 0x18;
		TR0 = 1;
		while(!TF0);
		TR0 = 0;
		TF0 = 0;
	}
}
// Ham gui xung kich hoat LCD, gui den chan E
void LCD_Enable(void){
LCD_EN=1;
delay_us(3);
LCD_EN=0;
delay_us(50);
}
// ham gui 4 bit du lieu cao ra LCD qua chan bd4 den bd7
void LCD_Send4Bit(unsigned char Data){
	LCD_D4=Data&0x01;
	LCD_D5=Data>>1&1;	//phep and & de giu trang thai
	LCD_D6=Data>>2&1;
	LCD_D7=Data>>3&1;
}
// Ham gui 1 lenh ra LCD
void LCD_SendCommand(unsigned char command ){
	LCD_Send4Bit(command >>4);// gui 4 bit cao
	LCD_Enable();
	LCD_Send4Bit(command);// gui 4 bit thap
	LCD_Enable();
}
// ham xoa man hinh LCD
void LCD_clear(){
	LCD_SendCommand(0x01);// xoa man hinh 01
	delay_us(10);
}
//Khoi tao LCD
void LCD_Init(){
	LCD_Send4Bit(0x01);//turn on man hinh
	delay_ms(20);
	LCD_RS=0;
	LCD_RW=0;
	LCD_Send4Bit(0x03);//funtion seting
	LCD_Enable();// gui xung kich hoat
	delay_ms(5);
	LCD_Enable();
	delay_us(100);
	LCD_Enable();
	LCD_Send4Bit(0x02);//gui con tro ve dau man hinh
	LCD_Enable();
	LCD_SendCommand(0x28);// lua chon che do 4 bit
	LCD_SendCommand(0x0C);// bat hien thi va tat con tro
	LCD_SendCommand(0x06);//Tu dong chuyen con tro sang ky tu ke tiep
	LCD_SendCommand(0x01);// xoa man hinh
}
// Ham go to x y
void LCD_gotoxy(unsigned char x, unsigned char y){
	unsigned char address;
	if(!y)address=(0x80+x);	//0x80 bat con tro ve vi tri dau tien cua hang 1
	else address=(0xc0+x);	//0x80 bat con tro ve vi tri dau tien cua hang 2
	delay_us(1000);
	LCD_SendCommand(address);
	delay_us(1000);	
}
// Ham gui 1 ky tu ra man hinh
void LCD_putchar(unsigned char Data){
LCD_RS=1;	//chon thanh ghi
LCD_SendCommand(Data);
LCD_RS=0;	//chon thanh ghi
}
// ham noi ky tu
void LCD_puts(char *s){
	while(*s){
		LCD_putchar(*s);
		s++;
	}
}

/*

		LCD_Init();
		LCD_puts(" hello");
		delay_ms(1000);
		LCD_clear();
		LCD_gotoxy(0,0);
		LCD_puts(" chao cac ban");
		delay_ms(1000);
		LCD_gotoxy(0,1);
		LCD_puts(" KTMT K19A");
		delay_ms(1000);
		LCD_gotoxy(0,1);
		LCD_puts("GOODBYE WORLD!");
		LCD_clear();
		delay_ms(100000);
		LCD_gotoxy(0,0);
		LCD_puts("LAP TRINH NHUNG");
		delay_ms(100000);
		LCD_gotoxy(0,1);
		LCD_puts("HE THONG IOT");
		LCD_clear();
		delay_timer(1000);
		//LCD_gotoxy(0,1);
		LCD_puts("HELLO WORLD");
		delay_timer(3000);
		//delay(800000);

*/















#include<intrins.h>
#include "lcd_1602.h"

typedef unsigned char u8;
typedef unsigned int u16;

//*****************************************************************************
//*				          I2C SDA SCL										  *
//*****************************************************************************
sbit scl=P0^6;
sbit sda=P0^7;

//******************************************************************************
//*                       I2C START Condition    							   *
//******************************************************************************
void i2cstart(void)
{
  sda=1;
  _nop_();_nop_();
  scl=1;
  _nop_();_nop_();
  sda=0;
  _nop_();_nop_();
}

//*******************************************************************************
//*				           I2C STOP Condition    							    *
//*******************************************************************************
void i2cstop(void)
{
  scl=0;
  sda=0;
  scl=1;
  sda=1;
}

//*******************************************************************************
//*				                I2C ACK              						    *
//*******************************************************************************
void i2cACK(void)
{
  scl=0;
  sda=1;
  scl=1;
  while(sda);
}

//*******************************************************************************
//*				                I2C NACK              						    *
//*******************************************************************************
void i2cNoAck(void)
{
  scl=0;
  sda=1;
  scl=1;
}

//*******************************************************************************
//*				                I2C ReStart Condition  						    *
//*******************************************************************************
void i2cRestart()
{
  scl=0;
  sda=1;
  scl=1;
  sda=0;
}

void i2cWrite(u8 dat)
{
  u8 i;
  for(i=0;i<8;i++)
 {
   scl=0;
   sda=(dat&(0x80>>i))?1:0;
   scl=1;
 }
}

u8 i2cRead(void)
{
  u8 i,buff=0;
  for(i=0;i<8;i++)
 {
   scl=0;
   scl=1;
   if(sda)
   buff|=0x80>>i;
 }
  return buff;
}

//*******************************************************************************
//*				                I2C Data Write Steps  						    *
//*******************************************************************************
//24c01c 24c256c
void i2cDevWrite(u8 sa,u8 buffer,u8 dat)
{
  i2cstart();		   // 1 . Master issue START condition
  i2cWrite(sa&0xfe);   // 2 . Master Send Device Address(8 bites)  fe = 11111110
  i2cACK();			   // 3 . Master Takes ACK from Slave
  i2cWrite(0x00);	   // 4 . Master Send Dummy Buffer/Resister Address(8 bites) 0x00
  i2cACK();			   // 5 . Master Takes ACK from Slave
  i2cWrite(buffer);    // 6 . Master Send Buffer/Resister Address(8 bites)  
  i2cACK();			   // 7 . Master Takes ACK from Slave
  i2cWrite(dat);	   // 8 . master issue data to be Written to Address Location
  i2cACK();			   // 9 . Master Takes ACK from Slave
  i2cstop();		   // 10 . Master issue STOP condition
  delay_ms(10);
}

//*******************************************************************************
//*				                I2C Data Read Steps  						    *
//*******************************************************************************
u8 i2cDevRead(u8 sa,u8 buffAddr)
{
  u8 buff;			   
  i2cstart();		   // 1 . Master issue START condition
  i2cWrite(sa&0xfe);   // 2 . Master Send Device Address(8 bites)  fe = 11111110
  i2cACK();			   // 3 . Master Takes ACK from Slave
  i2cWrite(0x00);      // 4 . Master Send Dummy Buffer/Resister Address(8 bites) 0x00
  i2cACK();			   // 5 . Master Takes ACK from Slave
  i2cWrite(buffAddr) ; // 6 . Master Send Buffer/Resister Address(8 bites) 
  i2cACK();			   // 7 . Master Takes ACK from Slave
  i2cRestart();		   // 8 . Master issue RESTART condition
  i2cWrite(sa|1);	   // 9 . Master issue Slave Address With Write Read Option.
  i2cACK();			   // 10 . Master Takes ACK from Slave
  buff=i2cRead();	   // 11 . Master Reads Data From Slave.
  i2cNoAck();		   // 12 . Master issue NACK 
  i2cstop();		   // 13 . Master issue STOP condition
  return buff;
}
void str_write(u8 sa, u8 buffAddr, char *st)
{
 u8 len = 0;
 while(st[len] != '\0')
 {
   i2cDevWrite(sa,buffAddr+len,st[len]);
   len++;
 }
}

void str_read(u8 sa, u8 buffAddr, char *str1,len)
{ 
 u8 count = 0;
 while(len != count)
 {
    str1[count]= i2cDevRead(sa,buffAddr+count);
    count++;
 }
  str1[count] = '\n';
}
void epprom(void)
{
  u8 t,i;
  char dat[10]={0};
  LCD_SendCommand(0x01);
  LCD_SendCommand(0x80);
  LCD_puts("Writing......");	
  str_write(0xa0,0x00,"MICROMAGIC");
  delay_ms(500);
  LCD_SendCommand(0x01);
  LCD_SendCommand(0x80);
  LCD_puts("Reading.....");
  LCD_SendCommand(0xc0);
  str_read(0xa0,0x00,dat,10);
  LCD_puts(dat);
  delay_ms(1000); 

  LCD_SendCommand(0x01);
  LCD_SendCommand(0x80);
  LCD_puts("Writing......");	
  for(i=0;i<26;i++)
  {								  //			  A2  A1  A0
   i2cDevWrite(0xa0,i,'A'+i);	 // a0   0 1 0 1  0   0   0    r/w
   LCD_SendCommand(0xc0);				 // a2   0 1 0 1  0   0   1    r/w
   lcd_data('A'+i);				 
   delay_ms(350);
  }
  LCD_SendCommand(0x01);
  LCD_SendCommand(0x80);
  lcd_str("Reading.....");
  for(i=0;i<26;i++)
  {
   t=i2cDevRead(0xa0,i);
   LCD_SendCommand(0xc0);
   lcd_data(t);
   delay_ms(400);
  }

/*  lcd_cmd(0x01);
  lcd_cmd(0x80);
  lcd_str("Writing......");	
  for(i=0;i<26;i++)
  {								  //			  A2  A1  A0
   i2cDevWrite(0xa2,i,'A'+i);	 // a0   0 1 0 1  0   0   0    r/w
   lcd_cmd(0xc0);				 // a2   0 1 0 1  0   0   1    r/w
   lcd_data('A'+i);				 
   delay_ms(250);
  }
  lcd_cmd(0x01);
  lcd_cmd(0x80);
  lcd_str("Reading.....");
  for(i=0;i<26;i++)
  {
   t=i2cDevRead(0xa2,i);
   lcd_cmd(0xc0);
   lcd_data(t);
   delay_ms(250);
  }

  lcd_cmd(0x01);
  lcd_cmd(0x80);
  lcd_str("Writing......");	
  for(i=0;i<26;i++)
  {								  //			  A2  A1  A0
   i2cDevWrite(0xa4,i,'a'+i);	 // a0   0 1 0 1  0   0   0    r/w
   lcd_cmd(0xc0);			
   lcd_data('a'+i);				 // a4	 0 1 0 1  0   1   0    r/w
   delay_ms(250);
  }
  lcd_cmd(0x01);
  lcd_cmd(0x80);
  lcd_str("Reading.....");
  for(i=0;i<26;i++)
  {
   t=i2cDevRead(0xa4,i);
   lcd_cmd(0xc0);
   lcd_data(t);
   delay_ms(250);
  }	 */
}

//*******************************************************************************
//*				                    MAIN             						    *
//*******************************************************************************
// main()
//{
//  lcd_init();
//  lcd_cmd(0x01);
//  lcd_cmd(0x80);
//  lcd_str("   welcome   ");
//  delay_ms(500);
// while(1)
// { 
//   epprom();
//   delay_ms(200);
// }
//}





/*
******************************************************
*time: 2023 
*embedded 8051 by langauge c.
*ex2: giao tiep eeprom at24c04
pin: sw24_scl: P3_7
		sw24_sda: P3_6
*******************************************************/
#include <REGX51.H>
//#include "lcd_1602.h"
#include "eeprom24c08.h"

void delay1(unsigned int time){
	while(time--);
}

void main(){
	LCD_Init();
	while(1){		
		LCD_gotoxy(0,0);
		LCD_puts(" chao cac ban");
		delay_ms(1000);
		LCD_clear();
		epprom();
		delay_ms(200);
	}
}
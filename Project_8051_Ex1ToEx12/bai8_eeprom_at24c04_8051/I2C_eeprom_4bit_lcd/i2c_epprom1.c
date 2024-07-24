#include<reg52.h>
#include<intrins.h>
#include "lcd.h"

typedef unsigned char u8;
typedef unsigned int u16;

//*****************************************************************************
//*				          I2C SDA SCL										  *
//*****************************************************************************
sbit scl=P3^7;
sbit sda=P3^6;

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
  lcd_cmd(0x01);
  lcd_cmd(0x80);
  lcd_str("Writing......");	
  str_write(0xa0,0x00,"MICROMAGIC");
  delay_ms(500);
  lcd_cmd(0x01);
  lcd_cmd(0x80);
  lcd_str("Reading.....");
  lcd_cmd(0xc0);
  str_read(0xa0,0x00,dat,10);
  lcd_str(dat);
  delay_ms(1000); 

  lcd_cmd(0x01);
  lcd_cmd(0x80);
  lcd_str("Writing......");	
  for(i=0;i<26;i++)
  {								  //			  A2  A1  A0
   i2cDevWrite(0xa0,i,'A'+i);	 // a0   0 1 0 1  0   0   0    r/w
   lcd_cmd(0xc0);				 // a2   0 1 0 1  0   0   1    r/w
   lcd_data('A'+i);				 
   delay_ms(350);
  }
  lcd_cmd(0x01);
  lcd_cmd(0x80);
  lcd_str("Reading.....");
  for(i=0;i<26;i++)
  {
   t=i2cDevRead(0xa0,i);
   lcd_cmd(0xc0);
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
 main()
{
  lcd_init();
  lcd_cmd(0x01);
  lcd_cmd(0x80);
  lcd_str("   welcome   ");
  delay_ms(500);
 while(1)
 { 
   epprom();
   delay_ms(200);
 }
}
#include "24c08.h"

/////////////////////////////////////////////////
//ham su dung cho i2c
void AT24CXX_I2C_Delay(unsigned int time)
{
   while(time)
   time--;
}
void AT24CXX_i2c_init()
{
   AT24CXX_SCL=1;
   I2C_Delay(AT24CXX_I2C_DELAY);
   AT24CXX_SDA=1;
   I2C_Delay(AT24CXX_I2C_DELAY);
}
void AT24CXX_I2C_Start()
{
		 AT24CXX_SDA=1; 
     AT24CXX_SCL=1; 
     AT24CXX_I2C_Delay(AT24CXX_I2C_DELAY);
     AT24CXX_SDA=0; 
     AT24CXX_I2C_Delay(AT24CXX_I2C_DELAY);
     AT24CXX_SCL=0;
     AT24CXX_I2C_Delay(AT24CXX_I2C_DELAY);
}
void AT24CXX_I2C_Stop()
{   
		 AT24CXX_SDA=0;
     AT24CXX_SCL=1;
     AT24CXX_I2C_Delay(AT24CXX_I2C_DELAY);
     AT24CXX_SDA=1;
     AT24CXX_I2C_Delay(AT24CXX_I2C_DELAY);
     AT24CXX_SCL=0;
     AT24CXX_I2C_Delay(AT24CXX_I2C_DELAY);
}
unsigned char AT24CXX_i2c_checkack(void)
{
   unsigned char ack=0;
     AT24CXX_SDA=1;
     AT24CXX_SCL=1;
     I2C_Delay(AT24CXX_I2C_DELAY/2);
     ack=AT24CXX_SDA;
     I2C_Delay(AT24CXX_I2C_DELAY/2);
     AT24CXX_SCL=0;
     AT24CXX_I2C_Delay(AT24CXX_I2C_DELAY);
     if(ack==1) return 0; 
     return 1;
}
void AT24CXX_i2c_write(unsigned char Data)
{
unsigned char i;
     for(i=0;i<8;i++)
    {
      AT24CXX_SDA=((Data<<i)&0x80);
      AT24CXX_SCL=1;
      AT24CXX_I2C_Delay(AT24CXX_I2C_DELAY);
      AT24CXX_SCL=0;
      AT24CXX_I2C_Delay(AT24CXX_I2C_DELAY);
   }
}
unsigned char AT24CXX_i2c_read(void)
{
     unsigned char I2C_data=0,i,temp;
     for(i=0;i<8;i++)
    {
				 AT24CXX_SDA=1;    
         AT24CXX_SCL=1;    
         AT24CXX_I2C_Delay(120);
         temp=AT24CXX_SDA;
         AT24CXX_I2C_Delay(120);
         AT24CXX_SCL=0;
         if(temp==1)
          {
            I2C_data=I2C_data<<1;
            I2C_data=I2C_data|0x01;
          }
         else
           I2C_data=I2C_data<<1;
    }
    return I2C_data;
}
/////////////////////////////////////////////////
void EEP_24CXX_Init()
{
	AT24CXX_i2c_init();
}
unsigned char EEP_24CXX_Read(unsigned char address)
{
  	bit AckTemp=1;
  	unsigned char Data;
  	AT24CXX_I2C_Start();
  	AT24CXX_i2c_write(0xa0);
  	AckTemp=AT24CXX_i2c_checkack();
  	AT24CXX_i2c_write(address);
  	AckTemp=AT24CXX_i2c_checkack();
  	AT24CXX_I2C_Start();
  	AT24CXX_i2c_write(0xa1);
  	AckTemp=AT24CXX_i2c_checkack();
  	Data=AT24CXX_i2c_read();
  	AckTemp=AT24CXX_i2c_checkack();
  	AT24CXX_I2C_Stop();
  	return Data;
}
void EEP_24CXX_Write(unsigned char address,unsigned char Data)
{
  	bit AckTemp=1;
  	AT24CXX_I2C_Start();
  	AT24CXX_i2c_write(0xa0);
  	AckTemp=AT24CXX_i2c_checkack();
  	AT24CXX_i2c_write(address);                   
  	AckTemp=AT24CXX_i2c_checkack();
  	AT24CXX_i2c_write(Data);                 
  	AckTemp=AT24CXX_i2c_checkack();
  	AT24CXX_I2C_Stop();
}
void EEP_24CXX_WriteS(unsigned char address,unsigned char*s)
{
	while(*s)
	{
		EEP_24CXX_Write(address++,*s);
		s++;
	}
}
void EEPROM_24CXX_ReadS(unsigned char address, unsigned char lenght, unsigned char *s)
{
	unsigned char i=0;
	while(lenght)
	{
		s[i++]=EEP_24CXX_Read(address++);
		lenght--;
	}
	s[++i]=0;
}
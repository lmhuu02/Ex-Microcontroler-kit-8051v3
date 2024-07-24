#ifndef __DS1307_H__
#define __DS1307_H__

#include "main.h"


//define cho I2C
#define I2C_DELAY      2

#define	SCL		P3_3
#define	SDA		P3_2




void I2C_Delay(unsigned int time);
void i2c_init();
void I2C_Start();
void I2C_Stop();
unsigned char i2c_checkack(void);
void i2c_write(unsigned char Data);
unsigned char i2c_read(void);
////////////////////////////////////////////////////////

//define cho ds1307
#define     DS1307_ID 0xD0   
#define     SEC 0x00
#define     MIN 0x01   
#define     HOUR 0x02
#define     DATE 0x04
#define     MONTH 0x05
#define     YEAR 0x06

unsigned char DS1307_get(unsigned char addr) ;
void DS1307_Write(unsigned char addr,unsigned char dat);

#endif

#ifndef __I2C_H
#define __I2C_H
#include "main.h"
 
#define I2C_DELAY      2
//#define	SCL		P3_3
//#define	SDA		P3_2
#define	SCL		P3_7
#define	SDA		P3_6



void I2C_Delay(unsigned int time);
void i2c_init();
void I2C_Start();
void I2C_Stop();
unsigned char i2c_checkack(void);
void i2c_write(unsigned char Data);
unsigned char i2c_read(void);
#endif

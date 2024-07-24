#ifndef __PCF8591_H
#define __PCF8591_H
#include "main.h"

//define cho I2C
#define PCF_I2C_DELAY      2

#define	PCF_SCL		P1_5
#define	PCF_SDA		P1_6

///////////////////////////////////////////////////////
//khai bao cho i2c
void PCF_I2C_Delay(unsigned int time);
void PCF_i2c_init();
void PCF_I2C_Start();
void PCF_I2C_Stop();
unsigned char PCF_i2c_checkack(void);
void PCF_i2c_write(unsigned char Data);
unsigned char PCF_i2c_read(void);
////////////////////////////////////////////////////////
////////////////////////////////////////////////////////

//khai bao cho PCF8591
void PCF8591_Init(void);
uint8_t PCF8591_Read(uint8_t chanel);
void PCF8591_Write(uint8_t DA);
#endif

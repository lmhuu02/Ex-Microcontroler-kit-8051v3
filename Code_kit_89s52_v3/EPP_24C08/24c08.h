#ifndef __24C08_H
#define __24C08_H
#include "main.h"

//define cho I2C
#define AT24CXX_I2C_DELAY     2

#define	AT24CXX_SCL		P3_7
#define	AT24CXX_SDA		P3_6




void AT24CXX_I2C_Delay(unsigned int time);
void AT24CXX_i2c_init();
void AT24CXX_I2C_Start();
void AT24CXX_I2C_Stop();
unsigned char AT24CXX_i2c_checkack(void);
void AT24CXX_i2c_write(unsigned char Data);
unsigned char AT24CXX_i2c_read(void);
////////////////////////////////////////////////////////

#define     AT24CXX_ID 0xA0
void EEP_24CXX_Init();
unsigned char EEP_24CXX_Read(unsigned char address);
void EEP_24CXX_Write(unsigned char address,unsigned char Data);
void EEP_24CXX_WriteS(unsigned char address,unsigned char *s);
void EEPROM_24CXX_ReadS(unsigned char address, unsigned char lenght, unsigned char *s);
#endif

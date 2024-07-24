#ifndef __TIMER_H
#define __TIMER_H
#include "main.h"

#define INFR_DATA	P1_1
void delay_timer_500us(void);
void delay_timer_200us(void);
void delay_timer_750us(void);
uint8_t INFR_CheckStart();
uint16_t INFR_GetCode(void);
#endif

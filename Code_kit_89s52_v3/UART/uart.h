#ifndef __UART_H
#define __UART_H
#include "main.h"
#ifndef UART_BUFFER_SIZE
	#define UART_BUFFER_SIZE	8
#endif
//#define UART_USE_TIMER1
#ifndef UART_USE_TIMER1
	#define UART_USE_TIMER2
#endif
void UART_Init(void);
void UART_Init(void);
void UART_PutChar(unsigned char c);
unsigned char UART_GetChar(void);
void UART_Puts(unsigned char *s);
#endif
#include "uart.h"
static unsigned char tran_busy;
void UART_Init(void)
{
	#ifdef UART_USE_TIMER1
	TMOD&=0x0f;
	TMOD |= 0x20;  //Timer 1 mode 2.
	TL1 = 0xFD; 			
	TH1 = 0xFD; 	// baud rate =9600    		  
	TR1 = 1;
	#endif
	#ifdef UART_USE_TIMER2
	RCLK=1;
	TCLK=1;	//Timer 2: Baud Rate Generator
	RCAP2L  = 0xDC;  //Baud Rate 9600
	RCAP2H  = 0xFF;	//Baud Rate 9600
	TR2=1;
	#endif
	ES = 1;       // Kich hoat ngat UART.
	IP = 0x10;    // Thiet lap muc uu tien cho ngat UART. 
	SCON = 0x50;  // Chon che do UART mode 1.
	PCON=PCON&(~(0x80));//khong nhan doi toc do baud.	
}
void UART_PutChar(unsigned char c)
{
	tran_busy = 1; 
	SBUF = c; 
	while(tran_busy); 
}
unsigned char UART_GetChar(void)
{	
	unsigned char temp=0;
	if(RI==1)
	{
		RI=0;
		temp=SBUF;
	}
	return temp;
}

void Ngat_Uart(void) interrupt 4
{
	if(TI==1)
		{
			TI=0;
			tran_busy=0;
		}
}
void UART_Puts(unsigned char *s)
{
	while (*s)
   {
      UART_PutChar(*s);
      s++;
   }
}
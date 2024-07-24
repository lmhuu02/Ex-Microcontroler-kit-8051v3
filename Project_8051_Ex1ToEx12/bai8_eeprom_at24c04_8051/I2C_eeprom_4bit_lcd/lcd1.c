#include<reg51.h>
#include<intrins.h>
#include "lcd.h"
#define lcd P2

sbit rs=P3^4;
sbit rw=P3^5;
sbit en=P3^6;

void delay_ms(unsigned int n)
{
unsigned int m;
for(n;n>0;n--)
{
for(m=121;m>0;m--);
    _nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	_nop_();
}
}
void lcd_init(void)
{
lcd_cmd(0x02);
lcd_cmd(0x28);	//38 for 8 bit mode .... 28 for 4 bit mode
lcd_cmd(0x01);
lcd_cmd(0x06);
lcd_cmd(0x0c);
}

void lcd_cmd(unsigned char cmd)
{								   //							LCD_PORT				 CMD			          value
lcd =(lcd & 0x0F) | (cmd & 0xF0); // send upper nibble lcd_port = 1111 1111	     cmd  = 1010 1100	    lcd_data  0000 1111
rs=0;							   //                    & 0X0F = 0000 1111    & 0XF0 = 1111 0000		cmd_data  1010 0000
rw=0;							   //					-------------------	    -------------------   ---------------------
en=1;							   //			       lcd_dada = 0000 1111  cmd_data = 1010 0000				  1010 1111
delay_ms(2);
en=0;
								   //							PORT				 CMD			          value
lcd =(lcd & 0x0F) | (cmd << 4);   // send lower nibble	 port_lcd = 1111 1111	   cmd  = 1010 1100	   port_data 0000 1111
en=1;							   //                      & 0X0F = 0000 1111      << 4         	   	cmd_data 1100 0000
delay_ms(2);					   //					   ------------------	 -------------------   --------------------
en=0;							   //			        port_dada = 0000 1111   cmd_data = 1100 0000			 1100 1111
}

void lcd_data(unsigned char ch)
{
lcd =(lcd & 0x0F) | (ch & 0xF0);  // send upper nibble lcd_port = 1111 1111	     cmd  = 1010 1100	    lcd_data  0000 1111
rs=1;							   //                    & 0X0F = 0000 1111    & 0XF0 = 1111 0000		cmd_data  1010 0000
rw=0;							   //					-------------------	    -------------------   ---------------------
en=1;							   //			       lcd_dada = 0000 1111  cmd_data = 1010 0000				  1010 1111
delay_ms(2);
en=0;
								   //							PORT				 CMD			          value
lcd =(lcd & 0x0F) | (ch << 4);   // send lower nibble	 port_lcd = 1111 1111	   cmd  = 1010 1100	   port_data 0000 1111
en=1;							   //                      & 0X0F = 0000 1111      << 4         	   	cmd_data 1100 0000
delay_ms(2);					   //					   ------------------	 -------------------   --------------------
en=0;							   //			        port_dada = 0000 1111   cmd_data = 1100 0000			 1100 1111
}

void lcd_str(unsigned char *v)
{
unsigned char i=0;
while(v[i]!='\0')
{
	lcd_data(v[i]);
	i++;
	delay_ms(10);
}
}

void main(void)
{
 lcd_init();
 lcd_cmd(0x80);
 lcd_str("SwapNiLLL....");

 lcd_cmd(0xc0);
 lcd_str("Nil..");
}
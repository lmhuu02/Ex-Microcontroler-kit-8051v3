#ifndef _LCD_H_
#define _LCD_H_
void lcd_cmd(unsigned char);
void lcd_init(void);
void lcd_data(unsigned char);
void delay_ms(unsigned int);
void lcd_str(unsigned char *);
#endif
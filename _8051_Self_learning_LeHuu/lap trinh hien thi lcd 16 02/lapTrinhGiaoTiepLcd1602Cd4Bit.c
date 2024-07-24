//power by le minh huu 5/3/2022
#include <REGX52.H>
#include <stdio.h>

//khai bao chan
#define lcd_rs P0_0
#define lcd_rw P0_1
#define lcd_en P0_2
#define lcd_d4 P0_4
#define lcd_d5 P0_5
#define lcd_d6 P0_6
#define lcd_d7 P0_7

	char chu[16];
	int so;
	so = 256;

//ham delay us
void delay_us(unsigned int time){
	unsigned int i;
	for(i = 0; i < time; i++);
}
//ham delay ms
void delay_ms(unsigned int time){
	unsigned int i,j;
	for(i = 0; i  < time; i ++)
		for(j = 0; j < 125; j ++);
}
//giao tiep lcd 4 bit . gui xung kich hoat lcd
void lcd_enable(void){
	lcd_en = 1;
	delay_us(3);
	lcd_en = 0;
	delay_us(50);
}

////ham gui du lieu 4 bit ra lcd- ham nay bi loi
//void lcd_sen4bit(unsigned char dulieu){
//	lcd_d4 = dulieu & 0x01;
//	lcd_d5 = (dulieu >>1)&1;
//	lcd_d6 = (dulieu >>2)&1;
//	lcd_d7 = (dulieu >>3)&1;
//}

//Ham Gui 4 Bit Du Lieu Ra LCD
void LCD_Send4Bit(unsigned char Data){
	lcd_d4=Data & 0x01;
	lcd_d5=(Data>>1)&1;
	lcd_d6=(Data>>2)&1;
	lcd_d7=(Data>>3)&1;
	}


//ham gui lenh cho lcd	che do 4 bit
void lcd_sendCommand(unsigned char command){
	LCD_Send4Bit(command >>4);	//gui 4 bit cao
	lcd_enable();
	LCD_Send4Bit(command);//gui 4 bit du lieu thap. khong can dich 4 bit
	lcd_enable();
}
//ham xoa man hinh lcd
void lcd_clear(){
	lcd_sendCommand(0x01);	//0x01 lenh xoa man hinh lcd
	delay_us(10);
}
//ham khoi tao lcd
void lcd_init(){
	LCD_Send4Bit(0x00);	//bat lcd
	delay_ms(20);
	lcd_rs = 0;
	lcd_rw = 0;
	LCD_Send4Bit(0x03);	//function setting
	lcd_enable();
	delay_ms(5);
	lcd_enable();
	delay_us(100);
	lcd_enable();
	LCD_Send4Bit(0x02);	//di chuyen con tro ve dau dong 
	lcd_enable();
	lcd_sendCommand(0x28);	//che do 4 bit
	lcd_sendCommand(0x0c);	//bat hien thi va tat con tro
	lcd_sendCommand(0x06);
	lcd_sendCommand(0x01);
}
//ham toa do lcd
void lcd_gotoxy(unsigned char x, unsigned char y){
	unsigned char address;
	if(!y) address = (0x80 + x);
	else	address = (0xc0 + x);
	delay_us(1000);
	lcd_sendCommand(address);
	delay_us(50);
}
//ham viet mot ky tu len lcd
void lcd_putChar(unsigned char Data){
	lcd_rs = 1;
	lcd_sendCommand(Data);
	lcd_rs = 0;
}
	
//ham viet mot chuoi ky tu len lcd
void lcd_puts(char *s){
	while(*s){
		lcd_putChar(*s);
		s++;
	}
}
//ham main chinh
void main(){
	lcd_init();
	delay_ms(20);
	lcd_puts("hello");
	delay_ms(1000);
	lcd_clear();
	lcd_gotoxy(0,0);
	lcd_puts("LINUX EMBEDDED");
	delay_ms(3000);
	lcd_gotoxy(0,1);
	lcd_puts("TAP TRUNG VAO");

	//lenh chuyen doi tu dang so sang dang chuoi bang lenh sprintf() trong thu vien stdio.h
	lcd_gotoxy(0,1);
	sprintf(&chu[0],"%d",so);
	lcd_puts(&chu[0]);
	
	while(1){}
}
//POWER BY LE MINH HUU 1/3/2022 finish bug: 21:50 7/3/2022
//Project KT VXL ung dung - nhom CLB Dien Tu: Le Minh Huu, Le Thanh Lam, Duong Van Nam
//Project mach canh bao an ninh dung 8051

#include <REGX52.H>
#include <stdio.h>	//lay ham chuyen doi number sang string

// gan chan lcd
#define lcd_rs P0_0
#define lcd_rw P0_1
#define lcd_en P0_2
#define lcd_d4 P0_4
#define lcd_d5 P0_5
#define lcd_d6 P0_6
#define lcd_d7 P0_7
#define on 1
#define off 0

//khai bao chan chuc nang
//sbit nut = P2^3;
sbit led_green = P2^1;	//led bao trang thai an toan
sbit led_red = P2^2;	//led bao trang thai xam nhap
//sbit led_white = P2^6;	//led bao he thong hoat dong
sbit buzzer = P2^0; 		//chan noi voi coi chip
sbit input_data = P1^7;	 //chan tin hieu vao tu pir rs 505

//ham delay
void delay(unsigned int time){
	while(time--);
}

//timer delay 
void delay_timer(int timer){
	while(timer--){
		TMOD = 0x01;	//timer 0 che do 1
		TH0 = 0xfc;
		TL0	= 0x18;
		TR0 = 1;
		while(!TF0);
		TR0 = 0;
		TF0 = 0;
	}
}

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

//ham ngat khi co tin hieu pir
void ngatPir(void) interrupt 2{	//ngat ngoai 1
	if(input_data == 1){	//an toan	
		delay_us(100);
			led_green = on;	//bat den xanh
			 buzzer = led_red = off;	//tat coi, tat den do
		}
		if(input_data == on){	//co canh bao
			led_green = off;	//tat den xanh
			buzzer = led_red = on;	//bat den do, coi
		}
	lcd_clear();
	lcd_gotoxy(0,0);
	lcd_puts(" -- WARINGING --");
	delay_us(30000);
	lcd_gotoxy(0,1);
	lcd_puts("   BI XAM NHAP ! ");
	delay_us(30000);
}

//kiem tra dkien led
void antoan(){
	if(input_data == 1){	//an toan
		delay(100);
			led_green = on;	//bat den xanh
			buzzer = led_red = off;	//bat den do, coii
		lcd_clear();
		lcd_gotoxy(0,0);
		lcd_puts("NGAY MOI VUI VE");
		lcd_gotoxy(0,1);
		lcd_puts("HE THONG AN TOAN");
		delay_timer(1000);
		
		}
	if(input_data == 0){	//co canh bao
		delay(100);
			led_green = off;	//tat den xanh
			buzzer = led_red   = on;	//bat den do, coii
			delay_us(100);
			lcd_clear();
			lcd_gotoxy(0,0);
			lcd_puts(" -- WARINGING --");
			delay_us(30000);
			lcd_gotoxy(0,1);
			lcd_puts("   BI XAM NHAP ! ");
			delay_us(30000);
		}
}

//ham main chinh
void main(){
	led_red = led_green  = buzzer =  off;	//tat den coi
	//led_white = on;	//bat led ktra he thong
	IE = 0x84;	//1 0 0 0   0 1 0 0//khoi tao ngat ngoai 1
	IT1 = 0;	//ngat ngoai 1 chan p3.3 INT1. IT1 = 0 ngat theo muc 
	lcd_init();	//khoi tao giao tiep lcd
	while(1){
		antoan();	//goi ham bat tat led
	}
}

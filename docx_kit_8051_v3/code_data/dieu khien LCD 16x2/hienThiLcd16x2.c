#include <REGX52.H>

#define LCD_RS P2_0	//chan RS chon thanh ghi
#define LCD_RW P2_1	//chan RW doc ghi du lieu
#define LCD_EN P2_2	//chan E cho phep chon mo dun
#define LCD_D4 P2_4	//chan tin hieu 2.4
#define LCD_D5 P2_5	//chan tin hieu 2.5
#define LCD_D6 P2_6	//chan tin hieu 2.6
#define LCD_D7 P2_7	//chan tin hieu 2.7

//ham delay us giay
void delay_us(unsigned int t){
unsigned int i;
for (i=0;i<t;i++);	
}
//ham delay mili day
void delay_ms(unsigned int t){
	unsigned int i,j;
	for (i=0;i<j;i++)
	for (j=0;j<125;j++);
}
//ham delay thong thuong time--
void delay(int time){
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
// Ham gui xung kich hoat LCD, gui den chan E
void LCD_Enable(void){
LCD_EN=1;
delay_us(3);
LCD_EN=0;
delay_us(50);
}
// ham gui 4 bit du lieu cao ra LCD qua chan bd4 den bd7
void LCD_Send4Bit(unsigned char Data){
	LCD_D4=Data&0x01;
	LCD_D5=Data>>1&1;	//phep and & de giu trang thai
	LCD_D6=Data>>2&1;
	LCD_D7=Data>>3&1;
}
// Ham gui 1 lenh ra LCD
void LCD_SendCommand(unsigned char command ){
	LCD_Send4Bit(command >>4);// gui 4 bit cao
	LCD_Enable();
	LCD_Send4Bit(command);// gui 4 bit thap
	LCD_Enable();
}
// ham xoa man hinh LCD
void LCD_clear(){
	LCD_SendCommand(0x01);// xoa man hinh 01
	delay_us(10);
}
//Khoi tao LCD
void LCD_Init(){
	LCD_Send4Bit(0x01);//turn on man hinh
	delay_ms(20);
	LCD_RS=0;
	LCD_RW=0;
	LCD_Send4Bit(0x03);//funtion seting
	LCD_Enable();// gui xung kich hoat
	delay_ms(5);
	LCD_Enable();
	delay_us(100);
	LCD_Enable();
	LCD_Send4Bit(0x02);//gui con tro ve dau man hinh
	LCD_Enable();
	LCD_SendCommand(0x28);// lua chon che do 4 bit
	LCD_SendCommand(0x0C);// bat hien thi va tat con tro
	LCD_SendCommand(0x06);//Tu dong chuyen con tro sang ky tu ke tiep
	LCD_SendCommand(0x01);// xoa man hinh
}
// Ham go to x y
void LCD_gotoxy(unsigned char x, unsigned char y){
	unsigned char address;
	if(!y)address=(0x80+x);	//0x80 bat con tro ve vi tri dau tien cua hang 1
	else address=(0xc0+x);	//0x80 bat con tro ve vi tri dau tien cua hang 2
	delay_us(1000);
	LCD_SendCommand(address);
	delay_us(1000);	
}
// Ham gui 1 ky tu ra man hinh
void LCD_putchar(unsigned char Data){
LCD_RS=1;	//chon thanh ghi
LCD_SendCommand(Data);
LCD_RS=0;	//chon thanh ghi
}
// ham noi ky tu
void LCD_puts(char *s){
	while(*s){
		LCD_putchar(*s);
		s++;
	}
}
void main(){
	while(1){
	LCD_Init();
	LCD_puts(" hello");
	delay_ms(1000);
	LCD_clear();
	LCD_gotoxy(0,0);
	LCD_puts(" chao cac ban");
	delay_ms(1000);
	LCD_gotoxy(0,1);
	LCD_puts(" KTMT K19A");
	delay_ms(1000);
	LCD_gotoxy(0,1);
	LCD_puts("GOODBYE WORLD!");
	LCD_clear();
	delay_ms(100000);
	LCD_gotoxy(0,0);
	LCD_puts("LAP TRINH NHUNG");
	delay_ms(100000);
	LCD_gotoxy(0,1);
	LCD_puts("HE THONG IOT");
	LCD_clear();
	delay_timer(1000);
	//LCD_gotoxy(0,1);
	LCD_puts("HELLO WORLD");
	delay_timer(3000);
	//delay(800000);
	}
}
//Ðang hiê?n thi? 6716513377461525417.

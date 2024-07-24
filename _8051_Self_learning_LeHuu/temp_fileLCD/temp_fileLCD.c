//power by le minh huu 21/3/2022
//nhom Le Minh Huu - Le Thanh Lam - Duong Van Nam
//code vdk 8051 mach canh bao an ninh 
#include <REGX52.H>

/********Khai bao chan giao tiep************/
#define LCD_RS P0_0
#define LCD_RW P0_1
#define LCD_EN P0_2
#define LCD_D4 P0_4
#define LCD_D5 P0_5
#define LCD_D6 P0_6
#define LCD_D7 P0_7
#define on 0
#define off 1
/************************************/
//khai bao chan chuc nang
sbit led_green = P2^1;	//led bao trang thai an toan
sbit led_red = P2^2;	//led bao trang thai xam nhap
sbit buzzer = P2^0; 		//chan noi voi coi chip
sbit input_data = P1^7;	 //chan tin hieu vao tu pir rs 505
/************************************/
void delay_us(unsigned int t){
        unsigned int i;
        for(i=0;i<t;i++);
}
void delay_ms(unsigned int t){
        unsigned int i,j;
        for(i=0;i<t;i++)
        for(j=0;j<125;j++);
}
/**************Ctr giao tiep LCD 16x2 4bit**********************/
void LCD_Enable(void){
        LCD_EN =1;
        delay_us(3);
        LCD_EN=0;
        delay_us(50);
}
//Ham Gui 4 Bit Du Lieu Ra LCD
void LCD_Send4Bit(unsigned char Data){
        LCD_D4=Data & 0x01;
        LCD_D5=(Data>>1)&1;
        LCD_D6=(Data>>2)&1;
        LCD_D7=(Data>>3)&1;
}
// Ham Gui 1 Lenh Cho LCD
void LCD_SendCommand(unsigned char command){
        LCD_Send4Bit(command >>4);/* Gui 4 bit cao */
        LCD_Enable();
        LCD_Send4Bit(command); /* Gui 4 bit thap*/
        LCD_Enable();
}
void LCD_Clear(){// Ham Xoa Man Hinh LCD
        LCD_SendCommand(0x01);
        delay_us(10);
}
// Ham Khoi Tao LCD
void LCD_Init(){
        LCD_Send4Bit(0x00);
        delay_ms(20);
        LCD_RS=0;
        LCD_RW=0;
        LCD_Send4Bit(0x03);
        LCD_Enable();
        delay_ms(5);
        LCD_Enable();
        delay_us(100);
        LCD_Enable();
        LCD_Send4Bit(0x02);
        LCD_Enable();
        LCD_SendCommand( 0x28 ); // giao thuc 4 bit, hien thi 2 hang, ki tu 5x8
        LCD_SendCommand( 0x0c); // cho phep hien thi man hinh
        LCD_SendCommand( 0x06 ); // tang ID, khong dich khung hinh
        LCD_SendCommand(0x01); // xoa toan bo khung hinh
}
void LCD_Gotoxy(unsigned char x, unsigned char y){
        unsigned char address;
        if(!y)address=(0x80+x);
        else address=(0xc0+x);
        delay_us(1000);
        LCD_SendCommand(address);
        delay_us(50);
}
void LCD_PutChar(unsigned char Data){//Ham Gui 1 Ki Tu
        LCD_RS=1;
        LCD_SendCommand(Data);
        LCD_RS=0 ;
}
void LCD_Puts (char *s){//Ham gui 1 chuoi ky tu
        while (*s){
                LCD_PutChar(*s);
                s++;
        }
}
//============================================================
//ham thuc hien ngat
void ngatPir(void) interrupt 2{	//ngat ngoai 1
	int b = 9999, a = 2000;
	LCD_Clear();
	LCD_Gotoxy(0,0);
	LCD_Puts("   BI XAM NHAP ! ");
	LCD_Gotoxy(0,1);
	LCD_Puts(" -- WARINGING --");
	LCD_Gotoxy(0,0);
	LCD_Puts("   BI XAM NHAP ! ");
	P2_2 = 0;	//bat led trang sang lien tuc
	while(a--){}
	P2_0 = 0;	//bat led do va coi chip
	P2_1 = 1;	//tat xanh do chan 2.1
	while(b--){}
		P2_0 = 1;	//tat led do va coi chip
}
//============================================================
//kiem tra dkien led
void antoan(){
		delay_ms(100);
		led_green = on;	//bat den xanh
		buzzer = led_red = off;	//bat den do, coii
		LCD_Clear();	//xoa man hinh lcd
		LCD_Gotoxy(0,0);	//in ra chuoi tai hang 1 vi tri bat dau thu 0
		LCD_Puts("NGAY MOI VUI VE");
		LCD_Gotoxy(0,1);//in ra chuoi tai hang 2 vi tri bat dau thu 0
		LCD_Puts("HE THONG AN TOAN");
		delay_ms(1000);
		P2_2 = 1; //tat xanh do chan 2.1
}


/******************Ctr chinh**************************/
//==========================================================
void main(){
	IE = 0x84;	//1 0 0 0   0 1 0 0//khoi tao ngat ngoai 1
	IT1 = 0;	//ngat ngoai 1 chan p3.3 INT1. IT1 = 0 ngat theo muc , IT =  1 ngat theo suon
	LCD_Init();//Khoi tao LCD
	delay_ms(1000);
	LCD_Puts("HUU - LAM - NAM");//Gui chuoi len LCD
	delay_ms(1000);
	LCD_Clear();	//xoa man hinh lcd
	LCD_Gotoxy(0,0);
	LCD_Puts("LOP KTMT K19A");
	LCD_Gotoxy(0,1);
	LCD_Puts("XIN CHAO");
	delay_ms(5000);
  P2_2 = 1;	//bat led xanh chan 2.2
	while(1){		
		antoan();	//goi ham an toan 
		}
}
//THE END
/*
Code by Vu Thai - SangTaoClub.Net
Cach su dung ham: but=get_key();
	- Neu but=0 thi khong co nut nao duoc nhan
	- Neu but 0<but<17  thi nut duoc nhan, tra ve vi tri cua nut 1-16
*/
#include <REGX51.H>
//Khai bao chan quet nut nhan
#define col0	P3_0	//cot
#define col1	P3_1
#define col2	P3_2
#define col3	P3_3
#define row0	P3_4	//hang
#define row1	P3_5
#define row2	P3_6
#define row3	P3_7
//Khai bao chan giao tiep LCD16x2 4bit
#define LCD_RS  P2_0
#define LCD_RW  P2_1
#define LCD_EN  P2_2
#define LCD_D4  P2_4
#define LCD_D5  P2_5
#define LCD_D6  P2_6
#define LCD_D7  P2_7

/*****************Ham delay*********************/
 void delay_us(unsigned int t){
        unsigned int i;
        for(i=0;i<t;i++);
}
void delay_ms(unsigned int t){
        unsigned int i,j;
        for(i=0;i<t;i++)
        for(j=0;j<125;j++);
}
/*******Ham quet matrix phim nhan 4x4******/
unsigned char check_but(){ //Kiem tra nut nhan
	row0=row1=row2=row3=0;
	if(!col0 || !col1 || !col2 || !col3 )return 1;
	return 0;
}
void scan_row(unsigned char r){ //Quet hang
	row0=row1=row2=row3=1;
	if(r==0)row0=0;
	else if(r==1)row1=0;
	else if(r==2)row2=0;
	else if(r==3)row3=0;
}
unsigned char check_col(){ //Kiem tra cot
	unsigned char c=0;
	if(!col0)c=1;
	else if(!col1)c=2;
	else if(!col2)c=3;
	else if(!col3)c=4;
	return c;
}
unsigned char get_key(){  //Ham tra ve vi tri nut 1-16, =0 la khong nhan
	unsigned char row,col;
    if(check_but()){
      delay_ms(5);
      if(check_but()){         
         for(row=0;row<4;row++){            
            scan_row(row); //Quet hang
			col=check_col(); //Lay vi tri cot
			if(col>0)return ((row*4)+col); //Tra ve vi tri nut duoc nhan
         }      
      }
   }
   return 0; //Khong co nut nao duoc nhan hoac nut da nha	  
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
        LCD_SendCommand( 0x28 );
        LCD_SendCommand( 0x0c); 
        LCD_SendCommand( 0x06 );
        LCD_SendCommand(0x01);
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
void LCD_Puts(char *s){//Ham gui 1 chuoi ky tu
        while (*s){
                LCD_PutChar(*s);
                s++;
        }
}
////////////////////////////////////////////////////////////////////////////////
unsigned char code ma_nut[16]={ //Khai bao mang nut nhan
	'7','8','9',':',
	'4','5','6','x',
	'1','2','3','-',
	'C','0','=','+'
};
void show_button(unsigned char key){
	 LCD_Puts("Key  ");
	 LCD_PutChar(ma_nut[key-1]); //Xuat ra vi tri nut nhan
}
void main(){  //Chuong trinh chinh
	 unsigned char but;
	 LCD_Init();
	 delay_ms(200);
	 LCD_Puts("Quet phim 4x4..");
	 delay_ms(500);
	 LCD_Clear();
	 LCD_Gotoxy(0,0);
	 LCD_Puts("SangTaoClub.Net");
	 while(1){
	 	 LCD_Gotoxy(0,1);
		 but=get_key();
		 if(but>0)show_button(but);
	 	 else LCD_Puts("No key");
		 delay_ms(200);
	 }

}

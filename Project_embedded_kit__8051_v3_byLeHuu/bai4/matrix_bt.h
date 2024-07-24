
//Khai bao chan quet nut nhan
#define col0	P1_7	//cot
#define col1	P1_6
#define col2	P1_5
#define col3	P1_4
#define row0	P1_0	//hang
#define row1	P1_1
#define row2	P1_2
#define row3	P1_3

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
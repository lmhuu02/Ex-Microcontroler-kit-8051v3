//POWER BY LE MINH HUU 15/1/2022
//LED 7 THANH

#include <REGX52.H>
//char so[] = {0x3f, 0x03,0x5b, 0x1f, 0x56,0x6d, 0x7d,0x7f,0x6f};	//khoi tao cac so tu 0 den 9 theo ma hex hoat dong o muc cao
char so[] = {0x40, 0x79,0x24,0xb0,0xB0,0x99,0x12,0x02,0x80,0x10};	//khoi tao cac so tu 0 den 9 theo ma hex hoat dong o muc thap
char chu[] = {0x09,0x06,0x47,0x47,0x40};
			//				H		E		L			L		O
char i,j,x;	//khai bao bien i cho vong for
void delay(int time){
	while(time--);
}

void main(){
	while(1){
		P0 = 1;
		for(i = 9; i >= 0; i--){	//cho vong for chay tu 0 den 9 tuong ung i tu 0 den 9
			for(x = 0; x < 20; x++){	//su dung them mot vong for nua de TANG SO LAN HIEN THI CUA MOT SO
				P0 = so[i];	//dem so - gan cong p0 = lan luot cac phan tu trong mang so
				delay(5000);
			}
		}
		delay(50000);
		
		
		/*for(j = 0; j <= 4; j++){
			P0 = chu[j];
			delay(50000);
			//P0 = 1;
			//delay(50000);
		}
		*/
		
		//nhu nay thi code se rat dai nen chuyen sang dung mang char
		/*
		delay(30000);
		 P0_6 = 1;
		P0_0 = P0_1 = P0_2 = P0_3 = P0_4 = P0_5 = 0;	//so 0
		delay(30000);
		P0_1 = P0_2 = 0;	//bat so 1
		P0_0 = P0_3 = P0_4 = P0_5 = P0_6 = 1;	
		delay(10000);
		*/
		
		//su dung parallel port chuyen sang ma hex, chon port, cho nao co tich la bit 1, bo tich la bit 0
		//viet nhu nay van lau chuyen sang mang char
		/*
		
		P0 = 0xC0; 	// so 0. g = 1
		delay(30000);
		P0 = 0x79; // so 1	a,d,e,f,g = 1
		delay(30000);
		P0 = 0x24; // so 2	b,d,e = 1
		delay(30000);	
		P0 = 0xB0; // so 3	d,e,f = 1
		delay(30000);
		P0 = 0x99;	// so 4 a, d,e = 1
		delay(30000);
		P0 = 0x12;	//so 5	b,e = 1
		delay(30000);
		P0 = 0x02;	//so 6	b = 1
		delay(30000);	
		P0 = 0x78;	//so 7	d,e,f,g = 1
		delay(30000);
		P0 = 0x00;	//so 8	 all = 0
		delay(30000);
		P0 = 0x10;	//so 9	e = 1	
		delay(30000);
		*/
		
	}
}
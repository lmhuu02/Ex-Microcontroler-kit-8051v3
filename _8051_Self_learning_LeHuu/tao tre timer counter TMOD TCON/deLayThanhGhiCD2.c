//power by le minh huu 16/2/2022
/*
CHE DO 1: thoi gian lon hon - o che do 1 thi co the lap trinh den mini giay - lap trinh 16 bit 2^16 = 65 536
CHE DO 2: thoi gian nho - con o che do 2 thi chi lap trinh duoc muc micro giay - lap trinh 8 bit 2^8 = 256
*/

//tre 200us dung thach anh 11.0592mHz tan so = 1.085Ms
/*
200us / 1.085 = 184.
256 - 184  = 72 --> 0x48
*/
#include <REGX52.H>

void delay_5ms(){
	TMOD = 0x02; 	// timer 0 che do 1
//	TL0 = 0x00;	//phai de thanh ghi tl0 truoc th0
//	TH0 = 0x48;	//hoac dung cach duoi
	TL0 = 0x48;
	TH0 =0x48;
	TR0 = 1;
	while(!TF0);
	TF0 = 0;
	TR0 = 0;
}

void main(){
	P3_0 = 0;
	while(1){
		P3_0 = ~ P3_0;
		delay_5ms();
	}
}



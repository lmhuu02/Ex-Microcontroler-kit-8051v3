//power by le minh huu 16/2/2022
/*
CHE DO 1: thoi gian lon hon - o che do 1 thi co the lap trinh den mini giay - lap trinh 16 bit 2^16 = 65 536
CHE DO 2: thoi gian nho - con o che do 2 thi chi lap trinh duoc muc micro giay - lap trinh 8 bit 2^8 = 256

*/
// TIMER 0 CHE DO 1 - tre 1ms dung thach anh 12mHz
/*
1ms = 1000 us / 1T = 1000  (chu ky cua thach anh 12mHZ).
65 536 - 1000 us = 64 536
doi 64 536 = 0xfc18
TH = 0xFC
TL = 0x18
*/

/*
#include <REGX52.H>

void delay_1ms(){
	TMOD = 0x01; 	// timer 0 che do 1
	TH0 = 0xfc;
	TL0 = 0x18;
	TR0 = 1;
	while(!TF0);
	TF0 = 0;
	TR0 = 0;
}

void main(){
	P3_0 = 0;
	while(1){
		P3_0 = ~ P3_0;
		delay_1ms();
	}
}
*/


//tre 5ms dung thach anh 11.0592mHz, chu ky thach anh = 1.085Ms
/*
5ms = 5000 us / 1.085 = 4 608 .
65 536 - 4 608 = 60 928 --> 0xee00
*/
#include <REGX52.H>

void delay_5ms(){
	TMOD = 0x01; 	// timer 0 che do 1
	TH0 = 0xee;
	TL0 = 0x00;
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


//power by le minh huu 24/3/2022
//gui mot ky tu len may tinh
/*
#include <REGX52.H>

//TH1 = 256 - (11 059 200 /(12*32))/9600 = 256 - 3 =253 == 0xFD

void main(){
	TMOD = 0x20;	//vi timer 1 che do 2
	TH1 = 0xFD;	//toc do baud 9600
	TH1 = 0xFD;	//toc do baud 9600
	TR1 = 1;	//bat bo dinh thoi
	SCON = 0x50;	//cd 1  8 bit timer 1. 0 1 0 1 0000
	while(1){
		SBUF = 'H';
		while(TI == 0){}
		TI = 0;
	}
}
*/


//=========================================================
//gui mot chuoi ky tu
#include <REGX52.H>
#include <string.h>
//baud 9600 pcon.7 = 0 .TH1 = 256 - (11 059 200 /(12*32))/9600 = 256 - 3 =253 == 0xFD
//baud 4800 pcon.7 = 0 .TH1 = 256 - (11 059 200 /(12*32))/4800 = 256 - 6 =250 == 0xFA
//baud 1200 pcon.7 = 0 .TH1 = 256 - (11 059 200 /(12*32))/1200 = 256 - 24 =232 == 0xE8
//baud 2400 pcon.7 = 0 .TH1 = 256 - (11 059 200 /(12*32))/2400 = 256 - 12 =244 == 0xF4
//baud 19 200 pcon.7 = 1 .TH1 = 256 - (2 * 11 059 200 /(12*32))/19 200 = 256 - 3 =253 == 0xFD  - neu de pcon.7 = 0 thi kq se ra le 1,5 --> sai
	//NOTE: KHI CHINH TOC DO BAUD THI PHAI CHINH TREN TERMINAL TREEN MO PHONG
void send_a(unsigned char a){
	SBUF = a;
	while(TI == 0){}
	TI = 0;	
}

void send_char(char *a){
	int i, n;
	n = strlen(a);
	for(i = 0; i <= n; i++){
		send_a(a[i]);
	}
}
//co the dung ham nay de noi chuooi
void send_char1(unsigned char *a){
	while(*a){
	send_a(*a);
		a++;
	}
}

void main(){
	TMOD = 0x20;	//vi timer 1 che do 2
//	TL1 = 0xFD;	//toc do baud 9600
//	TH1 = 0xFD;	//toc do baud 9600
	TL1 = 0xFA;	//toc do baud 4800 
	TH1 = 0xFA;	//toc do baud 4800
	TR1 = 1;	//bat bo dinh thoi
	SCON = 0x50;	//cd 1  8 bit timer 1. 0 1 0 1 0000
	while(1){
		send_char(" HELLO WORLD  \r\n ");
	///	sen_char();
	}
}
//power by le minh huu 8/3/2022
// truyen nhan du lieu qua uart dieu khien led bat tat
#include <REGX52.H>
#include <string.h>

//gui mot ky tu di
void send(unsigned char a){
	SBUF = a;
	while(TI == 0){}
	TI = 0;
}

//nhan mot ky tu
unsigned char Receiver(){
	unsigned char c;
	while(RI == 0){}
	c = SBUF;
	RI = 0;
	return c;	//tra ve gia tri vua nhan
}

//ham chinh
void main(){
	unsigned char i;
	TMOD = 0x20;	//timer 1 che do 2
	PCON = 0x80;	// bit SMOD = 1; nhan doi toc do baud
	SCON = 0x50;	//che do 1; SM0 = 0, SM1 = 1, REN = 1;
	TH1 = 0xfa;		//	
	TR1 = 1;	//khoi dong bo dinh thoi
	while(1){
		i = Receiver();	//nhan gia tri
		send(i);	//truyen gia tri di
		switch(i){
			case '1':{
					P2 = ~P2;
				break;
			}
		}
	}
}

/*
tinh gia tri TH1 = 256 - (2*crystal / 12*32)/baud
TH1 = 256 - (2*11059200 / 12*32) /9600
TH1 = 250 --> 0xfa;
*/
/*
******************************************************
*time: 2023 
*embedded 8051 by langauge c.
*ex2: giao tiep truyen thong uart max232.

//thanh ghi SCON che do 1 --> SM0 = 0, SM1 = 1. (che do 1 trong uart: 8 bit tu nap lai timer 1)
//	REN = 1 (cho phep truyen nhan du lieu)
//	thanh ghi PCON.7 ---- SMOD = 0 toc do binh thuong
//	tinh gia tri cho thanh ghi TH1, toc do baud = 9600
//	TH1 = 256 - ((11 059 200 / (12*32)) / 9600)	= 253 
//	TH1 = 0xfd;
//RxD: chan nhan du lieu
//TxD: chan truyen du lieu
*******************************************************/

/*
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
*/

#include <REGX51.H>
#include <string.h>	//thu vien cac ham cua chuoi ky tu

//gui mot ky tu ra may tinh
void send(unsigned char a){
		SBUF = a;		//truyen ky tu H
		while(TI == 0){}	//ktra truyen du lieu, TI = 1 truyen thanh cong
			TI = 0; 	//gan lai bit TI ve 0
}

void sendChar(char *a){
	int i,n;
	n = strlen(a);	//ham kiem tra do dai cua chuoi
	for(i = 0; i <= n; i++){
		send(a[i]);
	}
}

void main(){
	TMOD = 0x20;	//timer 1 che do 2.
	TH1 = 0xfd; 	//toc do baud = 9600
	SCON = 0x50; 	// 0 1 0 1   0 0 0 0: SM0 = 0; SM1 = 1; REN = 1 che do 1 uart 8 bit timer 1
	TR1 = 1;	//khoi dong bo dinh thoi timer 1
	while(1){
			sendChar("          HELLO WORLD!         ");
		//send('xin chao');
	}
}
//POWER BY LE MINH HUU 10/3/2022

//NGAT TIMER 0 CHE DO 1 TRONG THOI GIAN 10S TAXL = 12MHZ
/*
#include <REGX52.H>

//ham delay
void delay(int time){
	while(time--);
}

//ham khai bao ngat
void ngatTimer() interrupt 1 {	//ngat thu tu 1 => ngat timer 0
	long a = 10000;
	unsigned int t;
	t++;	//tang bien dem len
	TH0 = 0xfc;	//dinh thoi gian la 1 us
	TL0 = 0x18;
	TR0 = 1;	//khoi tao bo dinh thoi
	while (t > 1000){	//dem den 10000 lan la 10s
		P1_0 = 0;
		t = 0;	//khi t > 1000 thi cho quay lai dem tu 0
		while(a--);	//la ham delay 100000
		P1_0 = 1;
	}
}

void main(){
	TMOD = 0x01;	//timer 0 che do 1
	ET0 = 1;	//bat bit et0 ==> ngat timer 0
	EA = 1;	//bat ngat
	TR0 = 1;	//kd bo dinh thoi
	while(1){
		P2 = ~P2;
		delay(10000);
	}
}
*/

//NGAT TIMER 1  CHE DO 2 TRONG THOI GIAN 5S TXAL = 11.0592
//==============================================
#include <REGX52.H>

//ham delay
void delay(int time){
	while(time--);
}

//ham khai bao ngat
//TAXL 11.0592. 100/1.085 = 92. 256 - 92 = 164 == 0xa4
void ngatTimer() interrupt 3 {	//ngat thu tu 3 => ngat timer 1
	long a = 10000;
	unsigned int t;
	t++;	//tang bien dem len
	TL1 = 0xA4;
	TH1 = 0xA4;	//dinh thoi gian la 100 us
	TR1 = 1;	//khoi tao bo dinh thoi
	while (t > 50000){	//dem den 500 lan la 5s
		P1_0 = 0;
		t = 0;	//khi t > 500 thi cho quay lai dem tu 0
		while(a--);	//la ham delay 100000
		P1_0 = 1;
	}
}

void main(){
	TMOD = 0x20;	//timer 1 che do 2
	ET1 = 1;	//bat bit et1 ==> ngat timer 1
	EA = 1;	//bat ngat
	TR1 = 1;	//kd bo dinh thoi
	while(1){
		P2 = ~P2;
		delay(10000);
	}
}

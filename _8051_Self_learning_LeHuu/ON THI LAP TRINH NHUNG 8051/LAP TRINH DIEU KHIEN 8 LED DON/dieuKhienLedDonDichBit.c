
/*
2.1 chay tu d1 den d8 tat tu d1 den d8
2.2 giu trang thai tu d1 den d8 va tat tu d8 den d1
2.3 sang tu giua ra hai ben va giu trang thai 
*/

//=================================================
//bai 2  SU DUNG PHEP DICH BIT DIEU KHIEN MUC CAO (MUC 1)
#include <regx52.h>

void delay(int time){
while(time--){}
}
void traiPhaiNhay(){
	//nhay tu trai sang phai
unsigned char a,b;
	int i;
	a = 0x01;	// 0000 0001
	for(i = 0; i < 8; i++){
		P2 = a;
		delay(10000);
		a = a << 1;	// cac bit se luon luon doc tu 7 6 5 4 3 2 1 0. --> chay tu 0 den 7
	}
	//nhay phai sang trai
	b = 0x80; // 1000 0000
	for(i = 0; i < 8; i++){
		P2 = b;
		delay(10000);
		b = b >> 1;	// cac bit se luon luon doc tu 7 6 5 4 3 2 1 0. --> chay tu 7 den 0
	}
}
void giuTraiPhai(){
unsigned char a;
	int i;
	a = 0x01;
	for(i = 0; i < 8; i++){
		P2 = a;
		a = a << 1;
		a = a | 0x01;
		delay(10000);
	}
}
void giuaHaiBenGiu(){
unsigned char a, b;
	int i;
	a = 0x10;
	b = 0x08;
	for(i = 0; i < 4; i++){
		P2 = a + b;
		delay(10000);
		b = b >> 1;	
		a = a << 1;			
		a = a | 0x10;
		b = b | 0x08;
	}
}
void haiBenGiua(){
unsigned char a, b;
	int i;
	a = 0x01;
	b = 0x80;
	for(i = 0; i < 4; i++){
		P2 = a + b;
		delay(10000);
		a = a << 1;
		b = b >> 1;
	}
}
void main(){
	P2 = 0x00; 	//tat het port 2
	while(1){
	//	traiPhaiNhay();
		//giuTraiPhai();
		giuaHaiBenGiu();
		//haiBenGiua();
	}
}
/*
THI LAP TRINH NHUNG 8051 LE MINH HUU 30/10/2002 NGAY 19/5/2022
DE: LAP TRINH TRUYEN THONG UART CHUYEN CAC KY TU TU K DEN Z
tinh gia tri TH1 = 256 - (crystal /(12*32))/9600 = 256 - (11 059 200 / 384)/9600 = 256 - 3 = 253 = FD
SCON: sm0 sm1 sm2 ren tb8 rb8 ti ri. 0101 0000
TMOD: gate c/t m1 m0 gate c/t m1 m0 
PCON: SMOD _ _ .......

*/

#include <REGX52.H>
#include <string.h>
//ham delay
void delay(int time){
while(time--){}
}
//ham gui mot ky tu
void send(unsigned char a){
	SBUF = a;
	while(!TI){}	//kiem tra nhan
		TI = 0;
}
//ham gui chuoi ky tu
void sendChar(unsigned char *a){
	int i,x;
	x = strlen(a);
	for(i = 0; i <= x; i++){
			send(a[i]);
	}
}
//ham nhan ky tu tu may tinh
//void reciver(){
//	unsigned char b;
//	while(!RI){}	//kiem tra truyen
//		b = SBUF;
//		RI = 0;
//		return b;
//}
void main(){
	int i;
	TMOD = 0x20;	//0010 000 timer 1 che do 2, m1 = 1, m0 = 0
	SCON = 0x50;	//0101 0000 m1 = 1, m0 = 0, ren = 1  
	TH1 = 0XFD;	//tinh gia tri nap cho thanh ghi TH1
	PCON = 0x80;
	TR1 = 1;	//bat bo dinh thoi
	sendChar("Le Minh Huu ktmt k19 xin chao\r\n");
	for(i = 'k'; i <= 'z'; i++){	//gui ky tu tu k den z
		send(i);
	}
	while(1){}
}
/*
power by Le Minh Hu 2k2 @copyright 19/5/2022\
lap trinh UART gui ky tu tu a den k
TH1 = 256 - (crystal /(12*32))/9600
= 256 - (11 059 200 / (384))/9600 = 256 - 3 = 253 =0xfd
SCON sm0 sm1 sm2 ren tb8 rb8 ti ri
*/
#include <REGX52.H>
#include <string.h>

void delay (int time){
	while(time--){}
}

void send(unsigned char a){
	SBUF = a;
	while(!TI){}	//ktra truyen
		TI = 0;
}
void sendChar(unsigned char *a){
	int x = strlen(a);
	int i;
	for(i = 0; i <= x; i++){
		send(a[i]);
	}
}
void main(){
	int ii;
	char a;
	TMOD = 0x20;	//timer 1 cd 2
	TH1 = 0xfd;
	TR1 = 1;
	SCON = 0x50;
	//while(1){
		for(ii = 'a'; ii <= 'k'; ii++){
			send(ii);
		}
		delay(100000);
		sendChar("\r\n \r\n");
	//}
}

#include <REGX51.h>

//Le Minh Huu ngay 30/10/2021
void delay(int time){
	while(time--);
}

void blink(){
	while(1){
		P0 = P1 = P2 = P3 = 0;
		delay(5000);
		P0 = P1 = P2 = P3 = 0xff;
		delay(5000);
	}
}
void main(){
	while(1){
		blink();
	}
}
//POWER BY  LE MINH HUU - 17/1/2022
//DIEU KHIEN LED DON 
#include <REGX52.H>

sbit Led = P1^6;

void delay(int time){
	while(time--);
}

void delay1 (int time){
	int i;
	for(i = 0; i < time; i++){
		
	}
}

void main(){
	Led = 1;
	while(1){
		Led = 0;
		delay1(10000);
		Led = 1;
		delay1(10000);
	}
}
	
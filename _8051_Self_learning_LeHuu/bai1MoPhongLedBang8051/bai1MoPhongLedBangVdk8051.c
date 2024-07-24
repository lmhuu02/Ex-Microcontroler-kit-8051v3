#include <REGX51.H>

void delay(int time){
	while(time--);
}

void main(){
	while(1){
		P2_0 = 0;		//bat led
	delay(10000);
	P2_0 = 1;		//tat led
	delay(10000);	

	}

}
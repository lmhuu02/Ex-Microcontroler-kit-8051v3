#include <REGX52.H>

//timer 0 che do 2
void delay(){
	 TMOD = 0x02;
	TL0 = 0x48;
	TH0 = 0x48;
	TR0 = 1;
	while(!TF0);
	TR0 = 0;
	TF0 = 0;
}

//timer 1 che do 2
void delay_us(){
	 TMOD = 0x20;
	TL1 = 0x48;
	TH1 = 0x48;
	TR1 = 1;
	while(!TF1);
	TR1 = 0;
	TF1 = 0;
}

void main(){
	P3_0 = 1;
	while(1){
		P3_0 = ~ P3_0;
		delay_us();
		P3_0 = 0;
		delay();
	}
}
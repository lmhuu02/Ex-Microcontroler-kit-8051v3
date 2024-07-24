//POWER BY LE MINH HUU 24/2/2022
//TIMER CHE DO 1 DIEU KHIEN 1 LED
#include <REGX52.H>

//thach anh 20
void delay_ta0(){
	TMOD = 0x10;	//timer 1 che do 1
	TH1 = 0xf9;
	TL1 = 0x7e;
	TR1 = 1;
	while(!TF1);
	TF1 = 0;
	TR1 = 0;
}

//thach anh 11.0592, 
void delay_ta1(){
	TMOD = 0x10;	//timer 1 che do 1
	TH1 = 0xfc;
	TL1 = 0x67 ;
	TR1 = 1;
	while(!TF1);
	TF1 = 0;
	TR1 = 0;
}

//thach anh 12mhz, timer 0 che do 1
void delay(){
	TMOD = 0x01;	//timer 0 che do 1
	TH0 = 0xfc;
	TL0 = 0x18 ;
	TR0 = 1;
	while(!TF0);
	TF0 = 0;
	TR0 = 0;
}


void main(){
	P3_0 = 1;
	while(1){
		P3_0 = ~P3_0; 
		delay();
	}
}
//tao tre dung timer 1 che do 1 trong thoi gian 3s 5s
//power by le minh huu 18/3/2022
#include <REGX52.H>

//=============================
//TIMER 1 CHE DO 1 TXAL 12MHZ
void delay_T1_1s_12mhz(unsigned int time){
	while(time--){
		TMOD =0x10;	//timer 1 che do 1
		TH1 = 0xfc;	// tao thoi gian tre 1ms
		TL1 = 0x18;
		TR1 = 1;
		while(!TF1){}
		TR1 = 0;
		TF1 = 0;
	}
}

//================================
//TIMER 1 CHE DO 1 TXAL 20MHZ, T = 0.6
//1ms = 1000 us, 1000/ 0.6 = 1666. --> 65 536 - 1666 = 63 870 --> 9f7e
void delay_T1_1s_20mhz(unsigned int time){
	while(time--){
		TMOD = 0x10;	//timer 1 che do 1
		TH1 = 0x9f;	//tao thoi gian tre trong 1ms
		TL1 = 0x7e;
		TR1 = 1;
		while(!TF1){}
		TR1 = 0;
		TF1 = 0;
	}
}

//================================
//TIMER 1 CHE DO 1 TXAL 11.0592MHZ
//1ms = 1000 us, 1000/ 1.085 = 921. --> 65 536 - 921 = 64 615 --> fc67
void delay_T1_1s_11mhz(unsigned int time){
	while(time--){
		TMOD = 0x10;	//timer 1 che do 1
		TH1 = 0xfc;	//tao thoi gian tre trong 1ms
		TL1 = 0x67;
		TR1 = 1;
		while(!TF1){}
		TR1 = 0;
		TF1 = 0;
	}
}

void main(){
	while(1){
		P2 = 0xfc;
		delay_T1_1s_12mhz(3000); //tre 3s
		P2 = 1;
		delay_T1_1s_12mhz(3000); //tre 3s
	}
}

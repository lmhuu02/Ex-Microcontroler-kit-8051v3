//lap trinh tre 3 giay 5 giay dung timer 0 che do 1 dung thach anh 12 20 11.0592
//power by le minh huu 18/3/2022
#include <REGX52.H>

//================================
//TIMER 0 CHE DO 1 TXAL 12MHZ
void delay_T0_1s_12mhz(unsigned int time){
	while(time--){
		TMOD = 0x01;	//timer 0 che do 1
		TH0 = 0xfc;	//tao thoi gian tre trong 1ms
		TL0 = 0x18;
		TR0 = 1;
		while(!TF0){}
		TR0 = 0;
		TF0 = 0;
	}
}
//================================
//TIMER 0 CHE DO 1 TXAL 20MHZ, T = 0.6
//1ms = 1000 us, 1000/ 0.6 = 1666. --> 65 536 - 1666 = 63 870 --> 9f7e
void delay_T0_1s_20mhz(unsigned int time){
	while(time--){
		TMOD = 0x01;	//timer 0 che do 1
		TH0 = 0x9f;	//tao thoi gian tre trong 1ms
		TL0 = 0x7e;
		TR0 = 1;
		while(!TF0){}
		TR0 = 0;
		TF0 = 0;
	}
}

//================================
//TIMER 0 CHE DO 1 TXAL 11.0592MHZ
//1ms = 1000 us, 1000/ 1.085 = 921. --> 65 536 - 921 = 64 615 --> fc67
void delay_T0_1s_11mhz(unsigned int time){
	while(time--){
		TMOD = 0x01;	//timer 0 che do 1
		TH0 = 0xfc;	//tao thoi gian tre trong 1ms
		TL0 = 0x67;
		TR0 = 1;
		while(!TF0){}
		TR0 = 0;
		TF0 = 0;
	}
}
void main(){
	while(1){
		P2 = 0xff;
		delay_T0_1s_11mhz(3000);	//delay 3s
		P2 = 0;
		delay_T0_1s_11mhz(5000);	//delay 5s
	}
}

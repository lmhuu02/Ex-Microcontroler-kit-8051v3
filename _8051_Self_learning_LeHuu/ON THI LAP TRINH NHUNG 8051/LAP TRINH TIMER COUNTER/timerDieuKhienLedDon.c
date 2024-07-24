/*
power by Le Minh Huu 2k2 @copyright 19/5/2022
lap trinh timer dieu khien 8 led don
1. tao tre 3s
2. tre 5s timer 0 cd 1 ta 20mhz
3. tre 5s timer 0 cd 1 ta 11, 0592
4. 3s timer 0 cd 1 ta 12
5. 3s timer 0 cd 1 ta 20
*/
#include <REGX52.H>

//void delay(unsigned int time){
//	while(time--){}
//}

//2. tre 5s timer 0 cd 1 ta 20mhz. 5s = 5000ms. ta 20 --> t = 0.6. tinh 5ms = 5000us. 5000/0.6 = 8333
//65536 - 8333 =  57203 --> df73. 1000/ 0.6 = 1666
void delay1(int time){
	while(time--){
		TMOD = 0x01;	//timer 0 cd1. 0000 0001
		TH0 = 0xdf;
		TL0 = 0x73;
		TR0 = 1;
		 while(!TF0){}
		TR0 = 0;
		TF0 = 0;
	}
}
//5S TIMER 0 CD 1 TA 11.0592. T = 1.085. 5S = 5000MS, 5MS = 5000US, N = 5000/1.085 = 4608 
//65536 - 4600 = EE08
void delay2(int time){
	while(time--){
		TMOD = 0x01;	//timer 0 cd1. 0000 0001
		TH0 = 0xEE;
		TL0 = 0x08;
		TR0 = 1;
		 while(!TF0){}
		TR0 = 0;
		TF0 = 0;
	}
}
void delay3(int time){
	while(time--){
		TMOD = 0x01;	//timer 0 cd1. 0000 0001
		TH0 = 0x00;
		TL0 = 0x00;
		TR0 = 1;
		 while(!TF0){}
		TR0 = 0;
		TF0 = 0;
	}
}
void delay4(int time){
	while(time--){
		TMOD = 0x01;	//timer 0 cd1. 0000 0001
		TH0 = 0x00;
		TL0 = 0x00;
		TR0 = 1;
		 while(!TF0){}
		TR0 = 0;
		TF0 = 0;
	}
}

void main(){

	while(1){
		P2 = ~ P2;
		delay2(1000);
	}
}
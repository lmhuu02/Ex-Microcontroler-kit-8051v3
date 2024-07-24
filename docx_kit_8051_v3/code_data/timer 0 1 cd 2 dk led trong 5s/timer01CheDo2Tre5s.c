//tao tre dung timer 0 va timer 1 che do 2
//power by le minh huu 18/3/2022
#include <REGX52.H>


//===========================================
//TIMER 0 CHE DO 2 TXAL = 12MHZ
/*
tinh gia tri 100us nap vao tl va th --> 256 - 100 = 156. --> 0x9c
100us x 10000 = 1 000 000 us = 1000 ms = 1s
100us x 1000 x 10 = 1 000 000 us = 1000 ms = 1s
*/
void delay_T0_1s_12mhz(unsigned int time){
	unsigned int a = 10, b = 1000;
	while(time--){
		while(a--){
			while(b--){
				TMOD = 0x02;	//timer 0 che do 2
				TL0 = 0x9c;	//tre trong 100us
				TH0 =	0x9c;	//trong che do 2 thi cho TL len truoc TH
				TR0 = 1;
				while(!TF0){}
				TR0 = 0;
				TF0 = 0;
			}
		}
	}
}

//-------------------------------
/*
TIMER 0 CHE DO 2 TXAL 20MHZ --> T = 0,6
tinh 100us 100/0.6 = 167. --> 256 - 167 = 89 --> 0x59
*/
void delay_T0_1s_20mhz(unsigned int time){
unsigned int a = 10, b = 1000;
	while(time--){
		while(a--){	//100us x10 x1000
			while(b--){	//100us x1000
				TMOD = 0x02;	//timer 0 che do 2
				TL0 = 0x59;	//tre trong 100us
				TH0 = 0x59;
				TR0 = 1;
				while(!TF0){}
				TR0 = 0;
				TF0 = 0;
			}
		}
	}
}

//-------------------------------
/*
TIMER 0 CHE DO 2 TXAL 11.0592MHZ --> T = 1.085
tinh 100us 100/1.085 = 92. --> 256 - 92 = 164 --> 0xa4
*/
void delay_T0_1s_11mhz(unsigned int time){
unsigned int a = 10, b = 1000;
	while(time--){
		while(a--){	//100us x10 x1000
			while(b--){	//100us x1000
				TMOD = 0x02;	//timer 0 che do 2
				TL0 = 0xa4;	//tre trong 100us
				TH0 = 0xa4;
				TR0 = 1;
				while(!TF0){}
				TR0 = 0;
				TF0 = 0;
			}
		}
	}
}


//===========================================
//TIMER 1 CHE DO 2

/*
//TIMER 1 CHE DO 2 TXAL = 12MHZ
tinh gia tri 100us nap vao tl va th --> 256 - 100 = 156. --> 0x9c
100us x 10000 = 1 000 000 us = 1000 ms = 1s
100us x 1000 x 10 = 1 000 000 us = 1000 ms = 1s
*/
void delay_T1_1s_12mhz(unsigned int time){
	unsigned int a = 10, b = 1000;
	while(time--){
		while(a--){
			while(b--){
				TMOD = 0x20;	//timer 1 che do 2
				TL1 = 0x9c;	//tre trong 100us
				TH1 =	0x9c;	//trong che do 2 thi cho TL len truoc TH
				TR1 = 1;
				while(!TF1){}
				TR1 = 0;
				TF1 = 0;
			}
		}
	}
}

//-------------------------------
/*
TIMER 1 CHE DO 2 TXAL 20MHZ --> T = 0,6
tinh 100us 100/0.6 = 167. --> 256 - 167 = 89 --> 0x59
*/
void delay_T1_1s_20mhz(unsigned int time){
unsigned int a = 10, b = 1000;
	while(time--){
		while(a--){	//100us x10 x1000
			while(b--){	//100us x1000
				TMOD = 0x20;	//timer 1 che do 2
				TL1 = 0x59;	//tre trong 100us
				TH1 = 0x59;
				TR1 = 1;
				while(!TF1){}
				TR1 = 0;
				TF1 = 0;
			}
		}
	}
}

//-------------------------------
/*
TIMER 1 CHE DO 2 TXAL 11.0592MHZ --> T = 1.085
tinh 100us 100/1.085 = 92. --> 256 - 92 = 164 --> 0xa4
*/
void delay_T1_1s_11mhz(unsigned int time){
unsigned int a = 10, b = 1000;
	while(time--){
		while(a--){	//100us x10 x1000
			while(b--){	//100us x1000
				TMOD = 0x20;	//timer 1 che do 2
				TL1 = 0xa4;	//tre trong 100us
				TH1 = 0xa4;
				TR1 = 1;
				while(!TF1){}
				TR1 = 0;
				TF1 = 0;
			}
		}
	}
}


void main(){
	while(1){
		P2_0 = 1;
		delay_T0_1s_12mhz(5);
		P2_0 = 0;
		delay_T0_1s_12mhz(5);
		P2_0 = 1;
		delay_T1_1s_11mhz(5);
		P2_0 = 0;
		delay_T1_1s_11mhz(5);
	}
}

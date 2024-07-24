//LE MINH HUU 3/3/2022
#include <REGX52.H>

sbit led = P2^0;

//TIMER 0 CHE DO 2 500Us ==> tinh gia tri th tl cho 100us va lap lai 5 lan
//================================================
//THACH ANH TAN SO 11.0592	t = 1.085
//cd 2 la 8 bit 
//100ms  => n = 100 / 1.085 = 92
//256 - 92 = 164 ==> a4 hex
////ham tre 200us
void delay11t0(){
	int lan;
	lan = 5;
	while(lan--){
		TMOD = 0x02;	// 0000 0010 timer 0 che do 2
		TL0 = 0xa4;
		TH0 = 0xa4;
		TR0 = 1;
		while(!TF0);
		TR0 = 0;
		TF0 = 0;
	}
}
//================================================

//TIMER 0 CHE DO 2 500Us ==> tinh gia tri th tl cho 100us va lap lai 5 lan
//================================================
//THACH ANH TAN SO 20	t = 0.6
//cd 2 la 8 bit 
//100us  => n = 100 / 0.6666 = 166
//256 - 166 = 90 ==> 5a hex
////ham tre 500us
void delay20t0(){
	int lan;
	lan = 5;
	while(lan--){
		TMOD = 0x02;	// 0000 0010 timer 0 che do 2
		TL0 = 0x5a;
		TH0 = 0x5a;
		TR0 = 1;
		while(!TF0);
		TR0 = 0;
		TF0 = 0;
	}
}

//TIMER 0 CHE DO 2 500Us ==> tinh gia tri th tl cho 100us va lap lai 5 lan
//================================================
//THACH ANH TAN SO 12	t = 1
//cd 2 la 8 bit 
//100us  => n = 100 / 1 = 100
//256 - 100 = 156 ==> 9c hex
////ham tre 500us
void delay12t0(){
	int lan;
	lan = 5;
	while(lan--){
		TMOD = 0x02;	// 0000 0010 timer 0 che do 2
		TL0 = 0x9c;
		TH0 = 0x9c;
		TR0 = 1;
		while(!TF0);
		TR0 = 0;
		TF0 = 0;
	}
}


//TIMER 1 CHE DO 2 500Us ==> tinh gia tri th tl cho 100us va lap lai 5 lan
//================================================
//THACH ANH TAN SO 20	t = 0.6
//cd 2 la 8 bit 
//100us  => n = 100 / 0.6666 = 166
//256 - 166 = 90 ==> 5a hex
////ham tre 500us
void delay20t1(){
	int lan;
	lan = 5;
	while(lan--){
		TMOD = 0x20;	// 0010 0000 timer 1 che do 2
		TL1 = 0x5a;
		TH1 = 0x5a;
		TR1 = 1;
		while(!TF1);
		TR1 = 0;
		TF1 = 0;
	}
}

//TIMER 1 CHE DO 2 500Us ==> tinh gia tri th tl cho 100us va lap lai 5 lan
//================================================
//THACH ANH TAN SO 12	t = 1
//cd 2 la 8 bit 
//100us  => n = 100 / 1 = 100
//256 - 100 = 156 ==> 9c hex
////ham tre 500us
void delay12t1(){
	int lan;
	lan = 5;
	while(lan--){
		TMOD = 0x20;	// 0010 0000 timer 1 che do 2
		TL1 = 0x9c;
		TH1 = 0x9c;
		TR1 = 1;
		while(!TF1);
		TR1 = 0;
		TF1 = 0;
	}
}

//TIMER 1 CHE DO 2 500Us ==> tinh gia tri th tl cho 100us va lap lai 5 lan
//================================================
//THACH ANH TAN SO 11.0592	t = 1.085
//cd 2 la 8 bit 
//100ms  => n = 100 / 1.085 = 92
//256 - 92 = 164 ==> a4 hex
////ham tre 500us
void delay11t1(){
	int lan;
	lan = 5;
	while(lan--){
		TMOD = 0x02;	// 0010 0000 timer 0 che do 2
		TL1 = 0x00;
		TH1 = 0xa4;
		TR1 = 1;
		while(!TF1);
		TR1 = 0;
		TF1 = 0;
	}
}

void main(){
led = 1;
	while(1){
		led = !led;
		delay11t0();
	}
}

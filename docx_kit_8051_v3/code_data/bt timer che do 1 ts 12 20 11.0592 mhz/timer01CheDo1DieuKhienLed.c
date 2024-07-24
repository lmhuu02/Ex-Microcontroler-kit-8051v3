//LE MINH HUU 3/3/2022
//================================================
#include <REGX52.H>

sbit led = P2^0;

void delay(int time){
	while(time--);
}

//TIMER 0 CHE DO 1 5ms

//THACH ANH TAN SO 11.0592	t = 1.085
//cd 1 la 16 bit 
//5ms = 5000us => n = 5000 / 1.085 = 4608
//65 536 - 4608 = 60 928 ==> ee00 hex
////ham tre 5ms
void delay11t0(){
	TMOD = 0x01;	// 0000 0001 timer 0 che do 1
	TH0 = 0xee;
	TL0 = 0x00;
	TR0 = 1;
	while(!TF0);
	TR0 = 0;
	TF0 = 0;
}


//THACH ANH TAN SO 12 t = 1
//cd 1 la 16 bit 
//5ms = 5000us => n = 5000 / 1 = 50000
//65 536 - 5000 = 65 036 ==> fe0c hex
////ham tre 5ms
void delay12t0(){
	TMOD = 0x01;	// 0000 0001 timer 0 che do 1
	TH0 = 0xfe;
	TL0 = 0x0c;
	TR0 = 1;
	while(!TF0);
	TR0 = 0;
	TF0 = 0;
}

//THACH ANH TAN SO 20 -->  T = 20/12 = 1.6667
//cd 1 la 16 bit 
//5ms = 5000us => n = 5000 / 0.667 = 8333
//65 536 - 8333 = 57 203 ==> df73 hex
////ham tre 5ms
void delay20t0(){
	TMOD = 0x01;	// 0000 0001 timer 0 che do 1
	TH0 = 0xdf;
	TL0 = 0x73;
	TR0 = 1;
	while(!TF0);
	TR0 = 0;
	TF0 = 0;
}

//=================================================
//TIMER 1 CHE DO 1 5ms
//THACH ANH TAN SO 11.0592	t = 1.085
//cd 1 la 16 bit 
//5ms = 5000us => n = 5000 / 1.085 = 4608
//65 536 - 4608 = 60 928 ==> ee00 hex
////ham tre 5ms
void delay11t1(){
	TMOD = 0x10;	// 0001 0000 timer 1 che do 1
	TH1 = 0xee;
	TL1 = 0x00;
	TR1 = 1;
	while(!TF1);
	TR1 = 0;
	TF1 = 0;
}

//THACH ANH TAN SO 12 t = 1
//cd 1 la 16 bit 
//5ms = 5000us => n = 5000 / 1 = 50000
//65 536 - 5000 = 65 036 ==> fe0c hex
////ham tre 5ms
void delay12t1(){
	TMOD = 0x10;	// 0001 0000  timer 1 che do 1
	TH1 = 0xfe;
	TL1 = 0x0c;
	TR1 = 1;
	while(!TF1);
	TR1 = 0;
	TF1 = 0;
}

//THACH ANH TAN SO 20 -->  T = 20/12 = 1.6667
//cd 1 la 16 bit 
//5ms = 5000us => n = 5000 / 0.667 = 8333
//65 536 - 8333 = 57203 ==> df73 hex
////ham tre 5ms
void delay20t1(){
	TMOD = 0x01;	// 0001 0000  timer 1 che do 1
	TH1 = 0xdf;
	TL1 = 0x73;
	TR1 = 1;
	while(!TF1);
	TR1 = 0;
	TF1 = 0;
}

void main(){
	led = 1;
	while(1){
			led = ~led;
	//	delay(1000);
		//delay11t0();
		//delay12t0();
	//	delay20t0();
		delay11t1();
	//delay12t1();
		//delay20t1();
	}
}
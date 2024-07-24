//POWER BY LE MINH HUU 4/3/2022
//KIEM TRA CAU 1: DIEU KHIEN LED DON
#include <REGX52.H>

sbit led = P2^0;

//==============================================
//ham delay timer 0 che do 1 ts 12mhz tre 2ms
//2ms = 2000 us. n = 65 536 - 2000 = 63 536 ==> f830 hex
void delay_12mhz(){
	TMOD = 0x01; 	//timer 0 cd 1
	TH0 = 0xf8;
	TL0 = 0x30;
	TR0 = 1;
	while(!TF0);
	TR0 = 0;
	TF0 = 0;
}
//==============================================
//ham delay timer 1 che do 2 ts 20mhz tre 1us
//t = 0.6, 1 /0.6 = 1.  n = 256 - 1 = 255.  ==> ff hex
void delay_20mhz(){
	TMOD = 0x20; 	//timer 1 cd 2
	TL1 = 0xff;
	TH1 = 0xff;
	TR1 = 1;
	while(!TF1);
	TR1 = 0;
	TF1 = 0;
}
//==============================================
void main(){
led = 1; //tat led
	while(1){
		led = ~led;
		//tre 2ms voi timer 0 cd 1 ts 12mhz
		delay_12mhz();
		//tre 1us voi timer 1 cd 2 ts 20mhz
		delay_20mhz();
	}
}


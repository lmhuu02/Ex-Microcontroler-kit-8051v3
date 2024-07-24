//power by le minh huu 6/3/2022
//ngat timer dieu khien led
//==============================================================
//	NGAT TIMER 0 CHE DO 1. XTAL 12MHZ
/*
#include <REGX52.H>

int t = 0; 	//khai bao bien dem thoi gian

void delay(unsigned int time){
	while(time--);
}

//ngat timer 0 che do 1. XTAL = 12mhz. 	TH0 = 0xfc;	TL0 = 0x18;	 thuc hien dem trong thoi gian 1ms.
void ngat() interrupt 1 {
	long time = 50000; 	//khoi tao bien tre
	t++;		//tang bien t len moi. khi lan ngat tiep theo duoc thuc hien khi het thoi gian tre
	TH0 = 0xfc;	
	TL0 = 0x18;	
	TR0 = 1;	//khoi dong bo dinh thoi timer 0
	//kiem tra xem neu dem duoc 10000 lan thi thuc hien
	if(t > 1000){
		t = 0; 	//gan bien dem t = 0 de dem lai tu dau khi t > 10000
		P1_3 = 0;	//bat led
		while(time--){};	//lenh delay 50000.	 NOTE: KHONG DUNG CHUNG HAM DELAY TRONG HAM MAIN
			P2 = 0xff;	//tat led
			P1_3 = 1;	//tat led
		//while(time--){};
	}
}

void main(){
	//khai bao ngat
	TMOD = 0x01; 	//khai bao timer 0 che do 1: 
	ET0 = 1;	// cho phep ngat timer 0
	TR0 = 1; 	// khoi dong bo dinh thoi timer 0
	EA = 1; 	// cho phep ngat 
	while(1){ 		//thuc hien nhay led lien tuc tren cong p2
		P2 = 0;	//bat led
		delay(10000);
//		P2 = 0xff;	//tat led
//		delay(10000);

	}
}
*/

//================================================================
//	NGAT TIMER 1 CHE DO 1. XTAL 12MHZ
#include <REGX52.H>

int t = 0; 	//khai bao bien dem thoi gian

void delay(unsigned int time){
	while(time--);
}

//ngat timer 1 che do 1. XTAL = 12mhz. 	TH0 = 0xfc;	TL0 = 0x18;	 thuc hien dem trong thoi gian 1ms.
void ngat() interrupt 3 {	//timer 1 thu tu ngat: 3
	long time = 50000; 	//khoi tao bien tre
	t++;		//tang bien t len moi. khi lan ngat tiep theo duoc thuc hien khi het thoi gian tre
	TH1 = 0xfc;	
	TL1 = 0x18;	
	TR1 = 1;	//khoi dong bo dinh thoi timer 0
	//kiem tra xem neu dem duoc 10000 lan thi thuc hien
	if(t > 5000){
		t = 0; 	//gan bien dem t = 0 de dem lai tu dau khi t > 10000
		P1_3 = 0;	//bat led
		while(time--){};	//lenh delay 50000.	 NOTE: KHONG DUNG CHUNG HAM DELAY TRONG HAM MAIN
			P2 = 0xff;	//tat led
			P1_3 = 1;	//tat led
		//while(time--){};
	}
}

void main(){
	//khai bao ngat
	TMOD = 0x10; 	//khai bao timer 1 che do 1: 
	ET1 = 1;	// cho phep ngat timer 0
	TR1 = 1; 	// khoi dong bo dinh thoi timer 0
	EA = 1; 	// cho phep ngat 
	while(1){ 		//thuc hien nhay led lien tuc tren cong p2
		P2 = 0;	//bat led
		delay(6000);
		P2 = 0xff;	//tat led
		delay(10000);

	}
}
//==============================================================
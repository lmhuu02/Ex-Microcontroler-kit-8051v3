//ngat timer hen gio 5s bat led P1.0 MO PHONG CHUA CHAY DUOC
//power by le minh huu 18/3/2022
#include <REGX52.H>

//==================================
//ngat timer 0 txal = 12mhz. tg tre 1s --> fc18
void ngatTimer5s() interrupt 1{	//thu tu 0: ngoai 0 EX0 --> 1 TIMER 0 ET0 --> NGOAI 1 EX1 -->  TIMER 1 ET1 --> UART
	unsigned int a = 10000, count = 0;
	count++;
	TH0 = 0xfc;	//nap gia tri trong 1ms
	TL0 = 0x18;
	TR0 = 1;
	while(count > 500){
		P1_0 = 0; 	//bat led
		while(a--){}	//tao tre cho led
			P1_0 = 1;
		count = 0;	//gan lai count = 0
	}
}

void main(){
	P1_0 = 1; 	// tat led
	TMOD = 0x01; 	//timer 0 che do 1
	IE = 0x80; 		// EA _ _ ES EX1 ET1 EX0 ET0	//LENH NAY  BANG 2 LENH DUOI
	ET0 = 1;
	EA = 1;
	TR0 = 1;		//bat bo dinh thoi
	while(1){}
}

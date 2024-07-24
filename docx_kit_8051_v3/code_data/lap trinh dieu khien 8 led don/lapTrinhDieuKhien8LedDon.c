//POWER BY  LE MINH HUU - 17/1/2022
//DIEU KHIEN LED DON 
#include <REGX52.H>

sbit Led1 = P2^0;
sbit Led2 = P2^1;
sbit Led3 = P2^2;
sbit Led4 = P2^3;
sbit Led5 = P2^4;
sbit Led6 = P2^5;
sbit Led7 = P2^6;
sbit Led8 = P2^7;

//sbit led[] = {Led1, Led2, Led3, Led4,  Led5, Led6,  Led7, Led8};
char ledd[] = {0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xfd, 0xbf, 0x7f};//tung led sang lan luot tu chan 0 den 7 
//						Led1, Led2, Led3, Led4,  Led5, Led6,  Led7, Led8 = 0
	

void delay(int time){
	while(time--);
}

void blinkLedChanLe(int lan){
	int i;
	int j;
	for(i = 0; i < lan; i++){//so lan
		for(j = 0; j < 8; j++){	//chay tu chan 0 den chan 7
			if(j % 2 == 0){	//nhung led chan sang
				P2 = ledd[j];  delay(15000);
			}
		}
				//POWER BY  LE MINH HUU - 17/1/2022

		for(j = 0; j < 8; j++){	//chay tu chan 0 den chan 7
			if(j % 2 == 1){	//nhung led le sang
				P2 = ledd[j];  delay(15000);
			}
		}
	}
}

void sangTraiPhaiBlink(int lan){
	int i;
	for(i = 0; i < lan; i++){
		Led1 = 0; delay(10000); Led1 = 1; delay(10000); 
		Led2 = 0; delay(10000); Led2 = 1; delay(10000); 
		Led3 = 0; delay(10000); Led3 = 1; delay(10000); 
		Led4 = 0; delay(10000); Led4 = 1; delay(10000); 
		Led5 = 0; delay(10000); Led5 = 1; delay(10000); 
		Led6 = 0; delay(10000); Led6 = 1; delay(10000); 
		Led7 = 0; delay(10000); Led7 = 1; delay(10000); 
		Led8 = 0; delay(10000); Led8 = 1; delay(10000); 
	}
}

void phaiSangTraiBlink(int lan){
	int i;
	for(i = 0; i < lan; i++){
		Led8 = 0; delay(10000); Led8 = 1; delay(10000); 
		Led7 = 0; delay(10000); Led7 = 1; delay(10000); 
		Led6 = 0; delay(10000); Led6 = 1; delay(10000); 
		Led5 = 0; delay(10000); Led5 = 1; delay(10000); 
		Led4 = 0; delay(10000); Led4 = 1; delay(10000); 
		Led3 = 0; delay(10000); Led3 = 1; delay(10000); 
		Led2 = 0; delay(10000); Led2 = 1; delay(10000); 
		Led1 = 0; delay(10000); Led1 = 1; delay(10000); 
	}
}

void blink(int lan){
	int i;
	for(i = 0; i < lan; i++){
		Led1 = Led2 = Led3 = Led4 = Led5 = Led6 = Led7 = Led8 = 1;
		delay(10000);
		Led1 = Led2 = Led3 = Led4 = Led5 = Led6 = Led7 = Led8 = 0;
		delay(10000);
		//POWER BY  LE MINH HUU - 17/1/2022

	}
}

void giuaRaHaiBen(int lan){
	int i;
	for(i = 0; i < lan; i++){
		//giu sang
		P2 = 0xe7; delay(15000);
		P2 = 0xc3; delay(15000);
		P2 = 0x81; delay(15000);
		P2 = 0x00; delay(15000);
		//tat giua ra ngoai
		P2 = 0x18; delay(15000);
		P2 = 0x3c; delay(15000);
		P2 = 0x7e; delay(15000);
		P2 = 0xff; delay(15000);
		
		//nhay sang
		P2 = 0xe7; delay(15000);
		P2 = 0xdb; delay(15000);
		P2 = 0xbd; delay(15000);
		P2 = 0x7e; delay(15000);
		
	}
}

void haiBenVaoGiua(int lan){
	int i;
	for(i = 0; i < lan; i++){
		//giu sang
		P2 = 0x00; delay(15000);
		P2 = 0x81; delay(15000);
		P2 = 0xc3; delay(15000);
		P2 = 0xe7; delay(15000);
		//giu tat
		P2 = 0xff; delay(15000);
		P2 = 0x7e; delay(15000);
		P2 = 0x3c; delay(15000);
		P2 = 0x18; delay(15000);
		
		//nhay sang
		P2 = 0x7e; delay(15000);
		P2 = 0xbd; delay(15000);
		P2 = 0xdb; delay(15000);
		P2 = 0xe7; delay(15000);
	}
}

void sangChanLe(int lan){
	int i;
	for(i = 0; i < lan; i++){
		Led2 = Led4 = Led6 = Led8 = 0;	delay(15000);
		Led2 = Led4 = Led6 = Led8 = 1;	delay(15000);
		Led2 = Led4 = Led6 = Led8 = 0;	delay(15000);
		Led1 = Led3 = Led5 = Led7 = 1;	delay(15000);
	}
}


void sangGiuTraiPhai(int lan){
	int i;
	for(i = 0; i < lan; i++){
		//ban dau cho tat het led
		Led1 = Led2 = Led3 = Led4 = Led5 = Led6 = Led7 = Led8 = 1;
		//sang dan led trai sang phai, giu led sang
		Led1 = 0; delay(20000);
		Led2 = 0; delay(20000);
		Led3 = 0; delay(20000);
		Led4 = 0; delay(20000);
		Led5 = 0; delay(20000);
		Led6 = 0; delay(20000);
		Led7 = 0; delay(20000);
		Led8 = 0; delay(20000);
		
		//POWER BY  LE MINH HUU - 17/1/2022

		//tat dan led trai sang phai
		Led1 = 1; delay(20000);
		Led2 = 1; delay(20000);
		Led3 = 1; delay(20000);
		Led4 = 1; delay(20000);
		Led5 = 1; delay(20000);
		Led6 = 1; delay(20000);
		Led7 = 1; delay(20000);
		Led8 = 1; delay(20000);

	}
}
void sangGiuPhaiTrai(int lan){
	int i;
	for(i = 0; i < lan; i++){
		Led1 = Led2 = Led3 = Led4 = Led5 = Led6 = Led7 = Led8 = 1;
		//bat dan led tu phai sang trai
		Led8 = 0; delay(20000);
		Led7 = 0; delay(20000);
		Led6 = 0; delay(20000);
		Led5 = 0; delay(20000);
		Led4 = 0; delay(20000);
		Led3 = 0; delay(20000);
		Led2 = 0; delay(20000);
		Led1 = 0; delay(20000);
		
		//tat dan led tu phai sang trai
		Led8 = 1; delay(20000);
		Led7 = 1; delay(20000);
		Led6 = 1; delay(20000);
		Led5 = 1; delay(20000);
		Led4 = 1; delay(20000);
		Led3 = 1; delay(20000);
		Led2 = 1; delay(20000);
		Led1 = 1; delay(20000);
	}
}
void sangChanLel(int lan){
	int i;
	for(i = 0; i < lan; i++){
		//POWER BY  LE MINH HUU - 17/1/2022

	}
}


void main(){
	Led1 = Led2 = Led3 = Led4 = Led5 = Led6 = Led7 = Led8 = 1;
	while(1){
		blink(3); delay(10000);
		blinkLedChanLe(2); delay(10000);
		sangChanLe(1); delay(10000);
		sangGiuTraiPhai(1); delay(10000);
		sangGiuPhaiTrai(2); delay(10000);
		sangTraiPhaiBlink(2); delay(10000);
		phaiSangTraiBlink(3);	delay(10000);
		giuaRaHaiBen(2);	delay(10000);
		giuaRaHaiBen(1);	delay(10000);
		haiBenVaoGiua(2);	delay(10000);
		
	}
}
	
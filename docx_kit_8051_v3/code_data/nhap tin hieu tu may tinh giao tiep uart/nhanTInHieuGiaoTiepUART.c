#include <REGX52.H>

char kytu;

void initUART(){
	TMOD = 0x20; 	//timer 1 che do 2
	TH1 = 0xfd;	//baud = 9600
	TL1 = 0xfd;
	TR1 = 1;
	SCON = 0x50;	// 0 1 0 1 0000 SM0 = 0, SM1 = 1, REN = 1;
	//TI = 1;
}

void uartWrite(char a){
	while(TI == 0){}
		TI = 0;
		SBUF = a;
}

char uartRead(){
	RI = 0;
	return SBUF;
}

void uartWriteText(unsigned char * str){
	while(*str){
			uartWrite(str);
		str++;
	}
}

void main(){
	initUART();
	P1 = 0xff; 	//cho port 1 = 1 het
	kytu = uartRead();
	while(1){
		if(RI == 1){
			
			if(uartRead() == 'x') P1_0 = 0;
			if(uartRead() == 'y') P1_0 = 1;
			if(uartRead() == 'z') P1_1 = 0;
			if(uartRead() == 't') P1_1 = 1;
			if(uartRead() == 'a') { P1_0 = 0; P1_1 = 0;}
			
		}
	}
}
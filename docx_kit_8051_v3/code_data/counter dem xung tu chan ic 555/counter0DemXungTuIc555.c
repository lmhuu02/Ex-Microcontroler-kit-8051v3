//dem xung tu ic 555 bang counter 0 chan P3.2. INT0
//power by le minh huu 18/3/2022
#include <REGX52.H>

char so[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
unsigned int count = 0;

void delay(unsigned int time){
	while(time--);
}

void main(){
	TMOD = TMOD & 0x0f;
	TMOD = TMOD | 0x05; 	//counter 0 --> 0 0 0 0   0 1 0 1 //counter 0 che do 1
	TH0 = 0x00;
	TL0 =	0x00;
	TR0 = 1;	//bat bo dinh thoi
	P0 = 1;
	while(1){
		count = TL0 | TH0 << 8;	//bien count la gia tri cua thanh ghi th + tl va dich trai 8 bit de dam bao doc tu thanh ghi muc thap tl
		P0 = so[count];	//hien thi led 7 doan chung anot cho chan p0. noi chan a -> g lan luot tu chan 0 den 6 
		delay(10000);
		if(count == 10) count = 0;
	}
}

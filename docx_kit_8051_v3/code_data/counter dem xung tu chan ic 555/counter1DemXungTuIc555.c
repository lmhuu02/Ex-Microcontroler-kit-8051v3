//dem xung tu chan P3.3 counter 1, INT1.
//power by le minh huu 18/3/2022
#include <REGX52.H>

char so[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
unsigned int count = 0;

void delay(unsigned int time){
	while(time--);
}

void main(){
	TMOD = TMOD & 0xf0;	//xoa gia tri cu trong thanh ghi
	TMOD = TMOD | 0x50; 	//counter 1 che do 1
	TH1 = 0x00;	//gan dem chay tu dau
	TL1 = 0x00;
	TR1 = 1;	//khoi dong bo dinh thoi
	while(1){
		count = TH1 | TL1 << 8;	
		P0 = so[count];
		delay(1000);
		if(count == 10) count = 0;
	}
}

/*
power by Le Minh Huu 2k2 @copyright 19/5/2022
1. dem xung tu T0 P3_4 hien thi len led 7 thanh
2. dem xung chan/le
3. dem xung tu 50 den 80 hien thi len
*/
#include <REGX52.H>
#define on 0
#define off 1
#define ledDv P2_5
#define ledC	P2_4
#define ledT	P2_3
#define ledN	P2_2
#define ledCNghin	P2_1
#define ledTNghin	P2_0

char so[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
unsigned int count  =  0;
void delay(int time){
while(time--){}
}
//da dung counter ma dung them timer thi se gay ra xung dot neu khong chu y
//void delay_ms(unsigned int time){
//	while(time--){
//		TMOD = 0x20; 	// 0010 0000 timer 1 che do 1
//		TH1 = 0xfa;
//		TL1 = 0x18;
//		TR1 = 1;
//		while(!TF1){}
//		TR1 = 0;
//		TF1 = 0;
//	}
//}
void hienThi(unsigned int i){
int j;
	unsigned int dv, chuc, tram, nghin, cnghin, tnghin;
	dv = i % 10;
	chuc = (i / 10) % 10;
	tram = (i / 100) % 10;
	nghin = (i / 1000) % 10;
	cnghin = (i / 10000) % 10;
	tnghin = (i / 100000) % 10;
	for(j = 0; j < 10; j++){
		ledDv = on;	P0 = so[dv];	delay(100); ledDv = off;
		ledC = on; P0 = so[chuc]; delay(100); ledC = off;
		ledT = on; P0 = so[tram]; delay(100); ledT = off;
		ledN = on; P0 = so[nghin]; delay(100); ledN = off;
		ledCNghin = on; P0 = so[cnghin]; delay(100); ledCNghin = off;
		ledTNghin = on; P0 = so[tnghin]; delay(100); ledTNghin = off;	
	}	
}
void demXungTien(unsigned int i){
		hienThi(i);
}
void demChanLe(unsigned int i){
		if (i %2 == 0) hienThi(i);
}
void demXung50(unsigned int i){
if(i >= 50 && i <= 70) hienThi(i);
}
void main(){
	TMOD = TMOD & 0x0f;
	TMOD = TMOD | 0x05;	 // 0000 0101 counter 0 che do 1
	TR0 = 1;
	TL0 = 0x00;
	TH0 = 0x00;
	while(1){
		count = TL0 | TH0 <<8;
		demXungTien(count);
		demChanLe(count);
	}
}

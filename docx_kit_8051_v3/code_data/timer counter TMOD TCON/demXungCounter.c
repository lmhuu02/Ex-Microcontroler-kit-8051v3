#include <REGX52.H>

#define cdv P2_4
#define cchuc P2_3
#define ctram P2_2
#define cnghin P2_1
#define ccnghin P2_0
#define on 0
#define off 1

char soHienThi[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
unsigned int cNghin, nghin, tram, chuc, dv;
	
void delay(int time){
	while(time--);
}

void hienThi(unsigned int so){

	//su dung cach cua thay	
	cNghin = so / 10000;	so = so % 10000;	//so chuc nghin = so chia lay nguyen cho 10 000, so = so ban dau chia lay du cho 10 000
	nghin = so / 1000;	so = so % 1000;	// so nghin = so chia nguyen cho 1000, roi so = so chia lay du cho 1000
	tram = so / 100; so = so % 100;	//so tram = so chia nguyen cho 100
	chuc = so / 10; //so chuc = so chia nguyen cho 10
	dv = so % 10;	//so dv = so da chia lay du o hang chuc
	
	//su dung cach cua toi: Le HUU
//	dv = so % 10;	 so = so / 10;
//	chuc = so % 10; so = so / 10;
//	tram = so % 10; so = so / 10;
//	nghin = so % 10; so = so / 10;
//	cNghin = so % 10; so = so / 10;
	
	cdv = on; P0 = soHienThi[dv]; delay(1000); cdv = off;
	cchuc = on; P0 = soHienThi[chuc]; delay(1000); cchuc = off;
	ctram = on; P0 = soHienThi[tram]; delay(1000); ctram = off;
	cnghin = on; P0 = soHienThi[nghin]; delay(1000); cnghin = off;
	ccnghin = on; P0 = soHienThi[cNghin]; delay(1000); ccnghin = off;
	
}

void main(){
	unsigned int high,low,dem;//TIMEE 0,CDD 1/ TMOD=11110000 -> 1111 0101
	TMOD = TMOD & 0xf0;	//xoa gia tri cho tmod, lenh and (va) & dau ra = 1 khi ca 2 dau vao = 1
	TMOD = TMOD | 0x50; 	//cau hinh che do counter: 0101 0000 0x50 ==> counter 1 che do 1 
	TR0 = 1; 	// khoi chay thanh ghi 
	while(1){
		high=TH0;
		low=TL0;
		dem=high; //dich 8 bit lay gia tri cua th 0
		dem<<8;
		dem|low;
		hienThi(dem);
	}
}

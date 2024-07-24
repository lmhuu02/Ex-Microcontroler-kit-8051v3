/*
DO AN TOT NGHIEP: KIT 8051 V3.
NAME: BUTTON CONTROL AND 7SEG in chip 8051.
TIME: 3/2023	- ICTU.
*/
/*---------------------------INCLUDE AND DEFINE-----------------------------------*/
#include <REGX51.H>

#define cdv P2_7
#define cchuc P2_6
#define ctram P2_5
#define cnghin P2_4

#define on 0
#define off 1

char soHienThi[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
unsigned int cNghin, nghin, tram, chuc, dv;
unsigned int dem = 0;

/*------------------------------- FUNCTION-------------------------------*/
//function delay
void delay(int time){
	while(time--);
}

//function show data
void hienThi(unsigned int so){

	//su dung cach cua thay	
	cNghin = so / 10000;	so = so % 10000;	//so chuc nghin = so chia lay nguyen cho 10 000, so = so ban dau chia lay du cho 10 000
	nghin = so / 1000;	so = so % 1000;	// so nghin = so chia nguyen cho 1000, roi so = so chia lay du cho 1000
	tram = so / 100; so = so % 100;	//so tram = so chia nguyen cho 100
	chuc = so / 10; //so chuc = so chia nguyen cho 10
	dv = so % 10;	//so dv = so da chia lay du o hang chuc

	cdv = on; P0 = soHienThi[dv]; delay(500); cdv = off;
	cchuc = on; P0 = soHienThi[chuc]; delay(500); cchuc = off;
	ctram = on; P0 = soHienThi[tram]; delay(500); ctram = off;
	cnghin = on; P0 = soHienThi[nghin]; delay(500); cnghin = off;
}

//function button control data
void button(){
	if(P3_5 == 0){		
		while(P3_5 ==0){
			hienThi(dem);
		}
		dem++;
	}
	hienThi(dem);	//call function hienThi()
}
/*-------------------------------MAIN FUNCTION-------------------------------*/
void main(){
	TMOD &= 0xf0;
	TMOD |= 0x50;
	TL1 = 0x00;
	TH1 = 0x00;
	P3_5 = 1;
	TR1 = 1;
	while(1){
		//hienThi(TL1);
		button();
	}
}

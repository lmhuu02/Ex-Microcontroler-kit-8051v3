//POWER BY LE MINH HUU 4/3/2022
//KIEM TRA DEM XUNG CHAN LE SO NGUYEN TO
#include <REGX52.H>
#include <math.h>

#define on 0
#define off 1
sbit cdv  = P2^4;
sbit cchuc = P2^3;
sbit ctram = P2^2;
sbit cnghin = P2^1;
sbit ccnghin = P2^0;

//===========================================
void delay(unsigned int time){
	while(time--);
}
//===========================================
void hienThi(unsigned int so){
	unsigned int cNghin, nghin, tram, chuc, dv;
	char soht[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
	
	cNghin = so / 10000;	
	so = so % 10000;	//so chuc nghin = so chia lay nguyen cho 10 000, so = so ban dau chia lay du cho 10 000
	nghin = so / 1000;	
	so = so % 1000;	// so nghin = so chia nguyen cho 1000, roi so = so chia lay du cho 1000
	tram = so / 100; 
	so = so % 100;	//so tram = so chia nguyen cho 100
	chuc = so / 10; //so chuc = so chia nguyen cho 10
	dv = so % 10;	//so dv = so da chia lay du o hang chuc
	
	P0 = soht[dv]; cdv = on; delay(1000); cdv = off;
	P0 = soht[chuc]; cchuc = on; delay(1000); cchuc = off;
	P0 = soht[tram]; ctram = on; delay(1000); ctram = off;
	P0 = soht[nghin]; cnghin = on; delay(1000); cnghin = off;
	P0 = soht[cNghin]; ccnghin = on; delay(1000); ccnghin = off;
}
//ham dem so nguyen to
//===========================================
void demNguyenTo(unsigned int count){
	//so nguyen to la so chi chia het cho 1 va chinh no
	unsigned int a, dem;
		//kiem tra xem i co phai la so nguyen to hay khong neu phai thi thuc hien in ra 
		dem = 0;
		for(a = 1; a <= (count); a++){
			if( count % a == 0){
				dem++;
			}
		}
		if(dem == 2){	//neu dem == 2 thi day la so nguyen to. vi a =1 va a <= i.
			//dem snt
			hienThi(count);	//hien thi
			}
	}
//ham dem chan
//===========================================
void demChan(unsigned int count){
	if(count % 2 == 0){
		hienThi(count);
	}
}
//ham dem le	
//===========================================
void demLe(unsigned int count){
	if(count % 2 == 1){
		hienThi(count);
	}
}	
//POWER BY LE MINH HUU 4/3/2022
//@copyright
//===========================================
void main(){
	unsigned int count;
	//unsigned char high, low;

	TMOD &= 0x0f;	//xoa du lieu tg
	TMOD |= 0x50;	// 0101 000 counter 1 che do 1
	TL0 = 0x00;
	TH0 = 0x00;
	TR1 = 1;	//khoi dong thanh ghi
//-------------------------------------------------	
	while(1){
		count = TL1 | TH1  <<8;	//dem tu hai thanh ghi tl th va dich sang trai 8 bit de do tu thanh ghi tl
		/*
//		high = TH0;
//		low = TL0;
//		count = high;
//		count = count <<8;
//		count |=  low;
		*/
//-------------------------------------------------
		//dem xung chan 
		//demChan(count);
//-------------------------------------------------		
		//dem xung le
		//demLe(count);
//-------------------------------------------------		
		//dem snt
		demNguyenTo(count);		
	}
}
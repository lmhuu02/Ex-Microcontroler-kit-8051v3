/*
DO AN TOT NGHIEP: KIT 8051 V3.
NAME: SHOW DATA 7SEG 00 TO 99999 in chip 8051.
TIME: 3/2023	- ICTU.
*/
/*---------------------------INCLUDE AND DEFINE-----------------------------------*/
#include <REGX51.H>

#define sang 0
#define tat 1

int demSo;
char soHienThi[] = {0x60,0xf9,0x24,0x30,0x19,0x12,0x02,0xf8,0x00,0x10};	//led 7 thanh hien thi so tu 0 den 9
unsigned char quetSoThu[] = {0xef,0xdf,0xbf,0x7f,0xfe,0xfd,0xfb,0xf7};	//cho biet so led sang, dieu khien chan annot cua moi chu so 
unsigned char chuSoThu[8];	// toi da la 8 7seg mpx 
	
/*-------------------------------FUNCTION-------------------------------*/
//function delay
void delay1(int time){
	while(time--);
}

//function tach chu so
void tachChuSo(unsigned long temp, int soLed){
	int i;
	for(i = 0; i < soLed; i++){	//bien i duoc chay tu o den soLed duoc truyen vao 
		chuSoThu[i] = temp % 10;	//chuSoThu[i] la mot mang luu cac gia tri tach (chia lay du) lan luot tu hang don vi, chuc, tram, nghin,... tuy thuoc vao gia tri soLed 
		temp = temp/10;	
	}
}

//soLed duoc nhap vao tu ham main.
void quetLed(int soLed ){
	int i, j;
	for(i = 0; i < 15; i++){	//lap lai i lan tren cung mot so hien thi
			for(j = 0; j < soLed; j++){
				P0 = soHienThi[chuSoThu[j]];	//cong P0 de hien thi so tu 0 den 9 cho moi led 7 doan co gia tri la chuSoThu[], mang chuSoThu[] duoc luu  
				P2 = quetSoThu[soLed - j];	//cong P2 de kieu khien led 7 thanh nao dang hoat dong. mang quetSoThu tu 0 den 6, tuc la dieu kien led 7 thanh tu phai sang trai
				delay1(500); 	// delay 1000 de hien thi chu so lau hon
				P2 = 0xff; 	//tat tat ca cac led vua hien thi
			}
	}
}

/*-------------------------------MAIN FUNCTION-------------------------------*/
int i;
void main(){
	P0 = 0xff;
	while(1){
	
		//demSo tu 0 den 1 gia tri toi da (max) ma ta nhap vao
		for(demSo = 0; demSo < 999; demSo++){
			tachChuSo(demSo, 6);	//moi lan tang bien demSo va truyen gia tri vao ham tachChuSo thi mang chuSoThu lai thay doi 
			quetLed(6);	//goi ham hien thi, quyet led 7 thanh
		}
	}
}



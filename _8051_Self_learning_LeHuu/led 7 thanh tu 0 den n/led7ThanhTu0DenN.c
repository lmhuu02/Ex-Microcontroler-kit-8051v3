//power by dientu360.com e360 - make by le minh huu 10/2/2022
#include <REGX52.H>

#define sang 0
#define tat 1

int demSo;
char soHienThi[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};	//led 7 thanh hien thi so tu 0 den 9
unsigned char quetSoThu[] = {0xbf, 0xdf, 0xef, 0xf7, 0xfb, 0xfd, 0xfe};	//cho biet so led sang, dieu khien chan annot cua moi chu so 
unsigned char chuSoThu[7];	//do trong protues led 7 thanh chi co toi da la 7seg mpx 
	
void delay(int time){
	while(time--);
}

//temp la chu so ta can hien thi ra vd 87, soLed la so chu so led can hien thi vd soLed = 3 thi gia tri chay tu 0 den 999
//khi goi den ham tach chu so thi gia tri temp duoc truyen vao la thu tu duoc dem tu 0 trong ham main. 
//moi lan bien demSo tang len mot thi lai thuc hien lai ham tachChuSo va ghi de len cac gia tri truoc co trong  mang chuSoThu
// bien soLed truyen vao bang cach gan gia tri trong ham main: khi muon led chay tu 0 den 999 thi soLed = 3
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
	for(i = 0; i < 10; i++){	//lap lai i lan tren cung mot so hien thi
			for(j = 0; j < soLed; j++){
				P0 = soHienThi[chuSoThu[j]];	//cong P0 de hien thi so tu 0 den 9 cho moi led 7 doan co gia tri la chuSoThu[], mang chuSoThu[] duoc luu  
				P2 = quetSoThu[j];	//cong P2 de kieu khien led 7 thanh nao dang hoat dong. mang quetSoThu tu 0 den 6, tuc la dieu kien led 7 thanh tu phai sang trai
				delay(1000); 	// delay 1000 de hien thi chu so lau hon
				P2 = 0xff; 	//tat tat ca cac led vua hien thi
			}
	}
}

void main(){
	while(1){
		//demSo tu 0 den 1 gia tri toi da (max) ma ta nhap vao
		for(demSo = 0; demSo < 999999; demSo++){
			tachChuSo(demSo, 6);	//moi lan tang bien demSo va truyen gia tri vao ham tachChuSo thi mang chuSoThu lai thay doi 
			quetLed(6);	//goi ham hien thi, quyet led 7 thanh
		}
	}
}
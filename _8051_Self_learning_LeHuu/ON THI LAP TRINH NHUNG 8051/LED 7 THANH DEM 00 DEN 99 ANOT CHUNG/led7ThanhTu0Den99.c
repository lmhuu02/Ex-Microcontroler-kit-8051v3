/*
power by Le MInh Huu 2k2 @copyright 18/5/2022
1. dem tu  0 den 99
2. dem tu 99 ve 0
3. dem cac so chan/le
4. dem cac so nguyen to
5. dem cac so chia het cho 3 va 5
6. dem cac so nho hon 30 va lon hon 50
7. 
*/
#include <REGX52.H>
#define led1 P3_1
#define led2 P3_0
#define on 0
#define off 1

char so[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};

void delay(int time){
while(time--){}
}
void hienThi(int i){
int  chuc, donvi, j;
		chuc = i / 10;
		donvi = i % 10;
		for(j = 0; j < 17; j++){
			led1 = on; P2 = so[donvi]; delay(1000);  led1 = off;
			led2 = on; P2 = so[chuc]; delay(1000);  led2 = off;
		}
}
void dem0Den99(){
	int i;
	for(i = 0; i < 100; i++){
		hienThi(i);
	}
}
void dem99ve0(){
	int i;
	for(i = 99; i >= 0; i--){
		hienThi(i);
	}
}
void demChan(){
int i;
	for(i = 0; i < 100; i++){
		if(i % 2 == 0){
				hienThi(i);
		}
	}
}
void demNho30Lon50(){
int i;
	for(i = 0; i < 100; i++){
		if(i < 30 || i > 50){
				hienThi(i);
		}
	}
}
void demSNT(){
int i, j, dem;
	for(i = 0; i < 100; i++){
		dem = 0;
		for(j = 1; j <= i; j++){
			if(i % j == 0){
				dem++;
			}
		}
		if(dem == 2)	 	hienThi(i);
	}
}
void main(){
	while(1){
		demSNT();
	dem0Den99();
	}
}
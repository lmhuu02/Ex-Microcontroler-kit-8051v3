/*
DEM LED 7 THANH TU 0 DEN 9 CHUNG ANOT KET NOI BINH THUONG 7_, 6-g, 5-f, 4-e, 3-d, 2-c, 1-b, 0-a;
power by Le Minh Huu 2k2 @copyright 18/5/2022
1. dem 0 den 9
2. dem 9 den  0
3. dem so chan
4. dem so le
5. dem so chia het cho 3
6. dem so nguyen to
7. dem so lon hon 6, dem so nho hon 5
8. dem so tu 4 den 8
9. dem so hon hon 3 hoac lon hon 7
*/
#include <REGX52.H>

char so[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};

void delay(int time){
while(time--){}
}

void dem0To9(){
	int i; 
	for(i = 0; i < 10; i++){
		P2 = so[i];	delay(50000);
	}
}
void dem9ve0(){
int i;
	for(i = 9; i >= 0; i--){
		P2 = so[i]; delay(50000);
	}
}
void demchan(){
int i;
	for(i = 0; i < 10; i++){
		if( i % 2 == 0){
			P2 = so[i]; delay(50000);
		}
	}
}
void demle(){
int i;
	for(i = 0; i < 10; i++){
		if (i % 2 == 1){
			P2 = so[i]; delay(50000);
		}
	}
}
void demNho3Lon7(){
int i;
	for(i = 0; i < 10; i++){
		if(i < 3 || i > 7){
			P2 = so[i]; delay(50000);			
		}
	}
}
void dem4den8(){
int i;
	for(i = 4; i < 9; i++){
			P2 = so[i]; delay(50000);			
	}
}
void demSNT(){
int dem, i, j;
	for(i = 0; i < 10; i++){
		dem = 0;
		for(j = 1; j <= i; j++){
				if(i % j == 0)	 dem++;
		}
		if(dem == 2){
			P2 = so[i]; delay(50000);		
		}
	}
}
void main(){
	P2 = 0xff;
	while(1){
		//dem0To9();
		//dem9ve0();
		demSNT();
	}
}
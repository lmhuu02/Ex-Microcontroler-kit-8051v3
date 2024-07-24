//POWER BY LE MINH HUU - 11/2/2022 @Copyright
/*
l?p tr?nh di?u khi?n LED 7 thanh y?u c?u:

dem ti?n t? 00 d?n 99
demm l?i t? 99 v? 00
demm c?c s? ch?n
dem c?c s? l?
dem s? nguy?n t?
dem c?c s? chia h?t cho 3
dem c?c s? chia h?t cho 3 ho?c 5
*/
#include <REGX52.H>

#define sang 0
#define tat 1

#define led1 P3_0
#define led2 P3_1

int i, j, chuc, donVi;
char so[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};

void delay(int time){
	while(time--);
}

//thuc hien dem lan luot tu 00 den 99
void dem00Toi99(){
	for(i = 0; i <= 99; i++){
		//xac dinh so hang chuc va hang don vi
				chuc = i /10;
				donVi = i % 10;
				//thuc hien lap lai 1 so 10 lan
				for(j = 0; j < 10; j++){
					//bat led 1
					led2 = sang;
					P2 = so[donVi];
					delay(10000);
					led2 = tat;
					
					//bat led 2				
					led1 = sang;
					P2 = so[ chuc];
					delay(10000);
					led1 = tat;
				}
			}
}

//POWER BY LE MINH HUU - 11/2/2022 @Copyright
void main(){
	led1 = led2 = tat;	//thuc hien tat ca 2 led
	while(1){
		//thuc hien dem lan luot tu 00 den 99
		dem00Toi99(); delay(10000);
	

	}
}
//POWER BY LE MINH HUU - 11/2/2022 @Copyright

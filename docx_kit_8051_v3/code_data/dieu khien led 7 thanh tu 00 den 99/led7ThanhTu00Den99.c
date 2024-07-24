//POWER BY LE MINH HUU - 11/2/2022 @Copyright
/*
l?p trình di?u khi?n LED 7 thanh yêu c?u:

dem ti?n t? 00 d?n 99
demm lùi t? 99 v? 00
demm các s? ch?n
dem các s? l?
dem s? nguyên tô
dem các s? chia h?t cho 3
dem các s? chia h?t cho 3 ho?c 5
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

//dem lan luot tu 99 ve 00
void dem99Ve00(){
	for(i = 99; i >=0; i--){
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

//dem cac gia tri le tu 0 den 99
void demLe(){
	for(i = 0; i <= 99; i++){
		//xac dinh so hang chuc va hang don vi
			chuc = i /10;
			donVi = i % 10;
			if(i % 2 == 1){	//neu la so le thi thuc hien con khong thi khong lam gi
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
}

//thuc hien hien thi cac so nguyen to tu 0 den 99
void demNguyenTo(){
	//so nguyen to la so chi chia het cho 1 va chinh no
	int a, i, dem;
	for(i = 2; i <= 99; i++){
		//kiem tra xem i co phai la so nguyen to hay khong neu phai thi thuc hien in ra 
		dem = 0;
		for(a = 1; a <= i; a++){
			if( i % a == 0){
				dem++;
			}
		}
		if(dem == 2){	//neu dem == 2 thi day la so nguyen to. vi a =1 va a <= i.
			//xac dinh so hang chuc va hang don vi
					chuc = i /10;
					donVi = i % 10;
					//thuc hien lap lai 1 so 10 lan
				//	for(j = 0; j < 10; j++){
						//bat led 1
						led2 = sang;P2 = so[donVi];delay(10000);	led2 = tat;	
						//bat led 2				
						led1 = sang;P2 = so[ chuc];delay(10000);led1 = tat;
				//	}
			}
	}
}

//dem so chia het cho 3 tu 0 den 99
void demChiaHet3(){
for(i = 0; i <= 99; i++){
		//xac dinh so hang chuc va hang don vi
			chuc = i /10;
			donVi = i % 10;
			if(i % 3 == 0){	//neu la so chia het cho 3 thi thuc hien con khong thi khong lam gi
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
}

//dem so chia het cho ca 3 va 5 tu 0 den 99
void demChiaHet3Va5(){
for(i = 0; i <= 99; i++){
		//xac dinh so hang chuc va hang don vi
			chuc = i /10;
			donVi = i % 10;
			if(i % 3 == 0 && i % 5 == 0){	//neu la so chia het cho 3 thi thuc hien con khong thi khong lam gi
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
}

//POWER BY LE MINH HUU - 11/2/2022 @Copyright
void main(){
	led1 = led2 = tat;	//thuc hien tat ca 2 led
	//thuc hien quet tung led mot, trong cung mot thoi gian chi dieu khien duy nhat mot led 7 thanh, KHONG DIEU KHIEN DONG THOI CA 2 LED 7 THANH
	while(1){
		//thuc hien dem lan luot tu 00 den 99
		//dem00Toi99(); delay(10000);
		//dem lan luot tu 99 ve 00
     //dem99Ve00(); delay(10000);
		//dem cac gia tri le tu 0 den 99
		//demLe(); delay(10000);
		//dem so chia het cho 3 tu 0 den 99
		//demChiaHet3(); delay(10000);
		//dem so chia het cho ca 3 va 5 tu 0 den 99
		//demChiaHet3Va5(); delay(10000);
		//thuc hien hien thi cac so nguyen to tu 0 den 99
			demNguyenTo(); delay(10000);
	}
}
//POWER BY LE MINH HUU - 11/2/2022 @Copyright

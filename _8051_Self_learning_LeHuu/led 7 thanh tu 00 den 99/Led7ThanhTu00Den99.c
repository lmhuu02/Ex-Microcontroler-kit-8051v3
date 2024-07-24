//POWER BY LE MINH HUU - 10/2/2022
#include <REGX52.H>

#define led1  P0_0
#define led2  P0_1

#define sang 0
#define tat 1

//led 7 thanh chung annot, quet 2 led 7 thanh bang cach: sang lan luot hang chuc va don vi
//dieu kien chan chung annot va phuong phap chia lay du va lay nguyen de xac dinh hang chuc va hang don vi
//vd so = 78 --> chuc = so / 10 = 7; donvi = so % 10 = 8 ;

char so[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
int i, j, chuc, donVi;

void delay(int time){
	while(time){
		time--;
	}
}

void main(){
	led1 = led2 = tat;
	while(1){
		//led1 = sang; P2 = 0xf9; delay(10000);
		//cho so chay tu 0 den 99
		for(i = 0; i <= 99; i ++){
			// tinh so hang chuc va hang don vi
			chuc = i /10;
			donVi = i % 10;
			//vong for nay co tac dung hien thi j lan cho tung so, lam cho nhin ro hon
				for(j = 0; j < 20; j++){
					led1 = sang;	//cho led1 sang 
					P2 = so[chuc];			//sang dung so ma hang chuc da chia o tren
					delay(5000);	//delay 1 khoang de mat nhin thay roi chuyen trang thai tat
					led1 = tat;

					led2 = sang;	//cho led 2 sang
					P2 = so[ donVi];
					delay(5000);	//delay 1 khoang de mat nhin thay roi chuyen trang thai tat
					led2 = tat;
					delay(10000);
				}	
				
			// lap lai cho den 99 roi lai quay lai
		}
	}
}
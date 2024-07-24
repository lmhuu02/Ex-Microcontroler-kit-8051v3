//POWER BY LE MINH HUU 11/2/2022 @Copyright
#include <REGX52.H>

//huong lam: cho mot mang chua ma hex 7seg cho ic 74ls47 nhung gap doi ma hex
//chia port2 ra lam 2 phan phan tren gom 2.0, 2.1, 2.2, 2.3 se dieu khien led1 hang chuc. phan 2 gom 2.4, 2.5, 2.6, 2.7 dieu khien led2 hang don vi
char dieuKhienChuc[] = {0xf0,0xf1,0xf2,0xf3,0xf4,0xf5,0xf6,0xf7,0xf18,0xf9};
char dieuKhienDonVi[] = {0x0f,0x1f,0x2f,0x3f,0x4f,0x5f,0x6f,0x7f,0x8f,0x9f};
int i,j, chuc, donVi;

void delay(time){
	while(time--);
}

void main(){
	while(1){
		for(i = 0; i <= 99; i++){
		//xac dinh so hang chuc va hang don vi
				chuc = i /10;
				donVi = i % 10;
			for(j = 0; j < 10; j++){
				P2 = dieuKhienChuc[chuc];
				delay(1700);
				P2 = dieuKhienDonVi[donVi];
				delay(1700);	
			}
			
		}
	}
}
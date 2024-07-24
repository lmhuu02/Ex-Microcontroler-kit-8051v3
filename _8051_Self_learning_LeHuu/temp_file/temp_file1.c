////power by le minh huu 11/3/2022
////dem so tu 0 den 99 dung led 7 thanh chung cathot, chung am. dieu khien bang muc 1
//#include <REGX52.H>

////gan chan cho led chuc don vi
//#define led1 P1_0
//#define led2 P1_1

////khai bao nut nhan
//sbit start = P3^2;
//bit state;
////so tu 0 den 9 cho led 7 thanh chung cathot, chung am.
//char so[]={0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f};
//int dem;

//void delay(int time){
//	while(time--);
//}

////ham hien thi led
//void hienthi(int chuso){
//	int chuc, donvi;
//	chuc = chuso/10;	//tinh so hang chuc
//	donvi = chuso%10;	//tinh so hang don vi
//	//hien thi quyet led
//	led1 = 0; P2 = so[chuc]; delay(6000); led1 = 1;
//	led2 = 0; P2 = so[donvi]; delay(6000); led2 = 1;
//}

//void main(){
//	dem = P1_0 = P1_1 = 0;
//	while(1){
//		//kiem tra nut bam neu dung la bam thi tang bien dem len 1 don vi
//		if(start == 0){
//				delay(100);
//				if(start == 0 && state == 1){
//					dem++;
//					P0_0 = ~P0_0;	delay(1000);	//cho den led cong p0_0 nhap nhay
//					if(dem == 100) { dem = 0;}	//neu bien dem = 100 thi gan bien dem = 0
//				}
//			}
//		state = start;
//			//goi ham hien thi va truyen vao gia tri la bien dem
//		hienthi(dem);
//		delay(1000);
//	}
//}
#include <REGX51.H>
void delay(int time){
	while(time--);
}

void main(){
	P2_0 = 1;
	while(1){
		P2_0 = ~ P2_0;
		delay(10000);
	}		
}
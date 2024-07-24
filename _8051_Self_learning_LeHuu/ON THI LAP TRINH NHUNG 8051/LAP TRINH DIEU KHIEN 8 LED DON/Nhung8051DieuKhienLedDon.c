/*
lap trinh dieu khien led PORT 2 dieu khien muc thap (muc 0)
1.1. chay tu d8 den d1, tat tu d8 den d1
1.2. sang giu trang thai tu  d8 den d1 tat tu d1 den d8
1.3. sang chay tu 2 ben vao giua va sang giu tu 2 ben vao giua

2.1 chay tu d1 den d8 tat tu d1 den d8
2.2 giu trang thai tu d1 den d8 va tat tu d8 den d1
2.3 sang tu giua ra hai ben va giu trang thai 
*/
//=================================================
//bai 1 SU DUNG CACH TRUY XUAT BIT THONG THUONG

#include <regx52.h>
void delay(int time){
while(time--){}
}
//sang chay
void sangD1D8(){
	P2_0 = 0; delay(10000); P2_0 = 1;
	P2_1 = 0; delay(10000); P2_1 = 1;
	P2_2 = 0; delay(10000); P2_2 = 1;
	P2_3 = 0; delay(10000); P2_3 = 1;
	P2_4 = 0; delay(10000); P2_4 = 1;
	P2_5 = 0; delay(10000); P2_5 = 1;
	P2_6 = 0; delay(10000); P2_6 = 1;
	P2_7 = 0; delay(10000); P2_7 = 1;
}

void sangD8D1(){
		P2_7 = 0; delay(10000); P2_7 = 1;
		P2_6 = 0; delay(10000); P2_6 = 1;
		P2_5 = 0; delay(10000); P2_5 = 1;
		P2_4 = 0; delay(10000); P2_4 = 1;
		P2_3 = 0; delay(10000); P2_3 = 1;
		P2_2 = 0; delay(10000); P2_2 = 1;
		P2_1 = 0; delay(10000); P2_1 = 1;
		P2_0 = 0; delay(10000); P2_0 = 1;

}
//sang giu trang thai
void sangGiuD1D8(){
	P2_0 = 0; delay(10000); 
	P2_1 = 0; delay(10000); 
	P2_2 = 0; delay(10000); 
	P2_3 = 0; delay(10000); 
	P2_4 = 0; delay(10000); 
	P2_5 = 0; delay(10000); 
	P2_6 = 0; delay(10000); 
	P2_7 = 0; delay(10000);
	P2 = 0xff;
}

void sangGiuD8D1(){	
		P2_7 = 0; delay(10000); 
		P2_6 = 0; delay(10000); 
		P2_5 = 0; delay(10000); 
		P2_4 = 0; delay(10000); 
		P2_3 = 0; delay(10000); 
		P2_2 = 0; delay(10000); 
		P2_1 = 0; delay(10000); 
		P2_0 = 0; delay(10000); 
		P2 = 0xff;
}
	//sang tu 2 ben vao giua
void sangchay2Ben(){
	P2_7 = P2_0 = 0; delay(10000); P2_7 = P2_0 = 1;
	P2_6 = P2_1 = 0; delay(10000); P2_6 = P2_1 = 1;
	P2_5 = P2_2 = 0; delay(10000); P2_5 = P2_2 = 1;
	P2_4 = P2_3 = 0; delay(10000); P2_4 = P2_3 = 1;
}

void sangGiu2Ben(){
	P2_7 = P2_0 = 0; delay(10000); 
	P2_6 = P2_1 = 0; delay(10000); 
	P2_5 = P2_2 = 0; delay(10000); 
	P2_4 = P2_3 = 0; delay(10000); 
}
void main(){
P2 = 0xff;	//cho port 2 bang 1
	while(1){
		sangD1D8();
		sangD8D1();
		sangGiuD1D8();
		sangGiuD8D1();
		sangchay2Ben();
		sangGiu2Ben();
	}
}


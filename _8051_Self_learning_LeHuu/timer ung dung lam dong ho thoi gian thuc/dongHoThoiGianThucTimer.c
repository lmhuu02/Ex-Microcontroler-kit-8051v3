//power by le minh huu 17/2/2022
//ung dung timer lap trinh dong ho thoi gian thuc
#include <REGX52.H>

//khai bao lenh tien xu ly
#define on 0
#define off 1
#define led1 P2_0 
#define led2 P2_1
#define led3 P2_2
#define led4 P2_3
//#define led_don P2_4
#define button_second P2_5
#define button_hour P2_6

//mang so tu 0 den 9
char so[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
//unsigned char hour, second;

	
//ham tre 1ms thoi gian thuc timer 0 che do 1 thach anh 11.0592, chu ky la 1.085
/*	1ms = 1000 us. 1000 / 1.085 =  
		65 536 - 921 = 64 615 -> fc67
	*/
void delay_ms(unsigned char ms){
	int j;
	for(j = 0; j < ms; j++){
		TMOD = 0x01;	//timer 0 che do 1
		TH0 = 0xfc ;
		TL0 = 0x18;
		
		TR0 = 1;
		while(!TF0);
		TF0 = 0;
		TR0 = 0;
	}
}
//ham hien thi gio phut 
void hienThi(unsigned char gio, unsigned char phut){
unsigned char donVi0, donVi1, chuc0, chuc1, i;
	donVi0=  gio % 10;
	chuc0 = gio / 10;
	donVi1 = phut % 10;
	chuc1 = phut / 10;
	//thuc hien dem: tinh so delay trong moi cau lenh de dat gia tri i. sao cho timer dung 1s
	//i <25 vi trong vong for delay 4 lan 10ms => co 40ms trong vong for. 
	//cho vong for chay 25 lan => tong so thoi gian delay: 40 x 25 = 1000ms = 1s.
	for(i = 0; i < 25; i++){
		led1 = on; P0 = so[chuc0];  delay_ms(10); led1 = off;
		led2 = on; P0 = so[donVi0]; delay_ms(10); led2 = off;
		led3 = on; P0 = so[chuc1];  delay_ms(10); led3 = off;
		led4 = on; P0 = so[donVi1]; delay_ms(10); led4 = off;
	}
}
//ham main chuong  trinh chinh
void main(){
	unsigned char gio = 0, phut =  0, giay = 0;
	P2_4 = 0;
	while(1){
		P2_4 = ~ P2_4;
		 giay++;
		hienThi(gio, phut);
		if(giay == 59) phut++;
		if(phut == 59) gio++;
		if(button_hour == 0) gio++;
		if(button_second == 0) phut++;
		if(giay > 59) giay =0;
		if(phut > 59) phut = 0;
		if(gio > 23) gio = 0;
	}
}	
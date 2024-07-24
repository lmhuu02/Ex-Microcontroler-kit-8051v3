/*
bai tap nhay 8 led dung at89c52
vkd 8051 hoat dong o muc thap
*/
#include <regx52.h>

int demphai = 0;
sbit led1 = P0^0 ;
sbit led2 = P0^1 ;
sbit led3 = P0^2 ;
sbit led4 = P0^3 ;
sbit led5 = P0^4 ;
sbit led6 = P0^5 ;
sbit led7 = P0^6 ;
sbit led8 = P0^7 ;

sbit led11 = P2^0 ;
sbit led22 = P2^1 ;
sbit led33 = P2^2 ;
sbit led44 = P2^3 ;
sbit led55 = P2^4 ;
sbit led66 = P2^5 ;
sbit led77 = P2^6 ;
sbit led88 = P2^7 ;


void delay(int time){
	while(time--);
}
//nhay xin nhan phai
void xinnhanphai(int lan){
	while(lan--){
				led1 = 0;	delay(2000);	
				led2 = 0;	delay(2500);	
				led3 = 0;	delay(3000);	
				led4 = 0;	delay(3500);	
				led5 = 0;	delay(4000);	
				led6 = 0;	delay(4500);	
				led7 = 0;	delay(5000);	
				led8 = 0;	delay(5500);	
				led1 = led2 = led3 = led4 = led5 = led6 = led7 = led8 = 1;
			delay(5000);
	}		
}
//nhay xin nhan trai
void xinnhantrai(){
		int demtrai = 1;
		delay(5000);
		led11 = 0;	delay(2000);	
		led22 = 0;	delay(2500);	
		led33 = 0;	delay(3000);	
		led44 = 0;	delay(3500);	
		led55 = 0;	delay(4000);	
		led66 = 0;	delay(4500);	
		led77 = 0;	delay(5000);	
		led88 = 0;	delay(5500);	
		led11 = led22 = led33 = led44 = led55 = led66 = led77 = led88 = 1;
		//kiem tra nut bam nhan trai p1_1
		if(P1_1 == 0){	//p1_1 = 0 la bam nut
			delay(200);	//tao do tre khi bam nut
			if(P1_1 ==0)	//kiem tra lai mot lan nua
				demtrai++;
				if(demtrai == 0 )	demtrai = 1;	//neu bam 3 lan thi dem se qua lai 	1
		}
		if(demtrai == 2){	//bat xin nhan
			xinnhantrai();		//cho nay nhu kieu de quy y
			delay(1000);	
		}else  led11 = led22 = led33 = led44 = led55 = led66 = led77 = led88 = 1;	//tat xin nhan
		
}

void main(void){
	int lan;
	while(1){
			

	}
}
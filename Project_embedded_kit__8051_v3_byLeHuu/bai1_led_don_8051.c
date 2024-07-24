/*
time: 2023 
embedded 8051 by langauge c.
ex1: control 8 led, left right,....
*/
/*
power by CLB Dien Tu - EoI - ICTU
code: Le Minh Huu
time: t5 - 9/2/2023
lesson 1: control 8 led port 1 - low (positive)
embedded 8051 by laugauge C.
*/

//include library 8051
#include <REGX51.H>

//function base delay
void delay(unsigned int time){
		while(time--);
}
char hd1[8] = {0xfe, 0xfd,0xfb,0xf7,0xef,0xdf,0xbf,0x7f};	//trai sang phai
char hd2[4] = {0xe7,0xdb,0xbd,0x7e}; //giua ra hai ben
	char hd3[4] = {0xe7,0xc3,0x81,0x00}; //giua ra hai ben giu
		char hd4[4] = {0x7e, 0x3c,0x18,0x00}; //hai ben vao giua giu
		
int i;
void hieuUng1(){
	P1  = 0;	
	for(i = 0; i < 8; i++){
		P1 = hd1[i];	
		delay(10000);
	}
	P1  = 0;	
	for(i = 7; i >=0; i--){
		P1 = hd1[i];	
		delay(10000);
	}	
}
/*-------------------------------------*/
void hieuUng2(){
	P1  = 0;	
	for(i = 0; i < 4; i++){
		P1 = hd2[i];	
		delay(10000);
	}
	P1  = 0;
	for(i = 3; i >=0; i--){
		P1 = hd3[i];
		delay(10000);
	}	
}
/*-------------------------------------*/
/*-------------------------------------*/
void hieuUng3(){
	P1  = 0;	
	for(i = 0; i < 4; i++){
		P1 = hd3[i];	
		delay(10000);
	}
	P1  = 0;
	for(i = 3; i >=0; i--){
		P1 = hd3[i];
		delay(10000);
	}	
}
/*-------------------------------------*/
void test1(){
	P1_0 = P1_2 = P1_1 = P1_3 = P1_4 = P1_5 = P1_6 = P1_7 = 1;	//khoi tao port 1 =0		
		P1_3 = P1_4 = 0;	delay(100000);
		P1_2 = P1_5 = 0;	delay(100000);
		P1_1 = P1_6 = 0;	delay(100000);
		P1_0 = P1_7 = 0;	delay(100000);
}
/*-------------------------------------*/
void blink(){
		P1 = 0x00;
		delay(10000);
		P1 = 0xff;
		delay(100000);	
}
/*-------------------------------------*/

void main(){	//chuong trinh chinh
	while(1){
		//test();
		//ledTraiPhai();
		//giuTraiPhai();
		//test1();
	
		blink();
		blink();
		hieuUng1();
		hieuUng2();
		hieuUng3();
		hieuUng2();
		hieuUng2();
	}
}
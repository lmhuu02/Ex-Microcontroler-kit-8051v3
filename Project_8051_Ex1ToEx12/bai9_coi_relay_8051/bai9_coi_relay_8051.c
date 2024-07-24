/*
DO AN TOT NGHIEP: KIT 8051 V3.
NAME: CONTROL RELAY AND WHISTEL BY BUTTON in chip 8051.
TIME: 2/2023	- ICTU.
*/
/*---------------------------INCLUDE AND DEFINE-----------------------------------*/
#include <REGX51.H>
#include <lcd16x2.h>

//ngat ngoai 0 1: P3_2, P3_3
#define RELAY P1_0
// Chan dieu khien COI CHIP ----------------------
#define COI P1_3

/*------------------------------- FUNCTION-------------------------------*/
//ham delay timer 0 cd 1
void delay_ms1(unsigned int time){
	while(time--){
		TMOD = 0x01; 	//timer 0 che do 1
		TH0 = 	0xfc;
		TL0 =	0x18;
		TR0 = 1;
		while(!TF0){};
		TR0 =	0;
		TF0 = 0;
	}
}

//ham ngat dao bat led chan p1.3
void ngatngoai0() interrupt 0{	//vecto ngat 0: ngat ngoai 0. chan P3_2. INT0. IT0
	COI = ~ COI;
}

//ham ngat dao bat led chan p1.3
void ngatngoai1() interrupt 2{	//vecto ngat 0: ngat ngoai 0. chan P3_2. INT0. IT0
	RELAY = ~ RELAY;
}

/*-------------------------------MAIN FUNCTION-------------------------------*/
void main(){
	
	/*------------INIT INTERRUPT REGISTER---------*/
	RELAY = COI = 0; //npn b muc 1 bat.
	EX0 = 1;	//chon che do ngat: ngat ngoai 0
	EX1 = 1;
	EA = 1;	//bat thanh ghi ngat
	IT0 = 1; 	//ngat theo suon. (IT0 = 0 --> ngat theo muc). mac dinh la ngat theo muc
	
	/*-----------------INIT AND SHOW LCD16X2---------------*/
	lcd1602_init();
	lcd1602_clear();
	lcd1602_gotoxy(0,0);
	lcd1602_puts(" DO AN TOT NGHIEP");
	lcd1602_gotoxy(0,1);
	delay_ms(3000);
	lcd1602_puts("  KIT 8051 V3");
	delay_ms(2000);
	lcd1602_clear();
	lcd1602_gotoxy(0,0);
	lcd1602_puts("TEST RELAY COI");
	while(1){
		P1_4 = P1_5 = P1_6  = 0x00;	//bat led cong p2
		P2 = 0x00;
		delay_ms1(700);
		P1_4 = P1_5 = P1_6 = 0xff;	//tat led cong p2
		delay_ms1(700);
		P2 = 0xff;
	}
}
//power by le minh huu 6/3/2022
//NGAT NGOAI DIEU KHIEN LED
//=======================================================
//NGAT NGOAI 0 DIEU KHIEN LED THEO MUC: IT0 = 0;
//ngat ngoai 1 cung tuong tu nhu ngat ngoai 0 chi khac vecto ngat, che do ngat, chan ngat
/*
#include <REGX52.H>

//ham delay timer 0 cd 1
void delay_ms(unsigned int time){
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
	long time = 50000;
	P1_3 = 0;
	while(time--){};
	P1_3 = 1;
}

void main(){
	EX0 = 1;	//chon che do ngat: ngat ngoai 0
	EA = 1;	//bat thanh ghi ngat
	IT0 = 0; 	//ngat theo muc. (IT0 = 1 --> ngat theo suon). mac dinh la ngat theo muc
	while(1){
		P2 = 0;	//bat led cong p2
		delay_ms(700);
		P2 = 0xff;	//tat led cong p2
		delay_ms(700);
	}
}
*/
//NGAT THEO MUC KHI GIU TRANG THAI THI VAN SE THUC HIEN CHUONG TRINH NGAT CHO DEN KHI KHONG GIU
//NGAT THEO SUON SE CHI THUC HIEN LENH NGAT MOT LAN DUY NHAT KHI NHAN VA SE QUAY LAI CHUONG TRINH CHINH

//=======================================================
//NGAT NGOAI 0 DIEU KHIEN LED THEO SUON: IT0 = 0; --> chi khac theo muc la IT = 1
//THEO MUC IT = 0
//THEO SUON IT = 1;



#include <REGX52.H>

//ham delay timer 0 cd 1
void delay_ms(unsigned int time){
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
	long time = 50000;
	P1_3 = 0;
	while(time--){};
	P1_3 = 1;
}

void main(){
	EX0 = 1;	//chon che do ngat: ngat ngoai 0
	EA = 1;	//bat thanh ghi ngat
	IT0 = 1; 	//ngat theo suon. (IT0 = 0 --> ngat theo muc). mac dinh la ngat theo muc
	while(1){
		P2 = 0;	//bat led cong p2
		delay_ms(700);
		P2 = 0xff;	//tat led cong p2
		delay_ms(700);
	}
}
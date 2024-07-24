//power by le minh huu 11/3/2022 @copyright
//viet chuong trinh led cong P2 sang 1s va tat 1s, khi co ngat ngoai 0 chan P3_2 thi bat led P1_0
#include <REGX52.H>

sbit button = P3^2;	//khai bao button = chan ngat
bit state;

char so[]= {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09};	//dem so the dau vao la ma bcd
int dem, i;

//ham tre dung timer vi can thoi gian chinh xac. taxl = 12mhz, thoi gian tre 1ms, timer 0 che do 1
void delay(int time){
	while(time--){
		TMOD = 0x01; 	//timer 0 che do 1
		TH0 = 0xfc;		//tre trong 1 ms
		TL0 = 0x18;
		TR0 = 1;
		while(!TF0){}
		TR0 = 0;
		TF0 = 0;
	}
}

//khai bao ngat ngoai
void ngatngoai() interrupt 0{	//ngat ngoai 0 thu tu 0
	long a = 1000, b = 60;
	P0_0 = 0;
	//kiem tra ngat va tang so dem
	if(button == 0){
		while(button == 0){}	//cho den khi nao nut bam chuyen len muc 1
			dem++;
			if(dem == 10) {dem = 0;}	//neu dem = 10 thi quay lai 1
	}
	while(a--);
	P0_0 = 1;
}

void main(){
	EX0 = 1; //cho phep ngat ngoai 0 chan P3_2. INT0
	EA = 1;	//bat thanh ghi ngat
	IT0 = 0; //ngat theo muc
	TR0 = 1;	//khoi dong bo dinh thoi
	while(1){
		P2 = ~P2;
		delay(1000);	//do dau bai yeu cau thoi gian chinh xac nen can dung timer de dem thoi gian
		P1 = so[dem];
	}
}
//ngat ngoai INTERRUPT dieu khien 8 led cong P2 nhay
//power by le minh huu 18/3/2022
#include <REGX52.H>

void delay(unsigned int time){
	while(time--);
}

void ngatNgoai0() interrupt 0{
	unsigned int a = 10000;
	P2 = 0;
	while(a--){}
		P2 = 0xff;
}

void main(){
	IE = 0x82; 	// EA _ _ ES EX1 ET1 EX0 ET0 --> 1 0 0 0   0 0 1 0
	IT0 = 0; 		// ngat theo muc. mac dinh la theo muc. --> khi ngat lien tuc thi se thuc hien chuyen doi lien tuc
	//IT0 = 1; 		// ngat theo suong	--> khi giu trang thai ngat thi ngat chi thuc hien 1 lan duy nhat
	while(1){}
}

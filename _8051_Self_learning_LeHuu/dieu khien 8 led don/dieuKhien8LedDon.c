//POWER BY LE MINH HUU
//3/1/2022
//lap trinh 8 led don tao hieu ung
//co the khai bao sbit = led1 thay cho P2_0, no tuong tu nhau.
// dung vong for de xac dinh chinh xac so lan lap
//tao ham delay bang cach cho vong while chay tu time den 0 se ket thuc
#include <REGX52.H>

void delay(int time){
    while(time){
        time--;
    }
}

void traiPhai(int lan){
	int i;	
	for(i = 0; i < lan; i++){
    P2_0 = 0; delay(9000);	
    P2_1 = 0; delay(9000);
    P2_2 = 0; delay(8000);
    P2_3 = 0; delay(8000);
    P2_4 = 0; delay(7000);
    P2_5 = 0; delay(7000);
    P2_6 = 0; delay(6000);
    P2_7 = 0; delay(5000);
		//khi cho led sang het o muc 0 thi se chuyen led ve trang thai tat o muc 1
		//led hoat dong tich cuc o muc nao la do cach lap led tren mach cung
    P2_0 = P2_1 = P2_2 = P2_3 = P2_4 = P2_5 = P2_6 = P2_7 = 1;
    delay(10000);
	}
}

void phaiTrai(int lan){
	int i;
	for(i = 0; i < lan; i++){
    P2_7 = 0; delay(9000);
    P2_6 = 0; delay(9000);
    P2_5 = 0; delay(8000);
    P2_4 = 0; delay(8000);
    P2_3 = 0; delay(7000);
    P2_2 = 0; delay(7000);
    P2_1 = 0; delay(6000);
    P2_0 = 0; delay(6000);
    P2_0 = P2_1 = P2_2 = P2_3 = P2_4 = P2_5 = P2_6 = P2_7 = 1;
    delay(9000); 
	}
}

void giuaHaiBen(int lan){
	int i;
	for(i = 0; i < lan; i++){
    P2_4 = P2_3 = 0; delay(9000);
    P2_5 = P2_2 = 0; delay(9000);
    P2_6 = P2_1 = 0; delay(8000);
    P2_7 = P2_0 = 0; delay(8000);
    P2_0 = P2_1 = P2_2 = P2_3 = P2_4 = P2_5 = P2_6 = P2_7 = 1;
    delay(9000); 
	}
}

void haiBenGiua(int lan){
	int i;
	for(i = 0; i < lan; i++){
    P2_7 = P2_0 = 0; delay(8000);
    P2_6 = P2_1 = 0; delay(8000);
    P2_5 = P2_2 = 0; delay(9000);	
    P2_4 = P2_3 = 0; delay(9000);
    P2_0 = P2_1 = P2_2 = P2_3 = P2_4 = P2_5 = P2_6 = P2_7 = 1;
    delay(9000); 
	}
}

void donTraiPhai(int lan){
		//trai phai
	int i;
	for(i = 0; i < lan; i++){
		P2_0 = 0; delay(10000);
		P2_0 = 1; delay(9000);
		P2_1 = 0; delay(9000);
		P2_1 = 1; delay(8000);
		P2_2 = 0; delay(8000);
		P2_2 = 1; delay(8000);
		P2_3 = 0; delay(8000);
		P2_3 = 1; delay(7000);
		P2_4 = 0; delay(7000);
		P2_4 = 1; delay(7000);
		P2_5 = 0; delay(7000);
		P2_5 = 1; delay(7000);
		P2_6 = 0; delay(7000);
		P2_6 = 1; delay(7000);
		P2_7 = 0; delay(7000);
		P2_7 = 1; delay(6000);
	}
//power by Le Minh Huu
}

void donPhaiTrai(int lan){
	//phai trai
	int i;
	for(i = 0; i < lan; i++){
		P2_7 = 0; delay(6000);
		P2_7 = 1; delay(6000);
		P2_6 = 0; delay(7000);
		P2_6 = 1; delay(7000);	
		P2_5 = 0; delay(7000);
		P2_5 = 1; delay(7000);
		P2_4 = 0; delay(8000);
		P2_4 = 1; delay(8000);
		P2_3 = 0; delay(8000);
		P2_3 = 1; delay(8000);
		P2_2 = 0; delay(8000);
		P2_2 = 1; delay(9000);
		P2_1 = 0; delay(9000);
		P2_1 = 1; delay(9000);		
		P2_0 = 0; delay(9000);
		P2_0 = 1; delay(9000);
	}
}

void xemKe(int lan){
	int i;
	for(i = 0; i < lan; i++){
		P2_0 = P2_2 = 0; delay(9000);
    P2_1 = P2_3 = 0; delay(9000);
    P2_4 = P2_6 = 0; delay(8000);
    P2_5 = P2_7 = 0; delay(8000);
    P2_0 = P2_1 = P2_2 = P2_3 = P2_4 = P2_5 = P2_6 = P2_7 = 1;
    delay(9000);
	}
}

void main(){
    while(1){
			donTraiPhai(2);	delay(10000);
			donPhaiTrai(2);	delay(10000);
      traiPhai(3);		delay(10000);
			phaiTrai(3);		delay(10000);
			giuaHaiBen(3);	delay(10000);
			haiBenGiua(3);	delay(10000);
			xemKe(2); delay(10000);
    }
}


/*
POWER BY LE MINH HUU
3/1/2022
khong the noi truc tiep nguon dien 5v tu vi dieu khien 8051 cho relay duoc vi:
						relay can nguon cong suat lon hon nhieu so voi cong suat cua vdk cung cap
					vi the vdk se chi cap tin hieu co transistor pnp de noi voi mot nguon dien khac.
					NOTE: co the dung transistor npn cap nguon cho relay NEU vdk hoat dong tich cuc o muc cao (khong an toan).
					de chuan hon thi phai noi button vao chan ngat ngoai INT0 hoac ngat ngoai INT1: P3_2, p3_3 ==> NGAT THEO SUON
*/
//DAY LA KIEU NGAT THEO MUC
#include <REGX52.H>

void delay(int time){
    while(time--);
}

void main(){
    while(1){
        if(P1_4 == 0){	//nhan button
            delay(100);	//delay de tao do on dinh, kiem tra xem co thuc su nhan button khong
            if(P1_4 == 0);
							P2_0 = ~P2_0;	//dao chieu tin hieu dau noi ra relay
        }
    }
}
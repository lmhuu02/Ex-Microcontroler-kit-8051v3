#include <REGX51.h>

void delay(int time){	//nhap thoi gian 
	while(time--);	//giam dan thoi gian
}
//CHUONG TRINH THU 2, COI NHU DAU TIEN CUA LE MINH HUU. NGAY 30/10/2021. LUC 12H30 SINH NHAT.
//============================================
//chay tu trai sang phai
void traiSangPhai(int soLan){
	int i;
	for(i = 0; i < soLan; i++){
		P2_0 = 0;	delay(10000); P2_0 = 1;
		P2_1 = 0;	delay(10000); P2_1 = 1;
		P2_2 = 0;	delay(10000); P2_2 = 1;
		P2_3 = 0;	delay(10000); P2_3 = 1;
		P2_4 = 0;	delay(10000); P2_4 = 1;
		P2_5 = 0;	delay(10000); P2_5 = 1;
		P2_6 = 0;	delay(10000); P2_6 = 1;
		P2_7 = 0;	delay(10000); P2_7 = 1;
	}
}
//============================================
//chay tu phai sang trai
void phaiSangTrai(int soLan){
	int i;
	for(i = 0; i < soLan; i++){
		P2_7 = 0;	delay(10000); P2_7 = 1;
		P2_6 = 0;	delay(10000); P2_6 = 1;
		P2_5 = 0;	delay(10000); P2_5 = 1;
		P2_4 = 0;	delay(10000); P2_4 = 1;
		P2_3 = 0;	delay(10000); P2_3 = 1;
		P2_2 = 0;	delay(10000); P2_2 = 1;
		P2_1 = 0;	delay(10000); P2_1 = 1;
		P2_0 = 0;	delay(10000); P2_0 = 1;
	}
}
//============================================
void nhayToanBo(int soLan){
	int i;
	for(i = 0; i < soLan; i++){
		P2_0 = P2_1 = P2_2 = P2_3 = P2_4 = P2_5 = P2_6 = P2_7 = 0;
		delay(5500);
		P2_0 = P2_1 = P2_2 = P2_3 = P2_4 = P2_5 = P2_6 = P2_7 = 0;
	}
}
//============================================
void nhayTangDanTocDo(int soLan){
		int i, j;
		for(i = 0; i < soLan; i++){
			j = 15000;
			while(j > 0){
				delay(j);
				P2_0 = P2_1 = P2_2 = P2_3 = P2_4 = P2_5 = P2_6 = P2_7 = 0;
				delay(j);
				P2_0 = P2_1 = P2_2 = P2_3 = P2_4 = P2_5 = P2_6 = P2_7 = 1;
				j = j - 1000;
			}
		}
}
//============================================
void sangTrongRaNgoai(int soLan){
	int i;
	for(i = 0; i < soLan; i++){
		P2_3 = P2_4 = 0;
		delay(10000);
		P2_3 = P2_4 = 1;
		P2_2 = P2_5 = 0;
		delay(10000);
		P2_2 = P2_5 = 1;
		P2_1 = P2_6 = 0;
		delay(10000);
		P2_1 = P2_6 = 1;
		P2_0 = P2_7 = 0;
		delay(10000);
		P2_0 = P2_7 = 1;
		delay(10000);
	}
}
//============================================
void sangNgoaiVaoTrong(int soLan){
int i;
	for(i = 0; i < soLan; i++){
		P2_0 = P2_7 = 0;
		delay(10000);
		P2_0 = P2_7 = 1;
		delay(10000);
		P2_1 = P2_6 = 0;
		delay(10000);
		P2_1 = P2_6 = 1;
		P2_2 = P2_5 = 0;
		delay(10000);
		P2_2 = P2_5 = 1;
		P2_3 = P2_4 = 0;
		delay(10000);
		P2_3 = P2_4 = 1;
		delay(10000);

	}
}
//============================================
void main(){
	while(1){		//tao 1 vong lap luon dung de vi dieu khien co the thuc hien lap lai lien tuc
		nhayTangDanTocDo(3);
		sangTrongRaNgoai(10);
		sangNgoaiVaoTrong(10);
		nhayToanBo(3);
		traiSangPhai(3);
		phaiSangTrai(4);
	}
	
}
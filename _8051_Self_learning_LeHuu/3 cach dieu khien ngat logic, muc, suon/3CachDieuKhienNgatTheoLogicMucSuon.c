//POWER BY LE MINH HUU - 14/1/2022
//DIEU KHIEN BAT TAT BANG CONG TAC TRONG VDK 

/*
//dieu khien ngat theo kieu logic ngat theo muc
//neu dieu khien kieu nay thi se bi doi phim ==> KHONG NEN DUNG CACH NAY DE DIEU KHIEN NUT BAM
#include <REGX52.H>

sbit led = P2^4;	//khai bao can P2.4 la led

void delay(int time){	//ham tao tre don gian
	while(time--);
}

void main(){
	led = 1;	//ban dau khoi tao led = 1 ==> led tat vi vdk hoat dong tich cuc o muc 0
	while(1){
			if(P1_4 == 0){	//khiem tra neu nhan nut thi thuc hien
				delay(120);		//delay 1 khoang thoi gian ngan
				if(P1_4 == 0){	//sau khoang thoi gian delay ma van thay nhan nut thi thuc hien
					P1_7 = ~ P1_7;	//doi chieu hien co cua chan p1.7
					led = ~ led;		//doi chieu cua chan led (p1.4)
				}
			}
			delay(200);
	}
}
*/


/*
//dieu khien ngat theo kieu vong lap while ngat 
//han che duoc viec bi doi phim lam loan chuong trinh
//co the dung de dieu khien duoc

#include <REGX52.H>

//khai bao cac chan cua vdk, co the dung truc tiep chan  vd: p1_4, P1_7,...
sbit button = P1^4;
sbit led = P2^3;
sbit relay = P1^7;

//ham tao tre don gian
void delay(int time){	
	while(time--);
}

void main(){
	led = 1;		//gan cho led = 1 ==> khong sang vi vdk hoat dong tich cuc muc 0
	relay = 1;	//gan cho relay = 1 ==> khong sang vi vdk hoat dong tich cuc muc 0, muc thap
	while(1){
		if(button == 0){	//khi nhan cong tac thi thuc hien
			while(button == 0){}	//vi vong while se lap lai khi dieu kien dung. ma dieu kien la button == 0 ==> se thuc hien vong lap ({}: la khong lam gi ca) cho den khi khong nhan nua, khac phuc duoc tinh trang giu nut bam lam loan chuong trinh nhu cach bam o tren
				led = ~led;		//khi tha nut bam thi se thuc hien dao chieu led
				relay = !relay;	//khi tha nut bam thi se thuc hien dao chieu led
		}
	}
}
*/

//dieu khien cong tac theo suon
//NOTE: NEN DUNG CACH NAY HOAC CACH TREN, KHONG NEN DUNG CACH DAU TIEN

#include <REGX52.H>

//khai bao cac chan cua vdk, co the dung truc tiep chan  vd: p1_4, P1_7,...
sbit button = P1^4;
sbit led = P2^3;
sbit relay = P1^7;
bit button_state; //khai bao, button: la nut bam, state: la trang thai

//ham tao tre don gian
void delay(int time){	
	while(time--);
}

void main(){
	led = 1;		//gan cho led = 1 ==> khong sang vi vdk hoat dong tich cuc muc 0
	relay = 1;	//gan cho relay = 1 ==> khong sang vi vdk hoat dong tich cuc muc 0, muc thap
	while(1){		//van nhu binh thuong lap di lap lai
		if(button == 0){	//neu nut button (chan P1_4) duoc bam thi se thuc hien trong nhay kep khong thi se chuyen xuong lenh gan gia tri button_state = button ma button la chan P1_4 luon duoc treo len dien ap cao tuong duong voi muc 1 (luc khong duoc nhan)
			delay(100);
			if(button == 0 && button_state == 1){	//kiem tra neu button duoc nhan (button = 0) VA DONG THOI gia tri button_state = 1 thi moi thuc hien dao chieu. TUC LA so sanh 2 gia tri cua nut bam luc truoc sau voi hien tai: binh thuong nut bam se luon  = 1 nhung khi bam se bang =0, ==> so sanh trang thai dang bam neu = 0 va dong thoi trang thai cua button_state = 1 thi moi THOA MAN DIEU KIEN. tom lai: SO SANH NUT KHI DANG BAM = 0 VA TRANG THAI LUC TRUOC HOAC SAU = 1 THI MOI THUC HIEN DAO CHIEU
				led = !led;		//dao chieu led va relay
				relay = ~relay;
				//neu muon chuyen doi trang thai led, bam 1 lan duy nhat led sang 1 LAN DUY NHAT DU BAM NHIEU LAn thi o day gan cho led = 0; ==> chi 1 lan nhan thi se gan mai mai gia tri cua led = 0 --> led sang
			}
		}
		button_state = button;	//gan gia tri cua button_state = gia tri cua button luon = 1, = muc cao (tru truong hop dang bam nut)
		delay(100);
	}
}

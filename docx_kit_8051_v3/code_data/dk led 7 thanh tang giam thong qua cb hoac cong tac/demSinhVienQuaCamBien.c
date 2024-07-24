//power by le minh huu 18/2/2022 @copyright
//lap trinh dem so sinh vien trong lop hoc, cong vao thi tang, cong ra thi giam so dem
/*

*/
#include <REGX52.H>

//gan chan p1_0 cho button 1 va P1_2 cho button 2
#define button1 P1_0	//tang
#define button2 P1_2	//giam

//khai bao va khoi tao mang
char Chuc[] = {0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x07,0x08,0x09};
char DonVi[] ={0x00,0x10,0x20,0x30,0x40,0x50,0x60,0x70,0x80,0x90};
int state1, state2, i, j, ch, dv;

//ham delay
void delay(int time){
	while(time--);
}

void main(){
	//gan gia tri ban dau i = 0, tat cac led
	P2 = 1; 	i = 0;
	button1 = button2 = 1;
	while(1){
		//cho vong for chay tu 0 den 99 lien tuc, bien chay khac voi bien chia don vi va chuc
     for(j = 0; j < 100; j++){
				//khi co sinh vien vao thi tang len 1 (nhan cong tac 1)
				if(button1 ==0){
					delay(100);
					if(button1 == 0 && state1 ==1){
						j = i; i++;	//gan bien chay cho bien chia don vi chuc, //xac nhan nut bam 1 thi tang bien i len
					}
				}
				state1 = button1;
			//khi co sinh vien ra ngoai giam di 1: (nhan cong tac 2) 
					if(button2 == 0){
						delay(100);
							if(button2 == 0 && state2 ==1){
								j = i; i--;	//gan bien chay cho i	//giam i di 1 don vi            
							}
					state2 = button2;
					}
        }
				//thuc hien hien thi so ra led 7 thanh, 
				//khong de hien thi trong luc kiem tra dieu kien vi luc day: chi khi cong tac duoc nhan thi led 7 thanh moi hien
    ch=i/10; dv=i%10;		
		P2=Chuc[ch]+DonVi[dv];delay(100);
	}
}


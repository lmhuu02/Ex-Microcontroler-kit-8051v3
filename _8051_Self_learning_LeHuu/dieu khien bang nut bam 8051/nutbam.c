#include <REGX52.H>

int dem;

void delay(int time){
while(time--);
}

void main(){
	P1_5 = P1_6 = 1; //tat den
	//dem = 0;
	while(1){	
		//delay(100);
		//bam 3 nut dieu khien 2 led
		/*
			if(P1_0 == 0){
				P1_5 = 0; //den 1 sang
			}
			if(P1_2 == 0){
				P1_6 = 0;
			}
			if(P1_4 == 0){
				P1_5 = P1_6 = 1; //tat den
			}
		*/
			//1 nut bam P1_1 dieu khien 2 led
		if(P1_1 ==0 ){
			delay(200);
			if(P1_1 == 0)dem++;
			if(dem >= 4)	dem = 0;
		}
			if(dem == 0)P1_7 = 0;
			if(dem == 1)P1_5 = 0;
			if(dem == 2)P1_6 = 0;
			if(dem == 3){
				P1_5 = P1_6 = P1_7 =1;
			}
			
	}
}
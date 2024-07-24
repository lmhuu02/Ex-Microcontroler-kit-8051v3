/*
POWER BY LE MINH HUU
3/1/2022
vdk 8051 hoat dong ich cuc o muc thap (muc 0)
de bai: 1 nut bam dieu khien 3 led, 
    bam lan 1 led 1 sang
    bam lan 2 led 2 sang
    bam lan 3 led 3 sang
    bam lan 4 ca 3 led tat
    bam lan 5 ca 3 led sang
    bam lan 6 nhap nhay bam lan 7 quay lai lan 1
*/
#include <REGX52.H>

void delay(int time){
    while(time--);
}

void nhayHieuUng(){
            P2_3 = 0; delay(9000);
            P2_3 = 1; delay(9000);

            P2_4 = 0; delay(9000);
            P2_4 = 1; delay(9000);

            P2_5 = 0; delay(9000);
            P2_5 = 1; delay(9000);

            P2_4 = 0; delay(9000);
            P2_4 = 1; delay(9000);

            P2_3 = P2_5 = 0; delay(9000);
            P2_3 = P2_5 = 1; delay(9000);

            P2_4 = P2_3 = 0; delay(9000);
            P2_4 = P2_3 = 1; delay(9000);

            P2_4 = P2_5 = 0; delay(9000);
            P2_4 = P2_5 = 1; delay(9000);
}

void main(){
    int dem = 0;
    P2_3 = P2_4 = P2_5 = 1;
    while(1){
       if(P1_5 == 0){
				delay(120);   //tao do tre khi bam nut, tranh nhieu
         if(P1_5 == 0){	//neu sau khoang tg delay(120) ma van nhan nut P1_5 thi se tang bien dem len
           dem++;
          }
       }
			 //Power by Le Minh Huu
			 // moi lan bam phai delay de cho he thong chay on dinh hon, vi se du ra mot khoang thoi gian
       //neu khong de delay thi khi nhan button se bi nhay cac led, led sang khong theo nut bam 
			 if(dem == 1){	//bam 1 lan
					P2_3 = 0;    //led cong p2.3 sang 
					P2_4 = P2_5 = 1;     //led cong 2.4 2.5 tat
       }
			 delay(5000);			//delay de co thoi gian phan hoi
       if(dem == 2){	//bam 2 lan
           P2_4 = 0;    //led 2.4 sang
           P2_3 = P2_5 = 1; //led 2.3 2.5 tat
       } 
			 delay(5000);
       if(dem == 3){	//bam 3 lan
           P2_5 = 0;    //led 2.5 bat
           P2_3 = P2_4 = 1; //led 2.3 2.4 tat
       }
			 delay(5000);
       if(dem == 4){	//bam 4 lan
           P2_4 = P2_3 = P2_5 = 1;  //ca 3 led tat
       }
			 delay(5000);
       if(dem == 5){	//bam 5 lan
             //P2_4 = P2_3 = P2_5 = 1;  //ca 3 led tat
          nhayHieuUng();	//goi ham nhay hieu ung
       }
			 delay(5000);
       if(dem == 6){	//bam 6 lan
           dem = 1;	//cho dem tro lai ban dau = 0
       }
			 delay(5000);
    }
}

//POWER BY LE MINH HUU - 10/2/2022
#include <REGX52.H>

#define sang 0;
#define tat 1;

//led 7 thanh chung annot
char so[] = {0x40, 0x79, 0x24, 0x30, 0x19, 0x12, 0x02, 0x78, 0x00, 0x10};
int i;

void delay(int time){
	while(time--);
}

void main(){
	P2 = tat;
	while(1){
		for(i = 0; i < 10; i++){
			P2 = so[i];	
			delay(100000);
		}
	}
}
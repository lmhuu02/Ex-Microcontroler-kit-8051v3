/*
power by Le Minh Huu 2k2 @copyright 18/5/2022
lap trinh dem cac so chan le lui tu 9 ve 0 ic 74ls47
*/
#include <REGX52.H>

char so[] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09};

void delay(int time){
while(time--){}
}
void demLeLui(){
int i;
	for(i = 9; i > 0; i--){
		if(i % 2 == 1){
			P2 = so[i]; delay(50000);
		}
	}
}
void demLeTien(){
int i;
	for(i = 0; i < 10; i++){
		if(i % 2 == 1){
			P2 = so[i]; delay(50000);
		}
	}
}
void main(){

	while(1){
		demLeLui();
		demLeTien();
	}
}
/**
  ******************************************************************************
  * Ten Tep		:		  MTP4x4.c
  * Tac Gia		:	  	LE ANH QUANG
  * Cong Ty		:			MinhHaGroup
  *	Website 	:			MinhHaGroup.com
  * Phien Ban	:			V1.0.0
  * Ngay			:    	19-9-2012
  * Tom Tat   :     Dinh nghia cach thuc su dung trong ham MTP4x4.
  *           
  *
  ******************************************************************************
  * Chu Y		:
  *							 
  ******************************************************************************
  */
	
#include <main.h>

// Ban phim trong mo phong protues
static unsigned char code KEYS_PAD[4][4] ={'3','2','1','0', 
																					'7','6','5','4', 
																					'B','A','9','8', 
																					'F','E','D','C'};   

unsigned char mtp_quetphim()
{	
	unsigned char r,c;
	P1=0x0f;																		
	delay_us(2);
	
	if((P1&0x0f)!=0x0f)										// Kiem tra xem co phim bat ky nao duoc bam hay khong?
	{	
		delay_us(100);											// Chong nhieu 
		if((P1&0x0f)!=0x0f)									// Neu dung có phim duoc bam: Bat dau qua trinh quet phim
		{
			for(c=0;c<4;c++)									// Quet theo cot
			{
				P1=~(0x01<<(4+c));							// Lan luot keo cac cot xuong muc logic 0
				delay_ms(1);
				for(r=0;r<4;r++)								// Kiem tra cac hang
				{
						if((P1&(0x01<<r))==0)				// Neu hang nao co muc logic 0
						{
							while((P1&0x0f)!=0x0f);		// Cho den khi nut bam duoc tha ra
							return KEYS_PAD[r][c];		// Tra ve ma phim da duoc bam
						}
				}
			}
		}
	}
	return 0;														// Neu khong co phim nao duoc nhan: Tra ve gia tri 0
}

// ------------------END OF FILE--------------------
// -------------------------------------------------


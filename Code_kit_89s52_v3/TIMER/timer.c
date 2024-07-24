#include "timer.h"
void delay_timer_500us(void)
{
		TL0=0x33;		
		TH0=0xfe;	
		TF0=0;
		TR0=1;
		while(!TF0);
		TR0=0;
		TF0=0;
}

void delay_timer_200us(void)
{
		TL0=0x48;		
		TH0=0xff;	
		TF0=0;
		TR0=1;
		while(!TF0);
		TR0=0;
		TF0=0;
}

void delay_timer_750us(void)
{
		TL0=0x4d;		
		TH0=0xfd;	
		TF0=0;
		TR0=1;
		while(!TF0);
		TR0=0;
		TF0=0;
}

uint8_t INFR_CheckStart()
{
	uint8_t i;
	if(INFR_DATA==0)             
    {
        delay_timer_500us();           
        if(INFR_DATA==0)         
        {       
            for(i=0;i<40;i++)   
            {
                delay_timer_200us();
                if(INFR_DATA==1) return 0;    
            } 
            while(INFR_DATA==1);               
          // return 1;            
        }  
				
    } 
		return 1;  
}


uint16_t INFR_GetCode(void)
{
		uint8_t i;
    uint16_t data_infr=0;
    if(INFR_CheckStart())             // Neu dung xung START
    {
        while(INFR_DATA==0);          // Cho het bit 0 tiep theo
        for(i=0;i<24;i++)             // Lay 24 bit du lieu (bao gom 8 bit 0 va 8 bit 1 dau tien sau xung start)
        {    
            delay_timer_750us();            // Delay 750us de kiem tra bit
            data_infr=data_infr<<1;
            if(INFR_DATA==0) data_infr|=1;
            while(INFR_DATA==1);      // cho canh len
            while(INFR_DATA==0);     
        }
        delay_ms(600);                // Cho het tin hieu (chong nhieu) 
    }
		return data_infr;
}


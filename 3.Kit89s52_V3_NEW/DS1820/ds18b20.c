/**
  ******************************************************************************
  * Ten Tep		:		  ds18b20.c
  * Tac Gia		:	  	LE ANH QUANG
  * Cong Ty		:			MinhHaGroup
  *	Website 	:			MinhHaGroup.com
  * Phien Ban	:			V1.0.0
  * Ngay			:    	20-09-2012
  * Tom Tat   :     Dinh nghia cac ham xu ly DS18b20
  *           
  *
  ******************************************************************************
  * Chu Y		:
  *							 
  ******************************************************************************
  */
	
#include <main.h>

static bit presence;
//-------------------------------------------------
// Ham khoi tao DS18b20
//-------------------------------------------------
bit DS18B20_Init()
{
     DQ = 1 ;      
     delay_us(8);   
     DQ = 0 ;     
     delay_us(90) ;   
     DQ = 1 ;       
     delay_us(8) ;
     presence = DQ ;    
     delay_us(100) ;
     DQ = 1 ;
     return(presence) ; 
}

//-------------------------------------------------
// Ham doc 1 byte tu DS18b20 ra ngoai
//-------------------------------------------------
unsigned char ds18b20_readbyte(void)
{
unsigned char i = 0 ;
unsigned char Data = 0 ;
for (i = 8 ; i > 0 ; i--)
  {
    DQ = 0 ;
    Data >>= 1 ;
    DQ = 1 ; 
    if(DQ)
     Data |= 0x80 ;
    delay_us(4) ;
  }
  return (Data) ;
}

//-------------------------------------------------
// Ham viet 1 byte vao DS18b20
//-------------------------------------------------
void ds18b20_writebyte(unsigned char Data)
{
  unsigned char i = 0 ;
  for (i = 8 ; i > 0 ; i--)
  {
    DQ = 0 ;
    DQ = Data&0x01 ;
    delay_us(5) ;
    DQ = 1 ;
    Data>>=1 ;
  }
}

//-------------------------------------------------
// Ham chuyen doi va tra ve gia tri nhiet do do duoc
//-------------------------------------------------
float ds18b20_readtemp(void)
{
			float temp;
			unsigned char a,b;
			DS18B20_Init();										// Khoi tao DS18b20
			ds18b20_writebyte(0xCC) ;  				// Cho phep VDK truy cap thang den cac lenh bo nho cua DS18b20
			ds18b20_writebyte(0x44) ; 				// Khoi dong qua trinh do va chuyen doi nhiet do ra so nhi phan
			DS18B20_Init() ;
			ds18b20_writebyte(0xCC) ;  
			ds18b20_writebyte(0xBE) ;					// Cho phep doc du lieu tu bo nho DS18b20 ra ngoai
	
			a = ds18b20_readbyte(); 
			temp=((float)(a&0x0f))/16;				// Lay phan thuc cua gia tri nhiet do
			b = ds18b20_readbyte(); 				
			a =((a&0xf0)>>4)|((b&0x0f)<<4) ;	// Lay phan nguyen cua gia tri nhiet do
			temp=temp+a;
			return temp;											// Tra ve gia tri nhiet do
}

// ------------------END OF FILE--------------------
// -------------------------------------------------

/**
  ******************************************************************************
  * Ten Tep		:		  main.h
  * Tac Gia		:	  	LE ANH QUANG
  * Cong Ty		:			MinhHaGroup
  *	Website 	:			MinhHaGroup.com
  * Phien Ban	:			V1.0.0
  * Ngay			:    	19-10-2012
  * Tom Tat   :     Chuong trinh chinh, thuc hien cac chuc nang cua KIT89s52 V3
  *           
  *
  ******************************************************************************
  * Chu Y		:
  *							 
  ******************************************************************************
  */
	

#include <main.h>	
#include <var.h>

void main()
{
	unsigned char hour,min,sec,date,month,year;
	i2c_init();
	EEP_24CXX_Init();
	lcd1602_init();
	lcd1602_clear();
	lcd1602_gotoxy(0,0);
	lcd1602_puts("  MINHHAGROUP");
	lcd1602_gotoxy(0,1);
	lcd1602_puts(" TEST KIT 89S52");
	EA=0;				//cam ngat
	ET0=0;
	COI = 0;
	RELAY=0;
while(1)
{
	KEY = mtp_quetphim();
	//KEY='F';
// AN BT1: TEST MA TRAN BAN PHIM ==============================================
	if(KEY=='0')	
	{
		lcd1602_init();
		lcd1602_clear();
		lcd1602_gotoxy(0,0);
		lcd1602_puts("TEST KEY MATRIX");
		lcd1602_gotoxy(0,1);
		while(1)
		{
			KEY = mtp_quetphim();
			if(KEY)
			{
				lcd1602_putchar(KEY);
			}
		}
	}
	
// AN BT2: TEST MA TRAN BAN PHIM ==============================================
if(KEY=='1')
{
	unsigned int k;
	sprintf(Lcd_Buff,"TEST SINGLE KEY");
	lcd1602_clear();
	lcd1602_gotoxy(0,0);
    lcd1602_puts(Lcd_Buff);
    while(1)
    {
        k=get_key();
        if(k)
        {
            sprintf(Lcd_Buff,"KEY=%2u",k);
            lcd1602_gotoxy(0,1);
            lcd1602_puts(Lcd_Buff);
        }
    }
}

// AN BT3: TEST LED DON ========================================================	
	if(KEY=='2')	// SW1: TEST LED DON
	{
		lcd1602_clear();
		lcd1602_gotoxy(0,0);
		lcd1602_puts("TEST LED DON");
		while(1)
		{
		for (i=0;i<8;i++)
		{
			LED_DON = ~(0x80>>i);
			delay_ms(300);
		}
		}
	}
	
// AN BT4: TEST LED7 THANH ======================================================	
	if(KEY=='3')	
	{
		lcd1602_clear();
		lcd1602_gotoxy(0,0);
		lcd1602_puts("TEST LED 7 THANH");
			while(1)
			{
			LED7_DATA=0;
			for (i=0;i<4;i++)
			{
				LED7_SEG= ~(0x10<<i);
				delay_ms(300);
			}
			for (i=0;i<4;i++)
			{
				LED7_SEG= ~(0x01<<i);
				delay_ms(300);
			}
			LED7_SEG=0;
			for (i=0;i<8;i++)
			{
				LED7_DATA= ~(0x01<<i);
				delay_ms(300);
			}
		    }
	}

// AN BT5: TEST COI CHIP & RELAY ================================================			
	if(KEY=='4')	
	{
		COI = 0;
		RELAY = 0;
		lcd1602_clear();
		lcd1602_gotoxy(0,0);
		lcd1602_puts("TEST COI-ROLE");
		while(1)
		{
			if(!KEY0)		// AN SW16
			{
				delay_ms(10);
				KEY0 = 1;
				if(!KEY0)
				{
					while(!KEY0);
					COI=~COI;
					RELAY =~RELAY ;
				}
			}
		}
	}
	
//  TEST DS18B20 =========================================================	
	if(KEY=='5')	
	{
		lcd1602_clear();
		lcd1602_gotoxy(0,0);
		lcd1602_puts("TEST DS18B20");
		while(1)
		{
			Nhiet_Do = ds18b20_readtemp();		
			sprintf(Lcd_Buff," TEMP: %2.2f^C",Nhiet_Do);
			lcd1602_gotoxy(0,1);
			lcd1602_puts(Lcd_Buff);
			delay_ms(300);
		}
	}
	


// TEST UART =============================================================			
	if(KEY=='6')	
	{
			UART_Init();
			lcd1602_clear();
			lcd1602_gotoxy(0,0);
			lcd1602_puts("TEST UART");
			EA=1;
			UART_Puts("banlinhkien.vn");
			
			while(1)
			{
			  Uart_char = UART_GetChar();
				if(Uart_char)
				{
				//UART_PutChar(Uart_char);
				lcd1602_gotoxy(0,1);
				lcd1602_puts("RECEIVER:");
				lcd1602_gotoxy(10,1);
				lcd1602_putchar(Uart_char);
				}
			}
	}
	
//=============================================================================		
	if(KEY=='7')	// TEST DS1307
	{ 	
		
		lcd1602_clear();
		lcd1602_gotoxy(0,0);
		lcd1602_puts("TEST DS1307");
		delay_ms(1000);
		lcd1602_clear();
		DS1307_Write(SEC,0);
		DS1307_Write(MIN,30);
		DS1307_Write(HOUR,9);
		DS1307_Write(DATE,22);
		DS1307_Write(MONTH,10);
		DS1307_Write(YEAR,14);
		while(1)
			{  
				hour=DS1307_get(HOUR);
				min=DS1307_get(MIN);
				sec=DS1307_get(SEC);
				date=DS1307_get(DATE);
				month=DS1307_get(MONTH);
				year=DS1307_get(YEAR);
				sprintf(Lcd_Buff,"%bu:%bu:%bu ",hour,min,sec);
				lcd1602_gotoxy(0,0);
				lcd1602_puts("TIME:");
				lcd1602_puts(Lcd_Buff);
				sprintf(Lcd_Buff,"DATE:%bu:%bu:20%bu ",date,month,year);
				lcd1602_gotoxy(0,1);
				lcd1602_puts(Lcd_Buff);
			}	
		}
		///////////////////////////
		//TEST EPPROM
		if(KEY=='8')	
		{
		lcd1602_clear();
		lcd1602_gotoxy(0,0);
		lcd1602_puts("TEST AT24C08");
		sprintf(Lcd_Buff,"banlinhkien.vn ");
		EEP_24CXX_WriteS(0x20,Lcd_Buff);
		delay_ms(10);
		EEPROM_24CXX_ReadS(0x20,14,Lcd_Buff);
		lcd1602_gotoxy(0,1);
		lcd1602_puts(Lcd_Buff);
		while(1)
			{
			}
		}
		//////////////////////////////////
		//TEST ADC
		if(KEY=='9')	
		{
		lcd1602_clear();
		lcd1602_gotoxy(0,0);
		lcd1602_puts("TEST ADC PCF8591");
		PCF8591_Init();
		while(1)
			{
			adc_value=PCF8591_Read(0);
			sprintf(Lcd_Buff,"ADC0= %bu  ",adc_value);
			lcd1602_gotoxy(0,1);
			lcd1602_puts(Lcd_Buff);
			delay_ms(300);
			}
		}
		//////////////////////////////////
		//TEST DAC
		if(KEY=='A')
			{
				lcd1602_clear();
				lcd1602_gotoxy(0,0);
				lcd1602_puts("TEST DAC PCF8591");
				PCF8591_Init();
				while(1)
					{
							if(!KEY1)		// AN KEY1
							{
								delay_ms(10);
								KEY1 = 1;
								if(!KEY1)
									{
									while(!KEY1);
									dac_value+=5;
									PCF8591_Write(dac_value);
									}
							}
					}
				}
		//////////////////////////////////
		//DO NHIET DO BANG LM35		
		if(KEY=='B')
			{
				lcd1602_clear();
				lcd1602_gotoxy(0,0);
				lcd1602_puts("TEST LM35");
				PCF8591_Init();
				while(1)
					{
						adc_value=PCF8591_Read(1);
						value_lm35=(float)adc_value*5000;
						value_lm35=(float)value_lm35/2550;
						sprintf(Lcd_Buff,"Temp= %.2f  ",value_lm35);
						lcd1602_gotoxy(0,1);
						lcd1602_puts(Lcd_Buff);
						delay_ms(300);
					}
				}
			//////////////////////////////////
		 //TEST IR
			if(KEY=='C')
			{
				lcd1602_clear();
				lcd1602_gotoxy(0,0);
				lcd1602_puts("TEST IR");
				TMOD=0x01;	//Timer0, che do 1
				while(1)
					{
						Code=INFR_GetCode(); 
						if(Code)
							{
								sprintf(Lcd_Buff,"Ma Phim: %lu ",Code);
								lcd1602_gotoxy(0,1);
								lcd1602_puts(Lcd_Buff);
							}
					}
				}
			//////////////////////////////////
		 //DO TAN SO 	
			if(KEY=='D')
				{
				lcd1602_clear();
				lcd1602_gotoxy(0,0);
				lcd1602_puts("DO TAN SO");
				TMOD=0x01;
				EA=1;
				ET0=1;
				while(1)
					{
					TH0 = 0;
					TL0 = 0;
		
					while(INT0);	// Bo qua muc 1 dau tien
					while(!INT0);   // Bo qua muc 0
					TR0 = 1;
					while(INT0);
					TR0 = 0;

					t = TH0;
					t <<= 8;
					t |= TL0;
					t=t+value_timer0;
					value_timer0=0;
					t*=2;	
					f=(float)1000000/t;
					sprintf(Lcd_Buff,"F=%.2f Hz",f);
					lcd1602_gotoxy(0,1);
					lcd1602_puts(Lcd_Buff);
					delay_ms(500);
					}
				}
			
		
}
}
void ngat_timer_0	() interrupt 1
{
	value_timer0+=0xffff;
}

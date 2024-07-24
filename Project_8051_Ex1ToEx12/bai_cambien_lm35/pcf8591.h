
//define cho I2C
#define PCF_I2C_DELAY      2

#define	PCF_SCL		P1_5
#define	PCF_SDA		P1_6

typedef   unsigned         char uint8_t;
uint8_t adc_value, dac_value=0;
unsigned  char Lcd_Buff[16];//,str[16];	// LCD1602
float value_lm35;

//khai bao cho i2c
void PCF_I2C_Delay(unsigned int time);
void PCF_i2c_init();
void PCF_I2C_Start();
void PCF_I2C_Stop();
unsigned char PCF_i2c_checkack(void);
void PCF_i2c_write(unsigned char Data);
unsigned char PCF_i2c_read(void);
void delay_ms(unsigned int Time);
void delay_us(unsigned int Time);

void delay_ms(unsigned int Time)
{
	unsigned int i,j,t;
	t=Time;
	for(i=0;i<t;i++)
	{
		for(j=0;j<125;j++);
	}
}
void delay_us(unsigned int Time)
{
	unsigned int i,j;
	for(i=0;i<Time;i++)
	{
		for(j=0;j<2;j++);
	}
} 



//ham su dung cho i2c
void PCF_I2C_Delay(unsigned int time)
{
   while(time)
   time--;
}
void PCF_i2c_init()
{
   PCF_SCL=1;
   PCF_I2C_Delay(PCF_I2C_DELAY);
   PCF_SDA=1;
   PCF_I2C_Delay(PCF_I2C_DELAY);
}
void PCF_I2C_Start()
{
		 PCF_SDA=1; 
     PCF_SCL=1; 
     PCF_I2C_Delay(PCF_I2C_DELAY);
     PCF_SDA=0; 
     PCF_I2C_Delay(PCF_I2C_DELAY);
     PCF_SCL=0;
     PCF_I2C_Delay(PCF_I2C_DELAY);
}
void PCF_I2C_Stop()
{   
		 PCF_SDA=0;
     PCF_SCL=1;
     PCF_I2C_Delay(PCF_I2C_DELAY);
     PCF_SDA=1;
     PCF_I2C_Delay(PCF_I2C_DELAY);
     PCF_SCL=0;
     PCF_I2C_Delay(PCF_I2C_DELAY);
}
unsigned char PCF_i2c_checkack(void)
{
   unsigned char ack=0;
     PCF_SDA=1;
     PCF_SCL=1;
     PCF_I2C_Delay(PCF_I2C_DELAY/2);
     ack=PCF_SDA;
     PCF_I2C_Delay(PCF_I2C_DELAY/2);
     PCF_SCL=0;
     PCF_I2C_Delay(PCF_I2C_DELAY);
     if(ack==1) return 0; 
     return 1;
}
void PCF_i2c_write(unsigned char Data)
{
unsigned char i;
     for(i=0;i<8;i++)
    {
      PCF_SDA=((Data<<i)&0x80);
      PCF_SCL=1;
      PCF_I2C_Delay(PCF_I2C_DELAY);
      PCF_SCL=0;
      PCF_I2C_Delay(PCF_I2C_DELAY);
   }
}
unsigned char PCF_i2c_read(void)
{
     unsigned char I2C_data=0,i,temp;
     for(i=0;i<8;i++)
    {
       PCF_SDA=1;    
        PCF_SCL=1;    
         PCF_I2C_Delay(120);
         temp=PCF_SDA;
         PCF_I2C_Delay(120);
         PCF_SCL=0;
         if(temp==1)
          {
            I2C_data=I2C_data<<1;
            I2C_data=I2C_data|0x01;
          }
         else
           I2C_data=I2C_data<<1;
    }
    return I2C_data;
}
//////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////

//ham su dung cho PCF8591
void PCF8591_Init(void)
{
	bit Ack_Temp=1;
	PCF_I2C_Start();
	delay_ms(20);
  PCF_i2c_write(0x90);//byte dia chi,che do ghi
	Ack_Temp=PCF_i2c_checkack();
	delay_ms(20);
  PCF_i2c_write(0x40);//byte control,cho phep DA hoat dong,AD o che do 0,kenh 0 
	Ack_Temp=PCF_i2c_checkack();
	delay_ms(20);	
	PCF_I2C_Stop();
}
uint8_t PCF8591_Read(uint8_t chanel)
{
	uint8_t Data;
	bit Ack_Temp=1;
	PCF_I2C_Start();	
	delay_ms(10);
	
	PCF_I2C_Start();
	delay_ms(20);
  PCF_i2c_write(0x90);//byte dia chi,che do ghi
	Ack_Temp=PCF_i2c_checkack();
	delay_ms(20);
  PCF_i2c_write(0x40|chanel);//byte control,cho phep DA hoat dong,AD o che do 0,kenh 0 
	Ack_Temp=PCF_i2c_checkack();
	delay_ms(20);	
	PCF_I2C_Stop();
	
	PCF_I2C_Start();	
	delay_ms(10);
	
	PCF_i2c_write(0x91); //byte dia chi,che do doc
	Ack_Temp=PCF_i2c_checkack(); 
	Data=PCF_i2c_read();
	delay_ms(10);
	PCF_I2C_Stop();
	return Data;
	
}
void PCF8591_Write(uint8_t DA)
{
	bit Ack_Temp=1;
	PCF_I2C_Start();
	delay_ms(10);
  PCF_i2c_write(0x90);//byte dia chi
	Ack_Temp=PCF_i2c_checkack();
	delay_ms(10);
  PCF_i2c_write(0x40);//byte control  
	Ack_Temp=PCF_i2c_checkack();
	delay_ms(10);		
	PCF_i2c_write(DA);//byte du lieu
	Ack_Temp=PCF_i2c_checkack();
	delay_ms(10);	
	PCF_I2C_Stop();
}

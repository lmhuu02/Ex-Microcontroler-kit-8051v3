

/*---------------------------DEFINE ------------------------*/
//define cho I2C
#define I2C_DELAY      2

#define	SCL		P3_3
#define	SDA		P3_2

void I2C_Delay(unsigned int time);
void i2c_init();
void I2C_Start();
void I2C_Stop();
unsigned char i2c_checkack(void);
void i2c_write(unsigned char Data);
unsigned char i2c_read(void);
////////////////////////////////////////////////////////

////define cho ds1307
#define     DS1307_ID 0xD0   
#define     SEC 0x00
#define     MIN 0x01   
#define     HOUR 0x02
#define     DATE 0x04
#define     MONTH 0x05
#define     YEAR 0x06



unsigned char DS1307_get(unsigned char addr) ;
void DS1307_Write(unsigned char addr,unsigned char dat);

/*---------------------------FUNCTION CODE------------------------------*/


//ham su dung cho i2c
void I2C_Delay(unsigned int time)
{
   while(time)
   time--;
}
void i2c_init()
{
   SCL=1;
   I2C_Delay(I2C_DELAY);
   SDA=1;
   I2C_Delay(I2C_DELAY);
}
void I2C_Start()
{
		 SDA=1; 
     SCL=1; 
     I2C_Delay(I2C_DELAY);
     SDA=0; 
     I2C_Delay(I2C_DELAY);
     SCL=0;
     I2C_Delay(I2C_DELAY);
}
void I2C_Stop()
{   
		 SDA=0;
     SCL=1;
     I2C_Delay(I2C_DELAY);
     SDA=1;
     I2C_Delay(I2C_DELAY);
     SCL=0;
     I2C_Delay(I2C_DELAY);
}
unsigned char i2c_checkack(void)
{
   unsigned char ack=0;
     SDA=1;
     SCL=1;
     I2C_Delay(I2C_DELAY/2);
     ack=SDA;
     I2C_Delay(I2C_DELAY/2);
     SCL=0;
     I2C_Delay(I2C_DELAY);
     if(ack==1) return 0; 
     return 1;
}
void i2c_write(unsigned char Data)
{
unsigned char i;
     for(i=0;i<8;i++)
    {
         SDA=((Data<<i)&0x80);
      SCL=1;
      I2C_Delay(I2C_DELAY);
      SCL=0;
      I2C_Delay(I2C_DELAY);
   }
}
unsigned char i2c_read(void)
{
     unsigned char I2C_data=0,i,temp;
     for(i=0;i<8;i++)
    {
       SDA=1;    
         SCL=1;    
         I2C_Delay(120);
         temp=SDA;
         I2C_Delay(120);
         SCL=0;
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
//////////////////////////////////////////////////

//ham su dung cho ds1307
unsigned char DS1307_get(unsigned char addr) 
{
   unsigned int temp,ret; 
   bit AckTemp=1;
   I2C_Start(); /* Start i2c bus */
   i2c_write(DS1307_ID); /* Connect to DS1307 */
   AckTemp=i2c_checkack();
   i2c_write(addr);    /* Request RAM address on DS1307 */  
   AckTemp=i2c_checkack();
   I2C_Start();    /* Start i2c bus */
   i2c_write(DS1307_ID+1);   /* Connect to DS1307 for Read */
   AckTemp=i2c_checkack();
   ret = i2c_read();    /* Receive data */
   AckTemp=i2c_checkack();
   I2C_Stop();
//*********************************************
   temp = ret;    /*BCD to HEX*/
   ret = (((ret/16)*10)+ (temp & 0x0f));    /*for Led 7seg*/
//*********************************************   
   return ret;   
}


void DS1307_Write(unsigned char addr,unsigned char dat)
{
   unsigned int temp;
   bit AckTemp=1;
//**********************************************    /*HEX to BCD*/
   temp = dat ;    /*for Led 7seg*/
   dat = (((dat/10)*16)|(temp %10));
//**********************************************   
   I2C_Start(); /* Start i2c bus */
   i2c_write(DS1307_ID); /* Connect to DS1307 */
   AckTemp=i2c_checkack();
   i2c_write(addr);    /* Request RAM address on DS1307 */ 
   AckTemp=i2c_checkack();
   i2c_write(dat);   /* Connect to DS1307 for Read */
   AckTemp=i2c_checkack();
   I2C_Stop();
}
/************************************************** *********************/


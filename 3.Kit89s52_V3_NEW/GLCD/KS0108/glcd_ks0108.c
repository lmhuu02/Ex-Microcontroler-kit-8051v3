#include "glcd_ks0108.h"
uint8_t u8CursorX, u8CursorY;

void LcdDelay(uint32_t u32Duration)
{
	uint32_t u32Delay;
	for (u32Delay=0; u32Delay<u32Duration; u32Delay++);
}

/*-------------------------------------------------------------------------------
Select the side of the LCD
	LcdSelectSide(U8 u8LcdSide)
		u8LcdSide = LEFT or RIGHT
-------------------------------------------------------------------------------*/
void LcdSelectSide(uint8_t u8LcdSide)
{
	if(u8LcdSide == RIGHT)
	{
		/* switch to right */
		LCD_E=0;
		LCD_RS=0;
    LCD_RW=1;
    LCD_CS1=0; 	
    LCD_CS2=1;
    LcdInstructionWrite(Y_ADRESS); /* Set column to 0 */
  }
	else
	{
		/* switch to left */
		LCD_E=0;
		LCD_RS=0;
    LCD_RW=1;
    LCD_CS1=1; 	
    LCD_CS2=0;
	  LcdInstructionWrite(Y_ADRESS); /* Set column to 0 */
	}
}

/*-------------------------------------------------------------------------------
Send datas to the LCD
LcdDataWrite (U8 u8Data)
u8Data = data to send to the LCD
-------------------------------------------------------------------------------*/
void LcdDataWrite (uint8_t u8Data)
{
	LcdWaitBusy ();		/* wait until LCD not busy */
	LCD_RS = 1;      	/* Data mode */
	LCD_RW = 0;      	/* write mode */
	
	LCD_DATA = u8Data;	/* outbyte */
	
	LCD_E = 1;		/* Strobe */
	LcdDelay(1);	
	LCD_E = 0;
}

/*-------------------------------------------------------------------------------
Send instruction to the LCD
	LcdDataWrite (U8 u8Instruction)
		u8Instruction = Instructino to send to the LCD
-------------------------------------------------------------------------------*/
void LcdInstructionWrite (uint8_t u8Instruction)
{
   	LcdWaitBusy ();		/* wait until LCD not busy */
   	LCD_RS = 0;       	/* Instruction mode */
  	LCD_RW = 0;       	/* Write mode */
	 	
  	LCD_DATA = u8Instruction;/* outbyte */
  	  	
  	LCD_E = 1;		/* Strobe */
  	LcdDelay(1);
  	LCD_E = 0;
}
/*-------------------------------------------------------------------------------
Read data from LCD
	U8 = LcdDataRead();
-------------------------------------------------------------------------------*/
uint8_t LcdDataRead ()
{
	LCD_DATA = 0xFF;	/* set LCD_DATA port in input mode */
	
  LCD_RW = 1;       	/* Read mode */
  LCD_RS = 1;       	/* Data mode */
  	
  LCD_E  = 0;       	/* strobe */
  LcdDelay(1);
	LCD_E  = 1;
	LcdDelay(1);
	  	  	
	return LCD_DATA;	/* return the data read */
}

/*-------------------------------------------------------------------------------
Wait as long as the LCD is busy
	LcdWaitBusy();
-------------------------------------------------------------------------------*/
void LcdWaitBusy ()
{
	LCD_DATA=0xFF;		/* set LCD_DATA port in input mode */
	  	
  LCD_RS = 0;       	/* Instruction mode */
	LCD_RW = 1;       	/* Read mode */
  	
 LCD_E  = 0;       	/* strobe */
 LcdDelay(1);
 LCD_E  = 1;
	
 while (LCD_DATA & 0x7F == BUSY); /* mask the other status bits and test the
					    BUSY bit */
}

/*-------------------------------------------------------------------------------
Clear the LCD screen
	GLCD_ClearScren ()
-------------------------------------------------------------------------------*/
void GLCD_ClearScreen (void)
{
  	uint8_t u8Page=0;  //
  	uint8_t u8Column=0;  //
    
    	/* process the 8 pages of the LCD */
  	for (u8Page = 0; u8Page < 8; u8Page++) 
    	{
      		LcdSelectSide(LEFT);			/* Select left side */
      		LcdInstructionWrite(X_ADRESS | u8Page); /* Set the page number */
      		LcdInstructionWrite(Y_ADRESS);		/* Set column to 0 */
      		
      		/* process a page on both sides */
      		for (u8Column = 0; u8Column < 128; u8Column++) 
						{
						if (u8Column == 64)
            			{    
              			LcdSelectSide(RIGHT);	/* Select right side */
              			LcdInstructionWrite(X_ADRESS | u8Page); /* Set the page number */
              			LcdInstructionWrite(Y_ADRESS); /* Set column to 0 */
      		        }
          		LcdDataWrite (0x00);		/* erase a column */
						}
    	}
}

/*-------------------------------------------------------------------------------
Send an image to the LCD
	GLCD_DisplayPicture (U8 *au8PictureData)
		au8PictureData = contains datas for picture
-------------------------------------------------------------------------------*/
void GLCD_DisplayPicture (uint8_t *au8PictureData)
{
	 uint8_t u8Page=0;  //
   uint8_t u8Column=0;  //
      
   /* Send the left side */
   LcdSelectSide(LEFT);
  	for (u8Page = 0; u8Page < 8; u8Page++) /* loop on the 8 pages */
    	{
      		LcdInstructionWrite(X_ADRESS | u8Page); /* Set the page */
      		for (u8Column = 0; u8Column < 64; u8Column++)
			LcdDataWrite(au8PictureData[(128*u8Page)+u8Column]);
			}
	
	/* Send the right side */
	LcdSelectSide(RIGHT);
  	for (u8Page = 0; u8Page < 8; u8Page++) /* loop on the 8 pages */
    	{
      		LcdInstructionWrite(X_ADRESS | u8Page); /* Set the page */
      		for (u8Column = 64; u8Column < 128; u8Column++)
			LcdDataWrite(au8PictureData[(128*u8Page)+u8Column]);
			}	
}

/*-------------------------------------------------------------------------------
Draw a dot on the LCD
	LcdSetDoc (U8 u8Xaxis, U8 u8Yaxis)
		u8Xaxis = absciss
		u8Yaxis = ordinate
-------------------------------------------------------------------------------*/	
void LcdSetDot (uint8_t u8Xaxis, uint8_t u8Yaxis)
{
 	 uint8_t u8DataRead=0;  //
 	
 	LcdInstructionWrite(START_LINE); /* Set adress for line 0 */

	/* Left side */
	if (u8Xaxis < 64)
	{
    		LcdSelectSide (LEFT);				/* Select left side */
    		LcdInstructionWrite (X_ADRESS + (u8Yaxis / 8)); /* Select page number */
    		LcdInstructionWrite (Y_ADRESS + u8Xaxis);	/* Select column */
    		
    		u8DataRead = LcdDataRead ();  			/* read the current location */
    		u8DataRead = LcdDataRead ();  			/* on the LCD. dummy read */
    		
    		LcdInstructionWrite (X_ADRESS + (u8Yaxis / 8)); /* Select page number */
    		LcdInstructionWrite (Y_ADRESS + u8Xaxis);	/* Select column */
    		LcdDataWrite (u8DataRead | (1 << (u8Yaxis % 8)));/* plot the dot */
    	} 
  	else 
  	/* Right side */
  	{
    		LcdSelectSide(RIGHT);				/* Select left side */         
    		LcdInstructionWrite (X_ADRESS + (u8Yaxis / 8)); /* Select page number */       
    		LcdInstructionWrite (Y_ADRESS + u8Xaxis - 64);  /* Select column */            
    		                                                                               
    		u8DataRead = LcdDataRead ();                    /* read the current location */
    		u8DataRead = LcdDataRead ();                    /* on the LCD. dummy read */   
    		                                                                               
    		LcdInstructionWrite (X_ADRESS + (u8Yaxis / 8)); /* Select page number */       
    		LcdInstructionWrite (Y_ADRESS + u8Xaxis - 64);  /* Select column */            
    		LcdDataWrite (u8DataRead | (1 << (u8Yaxis % 8)));/* plot the dot */   
    		
    	}
      	LcdInstructionWrite(START_LINE); /* Set adress for line 0 */
}

/*-------------------------------------------------------------------------------
Print a char on the LCD
	GLCD_Putchar (U8 u8Char)
		u8Char = char to display
-------------------------------------------------------------------------------*/
void LcdPutchar (uint8_t u8Char, FONT_DEF *toto)
{
	 uint8_t u8CharColumn=0,u8RightSide=0;
	 uint8_t u8UpperCharPointer=1,u8Page=0;
	
	
	/* test for carrier return */
	if (u8CursorX > 128 - (toto->u8Width) ) 
	{	
		u8CursorX = 0;
		u8CursorY++;
		if (u8CursorY == 8) u8CursorY = 0;
	}
	
	/* Select the side of the LCD */
	if (u8CursorX < 64)
	{	
		/* Select left side */
		LcdSelectSide (LEFT);
		LcdInstructionWrite (Y_ADRESS + u8CursorX);
	}
	else 
	{
		/* Select right side */
		LcdSelectSide (RIGHT);
		LcdInstructionWrite (Y_ADRESS + u8CursorX - 64);
	}
	    	
    	/* Draw a char */
	while (u8CharColumn < (toto->u8Width) )
	{
		if ((toto->u8Height) > 8)
		{
			u8UpperCharPointer = 2;
			if (u8CursorX > 64)
				u8RightSide=64;
			LcdInstructionWrite (X_ADRESS + u8CursorY -1); 
			LcdInstructionWrite (Y_ADRESS + u8CursorX -u8RightSide);
			LcdDataWrite ((toto->au8FontTable)[( (u8Char - 32) * u8UpperCharPointer * (toto->u8Width) ) + ((u8CharColumn * u8UpperCharPointer) + 1)]);
			LcdInstructionWrite (Y_ADRESS + u8CursorX -u8RightSide);
			
		}
		LcdInstructionWrite (X_ADRESS + u8CursorY); 
		LcdDataWrite ((toto->au8FontTable)[( (u8Char - 32) * u8UpperCharPointer * (toto->u8Width) ) + (u8CharColumn * u8UpperCharPointer)]);		
		u8CharColumn++;
		u8CursorX++;
		
		/* test if a char is wrote on both sides of LCD */
		if (u8CursorX == 64)
		{
			u8RightSide=64;
			LcdSelectSide (RIGHT);	/* if yes, select right side */
			LcdInstructionWrite (X_ADRESS + u8CursorY);
			LcdInstructionWrite (Y_ADRESS + u8CursorX -u8RightSide);
		}
	}
	
	/* Insert a space after a char */	
	if (u8CursorX < 128) 		/* Check if this is the last char of the line */
	{
		if ((toto->u8Height) > 8)
		{
			LcdInstructionWrite (X_ADRESS + u8CursorY - 1); /* Select the page of the LCD */
			LcdInstructionWrite (Y_ADRESS + u8CursorX);
			LcdDataWrite(0x00);
			LcdInstructionWrite (Y_ADRESS + u8CursorX -u8RightSide);
		}
		LcdInstructionWrite (X_ADRESS + u8CursorY); /* Select the page of the LCD */
		LcdInstructionWrite (Y_ADRESS + u8CursorX );	
		LcdDataWrite(0x00); 	/* if not then insert a space before next letter */
	}
			
	u8CharColumn++;
	u8CursorX++;
}

/*-------------------------------------------------------------------------------
Print a string on the LCD
	GLCD_Printf (U8 *au8Text) 
		*au8Text = string to display
-------------------------------------------------------------------------------*/
void GLCD_Printf (uint8_t *au8Text, FONT_DEF *toto) 
{
	while(*au8Text != 0)
	{
		LcdPutchar (*au8Text,toto);
		au8Text++;
	}
}

/*-------------------------------------------------------------------------------
Set the position of the cursor
	GLCD_Locate (U8 u8Column, U8 u8Line)
		u8Column = Column number of the cursor (in pixels)
		u8Line   = Line number of the cursor (in page number)
-------------------------------------------------------------------------------*/
void GLCD_Locate (uint8_t u8Column, uint8_t u8Line)
{
	u8CursorX = u8Column;
	u8CursorY = u8Line;
}

/*-------------------------------------------------------------------------------
Convert a digital value into an ASCII string
	GLCD_DisplayValue (U32 u32Value, U8 u8NumberOfIntegerDigits, U8 u8NumberOfDecimalDigits)
		u32Value = 32 bits Value to display
		u8NumberOfIntegerDigits = Number of interger digits.
					  If this number is higher than the number of integer
					  digits, it will display the non significant '0'
		u8NumberOfDecimalDigits = Number of decimal digits			
-------------------------------------------------------------------------------*/
void GLCD_DisplayValue (uint32_t u32Value, uint8_t u8NumberOfIntegerDigits, uint8_t u8NumberOfDecimalDigits) 
{
	 uint8_t u8Size=0; 			/* Size of the table */
	 uint8_t au8ValueToDisplay[10];	/* String where is converted the value */
	 int8_t s8CharNumber=0;		/* Character number in the string */
	
	/* Check if the dot has to be displayed and change the Size value */	
	if (u8NumberOfDecimalDigits == 0)
		{
		u8Size = u8NumberOfIntegerDigits + u8NumberOfDecimalDigits;
		}
	else
		{
		u8Size = u8NumberOfIntegerDigits + u8NumberOfDecimalDigits + 1;
		}
	/* Last value of the table = 0 */	
	au8ValueToDisplay[u8Size] = 0;

	/* Convert the value to an ASCII string */			
	for(s8CharNumber=u8Size - 1;s8CharNumber>=0;s8CharNumber--)
	{
		if ((s8CharNumber == u8Size - 1 - u8NumberOfDecimalDigits) && u8NumberOfDecimalDigits !=0)
			{
			au8ValueToDisplay[s8CharNumber] = '.';
			}
		else
			{
			au8ValueToDisplay[s8CharNumber] = u32Value % 10 + '0';
			u32Value /= 10;
			}
	}
	
	/* Display the string */
	GLCD_Printf(au8ValueToDisplay,&Font_System5x8);
}	

/*-------------------------------------------------------------------------------
Draw a rectangle on the LCD
	GLCD_Rectangle (U8 u8Xaxis1,U8 u8Yaxis1,U8 u8Xaxis2,U8 u8Yaxis2)
		u8Xaxis1 = absciss top-left (in pixels)
		u8Yaxis1 = ordinate top-left (in pixels)
		u8Xaxis2 = absciss bottom-right (in pixels)
		u8Yaxis2 = ordinate bottom-right (in pixels)
-------------------------------------------------------------------------------*/
void GLCD_Rectangle (uint8_t u8Xaxis1,uint8_t u8Yaxis1,uint8_t u8Xaxis2,uint8_t u8Yaxis2)
{
  	 uint8_t u8CurrentValue=0;

	/* Draw the two horizontal lines */
  	for (u8CurrentValue = 0; u8CurrentValue < u8Xaxis2 - u8Xaxis1+ 1; u8CurrentValue++) 
  	{
		LcdSetDot(u8Xaxis1 + u8CurrentValue, u8Yaxis1);
		LcdSetDot(u8Xaxis1 + u8CurrentValue, u8Yaxis2);
	}
  	
  	/* draw the two vertical lines */
  	for (u8CurrentValue = 0; u8CurrentValue < u8Yaxis2 - u8Yaxis1 + 1; u8CurrentValue++)	
  	{
		LcdSetDot(u8Xaxis1, u8Yaxis1 + u8CurrentValue);
		LcdSetDot(u8Xaxis2, u8Yaxis1 + u8CurrentValue);
	}
}

/*-------------------------------------------------------------------------------
Draw a circle on the LCD
	GLCD_Circle (U8 u8CenterX, U8 u8CenterY, U8 u8Radius)
		u8CenterX = Center absciss (in pixels)
		u8CenterY = Center ordinate (in pixels) 
		u8Radius  = Radius (in pixels)
-------------------------------------------------------------------------------*/
void GLCD_Circle (uint8_t u8CenterX, uint8_t u8CenterY, uint8_t u8Radius)
{
	 int16_t s16tswitch=0, s16y=0, s16x=0;
	 uint8_t u8d;

	u8d = u8CenterY - u8CenterX;
	s16y = u8Radius;
	s16tswitch = 3 - 2 * u8Radius;
	while (s16x <= s16y) 
	{
		LcdSetDot(u8CenterX + s16x, u8CenterY + s16y);
		LcdSetDot(u8CenterX + s16x, u8CenterY - s16y);
		
		LcdSetDot(u8CenterX - s16x, u8CenterY + s16y);
		LcdSetDot(u8CenterX - s16x, u8CenterY - s16y);
		
		LcdSetDot(u8CenterY + s16y - u8d, u8CenterY + s16x);
		LcdSetDot(u8CenterY + s16y - u8d, u8CenterY - s16x);
		LcdSetDot(u8CenterY - s16y - u8d, u8CenterY + s16x); 
		LcdSetDot(u8CenterY - s16y - u8d, u8CenterY - s16x);

		if (s16tswitch < 0) 
			s16tswitch += (4 * s16x + 6);
		else 
		{
			s16tswitch += (4 * (s16x - s16y) + 10);
			s16y--;
		}
	
		s16x++;
	}
}


/*-------------------------------------------------------------------------------
LCD Initialization
	GLCD_LcdINIT()
-------------------------------------------------------------------------------*/
void GLCD_LcdInit(void)	
{
	LCD_DATA = 0;
	LCD_RS = 0;
  	LCD_RW = 0;
  	LCD_E = 0;
  	LCD_CS1 = 0;
  	LCD_CS2 = 0;
  	
  	//LCD_RST = 1;
  	LcdDelay(10);
  	//LCD_RST=0;
  	//LcdDelay(10);
  	//LCD_RST=1;
  	  	
  	LcdSelectSide(LEFT);
  	LcdInstructionWrite(DISPLAY_OFF); /* Display OFF */
  	LcdInstructionWrite(START_LINE);
  	LcdInstructionWrite(X_ADRESS);
  	LcdInstructionWrite(Y_ADRESS);
  	LcdInstructionWrite(DISPLAY_ON); /* Display ON */
  	
  	LcdSelectSide(RIGHT);
  	LcdInstructionWrite(DISPLAY_OFF); /* Display OFF */
  	LcdInstructionWrite(START_LINE);
  	LcdInstructionWrite(X_ADRESS);
  	LcdInstructionWrite(Y_ADRESS);
  	LcdInstructionWrite(DISPLAY_ON); /* Display ON */
  	
  	GLCD_ClearScreen();
}  	

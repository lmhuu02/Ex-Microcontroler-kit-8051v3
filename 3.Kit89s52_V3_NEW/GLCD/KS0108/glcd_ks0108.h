#ifndef __GLCD_KS0108_
#define __GLCD_KS0108_
#include "main.h"

//khai bao chan ket noi
#define LCD_CS1	P2_5
#define LCD_CS2	P2_6

/* LCD Registers */
#define X_ADRESS	0xB8	/* Adress base for Page 0 */
#define Y_ADRESS	0x40	/* Adress base for Y0	  */
#define START_LINE	0xC0	/* Adress base for line 0 */
#define DISPLAY_ON	0x3F	/* Turn display on	  */
#define DISPLAY_OFF	0x3E	/* Turn display off	  */

/* General use definitions */
#define RIGHT		0
#define LEFT		1
#define BUSY		0x80
void LcdDelay(uint32_t u32Duration);
void GLCD_LcdInit(void)	;
void LcdSelectSide(uint8_t u8LcdSide);
void LcdDataWrite (uint8_t u8Data);
void LcdInstructionWrite (uint8_t u8Instruction);
uint8_t LcdDataRead ();
void LcdWaitBusy ();
void GLCD_ClearScreen (void);
void GLCD_DisplayPicture (uint8_t *au8PictureData);
void LcdSetDot (uint8_t u8Xaxis, uint8_t u8Yaxis);
void LcdPutchar (uint8_t u8Char, FONT_DEF *toto);
void GLCD_Printf (uint8_t *au8Text, FONT_DEF *toto) ;
void GLCD_Locate (uint8_t u8Column, uint8_t u8Line);
void GLCD_DisplayValue (uint32_t u32Value, uint8_t u8NumberOfIntegerDigits, uint8_t u8NumberOfDecimalDigits);
void GLCD_Rectangle (uint8_t u8Xaxis1,uint8_t u8Yaxis1,uint8_t u8Xaxis2,uint8_t u8Yaxis2);
void GLCD_Circle (uint8_t u8CenterX, uint8_t u8CenterY, uint8_t u8Radius);
#endif

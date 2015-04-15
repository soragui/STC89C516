#ifndef LCD_H
#define LCD_H

#include <stc/stc89c5xrc.h>

#define LCD_DataPortH P0

#define WINDOW_XADDR_START	0x0050 // Horizontal Start Address Set
#define WINDOW_XADDR_END	0x0051 // Horizontal End Address Set
#define WINDOW_YADDR_START	0x0052 // Vertical Start Address Set
#define WINDOW_YADDR_END	0x0053 // Vertical End Address Set
#define GRAM_XADDR		    0x0020 // GRAM Horizontal Address Set
#define GRAM_YADDR		    0x0021 // GRAM Vertical Address Set
#define GRAMWR 			    0x0022 // memory write

sbit shiliu    = P2^1;
sbit LCD_RESET = P2^0;
sbit LCD_CS    = P2^2;
sbit LCD_RD    = P2^5;
sbit LCD_WR    = P2^4;
sbit LCD_RS    = P2^3;

typedef unsigned char uchar;
typedef unsigned int  uint;

#define White          0xFFFF
#define Black          0x0000
#define Blue           0x001F
#define Blue2          0x051F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0

void delayms(int time);
void TFT_Initial(void);
void Lcd_Write_Data(unsigned char DH, unsigned char DL);
void Lcd_Write_Com(unsigned char DH, unsigned char DL);
void Lcd_Write_Data_U16(unsigned int dat);
void Lcd_Write_Com_Data(unsigned char cmd, unsigned int dat);
void Lcd_SetPos(unsigned int x0, unsigned int x1, unsigned int y0, unsigned int y1);
void CLR_Screen(unsigned int bColor);


#endif
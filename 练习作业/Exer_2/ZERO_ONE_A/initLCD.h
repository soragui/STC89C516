#ifndef INIT
#define INIT

typedef unsigned char uchar;
typedef unsigned int  uint;

void TFT_Initial(void);
void Write_Data_U16(unsigned int y);
void Write_Cmd_Data(unsigned char x, unsigned int y);
void Write_Cmd(unsigned char DH,unsigned char DL);
void Write_Data(unsigned char DH,unsigned char DL);
void CLR_Screen(unsigned int bColor);
void LCD_SetPos(unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1);
void delayms(unsigned int count);

void Put_mych(unsigned short x, unsigned short  y,unsigned int width, unsigned int height,  short from, const char mycode[], unsigned int fColor,unsigned int bColor);

#endif
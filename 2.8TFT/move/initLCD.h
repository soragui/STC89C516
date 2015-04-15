#ifndef INIT
#define INIT

void TFT_Initial(void);
void Write_Data_U16(unsigned int y);
void Write_Cmd_Data(unsigned char x, unsigned int y);
void Write_Cmd(unsigned char DH,unsigned char DL);
void Write_Data(unsigned char DH,unsigned char DL);
void CLR_Screen(unsigned int bColor);
void LCD_SetPos(unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1);
void delayms(unsigned int count);
void Put_pixel(unsigned int x,unsigned int y,unsigned int color);
void circle(unsigned int x, unsigned int y, unsigned int r, unsigned int color);
void line(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int color);


#endif
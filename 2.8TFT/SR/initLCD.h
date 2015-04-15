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
void Set_Color(uchar x, uint y, uchar length, uint high, uchar color);
void LCD_SetPos(unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1);
void delayms(unsigned int count);
void Put_pixel(unsigned int x,unsigned int y,unsigned int color);
void circle(unsigned int x, unsigned int y, unsigned int r, unsigned int color);
//void line(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int color);
void GUI_DisPicture(uchar x, uint y, uchar length, uint high, const uchar *pic);
void GUI_HLine(uchar x, uint y, uchar length, uint color);
void GUI_VLine(uchar x, uint y, uchar length, uint color);

#endif
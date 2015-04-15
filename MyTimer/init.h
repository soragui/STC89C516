#ifndef INIT
#define INIT

#define uchar unsigned char 
#define uint  unsigned int

void init_LCD();
void init_Timer();
void Write_Data(uchar DH, uchar DL);
void Write_Data_U16(uint x);
void Write_Cmd (uchar DH, uchar DL);
void WriteCmd_Data(uchar x, uint y);
void delayms(uint tt);
void LCD_SetPos(uint x0, uint x1, uint y0, uint y1);
void CLR_Screen(uint bColor);
void Put_num(unsigned int x, unsigned int y, unsigned char ch, unsigned int fcolor, unsigned int bcolor);

#endif
#ifndef INIT
#define INIT

#define White          0xFFFF
#define Black          0x0000
#define Blue           0x001F
#define Blue2          0x051F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0

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
void line(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int color);
void GUI_DisPicture(uchar x, uint y, uchar length, uint high, const uchar *pic);
void GUI_HLine(uchar x, uint y, uchar length, uint color);
void GUI_VLine(uint X, uint Y0, uint Y1, unsigned int color);
void Put_mych(unsigned short x, unsigned short  y,unsigned int width, unsigned int height,  const char mycode[], unsigned int fColor,unsigned int bColor);

#endif
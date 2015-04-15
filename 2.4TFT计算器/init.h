#ifndef INIT_H
#define INIT_H，请打开此句
#define  LCD_DataPortH P0     //高8位数据口,8位模式下只使用高8位

#include <reg52.h>
#include <intrins.h>
  
#define White          0xFFFF
#define Black          0x0000
#define Blue           0x001F
#define Blue2          0x051F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0

sbit shiliu   = P2^1;   
sbit LCD_REST = P2^0;		//复位
sbit LCD_CS   = P2^2;		//片选
sbit LCD_RD   = P2^5;		     //读控制
sbit LCD_WR   = P2^4;   
sbit LCD_RS   = P2^3;		//数据/命令选

sbit DCLK	    = P1^4;   
sbit CS       = P1^3;
sbit DIN      = P1^2;	
sbit DOUT     = P1^1;																						   
sbit Penirq   = P1^0;   //检测触摸屏响应信号

void spistar();
void WriteCharTo7843(unsigned char num);
unsigned int ReadFromCharFrom7843();
void LCD_SetPos(unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1);
void delayms(int count);
void LCD_Writ_Bus(char VH,char VL);
void Lcd_Write_Com(char VH,char VL);
void Lcd_Write_Data(char VH,char VL);
void Address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2);
void Lcd_Init(void);
void Pant(int dcolor);
void draw_rec(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2, int dcolor);
void Write_Data_U16(unsigned int y);
void Write_Cmd_Data (unsigned char x,unsigned int y);
void Write_Data(char YH,char YL);
void Write_Cmd(char YH,char YL);

#endif
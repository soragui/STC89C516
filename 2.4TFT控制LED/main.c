#include <reg52.h>
#include <intrins.h>
#include "init.h"

unsigned int TP_X,TP_Y;	   //当前触控坐标

//LED 状态标签
unsigned char tag1 = 0;
unsigned char tag2 = 0;
unsigned char tag3 = 0;
unsigned char tag4 = 0;
unsigned char tag5 = 0;
unsigned char tag6 = 0;
unsigned char tag7 = 0;
unsigned char tag8 = 0;

int code color[] = {0xFFE0, 0xF81F};

sbit led1 = P0^0;
sbit led2 = P0^1;
sbit led3 = P0^2;
sbit led4 = P0^3;
sbit led5 = P0^4;
sbit led6 = P0^5;
sbit led7 = P0^6;
sbit led8 = P0^7;

void AD7843(void);

void main()
{
	unsigned int lx, ly;
	shiliu=1;
	spistar();  //模拟spi初始化
	Lcd_Init();   //tft初始化
	LCD_CS =0;  //打开LCD片选使能	
 	Pant(Cyan);	//清屏

	
	//画键盘：
	draw_rec(16, 96, 112, 136, Blue);
	draw_rec(16, 152, 112, 192, Blue);
	draw_rec(16, 208, 112, 248, Blue);
	draw_rec(16, 264, 112, 304, Blue);

	draw_rec(128, 96, 224, 136, Blue);
	draw_rec(128, 152, 224, 192, Blue);
	draw_rec(128, 208, 224, 248, Blue);
	draw_rec(128, 264, 224, 304, Blue);

	//标签
	LCD_PutString(81, 40, "LED Control", Red, Cyan);

	LCD_PutString(44, 108, "LED 1", Yellow, Blue);
	LCD_PutString(44, 164, "LED 2", Yellow, Blue);
	LCD_PutString(44, 220, "LED 3", Yellow, Blue);
	LCD_PutString(44, 276, "LED 4", Yellow, Blue);

	LCD_PutString(156, 108, "LED 5", Yellow, Blue);
	LCD_PutString(156, 164, "LED 6", Yellow, Blue);
	LCD_PutString(156, 220, "LED 7", Yellow, Blue);
	LCD_PutString(156, 276, "LED 8", Yellow, Blue);

	while (1)
	{
		if (Penirq == 0)
		{
			AD7843();
			lx=240-((TP_X-400)/13);
			ly=320-((TP_Y-400)/10);
			
			//LED 1
			if (lx >= 16 && lx <= 112 && ly >= 96 && ly <= 136)
			{
					led1 = ~led1;
					tag1 = (tag1 +1)%2;
					LCD_PutString(44, 108, "LED 1", color[tag1], Blue);
					while (Penirq == 0 && lx >= 16 && lx <= 112 && ly >= 96 && ly <= 136);
			}

			//LED 2
			if (lx >= 16 && lx <= 112 && ly >= 152 && ly <= 192)
			{
				led2 = ~led2;
				tag2 = (tag2 +1)%2;
				LCD_PutString(44, 164, "LED 2", color[tag2], Blue);
				while (Penirq == 0 && lx >= 16 && lx <= 112 && ly >= 152 && ly <= 192);
			}

			//LED 3
			if (lx >= 16 && lx <= 112 && ly >= 208 && ly <= 248)
			{
				led3 = ~led3;
				tag3 = (tag3 +1)%2;
				LCD_PutString(44, 220, "LED 3", color[tag3], Blue);
				while (Penirq == 0 && lx >= 16 && lx <= 112 && ly >= 208 && ly <= 248);
			}

			//LED 4
			if (lx >= 16 && lx <= 112 && ly >= 264 && ly <= 304)
			{
				led4 = ~led4;
				tag4 = (tag4 +1)%2;
				LCD_PutString(44, 276, "LED 4", color[tag4], Blue);
				while (Penirq == 0 && lx >= 16 && lx <= 112 && ly >= 264 && ly <= 304);
			}

			//LED 5
			if (lx >= 128 && lx <= 224 && ly >= 96 && ly <= 136)
			{
				led5 = ~led5;
				tag5 = (tag5 +1)%2;
				LCD_PutString(156, 108, "LED 5", color[tag5], Blue);
				while (Penirq == 0 && lx >= 128 && lx <= 224 && ly >= 96 && ly <= 136);
			}

			//LED 6
			if (lx >= 128 && lx <= 224 && ly >= 152 && ly <= 192)
			{
				led6 = ~led6;
				tag6 = (tag6 +1)%2;
				LCD_PutString(156, 164, "LED 6", color[tag6], Blue);
				while (Penirq == 0 && lx >= 128 && lx <= 224 && ly >= 152 && ly <= 192);
			}

			//LED 7
			if (lx >= 128 && lx <= 224 && ly >= 208 && ly <= 248)
			{
				led7 = ~led7;
				tag7 = (tag7 +1)%2;
				LCD_PutString(156, 220, "LED 7", color[tag7], Blue);
				while (Penirq == 0 && lx >= 128 && lx <= 224 && ly >= 208 && ly <= 248);
			}

			//LED 8
			if (lx >= 128 && lx <= 224 && ly >= 264 && ly <= 304)
			{
				led8 = ~led8;
				tag8 = (tag8 +1)%2;
				LCD_PutString(156, 276, "LED 8", color[tag8], Blue);
				while (Penirq == 0 && lx >= 128 && lx <= 224 && ly >= 264 && ly <= 304);
			}
		}
	}
}

void AD7843(void)              //外部中断0 用来接受键盘发来的数据
{
	 CS=0;
	//delayms(1);                     //中断后延时以消除抖动，使得采样数据更准确
	//while(BUSY);                //如果BUSY信号不好使可以删除不用
	//delayms(1);
	WriteCharTo7843(0x90);        //送控制字 10010000 即用差分方式读X坐标 详细请见有关资料
	//while(BUSY);               //如果BUSY信号不好使可以删除不用
	//delayms(1);
	DCLK=1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	DCLK=0; 
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	TP_Y=ReadFromCharFrom7843();
	WriteCharTo7843(0xD0);       //送控制字 11010000 即用差分方式读Y坐标 详细请见有关资料
	DCLK=1; 
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	DCLK=0;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	TP_X=ReadFromCharFrom7843();
	CS=1;
}
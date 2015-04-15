#include <reg52.h>
#include <intrins.h>
#include "init.h"

unsigned int TP_X,TP_Y;	   //当前触控坐标
long op_num, op_old, res; 
unsigned int op;


void AD7843(void);
void disnum(long num);
unsigned int wei(long num);

void main()
{
	unsigned int lx, ly;
	shiliu=1;
	spistar();  //模拟spi初始化
	Lcd_Init();   //tft初始化
	LCD_CS =0;  //打开LCD片选使能	
 	Pant(Cyan);	//清屏

	//画框
	draw_rec(8, 3, 232, 73, Blue);
	draw_rec(10, 5, 230, 71, Cyan);

	//画 + - * /
	draw_rec(8, 76, 58, 116, Blue2);
	draw_rec(66, 76, 116, 116, Blue2);
	draw_rec(124, 76, 174, 116, Blue2);
	draw_rec(182, 76, 232, 116, Blue2);

	//画 1 2 3
	draw_rec(8, 124, 58, 164, Blue2);
	draw_rec(66, 124, 116, 164, Blue2);
	draw_rec(124, 124, 174, 164, Blue2);

	//画 4 5 6
	draw_rec(8, 172, 58, 212, Blue2);
	draw_rec(66, 172, 116, 212, Blue2);
	draw_rec(124, 172, 174, 212, Blue2);

	//画 7 8 9
	draw_rec(8, 220, 58, 260, Blue2);
	draw_rec(66, 220, 116, 260, Blue2);
	draw_rec(124, 220, 174, 260, Blue2);

	//画 0 C = .
	draw_rec(8, 268, 58, 308, Blue2);
	draw_rec(66, 268, 174, 308, Blue2);
	draw_rec(182, 124, 232, 212, Blue2);
	draw_rec(182, 220, 232, 308, Blue2);

	//贴标签
	/*
	LCD_PutString(29, 92, "+", Red, Blue2);
	LCD_PutString(87, 92, "-", Red, Blue2);
	LCD_PutString(145, 92, "*", Red, Blue2);
	LCD_PutString(203, 92, "/", Red, Blue2);

	LCD_PutString(29, 140, "1", Red, Blue2);
	LCD_PutString(87, 140, "2", Red, Blue2);
	LCD_PutString(145, 140, "3", Red, Blue2);

	LCD_PutString(29, 188, "4", Red, Blue2);
	LCD_PutString(87, 188, "5", Red, Blue2);
	LCD_PutString(145, 188, "6", Red, Blue2);

	LCD_PutString(29, 236, "7", Red, Blue2);
	LCD_PutString(87, 236, "8", Red, Blue2);
	LCD_PutString(145, 236, "9", Red, Blue2);

	LCD_PutString(29, 282, "0", Red, Blue2);
	LCD_PutString(116, 282, "C", Red, Blue2);
	LCD_PutString(203, 160, ".", Red, Blue2);
	LCD_PutString(203, 256, "=", Red, Blue2);
	*/

	while (1)
	{
		if (Penirq == 0)
		{
			AD7843();
			lx=240-((TP_X-400)/13);
			ly=320-((TP_Y-400)/10);


			//运算符扫描
			if (lx >= 8 && lx <= 58 && ly >= 76 && ly <= 116)
			{
					op = 0;
					op_old = op_num;
					op_num = 0;
					//LCD_PutString(18, 50, "+", Magenta, Cyan);
					while (Penirq == 0 && lx >= 8 && lx <= 58 && ly >= 76 && ly <= 116);
			}

			if (lx >= 66 && lx <= 116 && ly >= 76 && ly <= 116)
			{
					op = 1;
					op_old = op_num;
					op_num = 0;
					//LCD_PutString(18, 50, "-", Magenta, Cyan);
					while (Penirq == 0 && lx >= 66 && lx <= 116 && ly >= 76 && ly <= 116);
			}

			if (lx >= 124 && lx <= 174 && ly >= 76 && ly <= 116)
			{
					op = 2;
					op_old = op_num;
					op_num = 0;
					//LCD_PutString(18, 50, "*", Magenta, Cyan);
					while (Penirq == 0 && lx >= 124 && lx <= 174 && ly >= 76 && ly <= 116);
			}

			if (lx >= 182 && lx <= 232 && ly >= 76 && ly <= 116)
			{
					op = 3;
					op_old = op_num;
					op_num = 0;
					//LCD_PutString(18, 50, "/", Magenta, Cyan);
					while (Penirq == 0 && lx >= 182 && lx <= 232 && ly >= 76 && ly <= 116);
			}


			//数字按键扫描
			// 1
			if (lx >= 8 && lx <= 58 && ly >= 124 && ly <= 164)
			{
					if (wei(op_num) < 10)
					{
						op_num = op_num * 10 + 1;
					}
					while (Penirq == 0 && lx >= 8 && lx <= 58 && ly >= 124 && ly <= 164);
			}

			//2
			if (lx >= 66 && lx <= 116 && ly >= 124 && ly <= 164)
			{
					if (wei(op_num) < 10)
					{
						op_num = op_num * 10 + 2; 
						while (Penirq == 0 && lx >= 66 && lx <= 116 && ly >= 124 && ly <= 164);
					}
					
			}

			//3
			if (lx >= 124 && lx <= 174 && ly >= 124 && ly <= 164)
			{
					
					if (wei(op_num) < 10)
					{
						op_num = op_num * 10 + 3;
						while (Penirq == 0 && lx >= 124 && lx <= 174 && ly >= 124 && ly <= 164);	
					}
					
			}

			//4
			if (lx >= 8 && lx <= 58 && ly >= 172 && ly <= 212)
			{
					if (wei(op_num) < 10)
					{
						op_num = op_num * 10 + 4;
					}
					while (Penirq == 0 && lx >= 8 && lx <= 58 && ly >= 172 && ly <= 212);
			}

			//5
			if (lx >= 66 && lx <= 116 && ly >= 172 && ly <= 212)
			{
					if (wei(op_num) < 10)
					{
						   op_num = op_num * 10 + 5;
					}
					while (Penirq == 0 && lx >= 66 && lx <= 116 && ly >= 172 && ly <= 212);
			}

			//6
			if (lx >= 124 && lx <= 174 && ly >= 172 && ly <= 212)
			{
					if (wei(op_num) < 10)
					{
						op_num = op_num * 10 + 6;
					}
					while (Penirq == 0 && lx >= 124 && lx <= 174 && ly >= 172 && ly <= 212);
			}

			//7
			if (lx >= 8 && lx <= 58 && ly >= 220 && ly <= 260)
			{
					if (wei(op_num) < 10)
					{
						op_num = op_num * 10 + 7;
					}
					while (Penirq == 0 && lx >= 8 && lx <= 58 && ly >= 220 && ly <= 260);
			}

			//8
			if (lx >= 66 && lx <= 116 && ly >= 220 && ly <= 260)
			{
					if (wei(op_num) < 10)
					{
						op_num = op_num * 10 + 8;
					}
					while (Penirq == 0 && lx >= 66 && lx <= 116 && ly >= 220 && ly <= 260);
			}

			//9
			if (lx >= 124 && lx <= 174 && ly >= 220 && ly <= 260)
			{
					if (wei(op_num) < 10)
					{
						op_num = op_num * 10 + 9;
					}
					while (Penirq == 0 && lx >= 124 && lx <= 174 && ly >= 220 && ly <= 260);
			}

			//0
			if (lx >= 8 && lx <= 58 && ly >= 268 && ly <= 308)
			{
					if (wei(op_num) < 10)
					{
						op_num = op_num * 10;
					}
					while (Penirq == 0 && lx >= 8 && lx <= 58 && ly >= 268 && ly <= 308);
			}

			disnum(op_num);
			
			// = 
			//draw_rec(182, 124, 232, 212, Blue2);
			if (lx >= 182 && lx <= 124 && ly >= 232 && ly <= 212) {
				
					switch (op) {
						case 0:
							res = op_old + op_num; 
							break;
						case 1:
							res = op_old - op_num; 
							break;
						case 2:
							res = op_old * op_num; 
							break;
						case 3:
							res = op_old / op_num;
							break;
						default: 
							res = 0;
							break;
					}
					
					disnum(res);
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

unsigned int wei(long num)
{
	long temp = 9;
	unsigned int numw = 1;
	while (num > temp)
	{
		numw ++;
		temp = temp * 10 + 9;				
	}
	return numw;
}

void disnum(long num)
{
	unsigned int count;
	unsigned int i, x = 220;
	unsigned char temp_num;
	count = wei(num);
	for (i = 0; i < count; i ++)
	{
		temp_num = num % 10 + '0';
		num = num / 10;
		//LCD_PutString(x, 50, &temp_num, Black, Cyan);
		x = x - 8;
	}
}

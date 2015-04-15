#include <reg51.h>

typedef unsigned int  uint;
typedef unsigned char uchar;

uchar code nnum[]={0x3f,0x30,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};	 //0--9 共阴极
uchar code onum[]={0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0x80,0x90};	 //0--9 共阳极

void delay(uint time);
void show_num(int num);

void main()
{		
	int i = 23;
	while (1)
	{		
		show_num(i);
					
	}
}

void show_num(int num)
{
		P0 = 0x01;
		P1 = onum[num%10];
		delay(10);
		//P0 = 0x00;
		
		P0 = 0x02;
		P1 = onum[num/10];
		delay(10);
		//P0 = 0x00;	
}

void delay(uint time)
{
	uint i = 110;
	while (time --)
	{
		while (i --);
		i = 110;
	}
}
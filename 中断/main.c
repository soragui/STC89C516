#include <reg51.h>
#include <intrins.h>

typedef unsigned int  uint;
typedef unsigned char uchar;

sbit DS1 = P2^0;
sbit DS2 = P2^1;

uchar code dis[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07, 0x7F,0x6F};

long num = 9232120, disnum;

void delay(uint time);
uint wei(long num);

int main ()
{
	uint j, k;
	uchar disw = 0xFE;
	while (1)
	{
		disnum = num;
		disw = 0xFE;
		k = wei(num);
		//显示一个数 从个位到最高位
		for (j = 0; j < k; j ++)
		{	
			P0 = _cror_(disw, 1);
			DS1 = 1;
			DS1 = 0;
			
			P0 = 0x00; DS2 = 1; DS2 = 0;	//消影
			
			P0 = dis[disnum%10];
			DS2 = 1;
			DS2 = 0;
			delay(10);
			
			disw = _cror_(disw, 1);
			disnum /= 10;
		}
		num ++;
	}
}

void delay(uint time)
{
	uint i = 110;
	while(time --)
	{
		while(i --);
		i = 110;
	}
}

uint wei(long num)
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
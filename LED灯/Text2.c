#include <reg51.h>
typedef unsigned int uint;

sbit led = P0^2;
sbit biaozhi1= P1^3;
sbit biaozhi = P1^1;

void init();
void delay(uint time);
uint j, k;

void main()
{
	init();
	while(1)
	{
		for (j = 0; j < 256; j ++)
		{
			led = ~led;
			for(k = 0; k < j; k ++);
			led = ~led;
			for (k = 256; k > j; k --); 
		}
	}
}

void init()
{
	P0 = 0x00;
	biaozhi1 = 0;
	P0 = 0xFF;
	biaozhi = 0;
}

void delay(uint time)
{
	uint i = 70;
	while(time --)
	{
		while(i --);
		i = 70;
	}
}
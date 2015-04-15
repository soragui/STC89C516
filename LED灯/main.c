#include <reg52.h>
#include <intrins.h>

typedef unsigned int  uint;
typedef unsigned char uchar;

void delay(uint time);

void main()
{
	uchar currentLed = 0xFE;
	uint circle;
	P0 = 0xDF;
	while(1)
	{
		for(circle = 0; circle < 8; circle ++)
		{
			P0 = currentLed;
			delay(70);
			currentLed = _crol_(currentLed, 1);
		}
		
		for(circle = 0; circle < 8; circle ++)
		{
			P0 = _cror_(currentLed, 1);
			delay(70);
			currentLed = _cror_(currentLed, 1);
		}		
	}
}

void delay(uint time)
{
	uint i, j;
	for(i = time; i > 0; i --)
	{
		for(j = 0; j < 1100; j ++);
	}
}

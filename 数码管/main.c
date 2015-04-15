#include <reg51.h>
#include "delay.h"

sbit ledNum = P2^0;
sbit ledBit = P2^1;

uchar code disNum[16]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,
                   //  0    1    2    3    4    5    6    7    
                     0x7F,0x6F,0x77,0x7C,0x39,0x5E,0x79,0x71};//0~FµÄ¶ÎÂë
                   //  8    9    A    B    C    D    E    F

void main()
{
	uint i;
	P1 = 0xEF;
	ledBit = 1;
	ledBit = 0;
	while(1)
	{
		for(i = 0; i < 16; i ++)
		{
			P1 = disNum[i];
			ledNum = 1;
			ledNum = 0;
			delay(100);	
		}
	}
}
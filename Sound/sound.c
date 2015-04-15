#include <reg51.h>
#include "delay.h"

sbit BZ = P0^0;

//uint code SOUNDTONE[]= {262,294,329,350,392,440,495};

 uchar code SOUNDLONG[25]=        //"生日快乐"节拍
 {
  15,5,20,20,20,40,
  15,5,20,20,20,40,
  15,5,20,20,20,20,20,
  15,5,20,20,20,40
 };

uchar code SOUNDTONE[25]=         //"生日快乐"音调
{
 212,212,190,212,159,169,
 212,212,190,212,142,159,
 212,212,106,126,159,169,190,
 119,119,126,159,142,159      
};

void playTone(uint, int);

void main()
{
	uint i;
	while(1)
	{
		for(i = 0; i < 25; i ++)
		{
			playTone(SOUNDTONE[i], SOUNDLONG[i]*32);
			delay(SOUNDLONG[i]);
		}
	}
}

void playTone(uint tone, int beat)
{
	uint T, B;
	for(B = 0; B < beat; B ++)
	{
		BZ = 0;
		for(T = 0; T < tone; T ++);
		BZ = 1;
		for(T = 0; T < tone; T ++);
	}
}
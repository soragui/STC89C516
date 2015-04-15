#include <reg52.h>
#include "init.h"

void delay(uint time)
{
	uint i = 10;
	while (time --)
	{
		while (i --);
		i = 10;
	}
}

void init_digit()
{
	P0 = 0x00;  
	Matrix = 0;
	P0 = 0xFF;
	Led = 0;
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
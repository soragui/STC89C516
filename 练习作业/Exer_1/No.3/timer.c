#include <reg52.h>
#include "timer.h"

void delayms(uint time)
{
	uint i, j;
	for(i = 0; i < time; i ++) 
		for(j = 0; j < 110; j ++);
}

void init_timer()
{
	//50ms
	TMOD = 0x10;
	TH1  = 0xEC;
	TL1  = 0x77;
	IE   = 0x88;
	//TR1  = 1;
}
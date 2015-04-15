#include <reg52.h>
#include "1602.h"
#include "delay.h"

sbit RS = P2^5;
sbit RW = P2^4;
sbit EN = P2^3;

void wcode(unsigned char t)
{
	RS = 0;
	RW = 0;
	EN = 1;
	P0 = t;
	delay(20);
	EN = 0;
}

void wdata(unsigned char t)
{
	RS = 1;
	RW = 0;
	EN = 1;
	P0 = t;
	delay(20);
	EN = 0;
}

void wword(unsigned char *word)
{
	while(*word)
	{
		wdata(*word++);
		//word ++;
	}
}

void show(unsigned char ge, unsigned char shifen, unsigned char baifen)
{
	wcode(0x80);
	wword("The volt now is:");
	
	wcode(0xCB);
	wdata(ge+0x30);
	wdata('.');
	wdata(shifen+0x30);
	wdata(baifen+0x30);
	wdata('V');	
}

void initLCD()
{
	wcode(0x01);
	wcode(0x06);
	wcode(0x0E);
	wcode(0x38);
}
#include <reg52.h>

sbit Oled =   P1^2;
sbit Cdigit = P1^1;
sbit C8x8  =  P1^3;
sbit Led = P0^0;
unsigned int i, j;

void init();
void delay(unsigned int time);

void main()
{
	init();
	//Oled = 1;
	while(1);
	{
		Led = 0;
		delay(150);
	}
}

void init()
{
	P0 = 0x00;
	C8x8 = 0;
	P0 = 0xFF;
	Cdigit = 0;
}

void delay(unsigned int time)
{

	for(i = time; i > 0; i --)
		for (j = 110; j > 0; j --);
}

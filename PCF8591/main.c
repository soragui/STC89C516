#include "PCF.h"
#include "1602.h"
#include "delay.h"

uchar ge, shifen, baifen;
float volt;

void main()
{
	uchar temp;
	initLCD();
	while(1)
	{
		temp = Read_AD(1);
		volt = (float)(temp*4.8/256);
		ge = (int)volt;
		shifen = (int)(volt*10)%10;
		baifen = (int)(volt*100)%10;
		show(ge, shifen, baifen);
		delay(100);
	}		
}
#include <reg52.h>
#include "gettime.h"
#include "1602.h"

void main()
{
   InitLCD();
   while(1)
   {
   	GetTime();
	xian1();
	xian2();
   }
}
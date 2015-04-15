#include <reg52.h>
#include "init.h"

#define White          0xFFFF   //LCD color
#define Black          0x0000
#define Blue           0x001F
#define Blue2          0x051F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0

uint Device_code;
uint count = 0, num = 0;
uint color = 0x0000;

void main()
{
	Device_code = 0x9328;
	init_LCD();
	init_Timer();
	CLR_Screen(color);
	//for(num = 0; num < 10; num ++)
	//{
	 	while(1)
		{
				
		}
		//delayms(100);
	//}	
}

void set() interrupt 3
{
	//TF0 = 0;
	TH1 = 0xEC;
	TL1 = 0x77;

	CLR_Screen(color);
		color += 50;
		if(color > 65536)
		{
			color = 0;
		}
	
	/*count ++;
	if(count == 30)    //count «Â¡„ 
	{
		count = 0;
		/*
		Put_num(40, 60, num, color, 0x00F2);
		num ++;
		if(num == 10)
		{
			num = 0;
		}
		
		
	}*/
} 
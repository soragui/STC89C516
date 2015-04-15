
#include <reg52.h>
#include <math.h>    
#include "NBCTFT.h"  

#define White          0xFFFF   //LCD color
#define Black          0x0000
#define Blue           0x001F
#define Blue2          0x051F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0
#define PI 3.14159

unsigned int Device_code;      

extern void delayms(unsigned int count);
//void circle(unsigned int x, unsigned int y, unsigned r);

main()
{
    unsigned int i, j;
    Device_code=0x9328;                
    TFT_Initial();                     	 
  	//while(1)                                
    //{
	 	//LCD_PutChar(123, 89, 'A', Blue, Cyan);
		//Show_RGB(0, 240, 0, 64, Cyan);
		//Put_mych(34, 34, my, Cyan, Red);
		CLR_Screen(Black);
		for(i = 120; i < 188; i ++)			
		{
			Put_pixel(i, 170 - sqrt(10000 - pow(i - 120, 2)), White);
			Put_pixel(i, sqrt(10000 - pow(i - 120, 2)) + 150, White);
			Put_pixel(240 - i, 170 - sqrt(10000 - pow(i - 120, 2)), White);
			Put_pixel(240 - i, sqrt(10000 - pow(i - 120, 2)) + 150, White);
		}
		for(i = 160; i < 228; i ++)
		{
			Put_pixel(sqrt(10000 - pow(i - 160, 2)) + 110, i, White);
			Put_pixel(130 - sqrt(10000 - pow(i - 160, 2)), i,White);
			Put_pixel(sqrt(10000 - pow(i - 160, 2)) + 110, 320 - i,White);
			Put_pixel(130 - sqrt(10000 - pow(i - 160, 2)), 320 - i,White);
		}
		//circle(120, 160, 40);
		//delayms(200000);	 	 
    //}

	//for(i = 0; i < 90; i ++)
	//{
	//	Put_pixel(cos(i*PI/180) + 120, sin(i*PI/180) + 160, White);	
	//}
	/*for(j = 90; j >= 0; j -= 5)
	{
		for(i = 0; i < 60; i ++)
		{
			Put_pixel(cos(j*PI/180) * i + 120, sin(j*PI/180) * i, White);
		}
		delayms(120);
		for(i = 0; i < 60; i ++)
		{
			Put_pixel(cos(240 - j*PI/180) * i, 320 - sin(j*PI/180) * i, Black);
		}	
	}*/

	for(j = 0; j <= 360; j = j + 6)
	{
		for(i = 0; i < 60; i ++)
		{
			Put_pixel(120 + cos((360-j)*PI/180) * i, 160 - sin((360 - j)*PI/180) * i, Yellow);
		}
		delayms(20);
		for(i = 0; i < 60; i ++)
		{
			Put_pixel(120 + cos((360 - j)*PI/180) * i, 160 - sin((360 - j)*PI/180) * i, Black);
		}	
	}

	for(j = 0; j <= 360; j ++)
	{
		Put_pixel(100 + cos((360-j)*PI/180) * 20, 200 + sin((360 - j)*PI/180) * 20, Yellow);
	}
	while(1);
}




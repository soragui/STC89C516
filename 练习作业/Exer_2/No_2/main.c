#include <reg52.h>
#include <math.h>
#include "initLCD.h" 
#include "num.h"
#include "PCF.h"

#define White          0xFFFF   //LCD color
#define Black          0x0000
#define Blue           0x001F
#define Blue2          0x051F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0

#define PI 3.1415926


int main()
{
	float old_angle;
	float current_angle;
	float voltage;
	uint x, y, i, j, k;
    uint r;
	uint line_length; 
	TFT_Initial();
	CLR_Screen(White);
	//circle(x1, y1, 100, Blue2);
	
	old_angle = current_angle = 0;
	
	x = 120;
	y = 100;
	
	r = 30;
	
	for(i = 195; i <= 345; i ++)
	{
		Put_pixel(x + 4*cos(i*PI/180)*r, y + 3*sin(i*PI/180)*r, Black);
	}
	
	for(i = 0; i < 4; i ++) {
		circle(x, y, i, Black);
	}
	
	for(i = 195, j = 0; i <= 345; i += 30, j++) {
		
		x += 4*cos(i*PI/180)*r;
		y += 3*sin(i*PI/180)*r;
	
		for(line_length = 0; line_length < 12; line_length ++) {
			Put_pixel(x + line_length*cos((i-180)*PI/180), y + line_length*sin((i-180)*PI/180), Black);
		}
		
		if(j < 3)
			Put_mych(x+5, y+5, 8, 15, num[j], Black, White); 
		else
			Put_mych(x-13, y+3, 8, 15, num[j], Black, White);
		
		if(j < 5)
			for(k = i; k < (i + 30); k += 6) {
					
					x = 120;
					y = 100;
				
					x += 4*cos(k*PI/180)*r;
					y += 3*sin(k*PI/180)*r;
				
					for(line_length = 0; line_length < 6; line_length ++) {
						Put_pixel(x + line_length*cos((k-180)*PI/180), y + line_length*sin((k-180)*PI/180), Black);
					}
			}

		x = 120;
		y = 100;
	}
	
	//GUI_HLine(12, 34, 200, 0x09F0);
	//Put_pixel(12, 34, 0x09F0);
	//GUI_DisPicture(100, 180, 59, 60, pic);
	while(1) {
		voltage = (Read_AD(1)*4.8/256); 
		current_angle = (int)(voltage/4.8 * 150);
		
		if(abs(old_angle - current_angle) > 0.5) {
				for(line_length = 0; line_length < 60; line_length ++) {
					Put_pixel(120 + line_length*cos((old_angle+195)*PI/180), 
						100 + line_length*sin((old_angle+195)*PI/180), White);
				//for(line_length = 0; line_length < 60; line_length ++)
					Put_pixel(120 + line_length*cos((current_angle+195)*PI/180), 
						100 + line_length*sin((current_angle+195)*PI/180), Black);
                }
		}
		
		old_angle = current_angle;
	}
//	{
//	 	for(x1 = 10, y1 = 20; x1 < 120; x1 ++, y1++)
//		{
//				GUI_DisPicture(x1, y1, 80, 31, pic);
//				delayms(800);
//				Set_Color(x1, y1, 80, 33, Black);
//				//delayms(180);
//		}	
//	}
}
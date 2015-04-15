#include <reg52.h>
#include "initLCD.h"
//#include "kkk.h"
#include "bmp.h"

#define White          0xFFFF   //LCD color
#define Black          0x0000
#define Blue           0x001F
#define Blue2          0x051F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0


int main()
{
	uint x1, y1;
	TFT_Initial();
	CLR_Screen(Blue);
	
	//GUI_HLine(12, 34, 200, 0x09F0);
	//Put_pixel(12, 34, 0x09F0);
	GUI_DisPicture(100, 180, 59, 60, pic);
	while(1) ;
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
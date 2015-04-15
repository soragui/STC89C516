#include <reg52.h>
#include <stdlib.h>
#include <math.h>
#include "ch_a.h"
#include "initLCD.h" 

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

//unsigned int Device_code;

//unsigned int code color[7] = { 0x001F, 0x51F, 0xF800, 0xF81F, 0x07E0, 0xFFE0, 0x7FFF };

unsigned int color = Red, extra = 0; 
unsigned int i, k, j;
							
void main()
{
	//Device_code = 0x9328;
	TFT_Initial();
	CLR_Screen(Black);
	//srand(1);
    for(k = 0; k < 6; k ++) {
        for(i = 20, j = 40; i > 12; i --, j --) {
            Put_mych(i+k*32, j, 32, 35, AHUTC[k], color, Black);
            color += 40;
        }
        Put_mych(i+k*32, j, 32, 35, AHUTC[k], Green, Black);
        color = Yellow+1200;
    }
    
    
//        for(i = 20, j = 40; i > 12; i --, j --) {
//            for(k = 0; k < 6; k ++) {
//                Put_mych(i+k*32, j, 32, 35, AHUTC[k], color, Black);
//            }
//            color += 40;
//        }
//        for(k = 0; k < 6; k ++) {
//            Put_mych(i+k*32, j, 32, 35, AHUTC[k], Green, Black);
//        }
//        color = Yellow+1200;
//    }
    
//    for(k = 0; k < 3; k ++) {
//        for(i = 20, j = 140; i > 12; i --, j --) {
//            Put_mych(i+k*16, j, 16, 15, computer[k], color, Black);
//            color += 40;
//        }
//        Put_mych(i+k*16, j, 16, 15, computer[k], Green, Black);
//        color = Yellow+1200;
//    }
    
    //for(k = 0; k < 3; k ++) {
//        for(i = 20, j = 140; i > 12; i --, j --) {
//            
//            for(k = 0; k < 3; k ++) {
//                Put_mych(i+k*16, j, 16, 15, computer[k], color, Black);
//            }
//            color += 40;
//           // Put_mych(i+k*16, j, 16, 15, computer[k], Green, Black); 
//        }

//       for(k = 0; k < 3; k ++) {
//            Put_mych(i+k*16, j, 16, 15, computer[k], Green, Black);
//       }
//        color = Yellow+1200;
//   // }
   
//	for(i = 320; i > 0; i --) {
//        //Put_mych(j, 280, 32, 35, AHUTC[i], color, Blue);
//		//GUI_VLine(120, i, 10, White);
//        //if(color & 0xF) 
//        GUI_HLine(0, i, 240, color);
//        color |= (extra&0x001F);
//        color |= ((extra<<5)&0x07E0);
//        extra += 1;
//		//delayms(20);
//		//GUI_VLine(120, i, i+10, Blue);
//	}
    
    
	
//	for(i = 250; i < 280; i += 2) {
//		GUI_VLine(100, i, i+6, Yellow);
//		delayms(20);
//		GUI_VLine(100, i, i+6, Blue);
//	}
	
	//srand(1);
	//while(1);
//	while(1) {
//		x = rand()%360;
//		y = rand()%360;
//		
//		line_length = rand()%30;
//		
//		color_num = rand()%6;
//		
//		Put_pixel(120 + line_length*cos((x)*PI/180), 
//						100 + line_length*sin((y)*PI/180), color[color_num]);
//	}
    while(1);
}
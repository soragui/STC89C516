#include <rtx51tny.h>
#include <reg52.h>
#include "character.h"
#include "initLCD.h"
#include "PCF.h"

code unsigned int  vt_table[]=	//电压与实际温度对照表
{
		4132,4098,4063,4026,3988,3949,3908,3866,3823,3779, //-9-0
		3733,3686,3639,3590,3540,3489,3437,3385,3331,3277, //1-10
		3222,3166,3110,3054,2997,2940,2882,2824,2767,2709, //11-20
		2651,2593,2536,2478,2421,2365,2309,2253,2198,2143, //21-30
		2089,2036,1984,1932,1881,1831,1782,1734,1686,1640, //31-40
		1594,1550,1506,1464,1422,1381,1341,1303,1265,1228, //41-50
};

#define White          0xFFFF   //LCD color
#define Black          0x0000
#define Blue           0x001F
#define Blue2          0x051F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0
#define Yellow2		   0x3E20

void startup(void) _task_ 0
{
    TFT_Initial();
	CLR_Screen(Blue);
    
    os_create_task(1);
    //os_create_task(2);
    
    os_delete_task(0);
}

void float_chinese_task(void) _task_ 1 
{
	unsigned char i, x;
	//unsigned int  temp;
    unsigned short cb; 
    
//	for(x = 190; x > 10; x -= 2) {
//		
//		for(i = 0; i < 3; i ++) {
//			Put_mych(x+i*16, 120, 16, 15, -8, computer[i],Cyan, Blue);
//		}
//		
//		delayms(100);
//		Put_mych(x+i*16, 120, 16, 15, -8, space, Blue, Blue);
//	}
    
//    for(x = 0; x < 48; x += 1) {
//        cb = x/16;
//        for(i = cb; i < 3; i ++) {
//            if(i == cb) 
//                Put_mych(-(x%16), 100, 16, 15, x%16, computer[i], Magenta, Blue);
//            else
//                Put_mych(16-(x%16)+(i-1-cb)*16, 100, 16, 15, 0, computer[i], Magenta, Blue);
//        }
//        delayms(200);
//		Put_mych(16-(x%16)+(i-1-cb)*16, 120, 16, 15, 0, space, Blue, Blue);
//    }
    
//     for(x = 0; x < 176; x += 1) {
//        cb = x/16;
//        for(i = cb; i < 11; i ++) {
//            if(i == cb) 
//                Put_mych(-(x%16), 100, 16, 20, x%16, num[i], Magenta, Blue);
//            else
//                Put_mych(16-(x%16)+(i-1-cb)*16, 100, 16, 20, 0, num[i], Magenta, Blue);
//        }
//        delayms(200);
//		//Put_mych(16-(x%16)+(i-1-cb)*16, 120, 16, 15, 0, space, Blue, Blue);
//    }
    while(1) {
        for(x = 0; x < 144; x += 2) {
            cb = x/16;
            for(i = cb; i < 9; i ++) {
                if(i == cb) 
                    Put_mych(-(x%16), 100, 16, 15, x%16, MCU_C[i], Magenta, Blue);
                else
                    Put_mych(16-(x%16)+(i-1-cb)*16, 100, 16, 15, 0, MCU_C[i], Magenta, Blue);
            }
            delayms(5);
            //Put_mych(16-(x%16)+(i-1-cb)*16, 120, 16, 15, 0, space, Blue, Blue);
        }
        
        for(x = 240; x > 96; x -=2) {
            cb = (240-x)/16 + 1;
            for(i = 0; i < cb; i ++) {
                if(i == (cb-1)) 
                    Put_mych(240-(240-x)%16, 100, 16, 15, (240-x)%16-16, MCU_C[i], Cyan, Blue);
                else
                    Put_mych(x+i*16, 100, 16, 15, 0, MCU_C[i], Cyan, Blue);
            }
            delayms(5);
        }
        
        for(x = 96; x > 0; x -=1) {
            for(i = 0; i < 9; i ++)  
                    Put_mych(x+i*16, 100, 16, 15, 0, MCU_C[i], Yellow, Blue); 
            delayms(5);
        }
    }
}

//        for(i = 0; i < 16; i ++) {
//            Put_mych(-i, 100, 16, 15, i, computer[0], Magenta, Blue);
//            delayms(100);
//            Put_mych(-i, 100, 16, 15, i, space, Magenta, Blue);
//        }


void temp_light_task(void) _task_ 2
{
   // unsigned int temp ; 
    //unsigned short j = 0;
//    unsigned char i, x;
//    
//	while(1) {
//        
//        for(x = 96; x > 0; x -=1) {
//            for(i = 0; i < 9; i ++)  
//                    Put_mych(x+i*16, 200, 16, 15, 0, MCU_C[i], Yellow, Blue); 
//            delayms(50);
//        }
//    }
        //Put_mych(-j, 100, 16, 15, j, computer[0], Magenta, Blue);
//    while(1) {
//		temp = Read_AD(0);
////       for(j = 0; j < 16; j ++) {
////            Put_mych(-j, 100, 16, 15, j, computer[0], Magenta, Blue);
////            delayms(100);
////            Put_mych(-j, 100, 16, 15, j, space, Magenta, Blue);
////        }
//		Put_mych(114,    130, 16, 20, 0, num[temp%10],     Cyan, Blue);
//		Put_mych(114-14, 130, 16, 20, 0, num[temp/10%10],  Cyan, Blue);
//		Put_mych(114-28, 130, 16, 20, 0, num[temp/100%10], Cyan, Blue);
//    }
}
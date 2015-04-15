#include "initLCD.h"

void init_timer();

unsigned short x = 0, y = 0;
unsigned char  change = 0;
unsigned char  sign = 0;

unsigned char count = 0;
unsigned char i = 0;

void main(void)
{
    TFT_Initial();
    CLR_Screen(Black);
    init_timer(); 
    
    while(1);
}

void init_timer()
{
    TMOD = 0x10;
    TH1  = 0x3C;
    TL1  = 0xB0;
    IE   = 0x88;
    TR1  = 1;
}

void squate_go() interrupt 3
{
    TH1  = 0x3C;
    TL1  = 0xB0;
        
    if(++x < 240) {
        for(i = x; i > 0; i --) { 
            if(++change == 20) {
                change = 0;
                if(sign) {
                    for(y = 80; y < 120; y ++)
                        Put_pixel(i, y, Blue);
                    sign = 0;
                } else {
                    for(y = 80; y < 120; y ++)
                        Put_pixel(i, y, Blue);
                    sign = 1;
                }
            }
            
            if(sign) {
                Put_pixel(i, 80, Blue);
            }  else {
                Put_pixel(i, 120, Blue);
            }
        }
        
        count = x/20;
        
        for(i = 0; i < count; i ++)
            for(y = 80; y < 121; y ++)
                Put_pixel(x-20*(i+1), y, Black);
        
        change = 0; 
        sign = 0;
      
    } else {
        if(++change == 20) {
            change = 0;
            if(sign)
                sign = 0;
            else
                sign = 1;
        } 
            for(x = 240; x > 0; x -= 20) {
                if(sign) {
                    sign = 0;
//                    for(y = 80; y < 121; y ++) {
//                        Put_pixel(x-20+change-1, y, Black);
//                        Put_pixel(x-20+change, y, Blue);
//                    }
                    for(y = 80; y < 121; y ++)  
                        Put_pixel(x-20+change-1, y, Black);
                    for(y = 80; y < 121; y ++) 
                        Put_pixel(x-20+change, y, Blue); 
                    Put_pixel(x-20+change-1, 120, Blue);
                } else {
                    sign = 1;
//                    for(y = 80; y < 121; y ++) {
//                        Put_pixel(x-20+change-1, y, Black);
//                        Put_pixel(x-20+change, y, Blue);
//                    }
                    for(y = 80; y < 121; y ++)  
                        Put_pixel(x-20+change-1, y, Black);
                    for(y = 80; y < 121; y ++) 
                        Put_pixel(x-20+change, y, Blue);
                    Put_pixel(x-20+change-1, 80, Blue);
                }
            } 
        x = 249;
    }
}
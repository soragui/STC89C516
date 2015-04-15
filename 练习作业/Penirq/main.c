#include "initLCD.h"
#include "pen.h"
#include <math.h>

void main()
{  
    unsigned int x1, x2;
    unsigned int y1, y2;
    unsigned int color = White;
    
    TFT_Initial();
    CLR_Screen(Black); 
    
    for(x1 = 0; x1 < 40; x1 ++)
        for(y1 = 0; y1 < 40; y1 ++)
            Put_pixel(x1, y1, Blue);
    
    for(x1 = 0; x1 < 40; x1 ++)
        for(y1 = 40; y1 < 80; y1 ++)
            Put_pixel(x1, y1, White);
    
    for(x1 = 0; x1 < 40; x1 ++)
        for(y1 = 80; y1 < 120; y1 ++)
            Put_pixel(x1, y1, Red);
    
    for(x1 = 0; x1 < 40; x1 ++)
        for(y1 = 120; y1 < 160; y1 ++)
            Put_pixel(x1, y1, Magenta);
            
    for(x1 = 0; x1 < 40; x1 ++)
        for(y1 = 160; y1 < 200; y1 ++)
            Put_pixel(x1, y1, Green);
    
    for(x1 = 0; x1 < 40; x1 ++)
        for(y1 = 200; y1 < 240; y1 ++)
            Put_pixel(x1, y1, Cyan);
    
    for(x1 = 0; x1 < 40; x1 ++)
        for(y1 = 240; y1 < 280; y1 ++)
            Put_pixel(x1, y1, Yellow);
            
    for(y1 = 0; y1<320; y1 ++) {
        Put_pixel(42, y1, 0x0FF2);
        Put_pixel(43, y1, 0xD621);
    }
     
    while(1) {
        if(!Penirq) {
            x1 = get_X();
            x2 = get_X();
            
            y1 = get_Y();
            y2 = get_Y();
            
            if(abs(x1-x2)<2 && abs(y1-y2)<2) {
                x1 = (x1+x2)/2;
                y1 = (y1+y2)/2;
                
                y1 = 320 - y1;
                
                if(x1 < 41) {
                    if(y1<41)
                        color = Blue;
                    else if(y1<81)
                        color = White;
                    else if(y1<121)
                        color = Red;
                    else if(y1<161)
                        color = Magenta;
                    else if(y1<201)
                        color = Green;
                    else if(y1<241)
                        color = Cyan;
                    else if(y1<281)
                        color = Yellow;
                    else {
                        LCD_SetPos(44, 240, 0, 320); 
                        for (y1 = 0; y1 < 320; y1 ++) {
                            for (x1 = 44; x1 < 240; x1 ++)
                                Write_Data_U16(Black);
                        }
                    }  
                } else {
                    Put_pixel(x1, y1, color);
                }
            }
        }
    }
}
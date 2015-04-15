#include "NBCTFT.h"
#include "ch_a.h"

unsigned int i, j, k, color;

void main()
{
    TFT_Initial();
    CLR_Screen(Black);
    
    for(k = 0; k < 6; k ++) { 
        color = Red - 0x0021;
        for(i = 20, j = 14; i > 10; i --, j--) {
            Put_mych(i+k*48, j, 48, 56, AHUTC[k], color);
            color -= 0x0021;
        }
         Put_mych(i+k*48, j, 48, 56, AHUTC[k], White);
    }
    
   for(k = 0; k < 5; k ++) {
        color = Red - 0x0021;
        for(i = 100, j = 80; i > 90; i --, j--) {
            if(k<4)
                Put_mych(i+k*29, j, 32, 27, team_name[k], color);
            else
                Put_mych(i+k*25, j, 32, 27, team_name[k], color);               
            color -= 0x0021;
        }
         if(k<4)
                Put_mych(i+k*29, j, 32, 27, team_name[k], White);
            else
                Put_mych(i+k*25, j, 32, 27, team_name[k], White);
    }
    
    for(k = 0; k < 2; k ++) {
        color = Red - 0x0021;
        for(i = 80, j = 110; i < 86; i ++, j++) {
            Put_mych(i+k*32, j, 32, 27, per_name[k], color);
            color -= 0x0021;
        }
         Put_mych(i+k*32, j, 32, 27, per_name[k], White);
    }
    
    for(k = 2; k < 4; k ++) {
        color = Red - 0x0021;
        for(i = 110, j = 110; i > 104; i --, j++) {
            Put_mych(i+k*32, j, 32, 27, per_name[k], color);
            color -= 0x0021;
        }
         Put_mych(i+k*32, j, 32, 27, per_name[k], White);
    }
    
    i = 40; j = 168;
    
    for(k = 0; k < 7; k ++) { 
         Put_mych(i+k*8, j, 8, 11, load[k], White);
    }
    
    for(k = 40; k < 280; k ++) {
        Put_pixel(k, 180, Yellow-0x0042);
        Put_pixel(k, 190, Yellow-0x0042);
    }
    
    for(k = 180; k < 190; k ++) {
        Put_pixel(40, k, Blue2-0x0042);
        Put_pixel(280, k, Blue2-0x0042);
    }
    
    for(k = 40; k < 280; k ++) {
        delayms(20);
        for(i = 180; i < 190; i ++)
            Put_pixel(k, i, 0xF6B2);
    }
    
    while(1);
}

#include <math.h>
#include "NBCTFT.h"
#include "ch_a.h"
#include "ad_c.h"

#define PI  3.1415

float voltage = 0;
unsigned char current_angle = 0, old_angle = 0;
unsigned int  color = Red, extra = 0;
unsigned short line_length;
    
void main()
{
//    unsigned int i, j, k;
//    unsigned char band_x, band_y;
//    unsigned int color = Yellow+1200;
    
    unsigned int i = 0, j, x, y, r, k;
    TFT_Initial(); 
    CLR_Screen(Black);
    //initADC();
    
//    for(k = 0; k < 10; k ++) {
//        for(i = 0; i <= 360; i ++) {
//            Put_pixel(120 + cos(i*PI/180)*20, 160 + sin(i*PI/180)*20, color);
//            Put_pixel(120 + cos(i*PI/180)*19, 160 + sin(i*PI/180)*19, color);
//            color += 30;
//        }
//    }
//    
//    for(i = 0; i <= 360; i ++) {
//            Put_pixel(120 + cos(i*PI/180)*20, 160 + sin(i*PI/180)*20, Black);
//            Put_pixel(120 + cos(i*PI/180)*19, 160 + sin(i*PI/180)*19, Black);
//           // color += 30;
//        }
        
//    for(k = 0; k < 40; k ++) {
//        for(i = 0; i < k; i ++) {
//            Put_pixel(200+k, 0+i, color);
//        }
//        color += 10;
//    }
//    
//    for(k = 0; k < 40; k ++) {
//        for(i = 0; i < k; i ++) {
//            Put_pixel(40-k, 240-i, color);
//        }
//        color += 10;
//    }
    
    for(k = 0; k < 6; k ++) { 
        for(i = 20, j = 14; i > 14; i --, j--) {
            Put_mych(i+k*48, j, 48, 56, AHUTC[k], color);
            color |= (extra&0x001F); 
            color |= ((extra<<5)&0x07E0);
            extra += 60;
        }
        Put_mych(i+k*48, j, 48, 56, AHUTC[k], Red);
        color = Yellow;
    }
    
    
    for(k = 0; k < 30; k ++) { 
        for(i = 40, j = 65; i > 30; i --, j--) {
            Put_mych(i+k*8, j, 8, 14, AHUTE[k], color);
            color += 40;
        }
        Put_mych(i+k*8, j, 8, 14, AHUTE[k], Green);
        color = Yellow+1200;
    }
    
    for(k = 0; k < 5; k ++) { 
        for(i = 100, j = 90; i > 90; i --, j--) {
            if(k < 4)
                Put_mych(i+k*29, j, 32, 27, team_name[k], color);
            else
                Put_mych(i+k*25, j, 32, 27, team_name[k], color);
            color += 40;
        }
        if(k < 4)
                Put_mych(i+k*29, j, 32, 27, team_name[k], Green);
            else
                Put_mych(i+k*25, j, 32, 27, team_name[k], Green);
        color = Yellow+1200;
    }
    
    for(k = 0; k < 4; k ++) { 
        for(i = 60, j = 120; i > 50; i --, j--) {
            if(k != 2)
                Put_mych(i+k*32, j, 32, 27, per_name[k], color);
            else if (k == 3)
                Put_mych(i+k*54, j, 32, 27, per_name[k], color);
            else
                Put_mych(i+k*37, j, 32, 27, per_name[k], color);
            color += 40;
        }
        if(k != 2)
            Put_mych(i+k*32, j, 32, 27, per_name[k], Green);
        else if (k == 3)
            Put_mych(i+k*54, j, 32, 27, per_name[k], Green);
        else
            Put_mych(i+k*37, j, 32, 27, per_name[k], Green);
        color = Yellow+1200;
    }

//    for(k = 0; k < 90; k ++) {
//        band_x = cos(k*PI/180)*40;
//        band_y = sin(k*PI/180)*40;
//        for(i = 0; i < band_x; i ++) {
//             Put_pixel(190+band_y, 140-i, color);
//         }
//         color += 10;
//    }
    
    
//        for(i = 22, j = 50; i < 140; i++, j++) { 
//            for(k = 0; k < 4; k ++) { 
//                Put_mych(i+k*8, j, 8, 16, imcu[k], color);
//            } 
//            color += 40;
//        }
//        
//        for(k = 0; k < 4; k ++) { 
//            Put_mych(i+k*8, j, 8, 16, imcu[k], Green);
//        }
    
//    x = 130;
//    y = 130;
//    
//    r = 110;
//    
//    for(i = 195; i < 345; i ++) {
//        Put_pixel(x+cos(i*PI/180)*r, y+sin(i*PI/180)*r, Yellow);
//    }
//    
//    //line_length = 10;
//    
//    for(i = 195; i <= 345; i += 30) {
//        
//        x = 130;
//        y = 130;
//		
//		x += cos(i*PI/180)*r;
//		y += sin(i*PI/180)*r;
//        
//        //Put_mych();
//	
//		for(line_length = 0; line_length < 12; line_length ++) {
//			Put_pixel(x + line_length*cos((i-180)*PI/180), y + line_length*sin((i-180)*PI/180), White);
//		}
//        
//        if(i < 335) 
//			for(j = i; j < (i + 30); j += 6) {
//					
//					x = 130;
//					y = 130;
//				
//					x += cos(j*PI/180)*r;
//					y += sin(j*PI/180)*r;
//				
//					for(line_length = 0; line_length < 6; line_length ++) {
//						Put_pixel(x + line_length*cos((j-180)*PI/180), y + line_length*sin((j-180)*PI/180), White);
//					}
//			}
//    }
//    
//    Put_mych(23, 90, 8, 16, num[1], Yellow);
    
//    x = 130;
//    y = 130;
    i = 2000;
    while(1) {
        line_length = 7;
        //for(i = 110; i < 210; i ++) {
            for(x = 0; x < 320; x += 1) {
                    for(y = 233; y < 233+line_length; y ++)
                        Put_pixel(x, y, color);
                color += 2;
                color += (2 << 5);
                delayms(30);
            }
        //}
        break;
        color = Blue + i;
        i -= 200;
        if(i == 0)
            i = 2000;
        
        //voltage  ; 
		//current_angle = (int)(voltage/4.8 * 150); 
        //current_angle = ADC_RESL*1.0/256*150;
		//if(abs(old_angle - current_angle) > 0.005) {
//        if((ADC_CONTR & ADC_FLAG) == ADC_FLAG) {
//            current_angle = ADC_RESL*1.0/256*150;
//            if(abs(old_angle - current_angle) > 0.5) {
//                IE = 0x00;
//                //i = voltage%10;
//                Put_mych(140, 140, 8, 16, num[6], Yellow);
//				for(line_length = 0; line_length < 60; line_length ++) {
//					Put_pixel(x + line_length*cos((old_angle+195)*PI/180), 
//						y + line_length*sin((old_angle+195)*PI/180), Black);
//				//for(line_length = 0; line_length < 60; line_length ++)
//					Put_pixel(x + line_length*cos((current_angle+195)*PI/180), 
//						y + line_length*sin((current_angle+195)*PI/180), White);
//                }
//                old_angle = current_angle;
//                IE = 0xA0;
//           }
//           
////            ADC_CONTR &= ~ADC_FLAG;
////            ADC_CONTR = ADC_POWER|ADC_START; 
////            } 
		} 
		  
    //while(1);
}

void adc_isr() interrupt 5 using 1
{
//    unsigned short line_length;
//    unsigned short x = 130;
//    unsigned short y = 130;
    ADC_CONTR &= ~ADC_FLAG; 
    //voltage = (ADC_RESH)/256*4.8;
    current_angle = ADC_RESL*1.0/256*150;
    voltage = ADC_RESL*1.0/256*4.8;
//    for(line_length = 0; line_length < 60; line_length ++) {
//					Put_pixel(x + line_length*cos((old_angle+195)*PI/180), 
//						y + line_length*sin((old_angle+195)*PI/180), Black);
//				//for(line_length = 0; line_length < 60; line_length ++)
//					Put_pixel(x + line_length*cos((current_angle+195)*PI/180), 
//						y + line_length*sin((current_angle+195)*PI/180), White);
//    }
//    old_angle = current_angle;
    ADC_CONTR = ADC_POWER|ADC_START;
    //IE = 0x00;
}
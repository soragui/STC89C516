#include <stc/stc12c5a60s2.h>
#include <rtx51tny.h>
#include <stdlib.h>
#include "initLCD.h"
#include "zoa.h"

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

void start_task() _task_ 0
{
	TFT_Initial();
	CLR_Screen(Black);
    
    os_create_task(1);
    os_create_task(2);

    os_delete_task(0);
}

void num_circle_task_1(void) _task_ 1
{
    
    unsigned short x, i; 
    unsigned short beg = 0;
    
    while(1) {
    
        for(x=0, i=beg; x < 240; x += 8, i ++) {
            if(i > 29)
                i = 0;
            Put_mych(x, 120, 8, 16, 0, line_one[i], Green, Black); 
        }
        
        if(++beg == 30)
                beg = 0;
    }
}

void num_circle_task_2(void) _task_ 2
{
    
    unsigned short x, i; 
    unsigned short beg = 0;
    
    while(1) {
    
        for(x=240, i=beg; x > 0; x -= 8, i ++) {
            if(i > 29)
                i = 0;
            Put_mych(x, 200, 8, 16, 0, line_one[i], Green, Black); 
        }
        
        if(++beg == 30)
                beg = 0;
    }
}
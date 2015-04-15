#include <rtx51tny.h>
#include <reg51.h>
#include "rtx51.h"

void delay(uint time)
{
    uint i, j;
    for(i = 0; i < time; i ++)
        for(j = 0; j < 50; j ++);
}

void set_one(void) _task_ 1
{
    while(1) {
        //P1 = 0x6F; 
    }
}

void set_two(void) _task_ 2
{
    uchar i, j;
    while(1) {
        //P1 = 0xF6; 
        j = 0x01;
        for(i = 0; i < 8; i ++) {
            P1 = ~j;
            delay(500);
            j <<= 1;
        }
    }
}

void task_start_up(void) _task_ 0
{
    os_create_task(1);
    os_create_task(2);
    
    os_delete_task(0);
}
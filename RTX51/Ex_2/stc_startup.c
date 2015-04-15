#include <stc/stc89c5xrc.h>
#include <rtx51tny.h>

void start_up(void) _task_ 0
{
    os_create_task(1);
    
    os_delete_task(0);
}

void led_light(void) _task_ 1
{
    while(1) {
        P0 = ~P0 ;
    }
}


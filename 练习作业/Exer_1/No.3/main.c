#include <reg52.h>
#include "timer.h"

sbit button    = P1^0;
sbit delay_led = P1^1;

uint time_count = 0;

void main()
{	
	init_timer();
	
	while(1) {
		while(!button) {
			delayms(8);
			if(!button) {
				TR1 = 1;
				delay_led = 1;
			}
		}
	}
	//return 0;
}


void led_light() interrupt 3
{
	TH1  = 0xEC;
	TL1  = 0x77;
	
	if(++ time_count == 1980) {
		time_count = 0;
		delay_led = 0;
	    TR1 = 0;
	}
}

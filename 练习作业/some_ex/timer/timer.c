#include "timer.h"

void I_init()
{
    IE = 0x82;
}

void T_init()
{
    TCON = 0x10;
    TMOD = 0x01;
    TH0  = 0x00;
    TL0  = 0x00;
    AUXR |= 0x80;
}

void T0_Routine() interrupt 1
{
    TH0  = 0x00;
    TL0  = 0x44;
    L0 = ~L0;
}
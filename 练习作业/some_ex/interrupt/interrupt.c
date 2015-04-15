#include "interrupt.h"

void initINT()
{
    IE   |= (Enable | En_Int0 | En_Int1);
    TCON |= Low_T_1; 
}

void Int_0_Routine() interrupt 0
{
    L0 = ~L0;
}

void Int_1_Routine() interrupt 2 using 1
{
    P1 = ~P1;
}
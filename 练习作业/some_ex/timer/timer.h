#ifndef TIMER_H
#define TIMER_H

#include "reg52.h"

sfr AUXR = 0x8E;

sbit L0  = P1^0;

void I_init();
void T_init();

#endif
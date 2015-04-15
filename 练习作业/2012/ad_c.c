#include "ad_c.h"
#include "NBCTFT.h"

void initADC()
{
    IE        = 0xA0; 
    P1ASF     = 0x01;
    ADC_AUXR  = 0x04;    
    ADC_RESH  = 0;
    ADC_CONTR = ADC_POWER|ADC_START;
    delayms(2);
}


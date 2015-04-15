#ifndef AD_C_H
#define AD_C_H

sfr     ADC_CONTR = 0xBC;
sfr     ADC_AUXR  = 0xA2;
sfr     ADC_RESH  = 0xBD;
sfr     ADC_RESL  = 0xBE;
sfr     P1ASF     = 0x9D;

#define ADC_POWER   0x80
#define ADC_FLAG    0x10
#define ADC_START   0x08
#define ADC_SPEEDLL 0x00
#define ADC_SPEEDL  0x20
#define ADC_SPEEDH  0x40
#define ADC_SPEEDHH 0x60

void initADC();

#endif
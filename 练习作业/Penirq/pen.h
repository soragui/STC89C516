#ifndef PEN_H
#define PEN_H

#include <reg52.h>

#define Xmin           0x0133
#define Xmax           0x0EDA
#define Ymin           0x00D0
#define Ymax           0x0E2F

sbit DCLK   = P3^7;
sbit CS     = P3^6;
sbit DIN    = P3^5;
sbit BUSY   = P3^4;
sbit DOUT   = P3^3;
sbit Penirq = P3^2;

void wait(unsigned int i);
void start_ADS();
void write_ADS(unsigned char dat);
unsigned int read_ADS();

unsigned int get_X();
unsigned int get_Y();

#endif
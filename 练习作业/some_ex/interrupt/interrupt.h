#ifndef INT_H
#define INT_H

#include <reg52.h>

#define Enable  0x80
#define En_Int0 0x01
#define En_Int1 0x04
#define Low_T_0 0x01
#define Low_T_1 0x04

sbit L0 = P1^0;
sbit L1 = P1^1;
sbit L2 = P1^2;
sbit L3 = P1^3;
sbit L4 = P1^4;
sbit L5 = P1^5;
sbit L6 = P1^6;
sbit L7 = P1^7;

typedef unsigned char uchar;
typedef unsigned int  uint;

void initINT();

#endif
#ifndef INIT_H
#define INIT_H

typedef unsigned int  uint;
typedef unsigned char uchar;

sbit Digit_duan = P1^0;
sbit Digit_wei = P1^1;
sbit Led = P1^2;
sbit Matrix = P1^3;

void init_digit();
void delay(uint time);
void keyscan();
uint wei(long num);

#endif
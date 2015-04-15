#ifndef H1602_H
#define H1602_H

void wcode(unsigned char);
void wdata(unsigned char);
void wword(unsigned char *);
void show(unsigned char, unsigned char, unsigned char);
void initLCD();

#endif

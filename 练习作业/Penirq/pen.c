#include "pen.h"

void wait(unsigned int i)
{
    while(i--);
}

void start_ADS()
{
    DCLK = 0;
    CS   = 1;
    DIN  = 1;
    DCLK = 1;
    CS   = 0;
}

void write_ADS(unsigned char dat)
{
    unsigned char i = 0;
    
    for(i = 0; i < 8; i ++) {
        if(dat&0x80)
            DIN = 1;
        else
            DIN = 0;
        DCLK = 0; wait(1);
        DCLK = 1; wait(1);
        dat <<= 1;
    }
}

unsigned int read_ADS()
{
    unsigned char i = 0;
    unsigned int dat = 0;

    for(i = 0; i < 12; i ++) {
        dat <<= 1;
        DCLK = 1; wait(1);
        DCLK = 0; wait(1);
        if(DOUT)
            dat ++;
    }
    
    return dat;
}

unsigned int get_X()
{
    unsigned int x;
    unsigned int temp_x;
    
    CS = 0;
    
    write_ADS(0xD0);
    DCLK = 1; wait(1);
    DCLK = 0; wait(1);
    
    temp_x = read_ADS();
    x = 240.0*(temp_x-Xmin)/(Xmax-Xmin);
    
    CS = 1;
    
    return x;
}

unsigned int get_Y()
{
    unsigned int y;
    unsigned int temp_y;
    
    CS = 0;
    
    write_ADS(0x90);
    DCLK = 1; wait(1);
    DCLK = 0; wait(1);
    
    temp_y = read_ADS();
    y = 320.0*(temp_y-Ymin)/(Ymax-Ymin);
    
    CS = 1;
    
    return y;
}
#include "initLCD.h"

void main()
{
    int x, y;
    TFT_Initial();
	CLR_Screen(Black);
    
    for(y=30, x=30; y < 200; y+=2, x+=3) {
        //for(x = 30; x < 180; x += 3) {
            GUI_VLine(x, y, 50, Blue);
            delayms(100);
            GUI_VLine(x, y, 50, Black);
    }
    
    while(1);
}
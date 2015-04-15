
#include <init24.h>

void main()
{
	int color = 0x0000;
	Lcd_Init();
	LCD_CS = 0;
	
	while(color != 0xFFFF) {
		Pant(color);
		color += 0x0202;
	}

	while(1);
}
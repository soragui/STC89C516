#include <reg51.h>
#include "initLCD.h"
//#include "num.h"


#define White          0xFFFF   //LCD color
#define Black          0x0000
#define Blue           0x001F
#define Blue2          0x051F
#define Red            0xF800
#define Magenta        0xF81F
#define Green          0x07E0
#define Cyan           0x7FFF
#define Yellow         0xFFE0

unsigned int Device_code;
void uart_init();
void uart_send(unsigned int ch);
unsigned char dnum = 4;

void main()
{
	uart_init();
	Device_code=0x9328;                
    TFT_Initial();
	CLR_Screen(Magenta); 
	while(1)
	{
	 	
		//for(dnum = 0; dnum < 16; dnum ++)
		//{
			Put_num(100, 100, dnum, Cyan, Magenta);
			//delayms(1000);	
		//}
		//while(1);
	}
}

void uart_init()
{
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = 0xFD;	   //设置寄存器初值 确定波特率
	TL1 = 0xFD;			  
	TR1 = 1;
	EA=1;
	ES=1;
	ET1=0;
}

void set() interrupt 4
{
	if(RI)
	{
		RI = 0;
		dnum = SBUF;
		uart_send(dnum);
	}
}

void uart_send(unsigned int ch)
{
	SBUF = ch;
	while(!TI);
	TI = 0;
}


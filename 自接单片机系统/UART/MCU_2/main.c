#include <reg52.h>
#define MAXPWM 500

void uart_init();
//void delay(unsigned short time);

unsigned int num;

void main()
{
	uart_init();  
	while(1)
	{
		P0 = num;
	}
}

void uart_init()
{
	TMOD= 0X20;
	TH1=0Xfd;
	TL1=0Xfd;
	TR1=1;
	REN=1;
	SM0=0;
	SM1=1;
	EA=1;
	ES=1;
	ET1=0;
}

void set() interrupt 4
{
	RI=0;
	num=SBUF;
}

/*void delay(unsigned short time)
{
	while(time --);
} */
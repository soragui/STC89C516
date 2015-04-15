#include <reg51.h>

typedef unsigned char uchar;
typedef unsigned int  uint;

//uint num = 0;
uchar buf [] = "wifimod:RSTOR";

//void delay (uint time);
void uart_init ();
void uart_send_byte (uchar dat);
void uart_send_string (uchar *dat);

void main () {
	uart_init();
	uart_send_string (buf);
    while(1);
}

void uart_init () {
	SCON = 0x50;
	TMOD = 0x20;
	TH1 = 0xFD;
	TL1 = 0xFD;			  
	TR1 = 1;
}

void uart_send_byte (uchar dat)
{
	SBUF = dat;
	while (TI == 0);
	TI = 0;	
}

void uart_send_string (uchar *dat)
{
	while (*dat)
	{
		uart_send_byte(*dat++);
	}
}
#include <reg51.h>

typedef unsigned char uint8;

unsigned char code wel[] =   {"<---Wel come--->"};
unsigned char code linux[] = {"This is LinuxCBT"};

sbit RS = P2^5;
sbit RW = P2^4;
sbit EN = P2^3;
sbit Busy = P0^7;

void init_1602();
void wait();
void w_data(uint8 dat);
void w_string(uint8 addr_start, uint8 *p);
void w_cmd(uint8 cmd);
void delay(uint8);

void main()
{
	init_1602();
	w_string(0x80, wel);
	//w_cmd(0x07);
	w_string(0xC0, linux);
	while(1);
}

void init_1602()
{
	w_cmd(0x38);
	w_cmd(0x0C);
	w_cmd(0x06);
	w_cmd(0x01);
}

void wait()
{
	P0 = 0xFF;
	do
	{
		RS = 0;
		RW = 1;
		EN = 0;
		EN = 1;		
	}while(Busy == 1);
	EN = 0;
}

void w_data(uint8 dat)
{
	wait();
	EN = 0;
	P0 = dat;
	RS = 1;
	RW = 0;
	EN = 1;
	EN = 0;
}

void w_string(uint8 addr_start, uint8 *p)
{
	w_cmd(addr_start);
	while( *p != '\0')
	{
		w_data(*p++);
		delay(120);
	}
}

void w_cmd(uint8 cmd)
{
	wait();
	EN = 0;
	P0 = cmd;
	RS = 0;
	RW = 0;
	EN = 1;
	EN = 0;	
}

void delay(uint8 time)
{
	unsigned int i;
	while (time --)
	{
		i = 110;
		while (i --);
	}
}
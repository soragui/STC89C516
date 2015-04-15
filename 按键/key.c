#include <reg51.h>

typedef unsigned char uchar;
typedef unsigned int  uint;

sbit duan = P1^0;
sbit wei = P1^1;
sbit LED = P1^2;
sbit Matrix = P1^3;
sbit cow1 = P2^4;
sbit cow2 = P2^5;
sbit cow3 = P2^6;
sbit cow4 = P2^7;

uchar code dis[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6};
uchar num = 0, temp;

void  delay (uint time);
uchar keyscan ();

void main () 
{
	P0 = 0x00;  
	Matrix = 0;
	P0 = 0xFF;
	LED = 0;

	P0 = 0x7F;
	wei = 1;
	wei = 0;

	while (1) 
	{
		P0 = dis [keyscan()];
		duan = 1;
		duan = 0;
	}		
}

void delay (uint time)
{
	uint i = 110;
	while (time --)
	{
		while (i --);
		i = 110;
	}
}

uchar keyscan()
{
	P2 = 0xFE;
	temp = P2;
	temp = temp & 0xFE;
	switch (temp)
	{
		case 0xEE: num = 1;
			break;
		case 0xDE: num = 2;
			break;
		case 0xBE: num = 3;
			break;
		case 0x7E: num = 4;
			break;
	}

	P2 = 0xFD;
	temp = P2;
	temp = temp & 0xFD;
	switch (temp)
	{
		case 0xED: num = 5;
			break;					    
		case 0xDD: num = 6;
			break;
		case 0xBD: num = 7;
			break;
		case 0x7D: num = 8;
			break;
	}
	return num;
}
#include <reg51.h>

typedef unsigned char uchar;

sbit A1 = P1^4;
sbit B1 = P1^3;
sbit C1 = P1^2;
sbit D1 = P1^1;	  

uchar speed;

void delay_us (uchar t);
void delay_ms (uchar t);
//void drive ();
void CW ();
void ACW ();

void main() {  
	speed = 1;
	while (1)
	{	
			CW ();
	}
}

void delay_us (uchar t) 
{
	while (t --);	
}

void delay_ms (uchar t)
{
	 while (t --)
	 {
	 	delay_us (245);
	 	delay_us (245);
	 }
}

void CW ()
{
	P1 = 0x10; 
	delay_ms(speed);
	
	P1 = 0x08;
	delay_ms(speed);
	
	P1 = 0x04; 
	delay_ms(speed);
	
	P1 = 0x02; 
	delay_ms(speed);		
}

void ACW ()
{
	P1 = 0x02; 
	delay_ms(speed);
	
	P1 = 0x04; 
	delay_ms(speed);
	
	P1 = 0x08;
	delay_ms(speed);
	
	P1 = 0x10; 
	delay_ms(speed);	
}


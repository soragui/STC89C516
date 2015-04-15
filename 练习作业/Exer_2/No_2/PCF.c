#include <reg52.h>
#include <intrins.h>
#include "PCF.h"

sbit sda = P2^7;
sbit scl = P2^6;

void start()
{
	sda = 1;
	_nop_();
	scl = 1;
	_nop_();
	sda = 0;
	_nop_();
	scl = 0;
	_nop_();	
}

void stop()
{
	sda = 0;
	_nop_();
	scl = 1;
	_nop_();
	sda = 1;
	_nop_();
}

void checkACK()
{
	scl = 1;
	_nop_();
	while(sda);
	scl = 0;
	_nop_();
}

void sendACK(bit ACK)
{
	if(ACK)
	{
		sda = 1;
	}
	else
	{
		sda = 0;
	}
	scl = 1;
	_nop_();
	scl = 0;
	_nop_();
}

void send_byte(unsigned char date)
{
	unsigned char i, temp;
	temp = date;
	for(i = 0; i < 8; i ++)
	{
		if(temp&0x80)
		{
			sda = 1;
		}
		else
		{
			sda = 0;
		}
		_nop_();
		scl = 1;
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		scl = 0;
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		temp <<= 1;
	}
	checkACK();
}

unsigned char receive_byte()
{
	unsigned char i, temp;
	sda = 1;
	_nop_();
	for(i = 0; i < 8; i++)
	{
		scl = 1;
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		temp = (temp<<1) | sda;
		scl = 0;
		_nop_();
		_nop_();
		_nop_();
		_nop_();
		_nop_();	
	}
	sendACK(0);
	return temp;
}

unsigned char Read_AD(unsigned char chn)
{
	unsigned char ad_data;
	start();
	send_byte(0x90);
	send_byte(0x40 | chn);

	start();
	send_byte(0x91);
	ad_data = receive_byte();
	sendACK(1);
	stop();
	return ad_data;
}
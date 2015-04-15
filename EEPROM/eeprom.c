#include <reg52.h>
#include <intrins.h>
#include "eeprom.h"

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
	while(sda == 1);
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

void send_byte(uchar date)
{
	uchar i, temp;
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
	//checkACK();
}

uchar receive_byte()
{
	uchar i, temp;
	sda = 1;
	_nop_();
	for(i = 0; i < 8; i ++)
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
	return temp;
}

void write_word(uchar device_add, uchar word_add, uchar date)
{
	start();
	send_byte(device_add);
	checkACK();
	send_byte(word_add);
	checkACK();
	send_byte(date);
	checkACK();
	stop();
}

uchar read_word(uchar device_add, uchar word_add)
{
	uchar date;
	start();
	send_byte(device_add);
	checkACK();
	send_byte(word_add);
	checkACK();
	start();
	send_byte(device_add+1);
	checkACK();
	date = receive_byte();
	sendACK(1);
	stop();
	return date;	
}
#include <reg52.h>
#include <intrins.h>
#include "eeprom.h"

void delay(uint);

void main()
{
	uchar temp;                   //定义中间变量
   temp=read_word(0xa0,0);       //从I2C器件a0的第0个地址读出数据赋予temp
   write_word(0xa0,0,temp+1);    //向I2C器件a0的第0个地址写temp+1
   delay(100);                   //延时  
   while(1)                      //死循环
    {
	  temp=read_word(0xa0,0);    //从第0个地址读出一个数据
	  delay(100);                //延时
      P1=~temp;                  //送数据到P1口显示
	}
}

void delay(uint time)
{
	uint i = 110;
	while(time --)
	{
		while(i --);
		i = 110;
	}
}
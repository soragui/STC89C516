#include<reg52.h>  //头文件
#include "delay.h"

int x,y;

/****************延时函数************************/
 void delay(unsigned int sm) //延时函数
{
 for(x=sm;x>0;x--)
  for(y=110;y>0;y--);
}  


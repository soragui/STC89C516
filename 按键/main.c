#include <reg51.h>
#include <intrins.h>
#include "delay.h"

/*sbit delayButton = P3^7;
sbit sound = P2^0; */

uchar keyValue;

void keyScan();
uint keyHandle();

void main()
{
	while(1)
	{
		/*if(!delayButton)
		{
			delay(10);
			while(!delayButton);
			sound = 0;
		}
		sound = 1; */
		keyScan();
		P1 = ~keyHandle();
	}
}

void keyScan()
{
	/*P3 = P3|0xF8;
	if((P3&0xF8) != 0xF8)
	{
		//delay(10);
		if((P3&0xF8) != 0xF8)
		{
			keyValue = P3&0xF8;
		}
	}*/

	/*uchar readcode = 0x00;
	uchar scancode = 0x00;

	P3 = 0xF0;
	if((P3&0xF0) != 0xF0)
	{
		delay(10);
		P3 = 0xF0;
		if((P3&0xF0) != 0xF0)
		{
			scancode = 0xFE;
			while(scancode != 0xEF)
			{
				P3 = scancode;
				if((P3&0xF0) != 0xF0)
				{
				//	while((P3&0xF0) != 0xF0);
					readcode = P3&0xF0;
					scancode = scancode&0x0F;
					keyValue = scancode + readcode;
					return ;
				}
				else
				{
					scancode = _crol_(scancode, 1);
				}
			}
		}
		else
		{
			return ;
		}
	}
	else
	{
		return ;
	} 

	uchar h;
	uchar l;

	P3 = 0xF0;
	if((P3&0xF0) != 0xF0)
	{
		delay(10);
		if((P3&0xF0) != 0xF0)
		{
			h = P3&0xF0;
			P3 = 0x0F;
			l = P3&0x0F;
			keyValue = h | l;	
		}
	}*/

	uchar x,y; 
  P3=0xf0;                              //P3赋值0xf0
  if((P3&0xf0)!=0xf0)                   //判断高4位是否为全1（高4位全1代表没按键按下）

    {
      delay(20);                        //延时去抖动，一般为5ms～10ms（由于机械触点的弹性作用，按键在闭合时不会马上稳定地接通，
	                                    //而在闭合瞬间伴随有一连串的抖动，键抖动会引起一次按键被误读多次）
      if((P3&0xf0)!=0xf0)               //如果还能检测到有键盘按下去 
        {
		  x=P3&0xf0;                    //读取P3口数据
          P3=0x0f;                      //反转，P3赋值0x0f             
          y=P3&0x0f;                    //读取P3口数据
          keyValue=x|y;                 //得到扫描结果
        }
    }
}
/*
uchar keyScan()  
{
  uchar scode=0x00;//扫描码
  uchar rcode=0x00;//读回码
  
  P3=0xf0;
  if((P3&0xf0)!=0xf0)                   //判断高4位是否为全1（高4位全1代表没按键按下）

    {
      delay(20);                        //延时去抖动，一般为5ms～10ms（由于机械触点的弹性作用，按键在闭合时不会马上稳定地接通，
	                                    //而在闭合瞬间伴随有一连串的抖动，键抖动会引起一次按键被误读多次）
      P3=0xf0;
      if((P3&0xf0)!=0xf0)               //还能检测到有键盘按下去，按行扫描
        {
		 
          scode=0xfe;                   //置扫描码
          while(scode!=0xef)            //如果没有扫描完，继续扫描
             {
               P3=scode;                //送扫描码
               if((P3&0xf0)!=0xf0)      //检测到了
                 {
                    rcode=P3;           //保存P3口的状态
                    rcode=rcode & 0xf0; //生成返回码高4位
                    scode=scode & 0x0f; //生成返回码低4位
                    keyValue=scode + rcode;//返回键盘编码, 程序跳出键盘扫描函数（程序执行到return语句的时候就返回，他后面的语句都不会执行）。
					return keyValue;					 
                 }
               else
                 {
                   scode=(scode<<1)|0x01;//移位，产生下一行扫描码,顺序：0xfe>>0xfd>>0xfb>>0xf7>>0xef
				   //scode = _crol(scode, 1)_
				   					     //当扫描码为0xef时，判断条件scode!=0xe为假 ，跳出while 循环
                 }
				
             }
           return(0);  //没有检测到返回0
        }
      else             //没有键盘按下去，上一次是一个干扰 
        {
         return(0);    //没有检测到返回0
        }
    }
  else  //没有键盘按下去
    {
     return(0);  //没有检测到返回0
    }
}*/

uint keyHandle()
{
	switch(keyValue)
	{
		case 0xee:{return(0);break;}	   //对应按键S1
	   case 0xde:{return(1);break;}	   //对应按键S2	
	   case 0xbe:{return(2);break;}	   //对应按键S3	
	   case 0x7e:{return(3);break;}	   //对应按键S4	
	   case 0xed:{return(4);break;}	   //对应按键S5	
	   case 0xdd:{return(5);break;}	   //对应按键S6	
	   case 0xbd:{return(6);break;}	   //对应按键S7	
	   case 0x7d:{return(7);break;}	   //对应按键S8	
	   case 0xeb:{return(8);break;}	   //对应按键S9	
	   case 0xdb:{return(9);break;}	   //对应按键S10	
	   case 0xbb:{return(10);break;}   //对应按键S11	
	   case 0x7b:{return(11);break;}   //对应按键S12
	   case 0xe7:{return(12);break;}   //对应按键S13	
	   case 0xd7:{return(13);break;}   //对应按键S14	
	   case 0xb7:{return(14);break;}   //对应按键S15	
	   case 0x77:{return(15);break;}   //对应按键S16
	   default:{break;}	
	}
}
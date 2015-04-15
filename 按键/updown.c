#include <reg51.h>
#include <intrins.h>
#include "init.h"

uchar code dis[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

long dis_num, num, res;
uchar disw, temp;
uint k, i, op = 0;

void main ()
{
	init_digit();

	while (1)
	{
		dis_num = num;
		disw = 0xFE;
		k = wei(num), i;
		//显示一个数 从个位到最高位
		for (i = 0; i < k; i ++)
		{	
			P0 = _cror_(disw, 1);
			Digit_wei = 1;
			Digit_wei = 0;
			
			P0 = 0x00; Digit_duan = 1; Digit_duan = 0;	//消影
			
			P0 = dis[dis_num%10];
			Digit_duan = 1;
			Digit_duan = 0;
			delay(15);
			
			disw = _cror_(disw, 1);
			dis_num /= 10;
		}
		keyscan();
	}
}

void keyscan()
{
    P2=0xfe;
    temp=P2;
    temp=temp&0xf0;
    while(temp!=0xf0)
    {
      delay(5);
      temp=P2;
      temp=temp&0xf0;
      while(temp!=0xf0)
      {
       	temp=P2;
      	switch(temp)
       {
        case 0xee: num= num/10;
         break;
        case 0xde: num = 0; res = 0;
         break;
        case 0xbe: {
						switch (op)
						{
							case 1: num = num + res; break;
							case 2: num = res - num; break;
							case 3: num = res * num; break;
							case 4: num = res / num; break;
							default : break;
						}
					}
         break;
        case 0x7e: {
						op = 4;
						if (!res) res = num;
						num = 0;
					}
         break;
       }
      while(temp!=0xf0)
       {
        temp=P2;
        temp=temp&0xf0;
       }
      }
     }

    P2=0xfd;
    temp=P2;
    temp=temp&0xf0;
    while(temp!=0xf0)
     {
      delay(5);
      temp=P2;
      temp=temp&0xf0;
      while(temp!=0xf0)
      {
       temp=P2;
      switch(temp)
       {
        case 0xed:num = num * 10 + 7;
         break;
        case 0xdd:num = num * 10 + 8;
         break;
        case 0xbd:num = num * 10 + 9;
         break;
        case 0x7d:{
						op = 3;
						if (!res) res = num;
						num = 0;
					}
         break;
       }
      while(temp!=0xf0)
       {
        temp=P2;
        temp=temp&0xf0;
       }
      }
     }


    P2=0xfb;
    temp=P2;
    temp=temp&0xf0;
    while(temp!=0xf0)
     {
      delay(5);
      temp=P2;
      temp=temp&0xf0;
      while(temp!=0xf0)
      {
       temp=P2;
      switch(temp)
       {
        case 0xeb:num = num * 10 + 4;
         break;
        case 0xdb:num = num * 10 + 5;
         break;
        case 0xbb:num = num * 10 + 6;
         break;
        case 0x7b:{
						op = 2;
						if (!res) res = num;
						num = 0;
					}
         break;
       }
      while(temp!=0xf0)
       {
        temp=P2;
        temp=temp&0xf0;
       }
      }
     }


    P2=0xf7;
    temp=P2;
    temp=temp&0xf0;
    while(temp!=0xf0)
     {
      delay(5);
      temp=P2;
      temp=temp&0xf0;
      while(temp!=0xf0)
      {
       temp=P2;
      switch(temp)
       {
        case 0xe7: num = num * 10 + 1;
         break;
        case 0xd7: num = num * 10 + 2;
         break;
        case 0xb7: num = num * 10 + 3;
         break;
        case 0x77: {
						op = 1;
						if (!res) res = num;
						num = 0;
					}
         break;
       }
      while(temp!=0xf0)
       {
        temp=P2;
        temp=temp&0xf0;
       }
      }
     }
}

 
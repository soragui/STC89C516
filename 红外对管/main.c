/***************************************************************************************************    
工程名称：	IFR_1602
功能描述：  按下遥控器上的任意按键，实现红外遥控器解码，1602液晶显示解码结果。
硬件连接：  用1位杜邦线将J9_2与J5_IFR连接,将1602液晶接口对应插接到P4接口。
维护记录：  2011-8-22
***************************************************************************************************/
#include "reg51.h"          //包含头文件
#define uchar unsigned char
#define uint  unsigned int

extern uchar Read_AD(uchar chn);
extern show();
extern InitLCD();

sbit IFR_in=P3^2;                     //红外触发外部中断管脚

char code Tab[16]="0123456789ABCDEF"; //1602液晶显示0-F的编码
uchar dis2[16];                       //解码结果
uchar  IRQ_num;                       //定时中断进入次数,用判断高低电平的计时
uchar  T_num[33];
bit IRF_ok;                           //解码1次完成标志位
bit irpro_ok,IRF_ok;
unsigned char decode[4];


//**************************************************************************************************
//延时函数
//**************************************************************************************************
delay(uint time)         //int型数据为16位,所以最大值为65535            
 {
  uint  i,j;             //定义变量i,j,用于循环语句 
  for(i=0;i<time;i++)    //for循环,循环50*time次
     for(j=0;j<100;j++); //for循环,循环50次
 }
//**************************************************************************************************
//定时中断0处理函数
//**************************************************************************************************
void IRQ_timer0(void) interrupt 1 using 1
{
  IRQ_num++;   //计数1个周期时间，即2个下降沿之间的时间
}

//**************************************************************************************************
//外部中断0处理函数
//**************************************************************************************************
void IRQ_EX0(void) interrupt 0 
{
  static uchar  i;         //接收红外信号处理
  static bit flag;         //第二次进入中断时，完成第1个周期计时
if(flag)                         
   {
    if(IRQ_num<63&&IRQ_num>=33)//按下一次按键，先来一个13.5ms(9ms+4.5ms)引导码
                        i=0;   //数组重新开始存储接下来的32位数的周期长度
    		T_num[i]=IRQ_num;  //存储每个每个周期的持续时间，用来判断高低电平
    		IRQ_num=0;         //定时中断次数置0，以便开始计数下一个周期的持续时间
    		i++;               //i加1
   			 if(i==33)
      			{
	  			 IRF_ok=1;     //解码1次完成，置标志位
				 i=0;          //数组重新开始存储接下来的32位数的周期长度
	  			}
          }
  	 else
		{
		IRQ_num=0;             //定时中断次数置0   
		flag=1;                //第一次进入中断,置标志位
		}
}
//**************************************************************************************************
//定时0初始化
//**************************************************************************************************
void timer0_init(void)//定时器0初始化
{

  TMOD=0x02; //定时器0工作方式2，自动装入时间常数的8位定时器/计数器
  TH0=0x00; 
  TL0=0x00;  //置初值,(256-0)x12/12000000=0.256ms
  ET0=1;     //开定时器0中断
  TR0=1;     //启动定时器0
}
//**************************************************************************************************
//外部中断0初始化
//**************************************************************************************************
void EX0init(void)
{
 IT0 = 1;   //指定外部中断0下降沿触发，INT0 (P3.2)
 EX0 = 1;   //使能外部中断
 EA = 1;    //开总中断
}
//**************************************************************************************************
//32位二进制得4字节数据
//**************************************************************************************************
void bit_byte(void) 
{ 
  uchar i, j, k=1;
  uchar temp,value;
  for(i=0;i<4;i++)        //循环4次得4字节
     {
      for(j=1;j<=8;j++)   //循环取8位得1字节
         {
          value>>=1;      //左移1位,依次从低位到高位
          temp=T_num[k];  //由于第1个数据为引导码，舍去，所以从第2开即是提取后面的32位
          if(temp>7)      //大于7*0.256=1.8ms为1,周期1.125ms表示"0"；周期2.25ms表示"1"
             value|=0x80; //为1则最高位赋1
          k++;            //k加1，准备提取下1位
         }
     decode[i]=value;     //获取到1字节
     value=0;             //清0，准备提取下1字节        
     } 
}
//**************************************************************************************************
//码值处理函数
//**************************************************************************************************
void code_pro(void)
{
       //处理16位用户码
       dis2[0] = Tab[decode[0]/16];   //取用户码第1字节的高4位
	   dis2[1] = Tab[decode[0]%16];   //取用户码第1字节的低4位
	   dis2[2] = Tab[decode[1]/16];   //取用户码第2字节的高4位
	   dis2[3] = Tab[decode[1]%16];   //取用户码第2字节的低4位

	   dis2[4] = '-';                 //符号
	   dis2[5] = '(';                 //符号
	   dis2[6] = Tab[decode[2]/16];   //处理数据码的高4位
	   dis2[7] = Tab[decode[2]&16];   //处理数据码的低4位
	   dis2[8] = '/';                 //符号
	   dis2[9] = Tab[decode[3]/16];   //处理数据反码的高4位,用于核对数据是否接收准确
	   dis2[10] = Tab[decode[3]%16];  //处理数据反码的低4位
	   dis2[11] =')';                 //符号
}
//**************************************************************************************************
//主函数
//**************************************************************************************************
void main(void)
{
	 uchar ch;
	 EX0init();            //初始化外部中断0
	 timer0_init();        //初始化定时器0
	 InitLCD();            //初始化液晶

 while(1)              //死循环
   {
    if(IRF_ok)         //接收完1次后处理
	  {   
	   bit_byte();     //提取到32位数据
       code_pro();     //码值处理
       show();         //显示码值
	   ch = dis2[6] | dis2[7];
	   P1 = ch;
 	   IRF_ok=0;       //清标志位
	  }  	  
   }
}
  

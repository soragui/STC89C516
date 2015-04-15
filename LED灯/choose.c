#include<reg52.h>  //头文件
#include "choose.h"

/***************选择程序 选择关闭共用IO口的模块*************************/
void choose(void)
 {   P0=0X00; //关闭点阵
     line=0;
     P0=0XFF; //关闭数码管
     wei=0;
  }
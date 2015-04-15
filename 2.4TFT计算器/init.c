
#include "init.h"

#define WINDOW_XADDR_START	0x0050 // Horizontal Start Address Set
#define WINDOW_XADDR_END	0x0051 // Horizontal End Address Set
#define WINDOW_YADDR_START	0x0052 // Vertical Start Address Set
#define WINDOW_YADDR_END	0x0053 // Vertical End Address Set
#define GRAM_XADDR		    0x0020 // GRAM Horizontal Address Set
#define GRAM_YADDR		    0x0021 // GRAM Vertical Address Set
#define GRAMWR 			    0x0022 // memory write

//unsigned int TP_X,TP_Y;	   //当前触控坐标

void spistar()                                     //SPI开始
{
	CS=1;
	DCLK=1;
	DIN=1;
	DCLK=1;
}
//**********************************************************
void WriteCharTo7843(unsigned char num)          //SPI写数据
{
	unsigned char count=0;
	DCLK=0;
	for(count=0;count<8;count++)
	{
		num<<=1;
		DIN=CY;
		DCLK=0; _nop_();_nop_();_nop_();                //上升沿有效
		DCLK=1; _nop_();_nop_();_nop_();
	}
}
//**********************************************************
unsigned int ReadFromCharFrom7843()             //SPI 读数据
{
	unsigned char count=0;
	unsigned int Num=0;
	for(count=0;count<12;count++)
	{
		Num<<=1;
		DCLK=1; _nop_();_nop_();_nop_();                //下降沿有效
		DCLK=0; _nop_();_nop_();_nop_();
		if(DOUT) Num++;
	}
	return(Num);
}

void delayms(int count)  // /* X1ms */
{
        int i,j;
        for(i=0;i<count;i++)
                for(j=0;j<1000;j++);
}

#ifdef  Bus_16    //条件编译-16位数据模式   
void LCD_Writ_Bus(char VH,char VL)   //并行数据写入函数
{
    LCD_DataPortH=VH;	
	LCD_DataPortL=VL;		
	LCD_WR=0;
	LCD_WR=1; 
}
#else			//条件编译-8位数据模式 
void LCD_Writ_Bus(char VH,char VL)   //并行数据写入函数
{	
    LCD_DataPortH=VH;	
   	LCD_WR=0;
	LCD_WR=1;
	LCD_DataPortH=VL;		
	LCD_WR=0;
	LCD_WR=1;
}
#endif

void Lcd_Write_Com(char VH,char VL)	 //发送命令
{	
    LCD_RS=0;
	LCD_Writ_Bus(VH,VL);
}


void Lcd_Write_Data(char VH,char VL)	//发送数据
{
    LCD_RS=1;
	LCD_Writ_Bus(VH,VL);
}

void Address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2)
{
	Lcd_Write_Com(0x00,0x20);Lcd_Write_Data(x1>>8,x1);	  //设置X坐标位置
    Lcd_Write_Com(0x00,0x21);Lcd_Write_Data(y1>>8,y1);   //设置Y坐标位置
    Lcd_Write_Com(0x00,0x50);Lcd_Write_Data(x1>>8,x1);   //开始X
	Lcd_Write_Com(0x00,0x52);Lcd_Write_Data(y1>>8,y1);	  //开始Y
    Lcd_Write_Com(0x00,0x51);Lcd_Write_Data(x2>>8,x2);   //结束X
	Lcd_Write_Com(0x00,0x53);Lcd_Write_Data(y2>>8,y2);   //结束Y
    Lcd_Write_Com(0x00,0x22);							 
}

void Lcd_Init(void)
{

	RD=1;
    LCD_REST=1;
    delayms(5);	
	LCD_REST=0;
	delayms(5);
	LCD_REST=1;
	LCD_CS=1;
	LCD_RD=1;
	LCD_WR=1;
	delayms(5);
   
	LCD_CS =0;  //打开片选使能
	//************* Start Initial Sequence **********//
	Lcd_Write_Com(0x00,0xE5); Lcd_Write_Data(0x78,0xF0); // set SRAM internal timing
	Lcd_Write_Com(0x00,0x01); Lcd_Write_Data(0x01,0x00); // set SS and SM bit
	Lcd_Write_Com(0x00,0x02); Lcd_Write_Data(0x07,0x00); // set 1 line inversion
	Lcd_Write_Com(0x00,0x03); Lcd_Write_Data(0x10,0x30); // set GRAM write direction and BGR=1.
	Lcd_Write_Com(0x00,0x04); Lcd_Write_Data(0x00,0x00); // Resize register
	Lcd_Write_Com(0x00,0x08); Lcd_Write_Data(0x02,0x07); // set the back porch and front porch
	Lcd_Write_Com(0x00,0x09); Lcd_Write_Data(0x00,0x00); // set non-display area refresh cycle ISC[3:0]
	Lcd_Write_Com(0x00,0x0A); Lcd_Write_Data(0x00,0x00); // FMARK function
	Lcd_Write_Com(0x00,0x0C); Lcd_Write_Data(0x00,0x00); // RGB interface setting
	Lcd_Write_Com(0x00,0x0D); Lcd_Write_Data(0x00,0x00); // Frame marker Position
	Lcd_Write_Com(0x00,0x0F); Lcd_Write_Data(0x00,0x00); // RGB interface polarity
	//*************Power On sequence ****************//
	Lcd_Write_Com(0x00,0x10); Lcd_Write_Data(0x00,0x00); // SAP, BT[3:0], AP, DSTB, SLP, STB
	Lcd_Write_Com(0x00,0x11); Lcd_Write_Data(0x00,0x07); // DC1[2:0], DC0[2:0], VC[2:0]
	Lcd_Write_Com(0x00,0x12); Lcd_Write_Data(0x00,0x00); // VREG1OUT voltage
	Lcd_Write_Com(0x00,0x13); Lcd_Write_Data(0x00,0x00); // VDV[4:0] for VCOM amplitude
	Lcd_Write_Com(0x00,0x07); Lcd_Write_Data(0x00,0x01);
	delayms(50); // Dis-charge capacitor power voltage
	Lcd_Write_Com(0x00,0x10); Lcd_Write_Data(0x10,0x90); // 1490//SAP, BT[3:0], AP, DSTB, SLP, STB
	Lcd_Write_Com(0x00,0x11); Lcd_Write_Data(0x02,0x27); // DC1[2:0], DC0[2:0], VC[2:0]
	delayms(50); // Delay 50ms
	Lcd_Write_Com(0x00,0x12); Lcd_Write_Data(0x00,0x1F); //001C// Internal reference voltage= Vci;
	delayms(50); // Delay 50ms
	Lcd_Write_Com(0x00,0x13); Lcd_Write_Data(0x15,0x00); //0x1000//1400   Set VDV[4:0] for VCOM amplitude  1A00
	Lcd_Write_Com(0x00,0x29); Lcd_Write_Data(0x00,0x27); //0x0012 //001a  Set VCM[5:0] for VCOMH  //0x0025  0034
	Lcd_Write_Com(0x00,0x2B); Lcd_Write_Data(0x00,0x0D); // Set Frame Rate   000C
	delayms(50); // Delay 50ms
	Lcd_Write_Com(0x00,0x20); Lcd_Write_Data(0x00,0x00); // GRAM horizontal Address
	Lcd_Write_Com(0x00,0x21); Lcd_Write_Data(0x00,0x00); // GRAM Vertical Address
	// ----------- Adjust the Gamma Curve ----------//
	Lcd_Write_Com(0x00,0x30); Lcd_Write_Data(0x00,0x00);
	Lcd_Write_Com(0x00,0x31); Lcd_Write_Data(0x07,0x07);
	Lcd_Write_Com(0x00,0x32); Lcd_Write_Data(0x03,0x07);
	Lcd_Write_Com(0x00,0x35); Lcd_Write_Data(0x02,0x00);
	Lcd_Write_Com(0x00,0x36); Lcd_Write_Data(0x00,0x08);//0207
	Lcd_Write_Com(0x00,0x37); Lcd_Write_Data(0x00,0x04);//0306
	Lcd_Write_Com(0x00,0x38); Lcd_Write_Data(0x00,0x00);//0102
	Lcd_Write_Com(0x00,0x39); Lcd_Write_Data(0x07,0x07);//0707
	Lcd_Write_Com(0x00,0x3C); Lcd_Write_Data(0x00,0x02);//0702
	Lcd_Write_Com(0x00,0x3D); Lcd_Write_Data(0x1D,0x04);//1604
	
	//------------------ Set GRAM area ---------------//
	Lcd_Write_Com(0x00,0x50); Lcd_Write_Data(0x00,0x00); // Horizontal GRAM Start Address
	Lcd_Write_Com(0x00,0x51); Lcd_Write_Data(0x00,0xEF); // Horizontal GRAM End Address
	Lcd_Write_Com(0x00,0x52); Lcd_Write_Data(0x00,0x00); // Vertical GRAM Start Address
	Lcd_Write_Com(0x00,0x53); Lcd_Write_Data(0x01,0x3F); // Vertical GRAM Start Address
	Lcd_Write_Com(0x00,0x60); Lcd_Write_Data(0xA7,0x00); // Gate Scan Line
	Lcd_Write_Com(0x00,0x61); Lcd_Write_Data(0x00,0x01); // NDL,VLE, REV
	Lcd_Write_Com(0x00,0x6A); Lcd_Write_Data(0x00,0x00); // set scrolling line
	//-------------- Partial Display Control ---------//
	Lcd_Write_Com(0x00,0x80); Lcd_Write_Data(0x00,0x00);
	Lcd_Write_Com(0x00,0x81); Lcd_Write_Data(0x00,0x00);
	Lcd_Write_Com(0x00,0x82); Lcd_Write_Data(0x00,0x00);
	Lcd_Write_Com(0x00,0x83); Lcd_Write_Data(0x00,0x00);
	Lcd_Write_Com(0x00,0x84); Lcd_Write_Data(0x00,0x00);
	Lcd_Write_Com(0x00,0x85); Lcd_Write_Data(0x00,0x00);
	//-------------- Panel Control -------------------//
	Lcd_Write_Com(0x00,0x90); Lcd_Write_Data(0x00,0x10);
	Lcd_Write_Com(0x00,0x92); Lcd_Write_Data(0x06,0x00);
	Lcd_Write_Com(0x00,0x07); Lcd_Write_Data(0x01,0x33); // 262K color and display ON
	LCD_CS =1;  //关闭片选使能

}

void Pant(int dcolor)
{
	int i,j;
	Address_set(0,0,240,320);
    for(i=0;i<320;i++)
	 {
	  for (j=0;j<240;j++)
	   	{
        	 Lcd_Write_Data(dcolor>>8,dcolor);
	    }	  
	  }
}

void draw_rec(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2, int dcolor)
{
	int i, j;
	Address_set(x1, y1, x2, y2);
	for (i = y1; i <= y2; i ++)
	{
		for (j = x1; j <= x2; j ++)
		{
			Lcd_Write_Data(dcolor>>8,dcolor);
		}
	}
}
 
void  Write_Data_U16(unsigned int y)
{
	unsigned char m,n;
	m=y>>8;
	n=y;
	Write_Data(m,n);

}

void Write_Cmd(char YH,char YL)	 
{	
    LCD_CS=0;
	LCD_RS=0;
	LCD_Writ_Bus(YH,YL);
    LCD_CS=1;
}
///////////////////////////////////////发送数据////////////////////////

void Write_Data(char YH,char YL)	
{
    LCD_CS=0;
	LCD_RS=1;
	LCD_Writ_Bus(YH,YL);
	LCD_CS=1;
}
/////////////////////////////////////////////////////////////
void  Write_Cmd_Data (unsigned char x,unsigned int y)
{
	unsigned char m,n;
	m=y>>8;
	n=y;
	Write_Cmd(0x00,x);
	Write_Data(m,n);
}

void Put_mych(unsigned short x, unsigned short y, unsigned int width, unsigned int height, const char mycode[], unsigned int fColor)
{
    unsigned int i, j;
    unsigned int k, l;
    
    k = width*height/8;
    l = width/8;
    
    for(i = 0; i < k; i ++) {
        unsigned short m = mycode[i];
        for(j = 0; j < 8; j ++) {
            if((m&0x80) == 0x80) {
                LCD_SetPos(y+i/l, y+i/l, x+i%l*8+j, x+i%l*8+j);
                Write_Data_U16(fColor);
            }
            m <<= 1;
        }
    }
}


void LCD_SetPos(unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1)
{
	Write_Cmd_Data(WINDOW_XADDR_START,x0);
	Write_Cmd_Data(WINDOW_XADDR_END,x1);
	Write_Cmd_Data(WINDOW_YADDR_START,y0);
	Write_Cmd_Data(WINDOW_YADDR_END,y1);
	Write_Cmd_Data(GRAM_XADDR,x0);
	Write_Cmd_Data(GRAM_YADDR,y0);
	Write_Cmd (0x00,0x22);//LCD_WriteCMD(GRAMWR);
}

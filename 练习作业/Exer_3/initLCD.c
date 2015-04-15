#include <reg51.h>
#include <math.h>
#include "initLCD.h"

#define DataPort P0   // ˝æ›ø⁄ π”√DataPor
#define PI 3.141592

sbit RS    =P2^5;		// ˝æ›√¸¡Ó—°‘Ò
sbit RW    =P2^4;       //–¥ ˝æ›/√¸¡Ó
sbit nRD   =P2^3;       //∂¡øÿ÷∆
sbit CS    =P2^2;		//∆¨—°
sbit RES   =P2^1;		//∏¥Œª

sbit LE    =P2^0;       //74HC573À¯¥Êøÿ÷∆

unsigned int Device_code=0x9328;

void delayms(unsigned int count)
{
    int i,j;                                                                                
    for(i=0;i<count;i++)                                                                    
       {
	     for(j=0;j<255;j++);
       }                                                                                     
}

void Write_Cmd(unsigned char DH,unsigned char DL)
{
	CS=0;
	RS=0;
    nRD=1;
    RW=0;

    //◊¢“‚£∫µ± π”√8Œª ˝æ›ø⁄«˝∂Ø16Œª ˝æ›ƒ£ Ω ±£¨ π”√74HC573◊˜Œ™IO¿©’π£¨≥Ã–Ú»Áœ¬
    DataPort=DL;            //ÀÕµÕ8Œª√¸¡Ó∏¯573¥˝À¯¥Ê
    LE=1;                   //À¯¥ÊŒª
    LE=0;                   //∂œø™À¯¥Ê,Œª—°573µƒQ7~Q0»‘±£≥÷ 

	DataPort=DH;            //ÀÕ∏ﬂ8Œª√¸¡Ó∏¯TFT

	/*
    //»Áπ˚ π”√16Œª ˝æ›ø⁄«˝∂Ø16Œª ˝æ›ƒ£ Ω£¨‘ÚŒﬁ–ËIO¿©’π£¨÷±Ω”Ω´ ˝æ›ÀÕµΩ ˝æ›ø⁄º¥ø…
    DataPort_L=DL; 
    DataPort_H=DH;
	*/

	RW=1;
	CS=1;
}

void Write_Data(unsigned char DH,unsigned char DL)
{
	
	CS=0;
	RS=1;

    //◊¢“‚£∫µ± π”√8Œª ˝æ›ø⁄«˝∂Ø16Œª ˝æ›ƒ£ Ω ±£¨ π”√74HC573◊˜Œ™IO¿©’π£¨≥Ã–Ú»Áœ¬
	DataPort=DL;            //ÀÕµÕ8Œª ˝æ›∏¯573¥˝À¯¥Ê
    LE=1;                   //À¯¥ÊŒª
    LE=0;                   //∂œø™À¯¥Ê,Œª—°573µƒQ7~Q0»‘±£≥÷ 

	DataPort=DH;            //ÀÕ∏ﬂ8Œª ˝æ›∏¯TFT

	/*
    //˝æ›ø⁄«˝∂Ø16Œª ˝æ›ƒ£ Ω£¨‘ÚŒﬁ–ËIO¿©’π£¨÷±Ω”Ω´ ˝æ›ÀÕµΩ ˝æ›ø⁄º¥ø…
    DataPort_L=DL; 
    DataPort_H=DH;
	*/

	RW=0;
	RW=1;
	CS=1;
}

void  Write_Data_U16(unsigned int y)
{
	unsigned char m,n; 
	m=y>>8;
	n=y;
	Write_Data(m,n);
}

void  Write_Cmd_Data (unsigned char x,unsigned int y)
{
	unsigned char m,n;
	m=y>>8;
	n=y;
	Write_Cmd(0x00,x);
	Write_Data(m,n);
}

void TFT_Initial(void)
{  

    RES = 1;    
	delayms(1);                    // Delay 1ms 
	RES = 0;  
	delayms(10);                   // Delay 10ms            
	RES = 1;  
	delayms(50);                   // Delay 50 ms  
  
	if(Device_code==0x9320)
     {

    //************* Start Initial Sequence **********//
	Write_Cmd_Data(0x00,0x0001);   //Set the OSC bit as °Æ1°Ø to start the internal oscillator
    Write_Cmd_Data(0x01,0x0100);   // set SS and SM bit
	Write_Cmd_Data(0x02,0x0700);   // set 1 line inversion
	Write_Cmd_Data(0x03,0x1030);   //set GRAM Write direction and BGR=1
    Write_Cmd_Data(0x04,0x0000);   // Resize register
	Write_Cmd_Data(0x08,0x0202);   // set the back porch and front porch
    Write_Cmd_Data(0x09,0x0000);   // set non-display area refresh cycle ISC[3:0]
    Write_Cmd_Data(0x0A,0x0000);   // FMARK function
    Write_Cmd_Data(0x0C,0x0000);   // RGB interface setting
	Write_Cmd_Data(0x0D,0x0000);   // Frame marker Position
    Write_Cmd_Data(0x0F,0x0000);   // RGB interface polarity
    delayms(30);
	//*************Power On sequence ****************//
	Write_Cmd_Data(0x10, 0x16b0);   // SAP, BT[3:0], AP, DSTB, SLP, STB
	delayms(30);
	Write_Cmd_Data(0x11, 0x0007);   //Write final user°Øs setting values to VC bit
	Write_Cmd_Data(0x12, 0x013a);   // set Internal reference voltage
	Write_Cmd_Data(0x13, 0x1a00);   // VDV[4:0] for VCOM amplitude
    delayms(30);
    Write_Cmd_Data(0x29, 0x000c);   // Set VCM[5:0] for VCOMH
	delayms(30); // Delay 50ms

	// ----------- Adjust the Gamma Curve ----------//
	Write_Cmd_Data(0x0030, 0x0000);
	Write_Cmd_Data(0x0031, 0x0505);
	Write_Cmd_Data(0x0032, 0x0304);
	Write_Cmd_Data(0x0035, 0x0006);
	Write_Cmd_Data(0x0036, 0x0707);
	Write_Cmd_Data(0x0037, 0x0105);
	Write_Cmd_Data(0x0038, 0x0002);
	Write_Cmd_Data(0x0039, 0x0707);
	Write_Cmd_Data(0x003C, 0x0704);
	Write_Cmd_Data(0x003D, 0x0807);

	//------------------ Set GRAM area ---------------//
	Write_Cmd_Data(0x0050, 0x0000); // Horizontal GRAM Start Address
	Write_Cmd_Data(0x0051, 0x00EF); // Horizontal GRAM End Address
	Write_Cmd_Data(0x0052, 0x0000); // Vertical GRAM Start Address
	Write_Cmd_Data(0x0053, 0x013F); // Vertical GRAM Start Address
	Write_Cmd_Data(0x0060, 0x2700); // Gate Scan Line
	Write_Cmd_Data(0x0061, 0x0001); // NDL,VLE, REV
	Write_Cmd_Data(0x006A, 0x0000); // set scrolling line
    Write_Cmd_Data(0x20, 0x0000);   // GRAM horizontal Address
	Write_Cmd_Data(0x21, 0x0000);   // GRAM Vertical Address

	//-------------- Partial Display Control ---------//
	Write_Cmd_Data(0x0080, 0x0000);
	Write_Cmd_Data(0x0081, 0x0000);
	Write_Cmd_Data(0x0082, 0x0000);
	Write_Cmd_Data(0x0083, 0x0000);
	Write_Cmd_Data(0x0084, 0x0000);
	Write_Cmd_Data(0x0085, 0x0000);

	//-------------- Panel Control ---------//
    Write_Cmd_Data(0x90,0x0010);   //Frame Cycle Contral
	Write_Cmd_Data(0x92,0x0000);   //Panel Interface Contral
	Write_Cmd_Data(0x93,0x0003);   //Panel Interface Contral 3. 
	Write_Cmd_Data(0x95,0x0110);   //Frame Cycle Contral
	Write_Cmd_Data(0x97,0x0000);   // 
	Write_Cmd_Data(0x98,0x0000);   //Frame Cycle Contral.     

	//-------------- Display on ---------//
    Write_Cmd_Data(0x07,0x0173); 

	}

	else if(Device_code==0x1505 )
     {

    //************* Start Initial Sequence **********//
	Write_Cmd_Data(0x00,0x0001);   //Set the OSC bit as °Æ1°Ø to start the internal oscillator
    Write_Cmd_Data(0x01,0x0100);   // set SS and SM bit
	Write_Cmd_Data(0x02,0x0700);   // set 1 line inversion
	Write_Cmd_Data(0x03,0x1030);   //set GRAM Write direction and BGR=1
    Write_Cmd_Data(0x04,0x0000);   // Resize register
	Write_Cmd_Data(0x08,0x0202);   // set the back porch and front porch
    Write_Cmd_Data(0x09,0x0000);   // set non-display area refresh cycle ISC[3:0]
    Write_Cmd_Data(0x0A,0x0000);   // FMARK function
    Write_Cmd_Data(0x0C,0x0000);   // RGB interface setting
	Write_Cmd_Data(0x0D,0x0000);   // Frame marker Position
    Write_Cmd_Data(0x0F,0x0000);   // RGB interface polarity
    delayms(30);
	//*************Power On sequence ****************//
	Write_Cmd_Data(0x10, 0x16b0);   // SAP, BT[3:0], AP, DSTB, SLP, STB
	delayms(30);
	Write_Cmd_Data(0x11, 0x0007);   //Write final user°Øs setting values to VC bit
	Write_Cmd_Data(0x12, 0x013a);   // set Internal reference voltage
	Write_Cmd_Data(0x13, 0x1a00);   // VDV[4:0] for VCOM amplitude
    delayms(30);
    Write_Cmd_Data(0x29, 0x000c);   // Set VCM[5:0] for VCOMH
	delayms(30); // Delay 50ms

	// ----------- Adjust the Gamma Curve ----------//
	Write_Cmd_Data(0x0030, 0x0000);
	Write_Cmd_Data(0x0031, 0x0505);
	Write_Cmd_Data(0x0032, 0x0304);
	Write_Cmd_Data(0x0035, 0x0006);
	Write_Cmd_Data(0x0036, 0x0707);
	Write_Cmd_Data(0x0037, 0x0105);
	Write_Cmd_Data(0x0038, 0x0002);
	Write_Cmd_Data(0x0039, 0x0707);
	Write_Cmd_Data(0x003C, 0x0704);
	Write_Cmd_Data(0x003D, 0x0807);

	//------------------ Set GRAM area ---------------//
	Write_Cmd_Data(0x0050, 0x0000); // Horizontal GRAM Start Address
	Write_Cmd_Data(0x0051, 0x00EF); // Horizontal GRAM End Address
	Write_Cmd_Data(0x0052, 0x0000); // Vertical GRAM Start Address
	Write_Cmd_Data(0x0053, 0x013F); // Vertical GRAM Start Address
	Write_Cmd_Data(0x0060, 0x2700); // Gate Scan Line
	Write_Cmd_Data(0x0061, 0x0001); // NDL,VLE, REV
	Write_Cmd_Data(0x006A, 0x2700); // set scrolling line
    Write_Cmd_Data(0x20, 0x0000);   // GRAM horizontal Address
	Write_Cmd_Data(0x21, 0x0000);   // GRAM Vertical Address

	//-------------- Partial Display Control ---------//
	Write_Cmd_Data(0x0080, 0x0000);
	Write_Cmd_Data(0x0081, 0x0000);
	Write_Cmd_Data(0x0082, 0x0000);
	Write_Cmd_Data(0x0083, 0x0000);
	Write_Cmd_Data(0x0084, 0x0000);
	Write_Cmd_Data(0x0085, 0x0000);

	//-------------- Panel Control ---------//
    Write_Cmd_Data(0x90,0x0010);   //Frame Cycle Contral
	Write_Cmd_Data(0x92,0x0000);   //Panel Interface Contral
	Write_Cmd_Data(0x93,0x0003);   //Panel Interface Contral 3. 
	Write_Cmd_Data(0x95,0x0110);   //Frame Cycle Contral
	Write_Cmd_Data(0x97,0x0000);   // 
	Write_Cmd_Data(0x98,0x0000);   //Frame Cycle Contral.     

	//-------------- Display on ---------//
    Write_Cmd_Data(0x07,0x0173); 

	}

    else if(Device_code==0x9328)
     {

    //************* Start Initial Sequence **********//
	 Write_Cmd_Data(0x0001,0x0100);   //set SS and SM bit //…Ë÷√…®√Ë∑ΩœÚ
    Write_Cmd_Data(0x0002,0x0700);   //EOR=1 and B/C=1 to set the line inversion  //…Ë÷√––∑¥◊™
    Write_Cmd_Data(0x0003,0x1030);   //set Entry Mode  //…Ë÷√Ω¯»Îƒ£ Ω   
    Write_Cmd_Data(0x0004,0x0000);   //
    Write_Cmd_Data(0x00A4,0x0001);
    Write_Cmd_Data(0x0008,0x0202); // set the back porch and front porch
    Write_Cmd_Data(0x0009,0x0000); // set non-display area refresh cycle ISC[3:0]
    Write_Cmd_Data(0x000A,0x0000); // FMARK function
    Write_Cmd_Data(0x000C,0x0000); // RGB interface setting
    Write_Cmd_Data(0x000D, 0x0000); // Frame marker Position
    Write_Cmd_Data(0x000F, 0x0000); // RGB interface polarity



//*************Power On sequence ****************//
    Write_Cmd_Data(0x0010, 0x0000); // SAP, BT[3:0], AP, DSTB, SLP, STB 
    Write_Cmd_Data(0x0011, 0x0007); // DC1[2:0], DC0[2:0], VC[2:0]
    Write_Cmd_Data(0x0012, 0x0000); // VREG1OUT voltage
    Write_Cmd_Data(0x0013, 0x0000); // VDV[4:0] for VCOM amplitude 
    delayms(30);
    Write_Cmd_Data(0x0010, 0x1690); // SAP, BT[3:0], AP, DSTB, SLP, STB 
    Write_Cmd_Data(0x0011, 0x0227); // R11h=0x0221 at VCI=3.3V, DC1[2:0], DC0[2:0], VC[2:0]
    delayms(30);
    Write_Cmd_Data(0x0012, 0x001C); // External reference voltage= Vci;
    delayms(30); 
    Write_Cmd_Data(0x0013, 0x1800); // R13=1200 when R12=009D;VDV[4:0] for VCOM amplitude
    Write_Cmd_Data(0x0029, 0x001C); // R29=000C when R12=009D;VCM[5:0] for VCOMH
    Write_Cmd_Data(0x002B, 0x000D); // Frame Rate = 91Hz
    delayms(30);    
    Write_Cmd_Data(0x0020, 0x0000); // GRAM horizontal Address
    Write_Cmd_Data(0x0021, 0x0000); // GRAM Vertical Address
// ----------- Adjust the Gamma Curve ----------// 		 
	Write_Cmd_Data(0x0030, 0x0007);
	Write_Cmd_Data(0x0031, 0x0302);
    Write_Cmd_Data(0x0032, 0x0105);
	Write_Cmd_Data(0x0035, 0x0206);
    Write_Cmd_Data(0x0036, 0x0808);	          
    Write_Cmd_Data(0x0037, 0x0206);
    Write_Cmd_Data(0x0038, 0x0504);
    Write_Cmd_Data(0x0039, 0x0007);
    Write_Cmd_Data(0x003C, 0x0105);
    Write_Cmd_Data(0x003D, 0x0808);
//------------------ Set GRAM area ---------------//
    Write_Cmd_Data(0x0050, 0x0000); // Horizontal GRAM Start Address
    Write_Cmd_Data(0x0051, 0x00EF); // Horizontal GRAM End Address
    Write_Cmd_Data(0x0052, 0x0000); // Vertical GRAM Start Address
	delayms(30);
    Write_Cmd_Data(0x0053, 0x013F); // Vertical GRAM Start Address
	delayms(30);
    Write_Cmd_Data(0x0060, 0xA700); // Gate Scan Line
    Write_Cmd_Data(0x0061, 0x0001); // NDL,VLE, REV  
    Write_Cmd_Data(0x006A, 0x0000); // set scrolling line
//-------------- Partial Display Control ---------//
    Write_Cmd_Data(0x0080, 0x0000);
    Write_Cmd_Data(0x0081, 0x0000);
    Write_Cmd_Data(0x0082,0x0000); 
    Write_Cmd_Data(0x0083,0x0000); 
    Write_Cmd_Data(0x0084,0x0000); 
    Write_Cmd_Data(0x0085,0x0000); 
//-------------- Panel Control -------------------//        
    Write_Cmd_Data(0x0090, 0x0010);
    Write_Cmd_Data(0x0092, 0x0000);
    Write_Cmd_Data(0x0093, 0x0003);
    Write_Cmd_Data(0x0095, 0x0110);
    Write_Cmd_Data(0x0097, 0x0000);
    Write_Cmd_Data(0x0098, 0x0000);
    Write_Cmd_Data(0x0007, 0x0133); // 262K color and display ON

	}
}

void LCD_SetPos(unsigned int x0,unsigned int x1,unsigned int y0,unsigned int y1)
{

  Write_Cmd_Data(0x50,x0);  // Horizontal GRAM Start Address
  Write_Cmd_Data(0x51,x1);  // Horizontal GRAM End Address
  Write_Cmd_Data(0x52,y0);  // Vertical GRAM Start Address
  Write_Cmd_Data(0x53,y1);  // Vertical GRAM Start Address
  Write_Cmd_Data(0x20,x0);  // GRAM horizontal Address
  Write_Cmd_Data(0x21,y0);  // GRAM Vertical Address
  Write_Cmd (0x00,0x22);    // 0x0022,Start to Write Data to GRAM 
}

void CLR_Screen(unsigned int bColor)
{
 unsigned int i,j;
 LCD_SetPos(0,240,0,320);//320x240
 for (i=0;i<320;i++)
	{
	   for (j=0;j<240;j++)
	       Write_Data_U16(bColor);
	}
}

void Put_pixel(unsigned int x, unsigned int y, unsigned int color)
{
	LCD_SetPos(x, x, y, y);
	Write_Data_U16(color);
}

void Set_Color(uchar x, uint y, uchar length, uint high, uchar color)
{
	 uchar i, xi;
	 uint  j, xj;
	 xi =  x+length-1;
	 xj =  y+high-1;
	 LCD_SetPos(x, xi, y, xj);
	 for(i = x; i < xi; i ++)
	 {
	 	for(j = y; j < xj; j ++)
		{
			Write_Data_U16(color);
		}
	 }
}

void circle(unsigned int x, unsigned int y, unsigned int r, unsigned int color)
{
	unsigned int i;
	for(i = 0; i <= 360; i ++)
	{
		Put_pixel(x + cos(i*PI/180)*r, y + sin(i*PI/180)*r, color);
	}
}

void GUI_DisPicture(uchar x, uint y, uchar length, uint high ,const uchar *pic)
//void GUI_DisPicture(uchar x, uint y, uchar length, uint high)
{
    unsigned int temp=0,tmp=0,num=0;
	LCD_SetPos(x, x+length-1, y, y+high-1);
	num=length*high*2;
	do
	{  
	   //temp=pic[tmp]|( pic[tmp+1]<<8);
	   temp=pic[tmp+1];
	   temp=temp<<8;
	   temp=temp|pic[tmp];
	   Write_Data_U16(temp);//÷µ„œ‘ æ
	   tmp+=2;
	}while(tmp<num);
}

void GUI_HLine(uchar x, uint y, uchar length, uint color) 
{  
//LCD_SetPos(x,y,x+length-1,y);
	//do
//	{  
//		Write_Data_U16(color);//÷µ„œ‘ æ£¨√Ë≥ˆÀÆ∆Ωœﬂ
//		length--;
//	}while(length);
	uchar i;
	for(i = x; i < length; i ++)
	{
		Put_pixel(i, y, color);
	}
}

void GUI_VLine(uint X, uint Y0, uint Y1, unsigned int color) 
{  
	uint i;
	//Y0 = Y0 > Y1?Y1:Y0;
	for(i = Y0; i < Y1; i ++) {
		Put_pixel(X, i, color);
	}
}


/*void line(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned int color)
{
	
} */

//void Put_mych(unsigned short x, unsigned short  y,unsigned int width, unsigned int height,  const char mycode[], unsigned int fColor,unsigned int bColor)
//{
//	unsigned int i, j, k;
//	unsigned short m;
//	unsigned int num = 0;
//	num = width*height/8;
//	LCD_SetPos(x,  x+width-1,y, y+height-1);
//	for(i = 0; i < num; i ++)
//	{
//		//num += i;
//		//for(j = 0; j < width/8; j ++) {
//			//num += j;
//			m = mycode[i];
//			for(k = 0; k < 8; j ++)
//			{
//				   if((m&0x80) == 0x80)
//				   {
//						Write_Data_U16(fColor);
//				   }
//				   else
//				   {
//						Write_Data_U16(bColor);
//				   }
//				   m <<= 1;
//			}
//		//}
//	}
//}

void Put_mych(unsigned short x, unsigned short  y,unsigned int width, unsigned int height,  short from,const char mycode[], unsigned int fColor,unsigned int bColor)
{
	unsigned int i, j, k;
	unsigned int num;
	unsigned char m;
	unsigned short count;
	//num = width*height/8;
	num = 0;
	count = width/8;
    
	if(from > 0) {
        unsigned short bj = from/8;
        LCD_SetPos(x+from, x+width-1, y, y+height-1);
        for(i = 0; i < height; i ++) {
            for(j = bj; j < count; j ++) {
                num = count*i + j;
                m = mycode[num];
                
                if(j == bj) {
                    m <<= (from%8);
                    for(k = (from%8); k < 8; k ++) {
                       if((m&0x80) == 0x80) {
                            Write_Data_U16(fColor);
                       } else {
                            Write_Data_U16(bColor);
                       }
                       m <<= 1;
                    }
                } else {
                    for(k = 0; k < 8; k ++) {
                       if((m&0x80) == 0x80) {
                            Write_Data_U16(fColor);
                       } else {
                            Write_Data_U16(bColor);
                       }
                       m <<= 1;
                    }
                }
            }
        }
	} else if(from < 0) {
        unsigned short ej = (-from)/8;
        count -= ej;
        LCD_SetPos(x,  x+from+width-1,y, y+height-1);
        for(i = 0; i < height; i ++) {
            for(j = 0; j < count; j ++) {
                num = width/8*i + j;
                m = mycode[num];
                
                if(j == count-1) {
                    ej = (8-(-from)%8);
                    for(k = 0; k < ej; k ++) {
                       if((m&0x80) == 0x80) {
                            Write_Data_U16(fColor);
                       } else {
                            Write_Data_U16(bColor);
                       }
                       m <<= 1;
                    }
                } else {
                    for(k = 0; k < 8; k ++) {
                       if((m&0x80) == 0x80) {
                            Write_Data_U16(fColor);
                       } else {
                            Write_Data_U16(bColor);
                       }
                       m <<= 1;
                    }
                }
            }
        }
    }else {
        LCD_SetPos(x,  x+width-1,y, y+height-1);
        for(i = 0; i < height; i ++) { 
            for(j = 0; j < count; j ++) {
                num = count*i + j;
                m = mycode[num];
                for(k = 0; k < 8; k ++) {
                       if((m&0x80) == 0x80) {
                            Write_Data_U16(fColor);
                       } else {
                            Write_Data_U16(bColor);
                       }
                       m <<= 1;
                }
            }
        }
    }
}



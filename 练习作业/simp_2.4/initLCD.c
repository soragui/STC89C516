#include "initLCD.h"

void delayms(int time)
{
    int i, j;
    for(i = 0; i < time; i ++)
        for(j = 0; j < 1000; j ++);
}

void Lcd_Write_Com(unsigned char DH, unsigned char DL)
{
    LCD_RS = 0;
    LCD_DataPortH=DH;	
   	LCD_WR = 0;
	LCD_WR = 1;
	LCD_DataPortH=DL;		
	LCD_WR = 0;
	LCD_WR = 1;
}

void Lcd_Write_Data(unsigned char DH, unsigned char DL)
{
    LCD_RS = 1;
    LCD_DataPortH=DH;	
   	LCD_WR = 0;
	LCD_WR = 1;
	LCD_DataPortH=DL;		
	LCD_WR = 0;
	LCD_WR = 1;
}

void Lcd_Write_Data_U16(unsigned int dat)
{
    Lcd_Write_Data(dat>>8, dat);
}

void Lcd_Write_Com_Data(unsigned char cmd, unsigned int dat)
{
    Lcd_Write_Com(0x00, cmd);
    Lcd_Write_Data(dat>>8, dat);
}

void TFT_Initial(void)
{

	RD=1;
    LCD_RESET=1;
    delayms(5);	
	LCD_RESET=0;
	delayms(5);
	LCD_RESET=1;
	LCD_CS=1;
	LCD_RD=1;
	LCD_WR=1;
	delayms(5);
   
	LCD_CS =0;  //ղߪƬѡʹŜ
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
	LCD_CS =1;   

}

void Lcd_SetPos(unsigned int x0, unsigned int x1, unsigned int y0, unsigned int y1)
{
    Lcd_Write_Com_Data(WINDOW_XADDR_START,x0);
	Lcd_Write_Com_Data(WINDOW_XADDR_END,x1);
	Lcd_Write_Com_Data(WINDOW_YADDR_START,y0);
	Lcd_Write_Com_Data(WINDOW_YADDR_END,y1);
	Lcd_Write_Com_Data(GRAM_XADDR,x0);
	Lcd_Write_Com_Data(GRAM_YADDR,y0);
	Lcd_Write_Com (0x00,0x22);
}

void CLR_Screen(unsigned int bColor)
{
    int i, j;
    Lcd_SetPos(0, 240, 0, 320);
    for(i = 0; i < 320; i ++) 
        for(j = 0; j < 240; j ++)
            Lcd_Write_Data_U16(bColor);
}
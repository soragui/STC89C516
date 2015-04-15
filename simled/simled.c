/*A simple led example
 *
*/
sfr P0 = 0x80;
sfr P1 = 0x90;


sbit P11 = P1^1;
sbit P00 = P0^0;

void delay(unsigned int time);
void disableDigital();

void main(void)
{
	disableDigital();
	while(1) {
		P00 = ~P00;
		delay(1200);
	}
}

void disableDigital()
{
	P11 = 1;
	P0  = 0xFF;
	P11 = 0;
}

void delay(unsigned int time)
{
	for(; time > 0; time --);
}
#include "18F2550.h"

//#include "16F887.h"
#USE delay(clock=8000000)
#FUSES NOMCLR, NOBROWNOUT, INTRC_IO,CPUDIV1,PLL2
#BYTE TRISB = 0xF93
#include <PCD8544.c>
int x=0;
void main(void)
{
	TRISB=0x00;
	PCD_begin(40,0x04);
	PCD_setContrast(40);
	PCD_display();
	delay_ms(1000);
	PCD_clearDisplay();
	PCD_display();
	delay_ms(100);
	while(TRUE)
	{

		PCD_setCursor(0,0);
		printf(PCD_drawChart,"CALLING:");
		PCD_setCursor(0,16);		
		printf(PCD_drawChart,"Number=%d",x);
		x++;
		PCD_setCursor(0,32);
		printf(PCD_drawChart,"   ANSWER?");
		PCD_setCursor(0,40);
		printf(PCD_drawChart," YES       NO");
		PCD_display();
		//delay_ms(100);
		//PCD_spiWrite(0xAA);
	}
}
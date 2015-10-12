#include "18F2550.h"

//#include "16F887.h"
#USE delay(clock=8M)
#FUSES NOMCLR, NOBROWNOUT, INTRC_IO,CPUDIV1,PLL1, NOWDT
#use rs232(baud=115200,bits=8, xmit=PIN_C6,rcv=PIN_C7, parity=N, TIMEOUT=5000)
#BYTE TRISB = 0xF93

#include <PCD8544.c>
char InputBuffer[85]={0};
unsigned int option=0,i=0;

#INT_RDA
void isr()
{
	int16 index=0;
	char c=0;
    do
    {	
		c=getc();
    }while(index<84 && c!=':'&& c!=0);//'\n');
	if(c!=0)
	{
		do
    	{
       		InputBuffer[index]=getc();	
			index++;
    	}while(index<84 && InputBuffer[index-1]!=','&& InputBuffer[index-1]!=0);//'\n');
		InputBuffer[index-1]=0;
		printf("%s",InputBuffer);
	}
output_toggle(PIN_B3);
}

void main(void)
{
	setup_oscillator(OSC_INTRC | OSC_8MHZ);	
	TRISB=0x00;
	PCD_begin(40,0x04);
	PCD_setContrast(40);
	PCD_display();
	delay_ms(300);
	PCD_clearDisplay();
	PCD_display();
	delay_ms(5000);
	set_tris_c(0x10);
	output_low(PIN_C0);
	while(TRUE)
	{	
		
		//printf("%s",InputBuffer);
		PCD_clearDisplay();
		PCD_setCursor(0,0);
		printf(PCD_drawChart,"%s",InputBuffer);
		//printf(PCD_drawChart,"MENU:");
		PCD_setCursor(0,8);
		if(option==0)printf(PCD_drawChart,"DISABLED");		
		//printf(PCD_drawChart,"Option 1");
		//PCD_setCursor(0,16);
		if(option==1)printf(PCD_drawChart,"ENABLED");
		//printf(PCD_drawChart,"Option 2");
		//PCD_setCursor(0,24);
		//if(option==2)printf(PCD_drawChart,">");
		//printf(PCD_drawChart,"Option 3");
		printf("buffer:%s",InputBuffer);
		disable_interrupts(INT_RDA);
		disable_interrupts(GLOBAL); 
		PCD_display();
		enable_interrupts(INT_RDA);
	    enable_interrupts(GLOBAL); 
		//option++;
		//if(option==3) option=0;
		delay_ms(1000);
		if(option==1) 
			{output_high(PIN_C0);delay_ms(2000);option=0;output_low(PIN_C0);PCD_setCursor(0,8);}
		for(i=0;i<=20;i++)
		{
			if(InputBuffer[i]=='1' && InputBuffer[i+1]=='6' && InputBuffer[i+2]=='5') option=1;
		}
		
	}
}


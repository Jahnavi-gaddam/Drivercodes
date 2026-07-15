#include<lpc21xx.h>
#include"header1.h"
extern unsigned char a[20];
extern unsigned int flag;
void uart0_isr(void)__irq
{
	static int i;
	int r;
	r=U0IIR;
	r&=0x0E;
	if(r==4)
	{
		a[i]=U0RBR;
			if(a[i]=='\r')
				uart0_tx('*');
			if(a[i]=='\r'||i==18)
			{
				
			if(i==18)
				i++;
			a[i]='\0';
			i=-1;
			flag=1;
		}
			i++;
	}
	VICVectAddr=0;
}


void config_vic_for_uart0(void)
	{
	VICIntSelect=0;
		VICVectCntl0=6|(1<<5);
		VICVectAddr0=(int)uart0_isr;
	VICIntEnable=(1<<6);
	}
	void config_uart0(void)
	{
		U0IER=3;
   }

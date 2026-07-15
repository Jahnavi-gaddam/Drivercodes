#include <LPC21xx.H>
#include "header.h"
extern unsigned int flag;
extern unsigned char arr[20];
void uart0_handler(void)__irq
{
	
char temp;
int r=U0IIR;
	static int i;
r&=0x0E;
if(r==4)
{
arr[i]=U0RBR;
if(arr[i]=='\r'||i==18)
{
	if(i==18)
		i++;
	arr[i]='\0';
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
VICVectAddr0=(int)uart0_handler;
VICIntEnable=(1<<6);
}
void config_uart0(void)
{
U0IER=3;
}

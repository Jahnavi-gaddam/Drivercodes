#include<lpc21xx.h>
#include "header1.h"

void uart0_init(unsigned int baud)
{
int a[]={15,60,30,15,15};
unsigned int result=0,pclk;
pclk=a[VPBDIV]*1000000;
result=pclk/(16*baud);
PINSEL0|=0X05;
U0LCR=0X83;
U0DLM=(result>>8)&0xff;
U0DLL=result&0xff;
U0LCR=0X03;
}
#define THRE ((U0LSR>>5)&1)
void uart0_tx(unsigned char data)
{
 U0THR=data;
	while(THRE==0);
}
#define RDR ((U0LSR)&1)
unsigned char uart0_rx(void)
{
while(RDR==0);
return U0RBR;
}
void uart0_tx_string(char *ptr)
{
	while(*ptr)
	{
		U0THR=*ptr;
		while(THRE==0);
		ptr++;
	}
}
void uart0_tx_integer(int num)
{
	int a[10],i;
	if(num==0)
	{
		uart0_tx('0');
		return;
	}
	if(num<0)
	{
		num=-num;
	 uart0_tx('-');
}
i=0;
while(num>0)
{
	a[i]=(num%10)+48;
	num=num/10;
	i++;
}
		for(i=i-1;i>=0;i--)
		uart0_tx(a[i]);
	}

void uart0_tx_float(float f)
{
	int i=0;
	i=f;
	uart0_tx_integer(i);
	uart0_tx('.');
	i=(f-i)*100;
	uart0_tx_integer(i);
}
	



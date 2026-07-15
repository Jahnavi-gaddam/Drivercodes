#include<LPC21XX.H>
//#include"header.h"
#define THRE ((U0LSR>>5)&1)
#define RDR (U0LSR&1)
void uart0_init(unsigned int baud)
{
unsigned int pclk,result=0;
int a[]={15,60,30,15,15};
pclk=a[VPBDIV]*100000;
result=pclk/(16*baud);
PINSEL0|=0x5;
U0LCR=0x83;
U0DLL=result&0xff;
U0DLM=(result>>8)&0xff;
U0LCR=0x03;
}
void uart0_tx(unsigned char data)
{
U0THR==0;
while(THRE==0);
}

unsigned char uart0_rx(void);
{
while(RDR==0);
return U0RBR;
}
void uart0_tx_string(char *ptr);
{
while(*ptr)
{
UOTHR=*ptr;
while(THRE==0);
ptr++;
}
}





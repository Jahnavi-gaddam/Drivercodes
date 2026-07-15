#include<LPC21XX.H>
#include"header.h"
#define THRE ((U0LSR>>5)&1)
#define RDR (U0LSR&1)
void uart0_init(unsigned int baud)
{
unsigned char a[]={15,60,30,15,15};
unsigned int pclk=0,result=0;
pclk=a[VPBDIV]*1000000;
result=pclk/(16*baud);
PINSEL0 |=0X05;
U0LCR=0X83;
U0DLL=result&0XFF;
U0DLM=(result>>8)&0xff;
U0LCR=0x03;
}
void uart0_tx(unsigned char data)
{
U0THR=data;
while(THRE==0);
}
unsigned char uart0_rx(void)
{
while(RDR==0);
return U0RBR;
}
void uart0_tx_string(const char *ptr)
{
while(*ptr)
{
U0THR=*ptr;
while(THRE==0);
ptr++;
}
}
void uart0_integer(int num)
{
if(num<0)
{
num=-num;
uart0_tx('-');
}
if(num==0)
uart0_tx('0');
if(num>0)
{
int i=0;
char a[20],t;
for(i=0;num;num=num/10,i++)
{
t=num%10;
a[i]=(t+48);
}
for(i=i-1;i>=0;i--)
uart0_tx(a[i]);
}
}
void uart0_float(float f)
{
//if(f==0){
//uart0_tx(’0’);
//return;
// }
if(f<0)
{
f=-f;
uart0_tx('-');
}
int num=f;
uart0_integer(num);
uart0_tx('.');
num=(f-num)*10000;
uart0_integer(num);
}







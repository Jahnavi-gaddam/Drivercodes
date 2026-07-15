#include <LPC21xx.H>
#include "header1.h"
extern unsigned char a[13];
unsigned int count2;
unsigned char i;
unsigned char flag;
void uart0_handler(void)__irq
{
 int r=U0IIR&0x0e;
 if(r==4)
 {
 a[i++]=U0RBR;
 U0THR=U0RBR;
 if(a[i-1]=='\r'||i==13)
 {
 flag=1;
 a[i-1]='\0';
 i=0;
 }
 }
 VICVectAddr=0;
 }

 void config_vic_for_uart0_string(void)
 {
 VICVectCntl1=6|(1<<5);
 VICVectAddr1=(int)uart0_handler;
 VICIntEnable=(1<<6);
 }
 void config_uart0(void)
{
 U0IER=1;
}

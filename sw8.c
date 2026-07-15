#include<LPC21XX.H>
#include"header.h"
#define sw ((IOPIN0>>14)&1)
#define sw1 ((IOPIN0>>15)&1)
#define sw2 ((IOPIN0>>16)&1)
main()
{
	int count=0;
while(1)
{
if(sw==0)
{
while(sw==0);
count++;
}
if(sw1==0)
{
while(sw1==0);
count--;
}
if(sw2==0)
{
while(sw2==0);
while(count!=0)
{
count--;
delay_ms(200);
}
}
}
}

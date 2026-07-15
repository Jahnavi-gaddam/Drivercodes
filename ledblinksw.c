#include<LPc21XX.H>
#include"header.h"
#define sw ((IOPIN0>>14)&1)
main()
{
int count=0;
IODIR0=1<<17;
IOSET0=1<<17;
while(1)
{
int count=0;
if(sw==0)
{
T0PC=0;
T0PR=15000000-1;
T0TC=0;
T0TCR=1;
while(sw==0);
count++;
while(T0TC<1)
{
if(sw==0)
{
while(sw==0);
count++;
}
}
T0TCR=0;
}
if(count==2)
IOCLR0=1<<17;
if(count==1)
IOSET0=1<<17;
}
}

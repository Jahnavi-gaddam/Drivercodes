#include<lpc21xx.h>
#include"header.h"
#define sw1 ((IOPIN0>>14)&1)
#define sw2 ((IOPIN0>>15)&1)
main()
{
 int i=0;
 IODIR0=1<<17;
 IOSET0=1<<17;
  while(1)
	{
	 if(sw1==0||sw2==0)// switch is ready to pressed
	 {
	 while(sw1==0||sw2==0);//switch is released
	 {
	  i=i^1;
	  if(i==1)
		IOSET0=1<<17;
		if(i==0)
		IOCLR0=1<<17;
		}
	}
 }
}

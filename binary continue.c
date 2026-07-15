#include<lpc21xx.h>
#include"header.h"
#define sw ((IOPIN0>>14)&1)
main()
{
	int i;
 IODIR0=7<<0;
 IOSET0=7<<0;
  while(1)
  {
   for(i=0;i<=7;i++)
   {
    IOCLR0=i<<0;
	 delay_ms(200);
	IOSET0=i<<0;
	 delay_ms(200);
   }
  }
 } 
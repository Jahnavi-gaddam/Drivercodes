#include<lpc21xx.h>
#include"header.h"
#define sw ((IOPIN0>>14)&1)
main()
{
	int count=0;
	 IODIR0=7<<17;
	 IOSET0=7<<17;
	  while(1)
	{
		if(sw==0)
		{
			while(sw==0);
			 count++;
			if(count>7)
				count=0;
		
				IOCLR0=count<<17;
			    delay_ms(20);
			  IOSET0=count<<17;
		}
	}
}

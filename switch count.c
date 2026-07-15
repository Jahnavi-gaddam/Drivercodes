#include<lpc21xx.h>
#include "header.h"
#define sw ((IOPIN0>>14)&1)
main()
{
 int c=0;
 while(1)
 {
  if(sw==0)
	{
	 while(sw==0);
	 c++;
		if(c>10)
			c=0;
	 }
	}
}


#include <LPC21xx.H>
#define led 7<<17
#define led1 1<<17
#define led2 1<<18
#define led3 1<<19

#define sw1 ((IOPIN0>>14)&1)
#define sw2 ((IOPIN0>>15)&1)
#define sw3 ((IOPIN0>>16)&1)
main()
{
 int c=0;
 IODIR0=led;
 IOSET0=led;
  while(1)
	{
	 if(sw1==0)
	 {
	 IOCLR0=led1;
	 while(sw1==0);
	  IOSET0=led1;
		if(c<59)
		{
		 c++;
		 }
		}
		if(sw2==0)
		{
		 IOCLR0=led2;
		 while(sw2==0);
		 IOSET0=led2;
		 if(c>0)
		 {
		 c--;
		 }
		 }          
    if(sw3==0)
		{
		 IOCLR0=led3;
		  while(sw3==0);
			IOSET0=led3;
			for(;c>0;c--);
		}
	}
}
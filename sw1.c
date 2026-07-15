#include <LPC21xx.H>
#include"header.h"
#define sw ((IOPIN0>>14)&1)
#define led 1<<17;
/*main()
{
	IODIR0=1<<17;
	IOSET0=1<<17;
	 while(1)
	 {
		 int c=0;
		 if(sw==0) //waiting to switch pressed
		 {
			 while(sw==0);//waiting to switch release
			 c++; //count for switch press and release
			 T0PC=0; //set starting count value
			 T0PR=15000000-1;//set ending count value
			 T0TC=0;
			 T0TCR=1;//start timer0
			 while(T0TC<1);//waiting for 1 sec delay
			 {
				 if(sw==0)//switch pressed  in 1 sec
				 {
					 while(sw==0);//switch released in 1 sec
					 c++;
				 }
			 }
			 T0TCR=0;//stop timer0
		 }
		 if(c==2)//count 2 twice on & off
			 IOCLR0=1<<17;
			if(c==1)//count 1 off
				IOSET0=1<<17;
	 }
 }*/
 
 int delay_sec1(const unsigned int sec)
 {
	 unsigned int c1=1;
	  T0PC=0;
	  T0PR=15000000-1;
	  T0TC=0;
	  T0TCR=1;
	  while(T0TC<sec)
		{
			if(sw==0)
			{
				while(sw==0);
				 c1++;
			}
		}
		T0TCR=0;
		return c1;
	}
 main()
	{
		unsigned int c;
		IODIR0=led;
		IOSET0=led;
		while(1)
		{
			if(sw==0)
			{
				while(sw==0);
				c=delay_sec1(1);
				if(c==2)
				{
					IOCLR0=led;
				}
				else if(c==1)
				{
					IOSET0=led;
				}
			}
		}
	}
	
 
	 


 
 
 
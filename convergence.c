#include<lpc21xx.h>
#include"header.h"
main()
//convergence
/*{
	int i,j;
 IODIR0=0XFF;
 IOSET0=0xFF;
  delay_ms(100);
  while(1)
  {
   for(i=0,j=7;i<j;i++,j--)
   {
    IOCLR0=1<<i|1<<j;
	 delay_ms(100);
	IOSET0=1<<i|1<<j;
	delay_ms(100);
	}
  }
}*/
// divergence
/*{ 
	int i,j;
	IODIR0=0XFF;
	IOSET0=0XFF;
	 while(1)
	 {
		 for(i=3,j=4;i>=0;i--,j++)
		 {
			 IOCLR0=1<<i|1<<j;
			  delay_ms(100);
			 IOSET0=1<<i|1<<j;
			  delay_ms(100);
		 }
	 }
 }*/
//convergence and divergence
/*{ 
	int i,j;
	IODIR0=0XFF;
	IOSET0=0XFF;
	 while(1)
	 {
		 for(i=0,j=7;i<8;i++,j--)
		 {
			 IOCLR0=1<<i|1<<j;
			  delay_ms(100);
			 IOSET0=1<<i|1<<j;
			  delay_ms(100);
		 }
	 }
 }*/
 {
	 IODIR0=0XFF;
	 IOSET0=0XFF;
	  while(1)
		{
			int i,j;
			for(i=0,j=7;i<7&&j>=0;i++,j--)
			{
				IOCLR0=1<<i|1<<j;
				 delay_ms(100);
				IOSET0=1<<i|1<<j;
				 delay_ms(100);
			}
		}
	}

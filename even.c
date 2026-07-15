#include<LPC21XX.H>
/*main()
{
 IODIR0=1<<0|1<<2|1<<4|1<<6;
 IOSET0=1<<0|1<<2|1<<4|1<<6;
delay_ms(200);
  while(1)
  {
 IOCLR0=1<<0|1<<2|1<<4|1<<6;
   delay_ms(200);
 IOSET0=1<<0|1<<2|1<<4|1<<6;
   delay_ms(200);
	 }
}*/

/*main()
{
IODIR0=0XFF;
IOSET0=0xFF;
while(1)
{
	IOSET0=0xAA;
	delay_ms(200);
	
	IOCLR0=0xAA;
	delay_ms(200);
	IOSET0=0x55;
	delay_ms(200);
	IOCLR0=0x55;
	delay_ms(200);
}
}*/
main()
{
	IODIR0=0XFF;
	IOSET0=0XFF;
	 //delay_ms(250);
	while(1)
	{
		for(int i=0;i<8;i=i+2)
		{
			IOCLR0=1<<i;
			 delay_ms(250);
			IOSET0=1<<i;
			 delay_ms(250);
		}
	 for(int j=1;j<8;j=j+2)
		{
			IOCLR0=1<<j;
			 delay_ms(250);
			IOSET0=1<<j;
			 delay_ms(250);
		}
	}
}


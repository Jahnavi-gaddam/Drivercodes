#include<LPC21XX.H>
main()
{
int temp,i,a,b;
//uart0_init();
while(1)
{
uart0_tx_string("\r\n enter the op : ");
uart0_tx_string(" a. for LED blinking: ");
uart0_tx_string("b. for LED shifting : ");
temp=uart0_rx();
uart0_tx(temp);
if(temp==a)
{
IOCLR0=255;
delay_ms(200);
IOSET0=255;
delay_ms(200);
}
if(temp==b)
{
for(i=0;i<8;i++)
{
IOCLR0=1<<i;
delay_ms(200);
IOSET0=1<<i;
//delay_ms(200);
}
}
}
}

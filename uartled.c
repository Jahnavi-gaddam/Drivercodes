#include<LPC21XX.H>
#include"header.h"
#define LED1 (1<<17)
#define LED2(1<<18)
main()
{
unsigned char cmd;
IODIR0|=LED1|LED2;
uart0_init(9600);
uart0_tx_string("\r\n menu");
uart0_tx_string("\r\n a.LED1.ON");
uart0_tx_string("\r\n b.LED2.OFF");
while(1)
{
cmd=uart0_rx();
uart0_tx(cmd);
switch(cmd)
{
case 'a':IOCLR0=LED1;
break;
case 'b':IOSET0=LED2;
break;
}
}



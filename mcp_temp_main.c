#include <LPC21xx.H>
#include "header.h"
unsigned int flag;
main()
{
uart0_init(9600);
adc_init();
config_uart0();
config_vic_for_uart0_init();
uart0_tx_string("\r\n press an enter key to read the temperature sensor");
while(1)
{
float vout,temp;
unsigned int adc_out;
adc_out=adc_read(1);
vout=(adc_out*3.3)/1023;
temp=(vout-0.5)/0.01;
if(flag==1)
{
uart0_float(temp);
uart0_tx_string("degrees");
flag=0;
uart0_tx_string("\r\n press an enter key to read the temperature sensor");
}
}
}

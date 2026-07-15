#include<lpc21xx.h>
#include "header1.h"
main()
{
unsigned int adcout;
float vout,tempr;
adc_init();
uart0_init(9600);
uart0_tx_string("TEST TEMP\r\n");
while(1)
{
adcout=adc_read(1);
vout=(adcout*3.3)/1023;
tempr=(vout-0.5)/0.01;
uart0_tx_float(tempr);
uart0_tx_string("\r\n");
}
}


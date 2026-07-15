/*#include<LPC21XX.h>
#include"header.h"
#define LED (1<<17)
char arr[13];
int flag,flag1;
main()
{
int k=0;
	IODIR0=0xFF;
	char p[5]="****";
uart0_init(9600);
config_uart0_intr();

	config_vic_for_uart0();
uart0_tx_string("enter the password\r\n");
while(1)
{
IOSET0=0xFF;
delay_ms(10);
if(flag==1)
{
flag=0;
for(k=0;arr[k]&&p[k];k++)
{
if(arr[k]!=p[k])
break;
}
if(arr[k]=='\0'&&p[k]=='\0')
uart0_tx_string("\r\n you are correct\r\n");
else
uart0_tx_string("\r\n wrong password\r\n");
uart0_tx_string("enter the password\r\n");
}
}
}*/


#include <LPC21xx.H>
#include "header.h"
unsigned int flag;
main()
{
uart0_init(9600);
adc_init();
config_uart0();
config_vic_for_uart0();
uart0_transx_string("\r\nPress an enter key to read the temperature sensor ");
while(1)
{
float vout,temp;
unsigned int adc_out;
adc_out = read_mcp(1);
vout=(adc_out*3.3)/1023;
temp=(vout-0.5)/0.01;
if(flag==1)
{
uart0_float(temp);
uart0_transx_string("degrees");
flag=0;
uart0_transx_string("\r\nPress an enter key to read the temperature sensor ");
}
}
}





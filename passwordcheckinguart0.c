#include<LPC21XX.h>
#include"header.h"
#define LED (1<<17)
char arr[13];
int flag,flag1;
main()
{
int k=0;
	IODIR0=0xFF;
	char p[5]="sunny";
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
}


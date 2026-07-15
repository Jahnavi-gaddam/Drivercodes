/* password check*/
#include<LPC21XX.H>
#include "header.h"
char arr[20];
int flag;
main()
{
int i=0;
IODIR0=0XFF;
IOCLR0=0X0FF;
char p[5]="sunny";
config_for_uart0();
config_vic_for_uart0();
uart0_init(9600);
uart0_tx_string("enter the password\r\n");
while(1)
{
IOSET0=0XFF;
if(flag==1)
{
flag=0;
for(i=0;arr[i]&&p[i];i++)
{
if(arr[i]!=p[i])
break;
}
if(arr[i]=="\0"&&p[i]=="\0")
uart0_tx_string("entered correct password\r\n");
else
uart0_tx_string("wrong password\r\n");
uart0_tx_string("enter the password\r\n");
}
}
}

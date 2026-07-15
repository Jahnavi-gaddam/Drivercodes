#include<lpc21xx.h>
#include <string.h>
#include "header1.h"
unsigned int c;
char a[13],f=0;
char temp;
extern unsigned char flag;
main()
{
	int i,j;
	uart0_init(9600);
 config_vic_for_uart0_string();
	config_uart0();
	while(1)
	{
		if(f==0)
		{
			uart0_tx_string("enter string:");
			f=1;
		}
		c++;
		if(flag==1)
		{
			flag=0;
			uart0_tx_string(a);
			uart0_tx_string("\r\n");
			int len;
			for(len=0;a[len];len++);
			for(i=0,j=len-1;i<j;i++,j--)
			{
				temp=a[i];
				a[i]=a[j];
				a[j]=temp;
			}
			uart0_tx_string("result:");
			uart0_tx_string(a);
			uart0_tx_string("\r\n");
			f=0;
		}
	}
}

#include<LPC21xx.h>
#include"header.h"
unsigned int flag;

unsigned char a[20];
main()
{
	int i,len;
	unsigned char b[20]="jahnavi";
	for(len=0;b[len];len++);
	uart0_init(9600);
	config_vic_for_uart0();
	config_uart0();
	
	
	uart0_tx_string("\r\n enter the password:");
	while(1)
	{
		
		if(flag==1)
		{
			flag=0;
//			uart0_tx_string(a);
			for(i=0;b[i];i++)
			{
				if(a[i]!=b[i])
					break;
			}
			if(a[i]==b[i])
				uart0_tx_string("\r\nenter correct password");
			else
				uart0_tx_string("\r\nwrong password");
			uart0_tx_string("\r\n enter the password:");
		}
	}
}

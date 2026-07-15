#include<lpc21xx.h>
#include "header1.h"
main()
{
	unsigned char op,n;
	int n1=0,n2=0,i;
	uart0_init(9600);
	uart0_tx_string("\r\n enter the no of digits:");
	while(1)
	{
		int a[10];
		n=uart0_rx();
		uart0_tx(n);
		n=n-48;
		n1=0;
		n2=0;
		uart0_tx_string("\r\n enter the first num:");
      for(i=0;i<n;i++)
		{
			a[i]=uart0_rx();
			uart0_tx(a[i]);
			n1=n1*10+a[i]-48;
		}
		uart0_tx_string("\r\nenter the second num:");
		for(i=0;i<n;i++)
		{
			a[i]=uart0_rx();
			uart0_tx(a[i]);
			n2=n2*10+a[i]-48;
		}
		
		uart0_tx_string("\r\nenter the option:");
		uart0_tx_string("\r\n a)ADD:");
		uart0_tx_string("\r\n b)SUB:");
		uart0_tx_string("\r\nc)MUL:");
		uart0_tx_string("\r\n d)DIV:");
		
    op=uart0_rx();
    uart0_tx_string("\r\n");
    uart0_tx(op);
    uart0_tx_string("\r\n");
		switch(op)
		{
			case 'a':uart0_integer(n1+n2);break;
			case 'b':uart0_integer(n1-n2);break;
			case 'c':uart0_integer(n1*n2);break;
			case 'd':uart0_integer(n1/n2);break;
			default :uart0_tx_string("\r\n entered wrong option");
		}
		uart0_tx_string("\r\n enter no.of digits:");
	}
}

		



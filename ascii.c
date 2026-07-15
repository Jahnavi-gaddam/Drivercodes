#include<LPC21XX.H>
#include"header.h"
main()
{
unsigned char temp;
uart0_init(9600);
while(1)
{
uart0_tx_string("\r\n Enter the char: ");
temp=uart0_rx();
uart0_tx(temp);
while((uart0_rx())!='\r');
uart0_tx_string("\r\n ASCII: ");
uart0_tx_integer(temp);
uart0_tx_string("\r\n binary: ");
uart0_tx_binary(temp);
uart0_tx_string("\r\n Hexa:0x ");
uart0_tx_hexa(temp);
uart0_tx_string("\r\n OCTAl:0 ");
uart0_tx_octal(temp);
}
}

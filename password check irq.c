#include<lpc21xx.h>
#include"header1.h"
extern signed char arr[13],flag;
void uart0_handler(void) __irq{
	int r=U0IIR;
	static int i;
	r=r&0x0e;
	if(r==4){
		arr[i]=U0RBR;
			if(arr[i]=='\r'){
				arr[i]='\0';
				i=-1;
				flag=1;
			}
			if(i==11){
				arr[12]='\0';
				i=-1;
				flag=1;
			}
			i++;
	}
	VICVectAddr=0;
}

void config_for_vic_uart0(void){
	VICVectCntl1=6|(1<<5);
	VICVectAddr1=(int)uart0_handler;
	VICIntEnable=(1<<6);
	U0IER=3;
}

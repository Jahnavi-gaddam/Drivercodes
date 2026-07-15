#include<lpc21xx.h>
#include "header.h"
void delay_ms(unsigned int ms)
{
 T0PC=0;   //set starting count value
 T0PR=15000-1;   //set ending value for 1 sec delay
 T0TC=0;
 T0TCR=1;      //start timer0
 while(T0TC<ms);    //waiting for timer0 to overflow
 T0TCR=0;     //stop timer0
}
void delay_sec(unsigned int sec)
{
 T0PC=0;    // set starting count value
 T0PR=15000000-1;   //set ending value for 1 sec delay
 T0TC=0;
 T0TCR=1;   //start timer
 while(T0TC<sec); //waiting for timer0 to overflow
 T0TCR=0;   //stop timer
}


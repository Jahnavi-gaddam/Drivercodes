#include <LPC21xx.H>
#include "header1.h"
void lcd_data(unsigned char data)
{
//higher nibble 
IOCLR1=0xFE<<16;// clear all the gpio pins
IOSET1=(data&0xF0)<<16;//higher nibble
IOSET1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19;

//lower nibble
IOCLR1=0xFE<<16;
IOSET1=(data&0X0F)<<20;
IOSET1=1<<17;
IOSET1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19;
}
void lcd_cmd(unsigned char cmd)
{
//higher nibble
IOCLR1=0xFE<<16;
IOSET1=(cmd&0xF0)<<16;
IOCLR1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(2);
IOCLR1=1<<19;

//lower nibble
IOCLR1=0XFE<<16;
IOSET1=(cmd&0x0F)<<20;
IOCLR1=1<<17;//RS=0
IOCLR1=1<<18;//RW=0
IOSET1=1<<19;//EN=1
delay_ms(2);
IOCLR1=1<<19;//en=0
}
void lcd_init()
{
 IODIR1=0XFE<<16;
 PINSEL2=0X0;
 IOCLR1=1<<19;//en=0
 lcd_cmd(0x02);//enable lcd 4bit mode 
 lcd_cmd(0x28);//select 1st and 2nd row of lcd
 lcd_cmd(0x0E);//enable cursor
 lcd_cmd(0x01);//to clear the screen
}

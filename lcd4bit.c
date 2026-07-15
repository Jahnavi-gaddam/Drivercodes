#include<LPC21XX.H>

void lcd_data(unsigned char data)
{
IOCLR1=0xFE<<16;
IOSET1=(data&0xf0)<<16;
IOSET1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(200);
IOCLR1=1<<19;

IOCLR1=0xFE<<16;
IOSET1=(data&0x0f)<<20;
IOSET1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
delay_ms(200);
IOCLR1=1<<19;
}
void lcd_cmd(unsigned char cmd)
{
IOCLR1=0xFE<<16;
IOSET1=(cmd&0xf0)<<16;
IOCLR1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
//delay_ms(200);
IOCLR1=1<<19;

IOCLR1=0xFE<<16;
IOSET1=(cmd&0x0f)<<20;
IOCLR1=1<<17;
IOCLR1=1<<18;
IOSET1=1<<19;
//delay_ms(200);
IOCLR1=1<<19;
}
void lcd_init()
{
IOCLR1=0xFE<<16;
PINSEL2=0x0;
IOCLR1=1<<19;
lcd_cmd(0x02);
lcd_cmd(0x28);
lcd_cmd(0x0e);
lcd_cmd(0x01);
}


/*void lcd_integer(int num)
{
int a[10],i;
if(num==0)
{
lcd_data('0');
}
if(num<0)
{
num=-num;
lcd_data('-');
}
if(num>0)
{
for(i=0;num;num/=10,i++)
{
a[i]=num%10+48;
}
for(i=i-1;i>=0;i--)
{
lcd_data(a[i]);
}
}
void lcd_float(float f)
{
int a[10],i;
if(f==0)
{
lcd_string("0.0");
}
if(f<0)
{
f-f;
lcd_data('-');
}
if(f>0)
{
num=f;
lcd_integer(num);
lcd_data('.');
num=(f-num)*100000;
lcd_integer(num);
}
}*/

/*main()
{
char *ptr;
char s[20]="taruni";
int i,len;


for(ptr=s,len=0;(*ptr),ptr++,len++);
len=strlen(s);
lcd_init();
while(1)
{
for(i=0,k=len;i<16;i++)
{
lcd_cmd(0x80+i)
lcd_string(s);
}
if(i+k-1>15)
{
lcd_cmd(0x80);
lcd_string(s+16-i);
k--;
delay_ms(200);
}
delay_ms(200);
lcd_cmd(0x01);
}
*/

/*#define sw ((IOPIN0>>14)&1)
main()
{
int count=0;
IODIR0=7<<17;
IOSET0=7<<17;
while(1)
{
if(sw==0)
{
while(sw==0);
count++;
if(count>7)
count=0;
IOCLR0=count<<17;
IOSET0=count<<17;
}
}*/
/*#define sw ((IOPIN0>>14&1)
main()
{
int flag=0;
while(1)
{
if(sw==0)
{
while(sw==0);
{
flag=flag^1;
if(flag==0)
IOSET0=1<<17;
if(flag==1)
IOCLR0=1<<17;
}*/

/*main()
{
lcd_init();
while(1)
{
for(i=0,j=7;i<8;i++,j--)
{
IOCLR0=1<<i|1<<j;
delay_ms(200);
IOSET0=1<<i|1<<j;*/




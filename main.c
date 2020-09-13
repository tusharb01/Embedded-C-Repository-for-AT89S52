#include<reg51.h>
sbit PIN0=P0^0;

void delay(unsigned int m)
{
unsigned int i,j;
	for(m;m>0;m--)
	{
	 for(i=250;i>0;i--);
	 for(j=247;j>0;j--);
	}
}
void main(void)
{
	while(1)
	{
		PIN0=1;
		delay(500);
		PIN0=0;
		delay(500);
	}
}

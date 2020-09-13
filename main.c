#include<reg51.h>
#include "delay.h"
sbit PIN0=P0^0;


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

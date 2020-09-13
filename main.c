#include<reg51.h>
#include "delay.h"

sbit LED=P2^0;
sbit SW1=P1^0;


void main(void)
{
	while(1)
	{	
			if(SW1==0)
				LED=0;
			else
				LED=1;
	}
}

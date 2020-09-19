#include <reg51.h>
#include "delay.h"
#include "lcd.h"
void main(void)
{
	lcd_init();
	lcd_data("A");
	while(1);
	//lcd_string("AT89S52");
	/*while(1)
	{	
			if(SW1==0)
				LED=0;
			else
				LED=1;
	}*/
}

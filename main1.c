#include <reg52.h>
#include "delay.h"
#include "lcd.h"
void main()
{
	unsigned int c;
	init();
	string("AT89S52");
		while(1)
		{
			if(sw==0)
			{
				led=0;
				++c;
				cmd (0xc0);
				lcd_integer(c);
			}
			else
			{
			led=1;
			c=0;
			cmd (0x01);
			
			}
					

		}
//	custom();
//	string("Electronics Hub ");
//	cmd(0xc0);
//	string("    Presents    ");
//	delay(2000);
//	cmd(0x01);
//	cmd(0x80);
//	string("  Custom Chars  ");
//	cmd(0xc0);
//	string("  on 16x2 LCD   ");
//	delay(2000);
//	cmd(0x01);
//	cmd(0x80);
//	string("ABCDEFGHIJKLMNOP");
//	cmd(0xc0);
//	string("1234567890");
//	cmd(0xca);
//	display(0);
//	display(1);
//	display(2);
//	display(3);
//	display(4);
//	display(5);

}
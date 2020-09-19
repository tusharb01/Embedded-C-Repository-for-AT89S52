#define lcd P1
sbit sw=P2^2;
sbit led=P2^3;
sbit rs=P2^0;
sbit e=P2^1;


void cmd (char);
void display (char);
void custom (void);
void string (char *);
void init (void);

unsigned char custom_char[]= {0x00,0x04,0x0E,0x04,0x15,0x0E,0x04,0x00, 
	                      0x00,0x04,0x0E,0x0E,0x0E,0x1F,0x04,0x00, 
	                      0x00,0x0A,0x15,0x11,0x11,0x0A,0x04,0x00,
			      0x0E,0x11,0x11,0x1F,0x1B,0x1B,0x1B,0x1F,
	                      0x0E,0x11,0x10,0x1F,0x1B,0x1B,0x1B,0x1F,
			      0x00,0x0E,0x15,0x1B,0x0E,0x0E,0x00,0x00,
	                      };
	                          

void cmd (char c)
{
	lcd=c;
	rs=0;
	e=1;
	delay(5);
	e=0;
}
void display (char c)
{
	lcd=c;
	rs=1;
	e=1;
	delay(5);
	e=0;
}
void custom (void)
{
	int k;
	cmd(0x40);
	for(k=0;k<48;k++)
	display(custom_char[k]);
	cmd(0x80);
}

void string (char *p)
{
	while(*p)
	{
		display(*p++);
	}
}
void init (void)
{
	cmd(0x38);
	cmd(0x0c);
	cmd(0x01);
	cmd(0x80);
}

void lcd_integer(int i)
{
int num,k=0;
char a[15];
num=i;
if(num==0)
{
	display('0');
	return;
}
else if(num<0)
{
	display('-');
num=-num;
}
for(num;num;num=num/10)
{
a[k++]=(num%10)+48;	
}
while(k--)
	display(a[k]);	
}

//#define LCD_PORT P0
//sbit RS=P2^0;
////sbit RW=P3^5;
//sbit EN=P2^1;

//void lcd_cmd(unsigned char c)
//{
//LCD_PORT=c;
//RS=0;
////RW=0;
//EN=1;
//delay(1);
//EN=0;

//}

//void lcd_data(unsigned char d)
//{
//LCD_PORT=d;
//RS=1;
////RW=0;
//EN=1;
//delay(1);
//EN=0;
//}

//void lcd_init()
//{
//lcd_cmd(0x2);
//lcd_cmd(0x38);
//lcd_cmd(0x6);
//lcd_cmd(0xE);
//lcd_cmd(0x1);
//}
///*
//sfr LCD_PORT=0x80;
//sbit LED=P2^0;
//sbit SW1=P2^1;
//sbit RS=P3^4;
//sbit RW=P3^5;
//sbit EN=P3^6;
///*
//void lcd_cmd(unsigned char c);
//void lcd_data(unsigned char d);
//void lcd_init(void);
//void lcd_string(char *);*/

///*
//void lcd_cmd(unsigned char c)
//{
//	LCD_PORT=c;
//	RS=0;
//	RW=0;
//	EN=1;
//	delay(5);
//	EN=0;
//}*/

///*
//void lcd_data(unsigned char d)
//{
//	LCD_PORT=d;
//	RS=1;
//	RW=0;
//	EN=1;
//	delay(5);
//	EN=0;
//}*/

///*
//void lcd_init(void)
//{
//	lcd_cmd(0x02);
//	lcd_cmd(0x38);
//	lcd_cmd(0x06);
//	lcd_cmd(0x0E);
//	lcd_cmd(0x01);
//}
//*/
///*
//void lcd_string(char *s)
//{
//	while(*s)
//		lcd_data(*s++);
//}*/
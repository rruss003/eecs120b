#include <avr/io.h>

int main(void)
{
	DDRA = 0; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 7;

	/* Replace with your application code */
	unsigned char ls0 = 0;
	unsigned char ls1 = 0;
	
	while (1)
	{
		unsigned char pc= PORTC;
		unsigned char pa0 = PINA & 1, pa1 = PINA & 2;
		if (pa0 == 1)
		{
			if (pa1)
				pc = 0;
			else
				if (ls0 == 0)
				{
					ls0 = 1;
					if (pc != 9)
						pc ++;
				}
		}
		else
		{
			if (ls0 == 1)
				ls0 = 0;
			if (pa1 == 1)
			{
				if (ls1 == 0)
				{
					ls1 = 1;
					if (pc != 0)
						pc --;
				}
			}
			else
				if (ls1 == 1)
					ls1 = 0;
		}
				
	
		
		PORTC = pc;
	}
	return 0;
}
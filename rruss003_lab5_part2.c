#include <avr/io.h>

int main(void)
{
	DDRA = 0; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 7;

	/* Replace with your application code */
	unsigned char ls0 = 0;
	unsigned char ls1 = 0;
	
	while (1)
	{
		unsigned char pb= PORTB;
		unsigned char pa0 = !(PINA & 1), pa1 = !(PINA & 2);
		if (pa0 == 1)
		{
			if (pa1)
			pb = 0;
			else
			{
				if (!ls0)
				{
					if (pb != 9)
					pb ++;
				}
				ls0 = 1;
			}
		}
		else
		{
			ls0 = 0;
			if (pa1)
			{
				if (!ls1)
				{
					if (pb != 0)
						pb --;
				}
				ls1 = 1;
			}
			else
				ls1 = 0;
		}
		
		PORTB = pb;
	}
	return 0;
}
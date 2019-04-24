#include <avr/io.h>

int main(void)
{
	DDRA = 0; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 1;

	/* Replace with your application code */
	unsigned char lastState = 0;
	while (1)
	{
		unsigned char pb = PORTB;
		unsigned char pa0 = PINA & 1;
		if (pa0 == 1)
		{
			if (lastState == 0)
			{
				lastState = 1;
				if ((pb & 0b11) == 0b10)
					pb -= 1;
				else
					pb += 1;
			}
		}
		else
			if (lastState == 1)
				lastState = 0;
		
		PORTB = pb;
	}
	return 0;
}
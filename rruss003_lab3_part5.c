#include <avr/io.h>

int main(void)
{
	DDRB = 0b110; PORTB = 0xFF;
	DDRD = 0; PORTD = 0xFF;

	/* Replace with your application code */
	while (1)
	{
		unsigned short s = ((PIND & 0xFF) << 1) + (PINB & 0x01);
		if (s > 5 && s < 70)
			PORTB = 0b010;
		else if (s >= 70)
			PORTB = 0b100;
		else
			PORTB = 0;
		 
	}
	return 0;
}
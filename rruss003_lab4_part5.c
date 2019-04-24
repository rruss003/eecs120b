#include <avr/io.h>

int main(void)
{
	DDRA = 0; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 7;

	/* Replace with your application code */
	unsigned char state = 0;
	unsigned char code[4] = {0b100, 0b1, 0b10, 0b10};
	
	while (1)
	{
		unsigned char inputs = PINA & 0b10000111;
		if (state == 0 && inputs == code[state])
			state++;
		else if (state == 1 && inputs == code[state])
			state++;
		else if (state == 2 && inputs == code[state])
			state++;
		else if (state == 3 && inputs == code[state])
			state++;
		else if (state == 4 && inputs == 0b10000000)
			state = 0;

		PORTC = state;
	}
	return 0;
}
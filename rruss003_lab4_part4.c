#include <avr/io.h>

int main(void)
{
	DDRA = 0; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 7;

	/* Replace with your application code */
	/*
	0 start (locked)
		press octothorpe
	1 locked
		release
	2 locked
		press y
	3 unlocked
		press inside button	
	*/
	unsigned char state = 0;
	unsigned char state2 = 0;
	
	while (1)
	{
		unsigned char inputs = PINA & 0b10000111;
		if (state == 0 && inputs == 0b100)
			state++;
		else if (state == 1 && inputs == 0)
			state++;
		else if (state == 2 && inputs == 0b10)
			state++;
		else if (state == 3 && inputs == 0b10000000)
			state = 0;
		else
		{
			if (state2 == 0 && inputs == 0b100)
				state2++;
			else if (state2 == 1 && inputs == 0)
				state2++;
			else if (state2 == 2 && inputs == 0b10)
			{
				state2 = 0;
				state = 0;
			}
			
		}
		
		PORTC = state;
	}
	return 0;
}
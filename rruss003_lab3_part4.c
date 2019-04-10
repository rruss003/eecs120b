#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;
	DDRB = 0xFF; PORTB = 0x00;

	/* Replace with your application code */
	while (1)
	{
		PORTB = (PINA & 0xF0) >> 4;
		PORTC = (PINA & 0x0F) << 4;
	}
	return 0;
}
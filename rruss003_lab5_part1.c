#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;

	/* Replace with your application code */
	while (1)
	{
		unsigned char level = ~PINA & 0x0F, PB = 0, misc = ~PINA & 0b01110000;
		if(!level) PB = 0b1000000;
		else if(level > 0 && level < 3)
		PB = 0b1100000;
		else if (level > 2 && level < 5)
		PB = 0b1110000;
		else if (level > 4 && level < 7)
		PB = 0b111000;
		else if (level > 6 && level < 10)
		PB = 0b111100;
		else if (level > 9 && level < 13)
		PB = 0b111110;
		else if (level > 12)
		PB = 0b111111;
		
		if (misc == 0b00110000)
		PB += 0b10000000;
		
		PORTB = PB;
	}
	return 0;
}
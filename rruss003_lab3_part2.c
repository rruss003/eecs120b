#include <avr/io.h>

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

	/* Replace with your application code */
	while (1)
	{
		unsigned char level = PINA & 0x0F, PC = 0, misc = PINA & 0b01110000;
		if(level > 0 && level < 3)
			PC = 0b100000;
		else if (level > 2 && level < 5)
			PC = 0b110000;
		else if (level > 4 && level < 7)
			PC = 0b111000;
		else if (level > 6 && level < 10)
			PC = 0b111100;
		else if (level > 9 && level < 13)
			PC = 0b111110;
		else if (level > 12)
			PC = 0b111111;
		if (level < 5)
		 PC += 0b1000000;
		 
		 if (misc == 0b00110000)
			PC += 0b10000000;
			
		 PORTC = PC;
	}
	return 0;
}
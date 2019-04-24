#include <avr/io.h>
int main()
{
	unsigned char state = 0;
	unsigned char s = 0;
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0xFF; PORTB = 0x00;
	while(1)
	{
		unsigned char pa = !(PINA & 1);

		switch(state)
		{
			case 7:
			if (pa)
				 state = (s+1)%6;
			break;
			default:
			s = state;
			if(!pa)	state = 7;
			break;
		}
		
		switch(state)
		{
			case 0:
			PORTB = 0b000000;
			case 1:
			PORTB = 0b100100;
			break;
			case 2:
			PORTB = 0b110110;
			break;
			case 3:
			PORTB = 0b111111;
			break;
			case 4:
			PORTB = 0b011011;
			break;
			case 5:
			PORTB = 0b001001;
			break;
			default:
			break;
		}
	}

	return 1;
}


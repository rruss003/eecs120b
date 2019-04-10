#include <avr/io.h>

unsigned char numones(unsigned char c)
{
	return (c & 0x01) + ((c & 0x02)>>1) + ((c & 0x04)>>2) + ((c & 0x08)>>3) + ((c & 0x10)>>4) + ((c & 0x20)>>5) + ((c & 0x40)>>6) + ((c & 0x80)>>7);
}

int main(void)
{
	DDRA = 0x00; PORTA = 0xFF;
	DDRB = 0x00; PORTB = 0xFF;
	DDRC = 0xFF; PORTC = 0x00;

    /* Replace with your application code */
    while (1) 
    {
		PORTC = numones(PINA & 0xFF)+numones(PINB & 0xFF);
    }
	return 0;
}


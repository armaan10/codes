/*
 * adc.cpp
 *
 * Created: 07-Nov-18 3:21:08 PM
 * Author : MAHE
 */ 

#include <avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
int main(void)

{TCCR0=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);
	
	
		DDRB|=1<<PINB3;
	PORTB|=1<<PINB3;
	ADCSRA|=1<<ADIE;//turn on interrupt
	ADCSRA|=1<<ADPS2;//prescale (
	ADMUX &= ~(1<<MUX0);
	ADMUX|=1<<REFS0;//set ref voltage
ADCSRA|=1<<ADEN;//enable
ADMUX|=1<<ADLAR;//using 8 bits

sei();

ADCSRA|=1<<ADSC;//start conversion 	
	
	
	
	
    /* Replace with your application code */
    while (1) 
    {

    }


}
ISR(ADC_vect)
{
	
	//PORTB^=1<<PINB3;
	//int lowip=ADCL;
	OCR0=ADCH;

		ADCSRA|=1<<ADSC;//start next conversion
	




}

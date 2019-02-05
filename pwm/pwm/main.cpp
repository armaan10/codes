/*
 * pwm.cpp
 *
 * Created: 07-Nov-18 6:06:52 PM
 * Author : MAHE
 */ 
#define F_CPU 1000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
void pwm()
{
	TCCR0=(1<<WGM00)|(1<<WGM01)|(1<<COM01)|(1<<CS00);
	DDRB|=(1<<PINB3);
	
}

int main(void)
{
    /* Replace with your application code */
	pwm();

int d;
    while (1) 
    {
for(d=0;d<255;d=d+1) 
{OCR0=d;
_delay_ms(10);}
_delay_ms(2000);
for (d=255;d>-1;d=d-1)
{OCR0=d;
_delay_ms(10);		
}




}
}

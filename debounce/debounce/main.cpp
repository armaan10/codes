/*
 * debounce.cpp
 *
 * Created: 05-Nov-18 6:49:39 PM
 * Author : MAHE
 */ 

#include <avr/io.h>
#include<avr/delay.h>

int main(void)
{//b3 output
    /* Replace with your application code */
    DDRD&=~(1<<PIND7);
	PORTD|=1<<PIND7;
	DDRB|=1<<PINB3;
	PORTB|=1<<PINB3;
	bool curr=1,last=1;
	
	while (1) 
    {
		curr=(PORTD & 1<<PORTD7)>>PORTD7;
		if(curr!=last)
		{
			
			_delay_ms(10);
		}
		curr=(PIND & 1<<PIND7)>>PIND7;
		
		if(curr==0 && last ==1)
		{
			PORTB^=1<<PINB3;
   
   
    }


	last=curr;
	
}
}

#include<lpc21xx.h>
extern void delay_ms(const unsigned int ms);
extern void delay_sec(const unsigned int sec);

/* function to generate delay for exact x millisecond */
extern void delay_ms(const unsigned int x){
	T0PC = 0;        		// set the starting count value
	T0PR = 15000-1;			// set the ending count value
	T0TCR = 1;					// enable the timer
	T0TC = 0;						// set timer counter to zero
	while(T0TC < x); 		// busy the processor for the x millisecond
	T0TCR = 0;					// disable the timer
}

/* function to generate delay for exact x second */
extern void delay_sec(const unsigned int x){
	T0PC = 0;								// set the starting count value
	T0PR = 15000000-1;			// set the ending count value
	T0TCR = 1;							// enable the timer
	T0TC = 0;								// set timer counter to zero									
	while(T0TC < x);				// busy the processor for the x second
	T0TCR = 0;							// disable the timer
}
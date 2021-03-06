#include <mega128.h>
#include <delay.h>
unsigned char delay;
unsigned char ADC(unsigned char);
void main() {
    DDRB = 0x0f;
    DDRF = 0xf0;
    ADCW = 0x0000;
    while(1) {
        delay = ((ADC(0x8f)) / 6) + 10;
        PORTB = 0x01;
        delay_ms(delay);
        PORTB = 0x04;
        delay_ms(delay); 
        PORTB = 0x02;
        delay_ms(delay); 
        PORTB = 0x08;
        delay_ms(delay);     
    }
}
unsigned char ADC(unsigned char ADCS) {
    ADMUX = 0x20;
    ADCSRA = ADCS;
    ADCSRA |= 0x40; //(1<<ADSC)
    delay_us(10);
    while(ADIF == 0);
    return ADCH;
}
    
/*
 * AD3.c
 *
 * Created: 2018-06-11 ���� 1:51:25
 * Author: KHJ
 */
unsigned int count;
#include <mega128.h>
#include <delay.h>
void main(void) {
    DDRA = 0xff;
    DDRD = 0xff;
    DDRF = 0x00;
    ADMUX = 0x00;
    ADCSRA = 0x8f;
    SREG = 0x80;
    do {
        ADCSRA = 0xcf;
        delay_ms(5);
    }
    while (1);
}
interrupt [ADC_INT] void ADCinter(void) {
    unsigned char st,nd,rd,th;
    count = (ADCW-1)/2;
    th = (count/1000)%10;
    rd = (count/100)%10;
    nd = (count/10)%10;
    st = count%10;
    PORTD = 0xe0 | th;
    delay_ms(2);
    PORTD = 0xd0 | rd;
    delay_ms(2);
    PORTD = 0xb0 | nd;
    delay_ms(2);
    PORTD = 0x70 | st;
    delay_ms(2);
}

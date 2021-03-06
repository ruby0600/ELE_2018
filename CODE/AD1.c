/*
 * AD1.c
 *
 * Created: 2018-06-11 ���� 1:51:25
 * Author: KHJ
 */

#include <mega128.h>
#include <delay.h>
void main(void) {
    DDRA = 0xff;
    DDRF = 0xf0;
    ADMUX = 0x21;
    ADCSRA = 0x8f;
    SREG = 0x80;
    do {
        ADCSRA = 0xcf;
        delay_ms(5);
    }
    while (1);
}
interrupt [ADC_INT] void ADCinter(void) {
    PORTA = ADCH;
    delay_ms(100);
}

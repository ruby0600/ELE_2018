/*
 * Timer3_2.c
 *
 * Created: 2018-06-05 ���� 12:27:15
 * Author: KHJ
 */

#include <mega128.h>
#include <delay.h>
unsigned char LED = 0x01, count = 0,FNDcount = 0;
void FND();
void main(void) {
    DDRA = 0xff;
    DDRD = 0xff;
    TIMSK = 0x01;
    TCCR0 = 0x07;
    TCNT0 = 0x00;
    SREG = 0x80;
    while (1) {
        PORTA = LED;
        FND();
        if(FNDcount == 5) {
            break;
        }
    }
}
interrupt [TIM0_OVF] void overflow(void) {
    count++;
    if(count == 31) {
        LED <<= 1;
        count = 0;
        if(LED == 0x00) {
            LED = 0x01;
            FNDcount++;
        }
    }
}
void FND(){
    unsigned char st,nd,rd,th;
    th = (FNDcount/1000)%10;
    rd = (FNDcount/100)%10;
    nd = (FNDcount/10)%10;
    st = FNDcount%10;
    PORTD = 0x70 | st;
    delay_ms(2);
    PORTD = 0xb0 | nd;
    delay_ms(2);
    PORTD = 0xd0 | rd;
    delay_ms(2);
    PORTD = 0xe0 | th;
    delay_ms(2);
}

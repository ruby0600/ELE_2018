/*
 * EX_INT3.c
 *
 * Created: 2018-06-04 ���� 12:20:22
 * Author: KHJ
 */

#include <mega128.h>
#include <delay.h>
unsigned int count;
void FND(void);
void main(void) {
    DDRD = 0xff;
    EICRB = 0xc0;
    EIMSK = 0x80;
    EIFR = 0x00;
    SREG = 0x80;
    while (1) {
        FND();
    }
}
interrupt [EXT_INT7] void upcount (void)
{
     count++;
}
void FND() {
    unsigned char st,nd,rd,th;
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
#include <mega128.h>
#include <delay.h>
void main() {
    unsigned int delay = 10;
    DDRB = 0xff;
    DDRC = 0x00;
    while(1) {
        delay = (PINC == 0) ? 10 : PINC * 10;
        PORTB = 0x09;
        delay_ms(delay);
        delay = (PINC == 0) ? 10 : PINC * 10;
        PORTB = 0x05;
        delay_ms(delay);
        delay = (PINC == 0) ? 10 : PINC * 10;
        PORTB = 0x06;
        delay_ms(delay);
        delay = (PINC == 0) ? 10 : PINC * 10;
        PORTB = 0x0a;
        delay_ms(delay);
    }
}
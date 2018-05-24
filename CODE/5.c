#include <mega128.h>
#include <delay.h>
#define LED PORTA
#define SW PORTC
 void main(void) {
    unsigned char Bits = 0xfe;
    DDRA = 0xff;
    DDRC = 0x00;
    DDRF = 0xff;
    PORTF = 0xff;
    while(1) {
        LED = Bits;
        if(PINC.0 != 0) {
            Bits <<= 1;
            Bits |= 0x01;
            delay_ms(500);
        }
        if(Bits == 0xff) {
            Bits = 0xfe;
        }
    }
 }
    
    
    
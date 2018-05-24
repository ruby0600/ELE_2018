#include <mega128.h>
#include <delay.h>
#define LED PORTA
 void main(void) {
    unsigned char Bits = 0xfe;
    DDRA = 0xff;
    while(1) {
        LED = Bits;
        Bits <<= 1;
        Bits |= 0x01;
        if(Bits == 0xff) {
            Bits = 0xfe;
        }
        delay_ms(500);
    }
 }
        
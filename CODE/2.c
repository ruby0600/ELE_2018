#include <mega128.h>
#include <delay.h>
#define LED PORTA
 void main(void) {
    unsigned char Bits = 0xfd;
    DDRA = 0xff;
    while(1) {
        LED = Bits;
        Bits <<=2;
        Bits |= 0x03;
        delay_ms(500);
        if(Bits == 0xff) {
            Bits = 0xfd;
        }
    }
 }
#include <mega128.h>
#include <delay.h>
#define LED PORTA
  void main(void) {
    unsigned char Bits = 0xfe;
    DDRA = 0xff;
    DDRC = 0x00;
    DDRF = 0xff;
    PORTF = 0xff;
   while(1) {
        LED = Bits;
        while(1) {
            LED = Bits;
            Bits <<= 1;
            Bits |= 0x01;
            delay_ms(500);
            if(Bits == 0x7f) {
                break;
            }
            if(PINC.0 == 0) {
                while(1){
                    if(PINC.0 == 1) {
                        break;
                    }
                }
            }
        }
        while(1) {
            LED = Bits;
            Bits >>= 1;
            Bits |= 0x80;
            delay_ms(500);
            if(Bits == 0xfe) {
                break;
            }
            if(PINC.0 == 0) {
                while(1){
                               if(PINC.0 == 1) {
                        break;
                    }
                }
            }
        }
  
    }
 }
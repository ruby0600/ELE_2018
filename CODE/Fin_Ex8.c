#include <mega128.h>
void main() {
    DDRD = 0xff;
    while(1) {
        PORTD = 0x72;
    }
}
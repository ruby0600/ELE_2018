#include <mega128.h>
#include <delay.h>
int speed = 100;
void main() {
    DDRA = 0xff;
    DDRB = 0xff;
    EIMSK = 0x30;
    EICRB = 0x0a;
    SREG = 0x80;
    TCCR1A = 0x81;
    TCCR1B = 0x05;
    TCNT1 = 0x0000;
    while(1) {
        OCR1A = speed;
        PORTA = speed;
    }
}
interrupt [EXT_INT4] void inter4(void) {
    speed += 10;
    if(speed > 255) {
        speed = 250;
    }
}
interrupt [EXT_INT5] void inter5(void) {
    speed -= 10;
    if(speed < 10) {
        speed = 10;
    }
}
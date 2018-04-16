/*
 * Motor2.c
 * 정방향 회전->정지->역방향 회전 -> 정지
 * Created: 2018-04-16 오후 12:27:01
 * Author: KHJ
 */

#include <mega128.h>
#include <delay.h>
#define MOTOR PORTB
void main(void) {
    DDRB = 0xf0;
    while(1) {
        MOTOR = 0b00100000;
        delay_ms(1000);
        MOTOR = 0x00;
        delay_ms(200);
        MOTOR = 0b00010000;
        delay_ms(1000);
        MOTOR = 0x00;
        delay_ms(200);
    }
}
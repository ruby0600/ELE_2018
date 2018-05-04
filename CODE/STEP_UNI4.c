/*
 * STEP_UNI4.c
 *
 * Created: 2018-05-01 ���� 2:40:33
 * Author: KHJ
 */

#include <mega128.h>
#include <delay.h>
#define Dtime 200
#define Angle 360
void main(void)
{
    unsigned char i,angle;
    DDRB = 0x0f;
    angle = Angle/1.8/4;
    for (i=0;i<angle;i++) {
        PORTB = 0x01;
        delay_ms(Dtime);
        PORTB = 0x04;
        delay_ms(Dtime);
        PORTB = 0x02;
        delay_ms(Dtime);
        PORTB = 0x08;
        delay_ms(Dtime);    
    }
}

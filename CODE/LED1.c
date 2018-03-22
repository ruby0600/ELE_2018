/* LED1.c
 * LED On/Off 실험 1은 LED8개를 동시에 켜고(On), 
 끄는(Off) 것을 반복하도록 프로그램을 작성하고
 동작시키는 실험이다.
 * Created  2018-03-19 오후 15:05:35           
 * Author: KHJ
 */
    
 #include <mega128.h>
 #include <delay.h>
 
 void main(){
 
    DDRA = 0xff;
    
    while(1){
        PORTA = 0xff;       //LED 8개 On
        delay_ms(200);
        PORTA = 0x00;       //LED 8개 Off
        delay_ms(200);
        }
 }        
/*
 * serial3.c
 *
 * Created: 2018-09-13 ���� 10:21:24
 * Author: Administrator
 */
unsigned char rx;
#include <mega128.h>
#include <delay.h>
#include <lcd.h>
#asm
    .equ __lcd_port = 0x12
#endasm
unsigned char PORTAnum[8] , PORTAnumchar;
char Getch(void) {
    while(!(UCSR0A & 0x80));
    rx = UDR0;
    return UDR0;
}
void PORTAnumadder(void) {
    unsigned char i = 0;
    PORTAnumchar = 0;
    for(i = 0; i < 8; i++) {
        if(PORTAnum[i] == 1) {
            switch(i) {
                case 0: PORTAnumchar = 1; break;
                case 1: PORTAnumchar += 2; break;
                case 2: PORTAnumchar += 4; break;
                case 3: PORTAnumchar += 8; break;
                case 4: PORTAnumchar += 16; break;
                case 5: PORTAnumchar += 32; break;
                case 6: PORTAnumchar += 64; break;
                case 7: PORTAnumchar += 128; break;
            }
        }            
    }
}
void main(void) {
    unsigned char i;
    DDRA = 0xff;
    DDRB = 0xff;
    DDRD = 0xff;
    lcd_init(16);     
    UCSR0A = 0x00;
    UCSR0B = 0x18;
    UCSR0C = 0x06;
    UBRR0H = 0;
    UBRR0L = 51;
    SREG = 0x80;
    lcd_clear();
    while (1) {
        Getch();
        switch(rx) {
            case 65: PORTAnum[0] = 1; break;
            case 66: PORTAnum[1] = 1; break;
            case 67: PORTAnum[2] = 1; break;
            case 68: PORTAnum[3] = 1; break;
            case 69: PORTAnum[4] = 1; break;
            case 70: PORTAnum[5] = 1; break;
            case 71: PORTAnum[6] = 1; break;
            case 72: PORTAnum[7] = 1; break;
        }
        switch(rx) {
            case 97: PORTAnum[0] = 0; break;
            case 98: PORTAnum[1] = 0; break;
            case 99: PORTAnum[2] = 0; break;
            case 100: PORTAnum[3] = 0; break;
            case 101: PORTAnum[4] = 0; break;
            case 102: PORTAnum[5] = 0; break;
            case 103: PORTAnum[6] = 0; break;
            case 104: PORTAnum[7] = 0; break;
        }
        PORTAnumadder();
        lcd_clear();
        lcd_gotoxy(2,0);
        lcd_putsf("Lamp Control");
        lcd_gotoxy(0,1);
        for(i = 0; i < 8; i++) {
            if(PORTAnum[i] != 0) {
                lcd_putchar(i + '0');
            } 
            PORTA = PORTAnumchar;
        }    
    }
}
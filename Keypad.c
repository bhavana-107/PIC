//4*4 keypad with LCD

#include <xc.h>
#define _XTAL_FREQ 20000000
#define RS RC0
#define RW RC1
#define EN RC2
void lcd_ini();
void command(unsigned char);
void data(unsigned char);
void main(void) {
    TRISC=0x00;
    TRISD=0x00;
    int i;
    lcd_ini();
    
    TRISB=0xF0;
    PORTB=0x00;
    ADCON1=0x0F;
    command(0x80);
    while(1){
         
        PORTB=0x0E;
        if(RB4==0){
            data('1');
        }
        if(RB5==0){
            data('2');
        }
        if(RB6==0){
            data('3');
        }
        if(RB7==0){
            data('A');
        }
        PORTB=0x0D;
        if(RB4==0){
            data('4');
        }
        if(RB5==0){
            data('5');
        }
        if(RB6==0){
            data('6');
        }
        if(RB7==0){
            data('B');
        }
        PORTB=0x0B;
        if(RB4==0){
            data('7');
        }
        if(RB5==0){
            data('8');
        }
        if(RB6==0){
            data('9');
        }
        if(RB7==0){
            data('C');
        }
        PORTB=0x07;
        if(RB4==0){
            data('*');
        }
        if(RB5==0){
            data('0');
        }
        if(RB6==0){
            data('#');
        }
        if(RB7==0){
            data('D');
        }
        
        
    }
    return;
}
void lcd_ini(){
    command(0x38);
    command(0x0C);
    command(0x06);
    command(0x01);
    //command(0x80);
}
void command(unsigned char c){
    RS=0;
    RW=0;
    PORTD=c;
    EN=1;
    __delay_ms(5);
    EN=0;
}
void data(unsigned char ch)
{
    RS=1;
    RW=0;
    PORTD=ch;
    EN=1;
    __delay_ms(5);
    EN=0;
    while(RB4==0);
    while(RB5==0);
    while(RB6==0);
    while(RB7==0);
}

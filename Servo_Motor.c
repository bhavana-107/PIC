// TO turn the motor 0deg, 90deg, and 180deg

#include <xc.h>
#define _XTAL_FREQ 20000000
unsigned long g=1000;
void servo_0(){
    for(int i=0;i<50;i++){
        RC0=1;
        __delay_us(g);
        RC0=0;
        __delay_us(19000);
    }
}
void servo_90(){
    for(int i=0;i<50;i++){
        RC0=1;
        __delay_us(1500);
        RC0=0;
        __delay_us(18500);
    }
}
void servo_180(){
    for(int i=0;i<50;i++){
        RC0=1;
        __delay_us(2000);
        RC0=0;
        __delay_us(18000);
    }
}
void main(void) {
    TRISC=0x00;
    
    servo_0();
    servo_90();
    servo_180();
    
    return;
}

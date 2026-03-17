//Button at RC4 and RC0 and RC1 connected to IN1 and IN2 of motor driver L293D
#include <xc.h>
#define _XTAL_FREQ 20000000

void main(void) {
    TRISC=0x10;
    
    while(1)
    {

        while(RC4==0);
        while(RC4==1);
        PORTC=0x01;      //Clock wise movement
        while(RC4==0);
        while(RC4==1);
        PORTC=0x02;      //Anti clock wise movement
        while(RC4==0);
        while(RC4==1);
        PORTC=0x03;      //to stop motor
    }
    return;
}

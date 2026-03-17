//Generate a delay around 13ms

#include <xc.h>

void main(void) {
    TRISC=0x00;
    T2CON=0x7F;
    PR2=255;
    while(1)
    {
        if(TMR2IF==1){
            PORTC=~PORTC;
            TMR2IF=0;
        }
    }
    return;
}

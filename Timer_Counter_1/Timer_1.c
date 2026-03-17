//Timer 0 creating a delay of 104 ms

#include <xc.h>

void main(void) {
    TRISC=0x00;
    T1CON=0xB1;    
    ADCON1=0x0F;
    while(1){
        if(TMR1IF==1){
            PORTC=~PORTC;
            TMR1IF=0;
        }
    }
    return;
}

// Generate a delay around 104ms

#include <xc.h>

void main(void) {
    TRISC=0x00;
    T3CON=0xB1;
    while(1){
        if(TMR3IF==1){
            PORTC=~PORTC;
            TMR3IF=0;
        }
    }
    return;
}

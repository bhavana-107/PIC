//Compare Mode using Timer 3, toggle the port on each comare match

#include <xc.h>

void main(void) { 
    TRISB=0x00;
    T3CON=0xF9;
    CCP1CON=0x0B;
    CCPR1L=0x30;
    CCPR1H=0xA2;
    ADCON1=0x0F;
  
    while(1){
        if(CCP1IF==1){
            PORTB=~PORTB;
            CCP1IF=0;
        }
    }
    return;
}

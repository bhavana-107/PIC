//Timer 08 bit mode creating a delay of 13ms

#include <xc.h>

void main(void) {
    TRISC=0x00;
    T0CON=0xC7;
    while(1){
        if(INTCONbits.TMR0IF==1){
            PORTC=~PORTC;
            INTCONbits.TMR0IF=0;
        }
        
    }
    return;
}



//Creating 5ms delay

#include <xc.h>

void main(void) {
    TRISC=0x00;
    T0CON=0xC7;
    TMR0L=158;
    while(1){
        if(INTCONbits.TMR0IF==1){
            TMR0L=158;
            PORTC=~PORTC;
            INTCONbits.TMR0IF=0;
        }
        
    }
    return;
}



//Creating 2 sec Delay

#include <xc.h>

void main(void) {
    TRISC=0x00;
    T0CON=0xC7;
    TMR0L=60;
    int i;
    while(1){
        for(i=0;i<200;i++){
            while(INTCONbits.TMR0IF==0);
            TMR0L=60;
            INTCONbits.TMR0IF=0;
        }
        
        PORTC=~PORTC;
      
    }
    return;
}

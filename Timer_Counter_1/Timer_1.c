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



//Creating a Delay of 1 sec

#include <xc.h>

void main(void) {
    TRISC=0x00;
    T1CON=0xB1;
    TMR1L=3036;
    int i;
    while(1){
        for(i=0;i<10;i++){
            while(TMR1IF==0);
            TMR0L=3036;
            TMR1IF=0;
        }
        
        PORTC=~PORTC;
    }
    return;
}

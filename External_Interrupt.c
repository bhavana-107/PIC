//Toggle the pins based on interrupts

#include <xc.h>
void __interrupt() ISR(){
    if(INT0IF==1){
        RB5=~RB5;
        INT0IF=0;
    }
    if(INT1IF==1){
        RB6=~RB6;
        INT1IF=0;
    }
    if(INT2IF==1){
        RB7=~RB7;
        INT2IF=0;
    }
}

void main(void) {
    TRISB=0x0F;
    ADCON1=0x0F;
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;
    INTCONbits.INT0IE=1;
    INTCON3bits.INT1IE=1;
    INTCON3bits.INT2IE=1;
    while(1);
    
    return;
}



/*Task: Blink a set of leds on a certain pattern and use 3 interrupts, enable 3 interrupt pins whenever an interrupt is triggered blink another set of leds on a 
pattern for 3 times and continue blinking previous set after that */

#include <xc.h>
#define _XTAL_FREQ 20000000
void __interrupt() ISR(){
    if(INT0IF==1){
        
        for(int i=0;i<3;i++){
            PORTC=0x01;
            __delay_ms(500);
            for(int j=0;j<3;j++){
                PORTC=PORTC<<1;
                __delay_ms(500);
            }
            
        }
        PORTC=0x00;
        INT0IF=0;
    }
    if(INT1IF==1){
        
        for(int i=0;i<3;i++){
            PORTC=0x08;
            __delay_ms(500);
            for(int j=0;j<3;j++){
                PORTC=PORTC>>1;
                __delay_ms(500);
            }
            
        }
        PORTC=0x00;
        INT1IF=0;
    }
    if(INT2IF==1){
        
        //for(int i=0;i<3;i++){
        int i=0;
        while(i<3){
            PORTC=0x05;
            __delay_ms(500);
            PORTC=~PORTC;
            __delay_ms(500);
            i++;
            
        }
        PORTC=0x00;
        INT2IF=0;
    }
}

void main(void) {
    TRISB=0x0F;
    ADCON1=0x0F;
    TRISC=0x00;
    TRISD=0x00;
    INTCONbits.GIE=1;
    INTCONbits.PEIE=1;
    INTCONbits.INT0IE=1;
    INTCON3bits.INT1IE=1;
    INTCON3bits.INT2IE=1;
    PORTD=0x00;
    while(1){
        PORTD=0x01;
        __delay_ms(500);
        for(int i=0;i<3;i++){
            PORTD=PORTD<<1;
            __delay_ms(500);
        }
    }
    return;
}

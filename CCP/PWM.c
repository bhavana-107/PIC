//PWM using Timer 2, method 1
//Directly assigning values to the register

#include <xc.h>
#define _XTAL_FREQ 20000000

void main(void) {
    TRISC=0x00;
    T2CON=0x7F;
    PR2=255;
    CCP1CON=0x0F;
    while(1){
        CCPR1L=0x3E;
        CCP1CON|=(0x02<<4);    //for 25% duty cycle
        __delay_ms(1000);
        CCPR1L=0x7D;
        CCP1CON&=0xCF;        //for 50% duty cycle
        __delay_ms(1000);
        CCPR1L=0xBB;
        CCP1CON|=(0x02<<4);   //for 75% duty cycle
        __delay_ms(1000);
    }
    return;
}


//Method 2

#include <xc.h>
#define _XTAL_FREQ 20000000

void main(void) {
    TRISC=0x00;
    T2CON=0x7F;
    PR2=255;
    CCP1CON=0x0F;
    while(1){
        for(int i=0;i<1000;i++)
        {
            CCPR1L=i>>2;
            CCP1CON&=0xCF;
            CCP1CON|=((i&0x03)<<4);
            __delay_ms(5);
        }
        for(int i=1000;i>0;i--)
        {
            CCPR1L=i>>2;
            CCP1CON&=0xCF;
            CCP1CON|=((i&0x03)<<4);
            __delay_ms(5);
        }
    }
    return;
}

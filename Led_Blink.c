//Led shifting

#include <xc.h>
#define _XTAL_FREQ 20000000

void main(void) {
    TRISC=0X00;
    while(1)
    {
        PORTC=0X01;
        __delay_ms(500);
        for(int i=0;i<7;i++)
        {
           PORTC=PORTC<<1;
           __delay_ms(500);
        }  
    }
    return;
}


//Led with button

#include <xc.h>
#define _XTAL_FREQ 20000000

void main(void) {
    TRISC=0x08; //setting only RC3 as input other pins as outputs
    while(1){    
        while(RC3==0); //button at RC3
        while(RC3==1);
        PORTC=0x02;    //Led at RC1 
        while(RC3==0);//
        while(RC3==1);
        PORTC=0x00;
    }
        
    return;
}

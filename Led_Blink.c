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

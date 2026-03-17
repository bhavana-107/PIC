//Common cathode
//Method 1

#include <xc.h>
#define _XTAL_FREQ 20000000

void main(void) {
    TRISC=0x00;
    PORTC=0x3F;
    __delay_ms(1000);
    PORTC=0x06;
    __delay_ms(1000);
    PORTC=0x5B;
    __delay_ms(1000);
    PORTC=0x4F;
    __delay_ms(1000);
    PORTC=0x66;
    __delay_ms(1000);
    PORTC=0x6D;
    __delay_ms(1000);
    PORTC=0x7D;
    __delay_ms(1000);
    PORTC=0x07;
    __delay_ms(1000);
    PORTC=0x7F;
    __delay_ms(1000);
    PORTC=0x67;
    __delay_ms(1000);
    
    return;
}


//Method 2 using an array

#include <xc.h>
#define _XTAL_FREQ 20000000
int arr[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x67};

void main(void) {
    TRISC=0x00;
    for(int i=0;i<10;i++){
        PORTC=arr[i];
        __delay_ms(1000);
    }
    return;
}

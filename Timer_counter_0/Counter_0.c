// counter using timer0 

#include <xc.h>
#include<stdio.h>
#define _XTAL_FREQ 20000000
unsigned int count_val;
void display(unsigned char *);
unsigned char buffer[10];

void main(void) {
    TRISA=0xFF;    //T0CKI at RA4(setting as input)
    T0CON=0xA8;    //8 bit counter
    TXSTA=0x24;
    RCSTA=0x90;
    BAUDCON=0x00;
    SPBRG=129;
    while(1){ 
        while(RA4==0);
        while(RA4==1);
        count_val=TMR0L;         
        sprintf(buffer,"%u\r\n",count_val);
        display(buffer);
        __delay_ms(50);
     
    }
    return;
}
void display(unsigned char *ptr){
    while(*ptr){
        while(!TXIF);
        TXREG=*ptr++;
        
    }
}

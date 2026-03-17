// Counter using Timer1

#include <xc.h>
#include<stdio.h>
#define _XTAL_FREQ 20000000
unsigned int count_val;
void display(unsigned char *);
unsigned char buffer[10];

void main(void) {
    TRISC=0xFF;
    T1CON=0x03;    
    TXSTA=0x24;
    RCSTA=0x90;
    BAUDCON=0x00;
    SPBRG=129;
    while(1){
        while(RC0==0);
        while(RC0==1);
        count_val=TMR0L;         
        count_val|=TMR1H<<8;    
        
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

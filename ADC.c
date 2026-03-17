//Analog to digital conversion and displaying through UART

#include <xc.h>
#include<stdio.h>
#define _XTAL_FREQ 20000000
void display(unsigned char *);
char buffer[10];

void main(void) {
    TRISA=0x01;
    ADCON0=0x01;
    ADCON1=0x0E;
    ADCON2=0xA6;
    TRISC=0x80;
    TXSTA=0x24;
    RCSTA=0x90;
    BAUDCON=0x00;
    SPBRG=129;
    TRISD=0x00;
    int c=0;
    while(1){
        ADCON0|=1<<1;
        while(ADCON0 & 1<<1);
        int ADC_value=ADRESL;
        ADC_value|=ADRESH<<8;
        sprintf(buffer,"%d",ADC_value);
        display(buffer);
        display("\r\n");   
        __delay_ms(1000);
    }
    return;
}
void display(unsigned char *ptr){
    while(*ptr){
        while(!TXIF);
        TXREG=*ptr++;
        
    }
}



//Based on different range of ADC value the LED will turened on

#include <xc.h>
#include<stdio.h>
#define _XTAL_FREQ 20000000
void display(unsigned char *);
char buffer[10];

void main(void) {
    TRISA=0x01;
    ADCON0=0x01;
    ADCON1=0x0E;
    ADCON2=0xA6;
    TRISC=0x80;
    TXSTA=0x24;
    RCSTA=0x90;
    BAUDCON=0x00;
    SPBRG=129;
    TRISD=0x00;
    int c=0;
    while(1){
        ADCON0|=1<<1;
        while(ADCON0 & 1<<1);
        int ADC_value=ADRESL;
        ADC_value|=ADRESH<<8;
        sprintf(buffer,"%d",ADC_value);
        display(buffer);
        display("\r\n");
        int a=0x01;
       if((ADC_value>=0) && (ADC_value<=100)){
           //PORTD=0x01;
           PORTD=a;
           c=1;
       }
       else if((ADC_value>100) && (ADC_value<=200)){
           PORTD=0x04;
           PORTD=a<<1;
           c=1;
       }
       else if((ADC_value>200) && (ADC_value<=300)){
           //PORTD=0x04;
           PORTD=a<<2;
           c=1;
       }
       else if((ADC_value>300) && (ADC_value<=400)){
           //PORTD=0x08;
           PORTD=a<<3;
           c=1;
       }
       else if((ADC_value>400) && (ADC_value<=500)){
           //PORTD=0x10;
           PORTD=a<<4;
           c=1;
       }
       else{
           PORTD=0x1F;    //all 5 leds
           c=1;
       }       
        __delay_ms(1000);
    }
    return;
}
void display(unsigned char *ptr){
    while(*ptr){
        while(!TXIF);
        TXREG=*ptr++;
        
    }
}

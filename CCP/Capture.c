//Capture mode using Timer 1

#include <xc.h>
#include<stdio.h>
unsigned int count_val;
void display(unsigned char *);
char buffer[10];   

void main(void) {
    TRISC=0xFF;    // CCP1(RC2) set as input  
    T1CON=0xB1;    //timer 1 is used
    CCP1CON=0x05;
    TXSTA=0x24;
    RCSTA=0x90;
    BAUDCON=0x00;
    SPBRG=129;
  
    while(1){
      
        if(CCP1IF==1){      //CCP1IF is set when capture is made
            count_val=CCPR1L;
            count_val|=CCPR1H<<8;
        
            sprintf(buffer,"%u\r\n",count_val);
            display(buffer);
            CCP1IF=0;
        }
    }
    return;
}
void display(unsigned char *ptr){
    while(*ptr){
        while(!TXIF);
        TXREG=*ptr++;
        
    }
}


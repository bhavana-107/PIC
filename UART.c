//UART transmission

#include <xc.h>
#define _XTAL_FREQ 20000000

void main(void) {
    TRISC=0x80;    //To make Tx(RC6) pin as output and Rx(RC7) pin as input
    TXSTA=0x24;
    RCSTA=0x90;
    BAUDCON=0x00;
    SPBRG=129;
    while(1)
    {
        while(!TXIF);    //TXIF is set when Data is transmitted
        TXREG='a';
        __delay_ms(1000);
        
    }
    return;
}


// Transmission and Reception

#include <xc.h>
#define _XTAL_FREQ 20000000

void main(void) {
    TRISC=0x80;
    TXSTA=0x24;
    RCSTA=0x90;
    BAUDCON=0x00;
    SPBRG=129;      //for baudrate=9600
    while(1)
    {
        while(!RCIF);    //RXIF flag is set when data is received completely
        char ch=RCREG;
        while(!TXIF);
        TXREG=ch;
        //__delay_ms(1000);
    }
    return;
}


//String transmission

#include <xc.h>
#define _XTAL_FREQ 20000000
void display(unsigned char*);
void main(void) {
    TRISC=0x80;
    TXSTA=0x24;
    RCSTA=0x90;
    BAUDCON=0x00;
    SPBRG=129;
    while(1){
        
        char ch[15]="bhavana\r\n";
        display(ch);
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



//Taking input from keyboard and displaying after pressing enter key

#include <xc.h>
#define _XTAL_FREQ 20000000
void display(unsigned char*);
char ch[5];

void main(void) {
    TRISC=0x80;
    TXSTA=0x24;
    RCSTA=0x90;
    BAUDCON=0x00;
    SPBRG=129;
    int i=0;
    while(1){
        while(!RCIF);
        ch[i]=RCREG;
        if(ch[i]=='\r'){
            ch[i]='\0';
            display(ch);
            display("\r\n");
            i=0;
            
        }
        else{
            if(i<5){    
                i++;
            }
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

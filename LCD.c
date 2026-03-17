//To display Hello world

#include <xc.h>
#include<stdio.h>
#define _XTAL_FREQ 20000000
#define RS RC0
#define RW RC1
#define EN RC2
char buffer[10];
void lcd_ini();
void command(unsigned char);
void display(unsigned char*);
void data(unsigned char);
void main(void) {
    TRISC=0x00;
    TRISD=0x00;
    int i;
    lcd_ini();
    
    while(1){ 
       command(0x80); 
       display("Hello World");
    }
    
    return;
}
void lcd_ini(){
    command(0x38);
    command(0x0C);
    command(0x06);
    command(0x01);
    //command(0x80);
}
void command(unsigned char c){
    RS=0;
    RW=0;
    PORTD=c;
    EN=1;
    __delay_ms(5);
    EN=0;
}
void display(unsigned char *ptr){
    while(*ptr){
        data(*ptr++);
    }
}
void data(unsigned char ch)
{
    RS=1;
    RW=0;
    PORTD=ch;
    EN=1;
    __delay_ms(5);
    EN=0;
}

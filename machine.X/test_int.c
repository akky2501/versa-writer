#include<pic18f25k22.h>
#include <xc.h>

#define _XTAL_FREQ 16000000   // delay????(????16MHz???)

#pragma config PRICLKEN=OFF,PLLCFG=OFF,FOSC=INTIO67    // CONFIG1H
#pragma config BOREN=NOSLP,BORV=285,PWRTEN=ON          // CONFIG2L
#pragma config WDTEN=OFF                               // CONFIG2H
#pragma config MCLRE=INTMCLR,HFOFST=OFF                // CONFIG3H
#pragma config LVP=OFF                                 // CONFIG4L

void Wait(unsigned int num)
{
     int i ;

     for (i=0 ; i < num ; i++) {
          __delay_ms(1) ; 
     }
}

void main()
{
    OSCCON = 0b01110010 ;    // ?????????(16MHz)
    ANSELA = 0b00000000 ;    // AN0-4 ???????????????I/O???
    ANSELB = 0b00000000 ;    // AN8-13???????????????I/O???
    ANSELC = 0b00000000 ;    // AN14-19???????????????I/O???
    TRISA  = 0b00000000 ;    // RA0-RA7????????1??? 0???
    TRISB  = 0b00010000 ;    // RB0-RB7???????
    TRISC  = 0b00000000 ;    // RC0-RC7??????? 
    
    LATA = 0b00000000;
    LATC = 0b00000000;
    LATB = 0b00000000;
    
    IOCB4 = 1; //RB4
    INTCONbits.RBIE = 1;    
    INTCONbits.PEIE = 1;
    INTCONbits.GIE  = 1;

    
    LATBbits.LATB5 = 0;LATBbits.LATB6 = 1;LATBbits.LATB7 = 1;
    
    while(1) {
    }
}


void interrupt func(void){
    static int x=0;
    if(INTCONbits.RBIF){
        INTCONbits.RBIF = 0;
        x++;
        LATA = x;
        LATC = x>>8;
        return;
    }
}





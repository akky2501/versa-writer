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
    PORTA  = 0b00000000 ;    // ????????(??LOW???)
    PORTB  = 0b00000000 ;    // ????????(??LOW???)
    PORTC  = 0b00000000 ;    // ????????(??LOW???)

    
    LATA = 0b00000000;
    LATC = 0b00000000;
    LATB = 0b00000000;
    
    LATBbits.LATB5 = 1;LATBbits.LATB6 = 1;LATBbits.LATB7 = 1;
    
    int i=0,j=0;
    unsigned int cnt=0;
    int prev = 0;
    while(1) {
        /*if(cnt==65530){
            cnt = 0;
            switch(j++){
            case 0: LATBbits.LATB5 = 1;LATBbits.LATB6 = 1;LATBbits.LATB7 = 1;break;            
            case 1: LATBbits.LATB5 = 1;LATBbits.LATB6 = 0;LATBbits.LATB7 = 0;break;
            case 2: LATBbits.LATB5 = 0;LATBbits.LATB6 = 1;LATBbits.LATB7 = 0;break;
            case 3: LATBbits.LATB5 = 0;LATBbits.LATB6 = 0;LATBbits.LATB7 = 1;break;
            case 4: LATBbits.LATB5 = 1;LATBbits.LATB6 = 1;LATBbits.LATB7 = 0;break;
            case 5: LATBbits.LATB5 = 1;LATBbits.LATB6 = 0;LATBbits.LATB7 = 1;break;
            case 6: LATBbits.LATB5 = 0;LATBbits.LATB6 = 1;LATBbits.LATB7 = 1;break;
            case 7: LATBbits.LATB5 = 1;LATBbits.LATB6 = 1;LATBbits.LATB7 = 1;
                    j=0;
                    break;
            }
        }
        cnt++;
        */
        if(PORTBbits.RB4 && prev == 0) {    //positive edge
            i++;
            prev = 1;
        }
        if(PORTBbits.RB4==0 && prev == 1){  //negative edge
            prev=0;
        }
        
        LATA = i;
        LATC = i>>8;

    }
}

/*
        switch(i++){
            case 0: LATBbits.LATB5 = 0;LATBbits.LATB6 = 0;LATBbits.LATB7 = 0;break;            
            case 1: LATBbits.LATB5 = 1;LATBbits.LATB6 = 0;LATBbits.LATB7 = 0;break;
            case 2: LATBbits.LATB5 = 0;LATBbits.LATB6 = 1;LATBbits.LATB7 = 0;break;
            case 3: LATBbits.LATB5 = 0;LATBbits.LATB6 = 0;LATBbits.LATB7 = 1;break;
            case 4: LATBbits.LATB5 = 1;LATBbits.LATB6 = 1;LATBbits.LATB7 = 0;break;
            case 5: LATBbits.LATB5 = 1;LATBbits.LATB6 = 0;LATBbits.LATB7 = 1;break;
            case 6: LATBbits.LATB5 = 0;LATBbits.LATB6 = 1;LATBbits.LATB7 = 1;break;
            case 7: LATBbits.LATB5 = 1;LATBbits.LATB6 = 1;LATBbits.LATB7 = 1;
                    i=0;
                    break;
        }
        Wait(3000);
        */
        
        //if(PORTBbits.RB4) {LATBbits.LATB5 = 0;LATBbits.LATB6 = 0;LATBbits.LATB7 = 0;}
        //else {LATBbits.LATB5 = 1;LATBbits.LATB6 = 1;LATBbits.LATB7 = 1;}
        


    // Top of Bar
    /*LATAbits.LATA0 = 1 ;        
    LATAbits.LATA1 = 1 ;
    LATAbits.LATA2 = 1 ;
    LATAbits.LATA3 = 1 ;
    LATAbits.LATA4 = 1 ;
    LATAbits.LATA5 = 1 ;
    LATAbits.LATA6 = 1 ;
    LATAbits.LATA7 = 1 ;

    LATCbits.LATC0 = 1 ;        
    LATCbits.LATC1 = 1 ;
    LATCbits.LATC2 = 1 ;
    LATCbits.LATC3 = 1 ;
    LATCbits.LATC4 = 1 ;
    LATCbits.LATC5 = 1 ;
    LATCbits.LATC6 = 1 ;
    LATCbits.LATC7 = 1 ;

    LATBbits.LATB0 = 1 ;        
    LATBbits.LATB1 = 1 ;
    LATBbits.LATB2 = 1 ;
    LATBbits.LATB3 = 1 ;*/
    //Bottom of Bar
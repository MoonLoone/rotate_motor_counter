#include <msp430.h> 

#include <time.h>

#define CPU_CLOCK       32768
#define delay_ms(ms)    __delay_cycles((CPU_CLOCK/1000)*(ms))
#define delay_s(s)    __delay_cycles(CPU_CLOCK*s)

void startPWM(){
    P1DIR |= 0x04;
    P1SEL |= 0x04;
    TACCTL1 = OUTMOD_7;
    TACCR0 = 660;
    TACCR1 = 40;
    TACTL = TASSEL_1 + MC_1;
}

void setupPWMWithDelay(int delaySeconds){
    int i = 0;
    for (i = 0; i < delaySeconds; i++) {
        __delay_cycles(1000000);
    }
    TACCR1 = 60;
}

void main( void ) {

WDTCTL = WDTPW + WDTHOLD;
startPWM();
setupPWMWithDelay(10);

}

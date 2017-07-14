#include "msp430G2553.h"

#define LED BIT6
#define BUTTON BIT3

int timerCounter = 0;
int Mode = 0;
int state = 0;
int lowBrightness = 50;
int mediumBrightness = 250;
int highBrightness = 750;
static volatile char data;
int unpressed = 0;

void InitializeButton(void);

void main(void)
{
   WDTCTL = WDTPW + WDTHOLD;  // Stop WDT
   BCSCTL1 = CALBC1_1MHZ; // Set DCO to 1MHz
   DCOCTL = CALDCO_1MHZ; // Set DCO to 1MHz
 
   InitializeButton();
 
   P1DIR |= LED;             // P1.6 LED to output
   P1SEL |= LED;             // P1.6 LED to TA0.1
   P1SEL2 &= ~LED;           // P1.6 LED to TA0.1
 
   //For PWM - Timer 0 
   TA0CTL = TASSEL_2 + MC_1 + ID_0; // SMCLK as input clock, count up to TA0CCR0, clock/1
   TA0CCR0 = 1000; // Set maximum count value to determine PWM frequency = SMCLK/ClockDivide/TACCR0 (1MHz/1/1000 = 1kHz)
   // This will be changed in the timer 1 interrupt to change brightness -> //TA0CCR1 = 100; // Initialise counter compare value 1 to control Duty Cycle = TACCR1/TACCR0 (100/1000 = 10%)
   TA0CCTL1 = OUTMOD_7; // Set output to on when counter resets and off when counter equals TA0CCR1. Normal PWM.
 
   //For Timer Interrupt - Timer 1 - Called 8 times a second
   TA1CTL = TASSEL_2 + MC_1 + ID_1; // SMCLK as input clock, count up to TA0CCR0, clock/2
   TA1CCR0 = 62500; // Set maximum count value to determine count frequency = SMCLK/ClockDivide/TACCR0 (1MHz/2/62500 = 8Hz)
   TA1CCTL0 = OUTMOD_0 + CCIE; // Set out mode 0, enable CCR0 interrupt
 
   _BIS_SR(LPM0_bits+GIE);
}

void InitializeButton(void)
{
    P1DIR &= ~BUTTON;   // Set button pin as an input pin
    P1OUT |= BUTTON;    // Set pull up resistor on for button
    P1REN |= BUTTON;    // Enable pull up resistor for button to keep pin high until pressed
    P1IES |= BUTTON;    // Enable Interrupt to trigger on the falling edge (high (unpressed) to low (pressed) transition)
    P1IFG &= ~BUTTON;   // Clear the interrupt flag for the button
    P1IE |= BUTTON;     // Enable interrupts on port 1 for the button
}

#pragma vector=PORT1_VECTOR  //Called every time button is pressed (from high to low), initally mode and state are zero
__interrupt void PORT1_ISR(void)
{
  P1IFG &= ~BUTTON;                 // Clear the interrupt flag for the button
  P1IE &= ~BUTTON;                  // Disable Button interrupt
  WDTCTL = WDT_MDLY_32;             // Start and set watchdog timer (WDT) to trigger every 32ms
  IFG1 &= ~WDTIFG;                  // Clear the interrupt flag for the WDT
  IE1 |= WDTIE;                     // enable WDT interrupt
  
  timerCounter = 0;
 
  switch(Mode){  //Mode is zero when first program is first run to it will go to case 0 
  
    case 0:
      Mode = 1;
      state = 1;
     break;
     
    case 1:
      Mode = 2;
      state = 2;
     break;
     
     case 2:
      Mode = 0;
      state = 3;
     break;
  }
}

#pragma vector=WDT_VECTOR
__interrupt void WDT_ISR(void)
{
    IE1 &= ~WDTIE;                   // disable Watchdog timer (WDT) interrupt
    IFG1 &= ~WDTIFG;                 // clear WDT interrupt flag
    WDTCTL = WDTPW + WDTHOLD;        // put WDT back in hold state
    P1IE |= BUTTON;                  // Reenable interrupts for the button
}

#pragma vector=TIMER1_A0_VECTOR
__interrupt void Timer_A0_ISR (void)
{
  timerCounter++;
  
  switch(state){
    
    case 0:
      TA0CCR1 = 0;
    break;
    
    case 1:
      TA0CCR1 = lowBrightness;
      break;
      
    case 2:
      TA0CCR1 = mediumBrightness;
    break;
      
    case 3:
      TA0CCR1 = highBrightness;
    break;
    
    if(timerCounter > 20){
      TA0CCR1 = 0;
      /*if(Mode == 0){
        Mode = 2;      
      }
      else Mode--;
    */
    }
  }

  __bic_SR_register(CPUOFF + GIE); // Put CPU to sleep in LPM0 with interrupts enabled
}

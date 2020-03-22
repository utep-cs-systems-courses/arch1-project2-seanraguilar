#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "buzzer.h"
#include "libTimer.h"
#include "stateMachine.h"

char switch_state_down, switch_state_changed, v1, v2, v3, v4;

static char switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);/* if switch down, sense up */
  return p2val;
}

void switch_init()/* setup switch */
{
  P2REN |= SWITCHES;/* enables resistors for switches */
  P2IE = SWITCHES;/* enable interrupts from switches */
  P2OUT |= SWITCHES;/* pull-ups for switches */
  P2DIR &= ~SWITCHES;/* set switches' bits for input */
  switch_update_interrupt_sense();
  switch_interrupt_handler();
}

void switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  v1 = (p2val & SW1) ? 0 : 1;
  v2 = (p2val & SW2) ? 0 : 1;
  v3 = (p2val & SW3) ? 0 : 1;
  v4 = (p2val & SW4) ? 0 : 1;

  if (v1){
    switch_state_down = v1;
    switch_state_changed = 1;
    siren();
  }
  else if (v2) {
    switch_state_down = v2;
    switch_state_changed = 1;
    imperialMarch();
  }
  else if (v3) {
    switch_state_down = v3;
    switch_state_changed = 1;
    marioThemeSong();
  }
  else if (v4) {
    switch_state_down = v4;
    switch_state_changed = 1;
    buzzer_set_period(0);
  }
  else {
    switch_state_down = 0;
    switch_state_changed = 1;
    buzzer_set_period(0);
  }
}

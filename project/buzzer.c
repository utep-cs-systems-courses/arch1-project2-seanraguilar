#include "libTimer.h"
#include "buzzer.h"
#include "stateMachine.h"
#include <msp430.h>

void buzzer_init(){
  /*
    Direct timer A output "TA0.1" to P2.6.
    According to table 21 from data sheet:
    P2SEL2.6, P2SEL2.7, and P2SEL.7 must be zero
    P2SEL.6 must be 1
    Also: P2.6 direction must be output
  */

  timerAUpmode(); //used to drive speaker
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6; //enable output to speaker (P2.6)
}

void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1; //one half cycle
}

void siren()
{
  int i = 0;
  int song[] = {1479.98, 2217.46, 1479.98, 2217.46, 1479.98, 2217.46, 1479.98, 2217.46,
		1479.98, 2217.46, 1479.98, 2217.46, 1479.98, 2217.46, 1479.98, 2217.46};
    while (i < sizeof(song))
    {
      int first_loop = 0;
      while (first_loop < 20)
      {
	int second_loop = 0;
	while (second_loop < 30000)
	{
	  second_loop++;
	}
	first_loop++;
      }
      buzzer_set_period(song[i]);
      state_advance();
      i++;
    }
}

void imperialMarch()
{
  int i = 0;
  /*int song[] = {392.00, 392.00, 392.00, 0, 392.00, 392.00, 392.00, 0, 392.00, 392.00, 392.00, 0,
		311.13, 311.13, 0, 466.16, 0, 392.00, 392.00, 392.00, 0, 311.13, 311.13, 0,
		466.16, 0, 392.00, 392.00, 392.00, 0, 392.00, 392.00, 392.00, 0,
		392.00, 392.00, 392.00, 0,
		587.33, 587.33, 587.33, 0, 587.33, 587.33, 587.33, 0, 587.33, 587.33, 587.33, 0,
		622.25, 622.25, 0, 466.16, 0, 369.99, 369.99, 369.99, 0,
		311.13, 311.13, 0, 466.16, 0,
		392.00, 392.00, 392.00, 0, 392.00, 392.00, 392.00, 0, 392.00, 392.00, 392.00, 0,
		783.99, 783.99, 783.99, 0, 392.00, 392.00, 392.00}; */
  int song[] = {3135.96, 3135.96, 3135.96, 0, 3135.96, 3135.96, 3135.96, 0,
		3135.96, 3135.96, 3135.96, 0, 2489.02, 2489.02, 0, 3729.31, 0, // G Eb Bb
		3135.96, 3135.96, 3135.96, 0, 2489.02, 2489.02, 0, 3729.31, 0, // G Eb Bb
		3135.96, 3135.96, 3135.96, 3135.96, 3135.96, 3135.96, 3135.96, 3135.96, 0, // G
		4698.63, 4698.63, 4698.63, 0, 4698.63, 4698.63, 4698.63, 0, // D D
		4698.63, 4698.63, 4698.63, 0, // D
		4978.03, 4978.03, 0, 3729.31, 0, 2959.96, 2959.96, 2959.96, 0, // Eb Bb Gb
		2489.02, 2489.02, 0, 3729.31, 0, // Eb Bb
		3135.96, 3135.96, 3135.96, 0, 3135.96, 3135.96, 3135.96, 0,
		3135.96, 3135.96, 3135.96, 0, // G
		6271.93, 6271.93, 6271.93, 0, // Other G
		3135.96, 3135.96, 0, 3135.96, 0, // G G
		6271.93, 6271.93, 6271.93, 0,  // Other G
		5919.91, 5919.91, 0, 5587.65, 0, 5274.04, 0, 4978.03, 0, 5274.04, 0, // Gb F E Eb E
		3322.44, 0, 4434.92, 4434.92, 0, 4186.01, 4186.01, 0, 4068.54, 0, // Ab Db C Cb
		3729.31, 0, 3520.00, 0, 3729.31 // Bb A Bb
		//0 // To End It
  };
  while (i < sizeof(song))
  {
    int first_loop = 0;
    while (first_loop < 5)
    {
      int second_loop = 0;
      while (second_loop < 30000)
      {
	second_loop++;
      }
      first_loop++;
    }
    buzzer_set_period(song[i]);
    state_advance();
    i++;
  }
}

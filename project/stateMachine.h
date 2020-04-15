#ifndef stateMachine_included
#define stateMachine_included

void state_advance();
//void toggle();
//void toggle_green();
//void toggle_red();
void reset_state();
void led_state(unsigned char g, unsigned char r);
void delay(unsigned int t);
void dim();

#endif // included

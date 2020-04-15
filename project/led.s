	.global led_init
led_init():
	BIS.B #0x0041, &Port_1_2P1DIR
	MOV.B #1, &led_changed
	CALL #led_update
	RET

	

	.global led_update
led_update():
	TST.B &led_changed
	JEQ (0xc0a4)


	
	.global ledFlags
char ledFlags redVal[red_on] | greenVal[green_on] :
	MOV.B &red_on, R13
	ADD.W #0xc002, R13
	MOV.B &green_on, R12
	ADD.W #0xc000, R12
	MOV.B R12, R12
	BIS.B R13, R12

	
	
	.global P1out
P1OUT(0xff^LEDS) | ledFlags:
	MOV.B R12, R13
	BIS.B #0xffb0, R13
	AND.B R13, &Port_1_2 P1OUT
P1OUT = ledFlags	
	BIS.B R12, &Port_1_2 P1OUT

	
	
	.global led_changed
led_changed=0:
	CLR.B &led_changed
	RET

	.arch msp430g2553
	.p2align 1,0

	.data
switch_state_changed:
	.byte			;storing switch_state_changed because it's an integer

	
	.text

jt:
	.word v1 		;creating room for the cases for the jump table
	.word v2
	.word v3
	.word v4

	.global state_advance	;initializing method as a global method
state_advance:
	cmp #4, &swithch_state_changed
	jnc end
	mov &witch_state_changed, r12
	add r12, r12
	mov jt(r12), r0

v1:
	call #toggle_red	;calling the method toggle_red()
	jmp end
	
v2:
	call #toggle_green	;calling the method toggle_green()
	jmp end
	
v3:
	call #toggle_red	;calling the method toggle_red()
	call #togle_green	;calling the method toggle_green()
	jmp end
	
v4:
	call #toggle_red	;calling the method toggle_red()
	call #toggle_green	;calling the method toggle_green()
	call #dim		;calling the method dim() 
	jmp end 
	
	
end:	pop r0
	
	

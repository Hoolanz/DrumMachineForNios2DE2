# file: BSU/strlen.s
# Author: Arlen Planting
# Date: September 2007
# Environment Tested: Altera Debug Client

#include "BSU\bsu_macros.inc"

.text
.global strlen

strlen:

	mov	r2,r0

	loop:
	
		ldb		r8,0(r4)
		beq		r8,r0,loop_end
		incr	r2
		incr	r4
		br		loop
		
	loop_end:
	
	ret

.end

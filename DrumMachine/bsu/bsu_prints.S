# File: BSU/bsu_prints.s
# Author: Arlen Planting
# Date: September 2007
# Environment Tested: Altera Debug Client
# Reference:	Quartus II Version 7.1 Handbook
#             Volume 5: Embedded Peripherals
#             Chapter 7: JTAG UART core with Avalon Interface

#include "system.h"
#include "BSU/bsu_macros.inc"

.text

# ---------------------------------------------------------------------
# Send character string to JTAG UART port
#		C syntax:	void bsu_prints(char *)
# 		Arguments:	r4 - pointer to string
# ---------------------------------------------------------------------
.global bsu_prints
bsu_prints:

	subi	sp,sp,8			# push stack pointer
	stw		ra,0(sp)		# save return address
	stw		r16,4(sp)		# preserve r16 for caller 

	mov		r16,r4			# reference string location
	loop:
		ldb		r4,0(r16)		# get next byte
		beq		r4,r0,loop_end	# end of string ?			
		call	bsu_putchar		# send character to JTAG UART
		incr	r16				# point to next char
		br		loop
	loop_end:
	
	ldw		ra,0(sp)		# restore return address
	ldw		r16,4(sp)		# restore r16 for caller
	addi	sp,sp,8			# restore stack pointer (pop)
		
	ret
	
# ---------------------------------------------------------------------
# Send character to JTAG UART port
#		C syntax:	void bsu_putchar(char ch)
# 		Arguments:	r4 - character to send to JTAG UART
# ---------------------------------------------------------------------
.global bsu_putchar
bsu_putchar:

	//movia	r13,JTAG_UART_BASE			# get addressability to port
	ldw		r13,%gprel(JTAG_UART_ADDR)(gp)

	putchar_wait:

		ldwio	r12,4(r13)				# check for space in FIFO
		andhi	r12,r12,0xffff			# mask it off
		beq		r12,zero,putchar_wait	# loop if no space

	stwio	r4,0(r13)					# send byte
	
	ret

.end

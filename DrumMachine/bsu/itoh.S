# file: BSU/itoh.s
# Author: Arlen Planting
# Date: September 2007
# Environment Tested: Altera Debug Client

#include "BSU\bsu_macros.inc"

.text

# ---------------------------------------------------------------------
# Convert word (32 bits) to printable (ASCII) hex
#	C syntax:	void itoh(unsigned int n, char s[]);
# 	Arguments:	r4 - word to convert
#			r5 - pointer to buffer for ASCIIZ string
# ---------------------------------------------------------------------
.global itoh
itoh:

	movia	r15,HEX_DIGITS		# ascii lookup table
	movi	r8,8			# counter (down)
	add	r2,r5,r8

	stb	r0,0(r2)		# terminate string
	
	loop:

		subi	r8,r8,1		# decrement count
		
		add	r2,r5,r8

		andi	r3,r4,0xf	# mask 4 bits
		add	r3,r15,r3	# index ASCII table
	
		ldb	r3,0(r3)	# get printable char
		stb	r3,0(r2)	# put in string

		srli	r4,r4,4		# shift next 4 bits
		
		bne	r8,r0,loop

	ret

.data

	HEX_DIGITS:	.ascii "0123456789abcdef"	
	
.end

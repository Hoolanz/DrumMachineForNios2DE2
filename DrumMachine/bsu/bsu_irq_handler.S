# File: BSU/bsu_irq_handler.S
# Author: Arlen Planting
# Date: October 2010
# Environment Tested: Altera Nios II IDE
#
# This routine is called from bsu_exceptions.S
# It handle all hardware interrupt exceptions by routine them
# to handlers registered in ISR_TABLE.
#

.text

.global bsu_irq_handler
bsu_irq_handler:

	subi	sp,sp,20
	stw		ra,0(sp)
	stw		r18,4(sp)
	stw		r19,8(sp)
	stw		r20,12(sp)
	stw		r21,16(sp)
	
	mov		r21,r4				# ipending values
	mov		r20,r0				# current IRQ number checking

	LOOP:
		
		beq		r21,r0,END_ISR		# no more IRQs
	
		andi	r19,r21,1			# test if IRQ is pending
		beq		r19,r0,LOOP_INCR	# NO - not pending

		movia	r18,ISR_TABLE		# YES - addr ISR Table	
		slli	r19,r20,2			# mult by 4 for offset in table
		add		r19,r18,r19			# add to start
		ldw		r19,0(r19)			# get ISR function address
		
		callr	r19					# call ISR
	
	  LOOP_INCR:
	
		srli	r21,r21,1		# shift ipending bits for next one
		addi	r20,r20,1		# increment current IRQ number
		br		LOOP
		
	LOOP_END:


	# **********************************************************
	
	END_ISR:

	ldw		ra,0(sp)
	ldw		r18,4(sp)
	ldw		r19,8(sp)
	ldw		r20,12(sp)
	ldw		r21,16(sp)
	addi	sp,sp,20
		
	ret
		
.end


# File: BSU/bsu_exceptions.S
# Author: Arlen Planting
# Date: October 2010
# Environment Tested: Altera Nios II IDE
#
# This routine is the initial entry point for all exceptions
# and generally will be located at address 0x20
# This module currently handles hardware interrupts and 
# routes all otheres to a break instruction
#

//#include "system.h"

        .set noat
      
.section .exceptions.entry.label, "xa"

.globl bsu_exceptions_entry
bsu_exceptions_entry:

# **********************************************************
# This routine determines what type of exception has
# occurred and takes appropriate action
# **********************************************************
#	break
	addi  sp,sp,-76
	stw   ra,  0(sp)
	stw   at,  8(sp)
	stw   r2, 12(sp)
	stw   r3, 16(sp)
	stw   r4, 20(sp)
	stw   r5, 24(sp)
	stw   r6, 28(sp)
	stw   r7, 32(sp)
	stw   r8, 36(sp)
	stw   r9, 40(sp)
	stw   r10,44(sp)
	stw   r11,48(sp)
	stw   r12,52(sp)
	stw   r13,56(sp)
	stw   r14,60(sp)
	stw   r15,64(sp)
	rdctl r5,estatus
	stw   r5, 68(sp)
	
	addi  r15,ea,-4
	stw   r15,72(sp)
	
	rdctl r4,ipending
	
	andi  r2,r5,1
	beq   r2,zero,NOT_HW
	beq   r4,zero,NOT_HW
	
	call  bsu_irq_handler
	br    bsu_irq_exit
	
NOT_HW:
	
	stw   ea,72(sp)
	ldw   r2,-4(ea)
	break 0
	
bsu_irq_exit:	
	
	ldw   r5,68(sp)
	ldw   ea,72(sp)
	ldw   ra,0(sp)
	wrctl estatus,r5
	ldw   at,8(sp)
	ldw   r2,12(sp)
	ldw   r3,16(sp)
	ldw   r4,20(sp)
	ldw   r5,24(sp)
	ldw   r6,28(sp)
	ldw   r7,32(sp)
	ldw   r8,36(sp)
	ldw   r9,40(sp)
	ldw   r10,44(sp)
	ldw   r11,48(sp)
	ldw   r12,52(sp)
	ldw   r13,56(sp)
	ldw   r14,60(sp)
	ldw   r15,64(sp)
	addi  sp,sp,76

	eret 

.end


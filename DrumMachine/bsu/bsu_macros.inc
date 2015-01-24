# File: BSU/bsu_macros.inc
# Author: Arlen Planting
# Date: October 2010
# Environment Tested: Altera Nios II IDE
#
# --------------------------------------------------------
#
.macro incr reg
	addi 	\reg,\reg,1
.endm

# --------------------------------------------------------
#
.macro decr reg
	addi 	\reg,\reg,-1
.endm

# --------------------------------------------------------
#
.macro testbiti rB,rA,IMM5
	.if \IMM5<16
		andi	\rB,\rA,(1<<\IMM5)
	.else
		andhi	\rB,\rA,(1<<(\IMM5-16))
	.endif
.endm

# --------------------------------------------------------
#
.macro  divr nbr,divisor
	div		r2,\nbr,\divisor
	mul		r3,r2,\divisor
	sub		r3,\nbr,r3
.endm

# --------------------------------------------------------
#
.macro  divrx result, remainder, nbr, divisor
	div		\result, \nbr, \divisor
	mul		\remainder, \result, \divisor
	sub		\remainder, \nbr, \remainder
.endm

# --------------------------------------------------------
#
.macro  getbits rego, regi, offset, mask
	srli	\rego, \regi, \offset
	andi	\rego, \rego, \mask    
.endm

# --------------------------------------------------------
#
.macro  putbits rego, regi, regoffset, imask
	ror		\rego, \rego, \regoffset
	nor		\rego, \rego, zero
	ori		\rego, \rego, \imask
	nor		\rego, \rego, zero
	andi	\regi, \regi, \imask
	or		\rego, \rego, \regi
	rol		\rego, \rego, \regoffset
.endm

# --------------------------------------------------------
#
.macro	shport name
	.section	.sbss,"aws",@nobits
	.type	\name, @object
	.size	\name, 4
	.align	2
\name:
	.zero	4
.endm

# --------------------------------------------------------
#
.macro push a1,a2,a3,a4,a5,a6,a7,a8

	.equ count,0
	.ifnc "\a1",""
		.set count,count+1
	.endif

	.ifnc "\a2",""
		.set count,count+1
	.endif

	.ifnc "\a3",""
		.set count,count+1
	.endif

	.ifnc "\a4",""
		.set count,count+1
	.endif

	.ifnc "\a5",""
		.set count,count+1
	.endif

	.ifnc "\a6",""
		.set count,count+1
	.endif

	.ifnc "\a7",""
		.set count,count+1
	.endif

	.ifnc "\a8",""
		.set count,count+1
	.endif

	.equ os,0

	subi	sp,sp,count*4+4
	
	stw	ra,os(sp)
	.equ	os,os+4

	.ifnc "\a1",""
		stw \a1,os(sp)
		.equ os,os+4
	.endif

	.ifnc "\a2",""
		stw \a2,os(sp)
		.equ os,os+4
	.endif

	.ifnc "\a3",""
		stw \a3,os(sp)
		.equ os,os+4
	.endif

	.ifnc "\a4",""
		stw \a4,os(sp)
		.equ os,os+4
	.endif

	.ifnc "\a5",""
		stw \a5,os(sp)
		.equ os,os+4
	.endif

	.ifnc "\a6",""
		stw \a6,os(sp)
		.equ os,os+4
	.endif

	.ifnc "\a7",""
		stw \a7,os(sp)
		.equ os,os+4
	.endif

	.ifnc "\a8",""
		stw \a8,os(sp)
		.equ os,os+4
	.endif
.endm

# --------------------------------------------------------
#
.macro pop a1,a2,a3,a4,a5,a6,a7,a8

	.equ oc,0

	ldw ra,oc*4(sp)
	.equ oc,oc+1

	.ifnc "\a1",""
		ldw \a1,oc*4(sp)
		.equ oc,oc+1
	.endif

	.ifnc "\a2",""
		ldw \a2,oc*4(sp)
		.equ oc,oc+1
	.endif

	.ifnc "\a3",""
		ldw \a3,oc*4(sp)
		.equ oc,oc+1
	.endif

	.ifnc "\a4",""
		ldw \a4,oc*4(sp)
		.equ oc,oc+1
	.endif

	.ifnc "\a5",""
		ldw \a5,oc*4(sp)
		.equ oc,oc+1
	.endif

	.ifnc "\a6",""
		ldw \a6,oc*4(sp)
		.equ oc,oc+1
	.endif

	.ifnc "\a7",""
		ldw \a7,oc*4(sp)
		.equ oc,oc+1
	.endif

	.ifnc "\a8",""
		ldw \a8,oc*4(sp)
		.equ oc,oc+1
	.endif

	addi	sp,sp,oc*4
.endm

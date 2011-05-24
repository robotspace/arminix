#==============================================================================
#
# IPC.s - Inter Process Communication
# written by: Léon Melis, for the Minix3 ARM port. Oct 2009.
#
#==============================================================================
.sect .text
.code 32

# See src/kernel/ipc.h for C definitions
.set SEND,		1
.set RECEIVE,	2
.set SENDREC,	3 
.set NOTIFY,	4
.set SENDNB,	5
.set SENDA,		16

.global _send
.global _receive
.global _sendrec
.global _notify
.global _sendnb
.global _senda

_send:
	mov	r2,r1			@ &m_ptr
	mov	r1,r0			@ &src_dst_e
	ldr	r0, =SEND		@ call_nr
	mov	r3, #0			@ bit_map
	swi #0
	mov pc,lr
	
_receive:
	mov	r2,r1			@ &m_ptr
	mov	r1,r0			@ &src_dst_e
	ldr	r0,=RECEIVE		@ call_nr
	mov	r3,#0			@ bit_map
	swi #0
	mov pc,lr

_sendrec:
	mov	r2,r1			@ &m_ptr
	mov	r1,r0			@ &src_dst_e
	ldr	r0,=SENDREC		@ call_nr
	mov	r3,#0			@ bit_map
	swi #0
	mov pc,lr
	
_notify:
	ldr	r2,=0			@ &m_ptr
	mov	r1,r0			@ &src_dst_e
	ldr	r0,=NOTIFY		@ call_nr
	mov	r3,#0			@ bit_map
	swi #0
	mov pc,lr
	
_sendnb:
	mov	r2,r1			@ &m_ptr
	mov	r1,r0			@ &src_dst_e
	ldr	r0,=SENDNB		@ call_nr
	mov	r3,#0			@ bit_map
	swi #0
	mov pc,lr
	
_senda:
	mov	r2,r1			@ &count
	mov	r1,r0			@ &table
	ldr	r0,=SENDA		@ call_nr
	mov	r3,#0			@ bit_map
	swi #0
	mov pc,lr

@ Get base pointer, for now, a 0 is returned. Could be rewritten to get basepointer from co-processor CP15
.code 32
.sect .text
.global _get_bp
.global get_bp

get_bp:
_get_bp:
	ldr	r0, =0
	mov	pc,lr
	
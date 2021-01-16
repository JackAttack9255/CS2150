	;; Sam Townsend
	;; sft3hy
	;; mathlib.s
	;; 10/25/20

	global _product
	global _power
	

	section .text

_product:
	xor	rax, rax	 ; zero out the return register
	xor	r10, r10	 ; zero out the counter i

start:
	cmp	r10, rsi	 ; does ?
	je	done		 ; if so, we are done with the loop
	add	rax, rdi	 ; add rax to itself
	inc	r10		 ; increment our counter i
	jmp	start		 ; we are done with this loop iteration

_power:
	xor	rax, rax 	 ; zero return register
	mov	rax, 1		 ; else {return 1}
	cmp	rsi, 0		 ; if(b == 0)
	je	done		 ; jump to done
	dec	rsi		 ; b--
	call	_power		 ; recursing
	mov	rsi, rax	 ; put return value into b
	call	_product	 ; return product(a, power(a,b))
done:	

	; Standard epilogue: the return value is already in rax, we
	; do not have any callee-saved registers to restore, and we do not
	; have any local variables to deallocate, so all we do is return
	ret

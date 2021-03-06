	global threexplusone

	section .text

	;; Param 1: x (rdi)

	;; OPTIMIZATIONS:
	;; used lea and addition of rdi 3 times instead of
	;; imul in line 35
	;; used bitshifting in line 41, faster than idiv
	

	
threexplusone:
	xor rax, rax		; return value
	xor r11, r11		; temporary x variable
	xor rcx, rcx
	
	;; check if x = 1
	;; if it is equal to 1, jump to done
	;; check if x is even or odd
	;; if even, divide by two (bitshift right 1 bit)
	;; if odd, multiply by 3 and add one
	;; increment i
	;; recurse (call _threeexplusone)

	cmp rdi, 1
	je  done
	mov r11, rdi
	and r11, 1
	jz  even
	jmp odd

odd:
	lea rdi, [rdi+rdi+rdi+1]
	call threexplusone
	inc rax
	jmp done

even:
	shr rdi, 1
	call threexplusone
	inc rax
	jmp done

done:
	ret

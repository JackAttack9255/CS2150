	global linearSearch

	section .text


	;; Parameter 1 is a pointer to the int array - rdi
	;; Parameter 2 is size of array - rsi
	;; Parameter 3 is element to find - rdx
	
linearSearch:
	xor rax, rax 		; zero out return register
	xor r10, r10 		; zero out counter i
	xor r11, r11 		; zero out another register
	mov rax, -1


start:
	;; compare i to size
	;; if they are equal, jump to done
	;; get address of a[i]
	;; compare param. 3 to a[i]
	;; if not equal, jump to after where I set rax = -1 and i++
	;; set rax = i
	;; jump to done
	
	cmp r10, rsi
	je  done
	cmp edx, [rdi+4*r10]
	jne after
	mov rax, r10
	jmp done

after:
	;; i++
	;; jump to start
	inc r10
	jmp start
	
	
done:
	ret

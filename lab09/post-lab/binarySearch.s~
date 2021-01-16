	global binarySearch

	section .text

	;; Param 1: pointer to array (rdi)
	;; Param 2: left end of array (rsi)
	;; Param 3: right end of array (rdx)
	;; Param 4: target to search for (rcx)
	;; r11: tmp variable that holds value of MID

binarySearch:
	mov rax, -1
	xor r11, r11
	xor ebx, ebx
	xor r9, r9
	xor r10, r10
	

	;; load left+right into r11
	;; divide r11 by two (shr r11, 1)
	;; compare search value (rcx) with r11
	;; if search value (rcx) is greater, lower bound becomes r11
	;; if search value (rcx) is less than, upper bound becomes r11


	
	cmp rdx, rsi
	je  done
	cmp rsi, rdx
	jg done
	lea r11, [rdx+rsi]
	shr r11, 1
	mov eax, [rdi+4*r11]
	cmp ecx, eax
	je  found
	jg  greater
	jl  less
	
	

greater:
	mov rsi, r11
	call binarySearch
	jmp done


less:
	mov rdx, r11
	call binarySearch
	jmp done

found:
	mov rax, r11
	jmp done

notfound:
	mov rax, -1
	jmp done

done:
	ret

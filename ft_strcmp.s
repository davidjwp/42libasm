;%rax: return value;%rdi: 1st arg;%rsi: 2nd arg;%rdx: 3rd arg
section .text
	global ft_strcmp

ft_strcmp:
	xor rax, rax
	xor bl, bl

.loop:
	mov bl, byte [rdi + rax]
	cmp bl, 0x0
	je .ret

	sub bl, byte [rsi + rax]
	cmp bl, byte 0x0
	jne .ret

	inc rax
	jmp .loop

.ret:
	cmp bl, byte [rsi + rax]
	js .neg
	
	mov rax, rbx
	ret

.neg:
	
	; sub ebx, dword [rsi + rax]
	mov eax, ebx
	ret
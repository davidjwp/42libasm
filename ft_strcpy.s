default	rel
	; 1st rdi 2nd rsi 

section .text
	global ft_strcpy

ft_strcpy:
	xor rcx, rcx
.loop:
	cmp byte [rsi + rcx], 0
	je .ret

	mov al, byte [rsi + rcx]
	mov [rdi + rcx], al

	inc rcx
	jmp	.loop

.ret:
	mov rax, rdi
	ret

default	rel

section .text
	global ft_strcpy

ft_strcpy:
	xor rcx, rcx

.loop:
	mov al, byte [rsi + rcx]
	mov [rdi + rcx], al
	
	inc rcx
	test al, al
	jne	.loop

	mov rax, rdi
	ret

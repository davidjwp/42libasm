section .text
	global ft_strcmp

ft_strcmp:
	xor rax, rax

.loop:
	mov bl, byte [rdi + rax]
	sub bl, byte [rsi + rax]
	jne .ret

	cmp byte [rsi + rax], 0
	je .ret

	inc rax
	jmp .loop

.ret:
	movsx rax, bl
	ret
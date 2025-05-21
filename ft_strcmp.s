;%rax: return value;%rdi: 1st arg;%rsi: 2nd arg;%rdx: 3rd arg
section .text
	global ft_strcmp

ft_strcmp:
	xor rax, rax
	xor bl, bl

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
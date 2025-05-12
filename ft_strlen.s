default rel
;volatile registers: RAX, RCX, RDX, R8, R9, R10, R11

section .text
	global ft_strlen

ft_strlen:
	xor rax, rax
.loop:
	cmp byte [rdi + rax], 0
	je .ret

	inc  rax
	jmp .loop

.ret:
	ret

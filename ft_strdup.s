section .text
	global ft_strdup
	extern malloc, __errno_location, ft_strlen

ft_strdup:
	push rdi
	call ft_strlen
	mov rdi, rax
	inc rdi

	call malloc wrt ..plt
	test rax, rax
	jz .err

	xor rbx, rbx
	pop rdi

.loop:
	mov cl, byte [rdi + rbx]
	mov byte [rax + rbx], cl

	inc rbx
	test cl, cl
	jnz .loop
	
	ret

.err:
	call __errno_location wrt ..plt
	mov dword [rax], 12
	xor rax, rax
	ret
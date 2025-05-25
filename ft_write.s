section .text
	global ft_write
	extern __errno_location 

ft_write:
	mov rax, 1
	syscall

	cmp rax, -1
	jns .ret

	neg rax
	push rax
	call __errno_location wrt ..plt
	pop rdi
	mov [rax], rdi
	mov rax, -1

.ret:		
	ret
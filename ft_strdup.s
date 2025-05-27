section .text
	global ft_strdup
	; extern ft_strlen
	extern __errno_location
	extern ENOMEM

ft_strdup:
	push rdi
	call ft_strlen
	inc rax
	push rax

	mov rdi, 0
	mov rax, 12
	syscall

	cmp rax, -1
	je .err

	pop rax

.loop:

	mov bl, byte [rdi + rax]
	mov byte ptr - [rax], bl

	cmp bl, 0
	je .loop
	ret	

.err:
	call __errno_location wrt ..plt
	mov [rax], ENOMEM
	mov rax, 0
	ret
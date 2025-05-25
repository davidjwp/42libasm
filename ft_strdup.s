section .text
	global ft_strdup
	; extern ft_strlen

ft_strdup:	
	push rdi
	call ft_strlen
	add rdi, rax
	mov rax, 12
	syscall

	

	ret	

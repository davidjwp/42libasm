;%rax: return value;%rdi: 1st arg;%rsi: 2nd arg;%rdx: 3rd arg
section .text
	global ft_strcmp

ft_strcmp:
	xor rax, rax

.loop:
	cmp [rdi + rax], [rsi + rax]
	inc rax
	je loop
	jn false

.true:
	xor rax, rax
	ret

.false:
	mov rax, 1
	ret
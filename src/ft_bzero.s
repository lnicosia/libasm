section .text
	global ft_bzero

ft_bzero:

	; void ft_bzero(void *s, size_t n)

	xor rcx, rcx

init_loop:
	mov [rdi + rcx - 1], byte 0	; put 0 in [addr pointed by rdi (first arg) + count - 1]
	inc rcx						; count--
	cmp rcx, rsi				; start again if count count <= n
	jle init_loop
	ret

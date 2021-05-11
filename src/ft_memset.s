section .text
	global ft_memset

ft_memset:

	; void *ft_memset(void *s, int c, size_t n)

	xor rcx, rcx

init_loop:
	mov [rdi + rcx - 1], sil	; put byte of rsi in [addr pointed by rdi (first arg) + count - 1]
	inc rcx						; count--
	cmp rcx, rdx				; start again if count count <= n
	jle init_loop
	mov rax, rdi
	ret

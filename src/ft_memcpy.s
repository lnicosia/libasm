section .text
	global ft_memcpy

ft_memcpy:

	; void *ft_memcpy(void *dest, const void *src, size_t n)

	xor rcx, rcx

init_loop:
	mov r8, [rsi + rcx - 1]
	mov [rdi + rcx - 1], r8b	; put byte of rsi in [addr pointed by rdi (first arg) + count - 1]
	inc rcx			; count--
	cmp rcx, rdx	; start again if count <= n
	jle init_loop
	mov rax, rdi
	ret
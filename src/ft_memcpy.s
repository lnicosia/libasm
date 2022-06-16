section .text
	global ft_memcpy

ft_memcpy:

	; void *ft_memcpy(void *dest, const void *src, size_t n)

	xor rcx, rcx

cpy_loop:
	mov r8b, byte [rsi + rcx] ; r8b = src[rcx]
	mov [rdi + rcx], r8b	; dest[rcx] = r8b
	inc rcx			; count++;
	cmp rcx, rdx	; start again if count <= n
	jle cpy_loop
	mov rax, rdi
	ret
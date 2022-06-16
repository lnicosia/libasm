section .text
	global ft_strcpy

ft_strcpy:

	; void *ft_strcpy(char *dest, const char *src)

	xor al, al		; set al to 0 to compare the bytes in src with it
	xor rcx, rcx	; init our counter to 0
	cmp [rsi], al	; start copying if src[0] is not 0
	jne cpy_loop

cpy_loop:
	mov r8b, byte [rsi + rcx]	; tmp = src[i]
	mov byte [rdi + rcx], r8b	; dest[i] = tmp
	inc rcx				; count ++
	cmp r8b, al	; start again if count <= n
	jne cpy_loop
	mov rax, rdi
	ret
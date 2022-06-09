section .text
	global ft_strcpy

ft_strcpy:

	; void *ft_strcpy(char *dest, const char *src)

	xor al, al		; set al to 0 to compare the bytes in src with it
	xor rcx, rcx	; init our counter to 0
	cmp [rsi], rcx	; start copying if src[0] is not 0
	jne cpy_loop

cpy_loop:
	mov r8, [rsi + rcx]	; tmp = src[i]
	mov [rdi + rcx], r8	; dest[i] = tmp
	cmp [rsi + rcx], al	; start again if count <= n
	inc rcx				; count ++
	jle cpy_loop
	mov rax, rdi
	ret
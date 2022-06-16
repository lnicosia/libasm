section .text
	global ft_strdup
	extern malloc
	extern ft_strlen
	extern ft_strcpy

ft_strdup:

	; char		*ft_strdup(const char *s);

	push rdi		; save s
	call ft_strlen	; get its len
	mov r12, rax	; save it in r10
	inc r12			; + 1 for the '\0'
	mov rdi, r12	; put it in rdi (arg for malloc)
	call malloc		; malloc new str (res is in rax)
	pop rsi
	push rax
	mov rdi, rax
	call ft_strcpy
	pop rax
	ret
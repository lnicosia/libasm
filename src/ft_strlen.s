section .text
	global ft_strlen

ft_strlen:

	; size_t	ft_strlen(const char *s)

	push rdi		; save first arg value on the stack because we will change it
	xor al, al		; al = 0
	xor rcx, rcx	; rcx = 0. rcx so we can count the biggest size possible
	not rcx			; all rcx bytes to 1 (rcx = -1) because we can only decrement it
	cld				; clear direction flag to make sure we go forward in the str
	repne scasb		; repeat rdi++ and rcx-- until we find the byte in al (0)
	not rcx			; all rcx bytes to 0 except what we counted
	dec rcx			; dec rcx because we counted the 0 byte
	pop rdi			; restore back the arg from the stack
	mov rax, rcx	; put the res into rax and return it
	ret
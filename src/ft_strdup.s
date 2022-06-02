section .text
	global ft_strdup
	extern	ft_puts
	extern	malloc
	extern	ft_strlen

ft_strdup:

	; char		*ft_strdup(const char *s);

	push rdi		; save s
	call ft_strlen	; get its len
	mov r12, rax	; save it in r10
	inc r12			; + 1 for the '\0'
	mov rdi, r12	; put it in rdi (arg for malloc)
	call malloc		; malloc new str (res is in rax)
	pop r9
	mov r14, rax
	xor rcx, rcx
	cmp rcx, r12
	jge end

copy_loop:
	mov r13, [r9 + rcx]	; save s[rcx] in r12
	mov [r14 + rcx], r13b	; cpy s[rcx] in rax[rcx]
	inc rcx
	cmp rcx, r12
	jl copy_loop
	mov [rax + rcx], byte 0
	

end:
	ret
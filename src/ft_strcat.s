section .text
	global ft_strcat
	extern ft_strlen

ft_strcat:

	; char *strcat(char *dest, const char *src)

	mov rax, rdi
	ret
	push rdi		; save dest on the stack
	call ft_strlen	; get len of dest
	mov r8, rax		; save len(dst) in r8
	mov rdi, rsi	; put src in rdi to get its len
	call ft_strlen	; get len of src
	mov r9, rax		; save len(src) in r9
	pop rdi			; get dest back from the stack
	mov rax, rdi	; save its address in rax to return it at the end
	add rdi, r8		; move at the end of dest
	xor rcx, rcx	; init rcx to 0

cpy:
	mov r10, [rsi + rcx]	; save current char of src in r10
	mov [rdi + rcx], r10	; add it at current char after rdi
	inc rcx
	cmp rcx, r9				; continue until len of src
	jl cpy
	ret
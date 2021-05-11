section .data
	msg db 10

section .text
	global ft_puts
	extern ft_strlen

ft_puts:

	; int	ft_puts(const char *s)

	push r8
	call ft_strlen
	mov rdx, rax	; len into rdx (3rd param for syscall)
	mov rsi, rdi	; rdi (param from ft_puts) into rsi (2nd param for syscall)
	mov rdi, 1		; stdout into rdi (1st param for syscall)
	mov rax, 1		; WRITE syscall in rax
	syscall
	mov r8, rax		; save the syscall return into r8
	mov rsi, msg	; new line msg into rsi (2nd param for syscall)
	mov rdx, 1		; len of 1 into rdx (3rd param for syscall)
	mov rax, 1		; put back WRITE syscall into rax
	syscall
	add rax, r8		; add the first return value to the new one that will be returned
	pop r8
	ret
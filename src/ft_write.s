extern __errno_location

section .text
	global ft_write

ft_write:

	; ssize_t write(int fd, const void* buf, size_t count)

	mov rax, 1		;	1 = syscall for write()
	syscall
	cmp rax, 0
	jl error
	ret

error:
	neg rax			;	error is negative idk why
	push rax 		;	save return value
	call __errno_location
	pop rdi			;	get return value back
	mov [rax], rdi	;	assign it to the value pointed by rax (ie errno)
	mov rax, -1		;	return value to -1
	ret
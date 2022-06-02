extern __errno_location

section .text
	global ft_write

ft_write:

	; ssize_t write(int fd, const void* buf, size_t count)

	mov rax, 1
	syscall
	cmp rax, 0
	jl error
	ret

error:
	neg rax
	push rax
	call __errno_location
	pop rdi
	mov [rax], rdi
	mov rax, -1
	ret
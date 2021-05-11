section .data
	buff db 0

section .text
	global ft_cat

ft_cat:

	; void	ft_cat(int fd)

	mov r12, rdi	; save fd in r12

read:
	
	mov rax, 0		; sycall value for read
	mov rdi, r12	; put fd in rdi
	mov rsi, buff	; read in buff
	mov rdx, 1		; read 1 char
	syscall
	cmp rax, 0
	je return

write:
	mov rax, 1		; syscall value for write
	mov rdi, 1		; syscall
	mov rsi, buff
	mov rdx, 1
	syscall
	jmp read

return:
	ret
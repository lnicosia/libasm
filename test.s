section .data
	msg db "Hello ", 10
	len equ $ - msg

section .text
	global _start

_start:
	mov rbx, 1
	mov r8, 10
	;jmp incr
	;mov rbx, 0
	;mov rax, 60
	;syscall

incr:
	mov rax, 1
	mov rdi, 1
	mov rsi, msg
	mov rdx, len
	syscall
	dec r8
	cmp r8, 0
	jg incr
	mov rbx, 0
	mov rax, 60
	syscall
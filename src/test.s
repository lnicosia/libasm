section .data
cc:
	.string db "Yooooo", 10
	.len equ $ - cc.string

section .text
	global _start
	global _main

_start:
	call _main
	ret

_main:
	;//push rbp
	;//mov rbp, rsp
	;//sub rsp, 16
	;//mov rdi, 1
	;//lea rsi, [rel cc.string]
	;//mov rdx, cc.len
	;//mov rax, 4
	;//syscall
	leave
	ret
section .text
	global ft_strcmp

ft_strcmp:

	; int	ft_strcmp(const char* s1, const char* s2);

	cld
	repz cmpsb
	xor eax, eax
	xor edx, edx
	dec rdi
	dec rsi
	mov al, byte [rdi]
	mov dl, byte [rsi]
	cmp al, dl
	jl return_neg
	je return_equ
	jg return_pos

return_neg:
	mov eax, -1
	ret
	
return_equ:
	xor eax, eax
	ret
	
return_pos:
	mov eax, 1
	ret
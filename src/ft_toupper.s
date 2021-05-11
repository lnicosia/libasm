section .text
	global ft_toupper

ft_toupper:

	; int ft_toupper(int c);

	mov	ax, 1		; set al to 1

lower:
	xor cx, cx		; set cx to 0
	xor dx, dx		; set dx to 0
	cmp edi, 96		; compare c to a (96)
	cmovg cx, ax	; set cx to 1 if it's more
	cmp edi, 123	; compare c to z (123)
	cmovl dx, ax	; set dc to 1 if it's less
	and cx, dx
	cmp cx, 1
	jne return

upper_it:
	sub edi, 32

return:
	mov eax, edi
	ret
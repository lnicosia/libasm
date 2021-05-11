section .text
	global ft_tolower

ft_tolower:

	; int ft_tolower(int c);

	mov	ax, 1		; set al to 1

upper:
	xor cx, cx		; set cx to 0
	xor dx, dx		; set dx to 0
	cmp edi, 64		; compare c to A (64)
	cmovg cx, ax	; set cx to 1 if it's more
	cmp edi, 91		; compare c to Z (91)
	cmovl dx, ax	; set dc to 1 if it's less
	and cx, dx
	cmp cx, 1
	jne return

lower_it:
	add edi, 32

return:
	mov eax, edi
	ret
section .text
	global ft_isprint

ft_isprint:

	; int ft_isprint(int c);

	mov	ax, 1		; set al to 1

nb:
	xor cx, cx		; set cx to 0
	xor dx, dx		; set dx to 0
	cmp edi, 31		; compare c to 31
	cmovg cx, ax	; set cx to 1 if it's more
	cmp edi, 127	; compare c to 127
	cmovl dx, ax	; set dc to 1 if it's less
	and cx, dx
	cmp cx, 1
	je true

false:
	xor eax, eax,
	ret

true:
	mov eax, 1
	ret
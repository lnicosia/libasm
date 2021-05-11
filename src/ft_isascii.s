section .text
	global ft_isascii

ft_isascii:

	; int ft_isascii(int c);

	mov	ax, 1		; set al to 1
	
ascii:
	xor cx, cx		; set cx to 0
	xor dx, dx		; set dx to 0
	cmp edi, 0		; compare c to 47
	cmovge cx, ax	; set cx to 1 if it's more
	cmp edi, 127	; compare c to 58
	cmovle dx, ax	; set dc to 1 if it's less
	and cx, dx
	cmp cx, 1
	je true

false:
	xor eax, eax,
	ret

true:
	mov eax, 1
	ret
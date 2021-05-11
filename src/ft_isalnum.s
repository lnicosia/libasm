section .text
	global ft_isalnum

ft_isalnum:

	; int ft_isalnum(int c);

	mov	ax, 1		; set al to 1
	
nb:
	xor cx, cx		; set cx to 0
	xor dx, dx		; set dx to 0
	cmp edi, 47		; compare c to 47
	cmovg cx, ax	; set cx to 1 if it's more
	cmp edi, 58		; compare c to 58
	cmovl dx, ax	; set dc to 1 if it's less
	and cx, dx
	cmp cx, 1
	je true

upper:
	xor cx, cx		; set cx to 0
	xor dx, dx		; set dx to 0
	cmp edi, 64		; compare c to 47
	cmovg cx, ax	; set cx to 1 if it's more
	cmp edi, 91		; compare c to 58
	cmovl dx, ax	; set dc to 1 if it's less
	and cx, dx
	cmp cx, 1
	je true

lower:
	xor cx, cx		; set cx to 0
	xor dx, dx		; set dx to 0
	cmp edi, 96		; compare c to 47
	cmovg cx, ax	; set cx to 1 if it's more
	cmp edi, 123	; compare c to 58
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

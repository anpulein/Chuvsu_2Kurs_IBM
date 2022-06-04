;  Макрокоманда поиска в массиве arr элемента,
; равного содержимому ячейки Х, и замены его содержимым
; ячейки Y. Число элементов списка задается первым элементом 

data segment
	mas db 6,1,-6,3,-8,3,9
	a db 5
data ends


change macro arr, X
	local m1, next, exit; метки внутри макрокоманды объявляют локальными
	push si cx ax; сохранить в стеке используемые регистры
	mov si, arr; начальный адрес массива
	mov al,X  ; В al записываем заменяемый символ  
	mov cx,0
	mov cl, [si]; длина массива
	jcxz exit
	
	m1: inc si
		cmp al, [si]
		je exit
		cmp [si], cl
		je next
		mov [si], ah
		
		next: mov [si+1],al ; Переход к следующему символу
			
	loop m1; dec cx, if cx <> 0, go to m1
	
exit:
pop ax cx si

endm
code segment


assume cs:code, ds:data
start: 
	mov ax,data;
	mov ds,ax;
	mov ax, offset mas
	change ax, a
	change ax, 4
	mov ah,4ch
	int 21h
	code ends
end start

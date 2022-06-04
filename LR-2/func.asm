code	segment byte public
		assume cs:code, ds:code
		public stringup
stringup	proc	far
S		equ		dword ptr [bp+6]
Res		equ		dword ptr [bp+12]
		push	bp		; сохранение bp
		mov 	bp,sp	; настройка bp на вершину стека
		push 	ds		; сохранение ds
		les		di,Res	; es:di:= адрес результата
		les		si,S	; ds:si:= адрес исходной строки
		cld				; очистка флага направления (инкремент)
		lodsb			; al:=(ds:[si]), si:=si+1 (al - длина S)
		stosb
		mov		ch,0	; подготовка cx в качестве счётчика
		mov		cl,al	; количество символов строки S
		jcxz	Exit	; выход, если S - пустая строка (cx=0)
Repeat:
		lodsb			; В al скачиваем байт из ds:si
		cmp		al,65
		jl		Save
		cmp		al,90
		jle		Save
		cmp		al,97
		jl		Save
		cmp		al,122
		jle		Change
		cmp		al,128
		jl		Save
Exit:	pop		ds
		pop		bp
		ret		4
		jmp		Exitt

Change:	sub		al,32
Save:	stosb
		loop	Repeat
		jmp		Exit
Exitt:
stringup	endp
code		ends
			end
		
		
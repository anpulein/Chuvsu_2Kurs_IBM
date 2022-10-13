; DLL для Win32 
; procedure StrUpCase(var S: pchar): pchar.
; Все строки заменяются на прописные.

.386
.model flat

; Функции, определяемые в этом dll
public StrUpCase

.code
; Процедура входа dll, в данном случае - пустая заглушка
start:
mov eax, 1 ; Надо вернуть ненулевое число в EAX
ret 12

; Параметры, передаваемые в процедуру 
str equ dword ptr[ebp + 8] ; offset - строка результата - param1


StrUpCase proc
		push ebp		; сохранение bp
		mov  ebp,esp	; настройка bp на вершину стека
		push esi 		; Сохранить регистры, которые нельзя изменять
		push edi
		
		mov esi, str ; Загружаю esi для loadsb
		mov edi, str
;		push 	ds		; сохранение ds
;		les		di,Res	; es:di:= адрес результата
;		les		si,S	; ds:si:= адрес исходной строки
		cld				; очистка флага направления (инкремент)
		lodsb			; al:=(ds:[si]), si:=si+1 (al - длина S)
		stosb
		mov		ecx,0	; подготовка cx в качестве счётчика
		mov		cl,al	; количество символов строки S
		jecxz	Exit	; выход, если S - пустая строка (cx=0)
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


Change:	sub		al,32
Save:	stosb
		loop	Repeat
Exit:
		pop edi
		pop esi
		pop	ebp
		ret		4
StrUpCase endp
End start
		
		
; явное подключение StrUpCaseProc.dll
includelib import32.lib

extrn MessageBoxA: near
extrn ExitProcess: near
extrn LoadLibraryA: near
extrn GetProcAddress: near


.386
.model flat, stdcall

.data
	S db 5,'aBcDe', 0
	; Подключение dll 
	librname db 'StrUpCaseProc.dll',0
	procname db 'StrUpCase',0
	hlib dd ?
	StrUpCase dd ?
	; Сообщения пользователю
	msg1 db 'Source string: ', 0
	msg2 db 'New string: ', 0
	msg3 db 'Lab_4', 0

.code
start:
	call LoadLibraryA, offset librname
	mov hlib, eax
	call GetProcAddress, hlib, offset procname
	mov StrUpCase, offset eax
	call StrUpCase, offset S
	call MessageBoxA, 0, offset S + 1, offset msg3, 0040H + 0
	call ExitProcess,0
	ends
	end start

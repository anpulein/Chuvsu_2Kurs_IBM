; неявное подключение StrUpCaseProc.dll
includelib import32.lib
includelib StrUpCaseProc.lib

extrn MessageBoxA: near
extrn ExitProcess: near
extrn StrUpCase: near


.386
.model flat, stdcall

.data
	S db 7,'aBcDefg', 0
	; Сообщения пользователю
	msg1 db 'Source string: ', 0
	msg2 db 'New string: ', 0
	msg3 db 'Lab_4', 0

.code
start: call StrUpCase, offset S
	call MessageBoxA, 0, offset S + 1, offset msg3, 0040H + 0
	call ExitProcess,0
	ends
	end start

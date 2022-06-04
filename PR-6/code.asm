;Внешние процедуры
includelib import32.lib
 extrn MessageBoxA:proc
 extrn ExitProcess:proc
.386 ;включение 32-битного режима
.model FLAT,STDCALL ;модель памяти FLAT,
;прямая передача параметров
.data
mb_text db 'Hello, World!',0 ;Текстовные константы
mb_title db 'Next program',0 ;для выполнения программы
.code
start:
 call MessageBoxA,0,offset mb_text, offset mb_title,0
 call ExitProcess,0 ;завершение программы
 ends
 end start
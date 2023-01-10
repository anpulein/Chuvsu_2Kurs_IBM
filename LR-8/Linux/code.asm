format ELF64 


public _start
; Процедура, которая является выходной точкой
public fin

;=========================
section '.text' executable
_start:
    mov rax,3Ch

    mov rcx,0 ;нет атрибутов

    mov rdx, myfile ;адрес имени файла

    jc fin ;создан ?

    push rax ;да, дескриптор в стек

    syscall

;=========================

fin: ;нет !

    mov rax,4c00h
    syscall

section '.data' writeable
    myfile db 'test.txt',8
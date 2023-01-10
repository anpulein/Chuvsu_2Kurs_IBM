global _start
section .text

_start:
        pop eax     ; pop argc
        cmp eax, 0x2; если нет аргументов командной строки
        jne _exit   ; exit
        pop eax     ; 
        pop ebx

        ; Открываем файла для изменения
        mov eax,15       ; Функция chmod
        ;mov ebx,filename ; 1 аргумент - название файла
        mov ecx,344      ; 2 аргумент - права доступа   
        int 0x80

_exit:
    mov eax, 1              ; sys_exit                                      
    mov ebx, 0
    int 0x80

section .data
    ;filename db 'test.txt', 0
    ;lenfilename equ $ - filename
    buf_size equ 2048
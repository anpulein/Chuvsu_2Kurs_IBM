;ВЫЧИСЛЕНИЕ ЭКСПОНЕНТЫ С ПОМОЩЬЮ ФУНКЦИЙ СОПРОЦЕССОРА
; Вычислить функцию y = ln(1+x) при |x|<1 двумя способами: 
; а) с использованием трансцендентных команд соцпроцессора
; б) путем разложения функции в ряд y = x-(x^3/3) + (x^5/5)-...

data segment
X dd 0.2
data ends
code segment
assume cs: code, ds: data
mov ax, data
mov ds, ax
SUB EBP, X;
SUB [BX+4*3], EAX;
SUB AL, [ESI*2];
SUB EAX, [EBX+EDX*4];
POP DS;
code ends
end 
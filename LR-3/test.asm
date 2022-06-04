Cseg segment
 assume cs:Cseg,ds:Cseg
x dq 1.0 ; аргумент функции
sum dq ? ; результат вычисления функции
eps dq 1.0E-05; точность вычисления
 ;
start: mov ax,cs ; настройка сегмента данных на cs
 mov ds,ax
 finit ; инициализация сопроцессора
; реализация первого шага алгоритма
 Fld eps
 fld1
 fld x
 fldz
 fld1
 fld1
 fld1
; шаг 2
calc: fxch st(3) ;
 fadd st(0),st(5) ; n=n+1
 fst st(3)
 fdivr st(0),st(2) ; Delta/n
 fmul st(0),st(4) ; (Delta/n)*x
 fst st(2)
 fadd st(1),st(0) ; S=S+Delta
; шаг 3
 fabs ;, ABS(Delta)
; fcomi st(6) ; ABS(Delta)>eps
 db 0dbh,0f6h; машинный код команды
 ja calc ; переход к шагу 2
 fstp st
 fstp sum ; запоминание результата
 finit
 mov ax,4c00h ; выход из программы
 int 21h
Cseg ends
 end start
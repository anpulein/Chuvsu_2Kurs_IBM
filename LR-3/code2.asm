;ВЫЧИСЛЕНИЕ ЭКСПОНЕНТЫ С ПОМОЩЬЮ РАЗЛОЖЕНИЯ В РЯД
; Вычислить функцию y = ln(1+x) при |x|<1 двумя способами: 
; б) путем разложения функции в ряд y = x-(x^3/3) + (x^5/5)-...
; Алгоритм вычисления
; 1. znam=1; chisl=x; S=x
; 2. znam=znam+1; chisl=chisl *(-x); chisl/znam; S=S+chisl/znam
; 3. Если ABS(chisl/znam)>eps идти к 2, иначе - закончить распределение регистров 
; ST(0) - рабочий, ST(1) - S, ST(2) - chisl,
; ST(3) - znam, ST(4) - -x, ST(5) - 1, ST(6) - eps


Cseg segment
 assume cs:Cseg,ds:Cseg
x dq 0.2 ; аргумент функции
sum dq ? ; результат вычисления функции
eps dq 1.0E-05; точность вычисления

start: mov ax,cs ; настроить сегментные
 mov ds,ax ; регистры
 finit ; инициализировать сопроцессор
 .386
 ; реализация первого шага алгоритмов 
 fld eps ; загрузка точности eps
 fld1 ; загрузка 1
 fld x ; загрузить x
 fchs
 fld1 ; загрузка 1
 fld x ; загрузка 1
 fld x ; загрузка x
 fld1 ; загрузка 1
 ; шаг 2
 calc:
	fxch st(3) ; обмен значений st(0) <-> st(3) - znam
	fadd st(0),st(5)
	fst st(3)
	fxch st(2) ; обмен значений st(0) <-> st(2) - chisl
	fmul st(0),st(4) ; chisl * x
	fst st(2)
	fdiv st(0),st(3) ; chisl/znam
	fadd st(1),st(0)
	fabs ; ABS(chisl)
;	fcomi st,st(6) ; ABS(chisl)/znam > eps
	;db 0dbh,0f6h ; машинный код команды
	fcom st(6)
	fstsw ax ; Считывает слово состояния сопроцессора в память
	sahf ; записывает содержимое ah в регист флагов
	ja calc
	fstp st;
	fstp sum ; запоминание результата
	finit
 mov ax,4c00h ; вернуться в DOS
 int 21h
Cseg ends
 end start
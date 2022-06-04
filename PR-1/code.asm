data segment
X db 'a', 0
Y db 'b', 0
data ends
code segment
.386
assume cs: code, ds: data
mov ax, data
mov ds, ax
MOV BL, AX;
MOV X, [BX+4*3];
MOV X, Y;
PUSH CS;
MOV x, SP;
code ends
end

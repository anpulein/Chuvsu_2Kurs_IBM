data segment
X dw 1
data ends
code segment
.386
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
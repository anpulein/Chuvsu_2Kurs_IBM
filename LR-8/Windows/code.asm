includelib import32.lib
; ����� ������������ ������� �� kernel32.dll
 extrn ExitProcess:near
 extrn GetCommandLineA:near
 extrn CreateFileA:near
 extrn GetFileAttributesA:near
 extrn SetFileAttributesA:near
 extrn WriteFile:near
 extrn   GetLastError:near
; ������������ ��� ���������� ���������� ����
 GetCommandLine equ GetCommandLineA
 CreateFile equ CreateFileA
; ����������� �������� � �����
STD_OUTPUT_HANDLE equ -11
GENERIC_READ equ 80000000h
GENERIC_WRITE equ 40000000h
OPEN_EXISTING equ 3
; ���������� ����������, ��������� �� �������
; ����
.386
.model FLAT,STDCALL
.data

nameout db 'CONOUT$'
hcons dd ?
numw       dd    ?
str2  db 'Putin molodec',0
str1  db 'File not found',0

.code
_start: 
 call    CreateFile,offset nameout,GENERIC_READ+GENERIC_WRITE,0,0,OPEN_EXISTING,0,0
                mov     hcons,eax               ;��������� ������ �� ������� ��� �� ����
                call    GetCommandLine          ;� EAX - ��������� �� ���������� ������ 
                mov     esi,eax
                xor     ecx,ecx                 ;�������
                mov     edx,1                   ;�������
n1:             cmp     byte ptr [esi],0        ;����� ������
                je      end_                    ;��� ���������
                cmp     byte ptr [esi],32       ;������
                je      n3
                add     ecx,edx
                cmp     ecx,2                   ;������ �������� - ��� ���������. ������ - ��� �����.
                je      n4
                xor     edx,edx
                jmp     n2
n3:             or      edx,1
n2:             inc     esi
                jmp     n1
n4:             call    GetFileAttributesA,esi

		call GetLastError
  		cmp  eax,02h
  		je  point1

		or eax,1;

		call    SetFileAttributesA,esi,eax
		call WriteFile,hcons,offset str2,14,numw,0
		jmp end_

point1:		call WriteFile,hcons,offset str1,17,numw,0
                
end_:               call ExitProcess,0 
end _start
format PE Native 4.0

include 'win32w.inc'
include 'DDK\ntstatus.inc'

entry DriverEntry

TIMER_FREQUENCY        equ 1193167
OCTAVE		       equ 2

DO		  equ 523			; ��        -  523,25 ��
MI		  equ 659			; ��        -  659,25 ��
SOL		  equ 784			; ����      -  783,99 ��

TONE1		      equ TIMER_FREQUENCY/(DO*OCTAVE)
TONE2		      equ TIMER_FREQUENCY/(MI*OCTAVE)
TONE3		      equ TIMER_FREQUENCY/(SOL*OCTAVE)

section '.code' code readable executable

proc Sound dwPitch

    cli

    invoke WRITE_PORT_UCHAR, 43h, 10110110b

    mov eax, [dwPitch]
    out 42h, al

    mov al, ah
    out 42h, al

    ; �������� ������� 

    invoke READ_PORT_UCHAR, 61h
    or	al, 11b
    invoke WRITE_PORT_UCHAR, 61h, eax

    sti

    mov ecx, 5000000h
    loop $

    cli

    ; ��������� ������� 

    invoke READ_PORT_UCHAR, 61h
    and al, 11111100b
    invoke WRITE_PORT_UCHAR, 61h, eax

    sti

    ret

endp

proc DriverEntry DriverObject, RegistryPath

    stdcall  Sound, TONE1
    stdcall  Sound, TONE2
    stdcall  Sound, TONE3

    mov eax, STATUS_DEVICE_CONFIGURATION_ERROR
    ret

endp

section '.relocs' fixups readable writeable discardable

section '.idata' import readable writeable

  library hal,'hal.dll'

  import hal,\
	 WRITE_PORT_UCHAR, 'WRITE_PORT_UCHAR',\
	 READ_PORT_UCHAR, 'READ_PORT_UCHAR'
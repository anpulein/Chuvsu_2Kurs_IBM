format PE GUI 4.0

include 'win32a.inc'

entry start

section '.data' data readable writeable


caption db 'First Win32 program',0
Message db 'Hello World!',0

counter dd 10
timerID dd ?
msg MSG

section '.code' code readable executable

ConcatStrings:
     push ebp
     mov ebp, esp
     push esi
     push edi
     ; param1 - [ebp+8]
     ; param2 - [ebp+12]
     ; param3 - [ebp+16]

     invoke lstrlen, [ebp+8]
     mov ecx, eax
     mov esi, [ebp+8]
     mov edi, [ebp+16]
     rep movsb

     invoke lstrlen ,[ebp+12]
     mov ecx, eax
     mov esi, [ebp+12]
     rep movsb

     pop edi
     pop esi
     leave
     retn 12

StdcallProcSample:

     push ebp
     mov ebp, esp
     sub esp, 8
     push ebx

     ; previous ebp - [ebp]
     ; return address [ebp+4]
     ; param1 - [ebp+8]
     ; param2 - [ebp+12]
     ; local var 1 - [ebp-4]
     ; local var 2 - [ebp-8]
     invoke lstrlen, [ebp+8]
     mov [ebp-4], eax
     invoke lstrlen, [ebp+12]
     add [ebp-4], eax
     inc dword [ebp-4]

     invoke GetProcessHeap
     mov [ebp-8], eax
     invoke HeapAlloc, eax, HEAP_ZERO_MEMORY, [ebp-4]
     mov [ebp-4], eax

     stdcall ConcatStrings, [ebp+8], [ebp+12], [ebp-4]

     invoke MessageBox, 0 , [ebp-4], [ebp+12], 0
     invoke HeapFree, [ebp-8], 0, [ebp-4]

     pop ebx
     leave
     retn 8

start:
	stdcall StdcallProcSample, Message, caption

	invoke ExitProcess, 0

section '.relocs' fixups readable writeable

section '.idata' import data readable writeable


  library kernel,'KERNEL32.DLL',\
	  user,'USER32.DLL'

  import kernel,\
	 ExitProcess,'ExitProcess',\
	 GetProcessHeap, 'GetProcessHeap',\
	 HeapAlloc,'HeapAlloc',\
	 HeapFree,'HeapFree',\
	 lstrlen, 'lstrlenA'

  import user,\
	 MessageBox,'MessageBoxA'
tasm.exe main.asm /l
pause
tlink main.obj+func.obj
pause
td.exe main.exe
tasm32 /ml /l code.asm
pause
tlink32 /Tpe /ap /c /x code.obj
pause
td32.exe code.exe text.txt
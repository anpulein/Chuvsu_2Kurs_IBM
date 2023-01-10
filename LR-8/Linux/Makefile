CC = fasm
LIBS = asmlib/fmt.asm asmlib/mth.asm asmlib/irp.asm asmlib/str.asm asmlib/sys.asm
.PHONY: default compile
default: compile
compile: $(LIBS)
	$(CC) fmt.asm && $(CC) mth.asm && $(CC) irp.asm && $(CC) str.asm && $(CC) sys.asm
build: code.asm
	$(CC) code.asm
	ld code.o $(LIBS) -o code
once: code.asm
	$(CC) code.asm
	ld code.o -o code
dump: code
	objdump -S -M intel -d code > obj.dump
	cat obj.dump 
hex: code
	hexeditor code
run: code
	./code
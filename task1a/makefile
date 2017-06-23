all: task1
 
task1: encoder.o lab4_util.o lab4_start.o
	ld -melf_i386 -g lab4_start.o encoder.o lab4_util.o -o task1
encoder.o: encoder.c
	gcc -m32 -Wall  -g -ansi -c -nostdlib -fno-stack-protector encoder.c -o encoder.o
lab4_util.o: lab4_util.c
	gcc -m32 -Wall -ansi -g -c -nostdlib -fno-stack-protector lab4_util.c -o lab4_util.o
lab4_start.o: lab4_start.s
	nasm -f elf -g lab4_start.s -o lab4_start.o
clean:
	rm -f *.o  task1
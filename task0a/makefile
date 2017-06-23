all: task0
 
task0: main.o lab4_util.o lab4_start.o
	ld -melf_i386 lab4_start.o main.o lab4_util.o -o task0
main.o: main.c
	gcc -m32 -Wall -ansi -c -nostdlib -fno-stack-protector main.c -o main.o
lab4_util.o: lab4_util.c
	gcc -m32 -Wall -ansi -c -nostdlib -fno-stack-protector lab4_util.c -o lab4_util.o
lab4_start.o: lab4_start.s
	nasm -f elf lab4_start.s -o lab4_start.o
clean:
	rm -f *.o  task0
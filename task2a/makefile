all: task2
 
task2: flame.o lab4_util.o lab4_start.o
	ld -melf_i386 -g lab4_start.o flame.o lab4_util.o -o task2
flame.o: flame.c
	gcc -m32 -Wall  -g -c -nostdlib -fno-stack-protector flame.c -o flame.o
lab4_util.o: lab4_util.c
	gcc -m32 -Wall  -g -c -nostdlib -fno-stack-protector lab4_util.c -o lab4_util.o
lab4_start.o: lab4_start.s
	nasm -f elf -g lab4_start.s -o lab4_start.o
clean:
	rm -f *.o  task2
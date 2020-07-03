all: clean build

build: main.c a_power_b.o
	gcc -m32 main.c a_power_b.o -o a_power_b

a_power_b.o: a_power_b.asm
	nasm -g -f elf -o a_power_b.o a_power_b.asm

clean:
	rm -f a_power_b
	rm -f a_power_b.o

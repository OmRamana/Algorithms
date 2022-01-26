all: main.o isGeometric.o
	gcc main.o isGeometric.o -o main

main.o: main.c
	gcc -c main.c
	
isGeometric.o: isGeometric.asm
	yasm -f elf64 -g dwarf2 isGeometric.asm -o isGeometric.o

run: all
	./main

clean:
	rm *.o main

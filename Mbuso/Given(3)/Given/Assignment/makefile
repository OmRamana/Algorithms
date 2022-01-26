O_FILES = grey.o main.o

a.out: $(O_FILES)
	gcc $(O_FILES) -o a.out -g -m64 -static

main.o: main.c
	gcc -c main.c -g -m64

grey.o: grey.asm
	yasm -f elf64 -g dwarf2 grey.asm -o grey.o

run: a.out
	./a.out

clean:
	rm -rf *.o a.out

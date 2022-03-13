DEBUG_FLAGS = -g3 -O0
RELEASE_FLAGS = -DNDEBUG -O3

FLAGS = $(RELEASE_FLAGS)

preprocess:
	gcc $(FLAGS) -E main.c > temp.c

assemble:
	gcc $(FLAGS) -S main.c

compile:
	gcc $(FLAGS) -c main.c -o main.o

build:
	gcc $(FLAGS) main.o -o main

print_exe:
	objdump -CS main

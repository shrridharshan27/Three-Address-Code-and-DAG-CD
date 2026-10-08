CC = gcc
CFLAGS = -std=c99 -Wall -Wextra

all: build/tac_dag

build/tac_dag: src/tac_and_dag.c
	mkdir -p build
	$(CC) $(CFLAGS) src/tac_and_dag.c -o build/tac_dag

run: all
	./build/tac_dag

clean:
	rm -rf build *.exe

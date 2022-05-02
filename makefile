bin: main.c
	gcc -o bin main.c -lpthread

run: bin
	./bin

clean:
	rm bin
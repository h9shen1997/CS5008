all: clean run

compile: deque.c doubly.c main.c
	@echo -e "\033[0;34mCompiling deque and doubly linkedlist implementation...\033[0m"
	gcc -g main.c deque.c doubly.c -o deque

run: compile
	@echo -e "\033[0;34mRunning deque and doubly linkedlist implementation...\033[0m"
	./deque

.PHONY: compile clean

clean: 
	@echo -e "\033[0;34mCleaning...\033[0m"
	rm -rf duque

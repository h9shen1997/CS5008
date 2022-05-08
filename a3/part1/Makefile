all: clean run

sort: sort.c linkedlist.c  main.c
	@echo -e "\033[0;34mRunning Compile for part1...\033[0m"
	gcc -g main.c sort.c linkedlist.c -o sort

run: sort
	@echo -e "\033[0;34mRunning insertion sort on doubly linked list...\033[0m"
	./sort

.PHONY: sort clean

clean: 
	@echo -e "\033[0;34mCleaning...\033[0m"
	rm -rf sort

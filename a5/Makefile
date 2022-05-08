all: clean run

compile: shell.c shell.h
	@echo -e "\033[0;34mCompiling k-sea-shell...\033[0m"
	gcc shell.c shell.h -o shell

pwd: pwd.c
	@echo -e "\033[0;34mCompiling pwd external command...\033[0m"
	gcc pwd.c -o pwd

run: compile move
	@echo -e "\033[0;34mRunning k-sea-shell...\033[0m"
	./shell

move: pwd
	@echo -e "\033[0;34mMoving pwd executable to $(HOME)/bin...\033[0m"
	mkdir -p $(HOME)/bin
	cp pwd $(HOME)/bin/pwd

.PHONY: pwd compile clean

clean:
	@echo -e "\033[0;34mCleaning...\033[0m"
	rm -rf shell
	rm -rf pwd
	rm -rf $(HOME)/bin/pwd

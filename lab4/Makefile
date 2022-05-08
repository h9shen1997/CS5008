all: clean run

# set the color to blue using \033[0;34m
# reset the color using \033[0m
compile, greetings: goodbye.c greeting.c start.c
	@echo -e "\033[0;34mRunning compile...\033[0m"
	gcc -g goodbye.c greeting.c start.c -o greetings

run: greetings
	@echo -e "\033[0;34mRunning program....\033[0m"
	./greetings

.PHONY: compile clean

clean: 
	@echo -e $(pwd)"\033[0;34mCleaning...\033[0m"
	rm -rf greetings

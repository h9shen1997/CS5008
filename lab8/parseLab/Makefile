all: clean compile

compile: parse.c
	@echo -e "\033[0;34mCompiling parse...\033[0m"
	gcc parse.c -o parse

clean:
	@echo -e "\033[0;34mCleaning...\033[0m"
	rm -rf parse

.PHONY: compile clean
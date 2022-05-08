all: clean run valgrind

mt_search: mt_search.c mt_search.h
	@echo -e "\033[38;5;198m===================================="
	@echo Compiling mt_search...
	@echo -e "====================================\033[0m"
	gcc -pthread -o mt_search mt_search.c 

run: clean mt_search
	@echo -e "\033[38;5;198m===================================="
	@echo Running mt_search with multiple sets of cmd arguments
	@echo -e "\033[38;5;198m====================================\033[0m"
	./mt_search inputs/input1.txt 5 2 11
	@echo -e "\033[38;5;198m====================================\033[0m"
	./mt_search inputs/input1.txt 2 3 11
	@echo -e "\033[38;5;198m====================================\033[0m"
	./mt_search inputs/input2.txt 3 4 26
	@echo -e "\033[38;5;198m====================================\033[0m"
	./mt_search inputs/nums10000.txt 527 20 1000

valgrind: clean mt_search
	@echo -e "\033[38;5;198m===================================="
	@echo Running valgrind on mt_search to check for memory usage
	@echo -e "====================================\033[0m"
	valgrind --leak-check=full ./mt_search inputs/input2.txt 3 4 26

style: clean mt_search
	@echo -e "\033[38;5;198m===================================="
	@echo Running clint.py on all *.c and *.h files to check style
	@echo -e "====================================\033[0m"
	clint.py *.c *.h

.PHONY: clean

clean:
	@echo -e "\033[38;5;198m===================================="
	@echo Cleaning the directory
	@echo -e "\033[38;5;198m====================================\033[0m"
	rm -f mt_search

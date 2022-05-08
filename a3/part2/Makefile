all: clean run

compile, sort_compare: countingsort.c heapsort.c quicksort_median.c quicksort_shuffle.c sort_comparison.c swap.c
	@echo -e "\033[0;34mRunning Compile for part2...\033[0m"
	gcc -g countingsort.c heapsort.c quicksort_median.c quicksort_shuffle.c sort_comparison.c swap.c -o sort_compare

run: sort_compare
	@echo -e "\033[0;34mRunning comparison of different sorting algorithms...\033[0m"
	./sort_compare

.PHONY: compile clean

clean:
	@echo -e "\033[0;34mCleaning...\033[0m"
	rm -rf sort_compare

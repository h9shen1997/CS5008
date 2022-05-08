all: test_suite run

# Points to the root of Google Test, relative to where this file is.
# Remember to tweak this if you move this file.
GTEST_DIR_A = ${HOME}/src/googletest-release-1.8.0/googletest
GOOGLE_TEST_LIB = ${HOME}/lib/gtest/libgtest.a
GOOGLE_TEST_INCLUDE = ${HOME}/src/googletest-release-1.8.0/googletest/include/

GTEST_DOWNLOAD = ${HOME}/src/googletest-release-1.8.0/

# Where to find user code.
USER_DIR = .

# Flags passed to the preprocessor.
# Set Google Test's header directory as a system directory, such that
# the compiler doesn't generate warnings in Google Test headers.
CPPFLAGS += -isystem $(GTEST_DIR_A)/include

# Flags passed to the C++ compiler.
CXXFLAGS += -g -Wall -Wextra -pthread

# All Google Test headers.  Usually you shouldn't change this
# definition.
GTEST_HEADERS = $(GTEST_DIR_A)/include/gtest/*.h \
                $(GTEST_DIR_A)/include/gtest/internal/*.h

# Builds gtest.a

# Usually you shouldn't tweak such internal variables, indicated by a
# trailing _.
GTEST_SRCS_ = $(GTEST_DIR_A)/src/*.cc $(GTEST_DIR_A)/src/*.h $(GTEST_HEADERS)
release-1.8.0.tar.gz : 
	@echo -e "\033[1;93m ----------------"
	@echo NEED GTEST ZIP
	@echo -e "----------------\033[0m"

${GTEST_DIR_A}/src/gtest-all.cc: release-1.8.0.tar.gz
	@echo -e "\033[1;93m==========================="
	@echo Extracting gtest source
	@echo -e "===========================\033[0m"
	mkdir -p ${HOME}/src
	cp release-1.8.0.tar.gz ${HOME}/src/
	tar -xzmf ${HOME}/src/release-1.8.0.tar.gz -C ${HOME}/src/

gtest_main.o : $(GTEST_DIR)/src/gtest_main.cc
	$(CXX) $(CPPFLAGS) -I$(GTEST_DIR) $(CXXFLAGS) -c \
            $(GTEST_DIR)/src/gtest_main.cc

$(GOOGLE_TEST_LIB): ${GTEST_DIR_A}/src/gtest-all.cc
	@echo -e "\033[1;93m==========================="
	@echo Building the GTest library
	@echo -e "===========================\033[0m"
	g++ -isystem ${GTEST_DIR_A}/include -I${GTEST_DIR_A} \
		-pthread -c ${GTEST_DIR_A}/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o
	mkdir -p ~/lib/gtest/
	mv libgtest.a ~/lib/gtest/

run: Hashtable.c Hashtable.h LinkedList.c LinkedList.h LinkedListPriv.c LinkedListPriv.h Main.c
	gcc -g Hashtable.c LinkedList.c LinkedListPriv.c Main.c -o main
	./main

Hashtable.o: Hashtable.c Hashtable.h
	@echo -e "\033[1;93m============================================"
	@echo Building Hashtable.o for testing...
	@echo -e "============================================\033[0m"
	gcc -c -Wall -g Hashtable.c -o Hashtable.o

LinkedList.o: LinkedList.c LinkedList.h
	@echo -e "\033[1;93m============================================"
	@echo Building LinkedList.o for testing...
	@echo -e "============================================\033[0m"
	gcc -c -Wall -g LinkedList.c -o LinkedList.o

LinkedListPriv.o: LinkedListPriv.c LinkedListPriv.h
	@echo -e "\033[1;93m============================================"
	@echo Building LinkedListPriv.o for testing...
	@echo -e "============================================\033[0m"
	gcc -c -Wall -g LinkedListPriv.c -o LinkedListPriv.o

## Compiles your hashtable tests.
test_hashtable.o : test_hashtable.cc
	g++ -c -Wall -I $(GOOGLE_TEST_INCLUDE) test_hashtable.cc \
		-o test_hashtable.o

## Puts it all together. 
test_suite: $(GOOGLE_TEST_LIB) test_hashtable.o Hashtable.o LinkedListPriv.o LinkedList.o
	g++ -o test_suite test_hashtable.o LinkedListPriv.o LinkedList.o Hashtable.o \
		 -L${HOME}/lib/gtest -lgtest -lpthread
	@echo -e "\033[38;5;198m===================================="
	@echo Run tests by running ./test_suite
	@echo -e "====================================\033[0m"
	./test_suite

.PHONY: clean

clean: 
	rm -rf test_suite *.o

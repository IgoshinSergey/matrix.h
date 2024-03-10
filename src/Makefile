CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
GCOV_FLAGS=--coverage
OS=$(shell uname -s)
LIB_FILES=arithmetic/s21*.c matrix/s21*.c transformations/s21*.c common/s21*.c
TEST_FILES=unit_tests/*.c

ifeq ($(OS), Linux)
	LEAK_CHECK=valgrind --tool=memcheck --leak-check=yes
	OPEN_CMD=xdg-open
	ADD_LIB=-pthread -lcheck_pic -pthread -lrt -lm -lsubunit
else ifeq ($(OS), Darwin)
	LEAK_CHECK=leaks -atExit --
	OPEN_CMD=open
	ADD_LIB=-lm -lcheck -lpthread
endif

all: clean s21_matrix.a test gcov_report leaks clang clean

s21_matrix.a: clean
	@$(CC) -c $(CFLAGS) $(LIB_FILES) $(ADD_LIB)
	ar -rcs s21_matrix.a s21_*.o
	@rm -rf *.o

test: clean s21_matrix.a
	@$(CC) -c $(CFLAGS) $(TEST_FILES) $(ADD_LIB)
	@$(CC) $(CFLAGS) s21_*.o s21_matrix.a -o test $(ADD_LIB)
	./test
	@rm -rf *.o test s21_matrix.a

gcov_report: clean
	@$(CC) $(CFLAGS) $(GCOV_FLAGS) $(LIB_FILES) $(TEST_FILES) -o gcov_test $(ADD_LIB)
	./gcov_test
	@lcov -c -d . -o gcov_test.info
	@genhtml -o report gcov_test.info
	
	@rm -rf gcov_test *.out *.o *.gcno *.gcda *.info
	@chmod 777 report/*
	@$(OPEN_CMD) ./report/index.html
	@rm -rf report/

leaks: clean
	@$(CC) $(CFLAGS) $(LIB_FILES) $(TEST_FILES) -o leaks_test $(ADD_LIB)
	$(LEAK_CHECK) ./leaks_test
	@rm -rf leaks_test

clang:
	@clang-format -n $(LIB_FILES) $(TEST_FILES) *.h unit_tests/*.h 

clean:
	@rm -rf *.out *.o *.a
	@rm -rf *.gcno *.gcda *.info
	@rm -rf report/
	@rm -rf test gcov_test leaks_test

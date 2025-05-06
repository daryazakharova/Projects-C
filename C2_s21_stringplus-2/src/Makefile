CC = gcc -Wall -Wextra -Werror -std=c11 -g
.PHONY = all clean gcov_report rebuild check test
OBJ	= s21_string.o 
SRCS = $(wildcard s21*.c)
TEST_SRCS = $(wildcard ./tests/*.c)
OS = $(shell uname)
LIB = -l:s21_string.a
ifeq ($(OS), Linux)
	CHECK_FLAGS = -lcheck -pthread -lrt -lm -lsubunit -L.
else
	CHECK_FLAGS = -lcheck -L.
endif
GCOV_FLAGS = --coverage -Wno-coverage-invalid-line-number
BINARY = test21

all: s21_string.a

s21_string.a: $(OBJ)
	ar rcs s21_string.a *.o
	rm -rf *.o

$(OBJ):
	$(CC) -c $(SRCS)

test: s21_string.a
	$(CC) -o $(BINARY) $(TEST_SRCS) $(CHECK_FLAGS) $(LIB) 
	./test21

gcov_report: test
	$(CC) -o $(BINARY) $(SRCS) $(TEST_SRCS) $(CHECK_FLAGS) $(GCOV_FLAGS)
	./test21
	lcov -t $(BINARY) -o 21_test.info -c -d .
	genhtml -o report 21_test.info
	open ./report/index.html
	rm -rf *.gcda *.gcno 21_test.info

clean: 
	rm -rf *.o *.gcno *gcda *.info *.a $(BINARY) report

rebuild: clean all

check:
	clang-format -i *.c *.h $(TEST_SRCS) 
ifeq ($(OS), Darwin)
	leaks --atExit -- ./$(BINARY)
else
	valgrind ./$(BINARY) --leak-check-full
endif

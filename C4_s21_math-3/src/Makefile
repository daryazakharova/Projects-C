CC = gcc -Wall -Werror -Wextra -std=c11 -pedantic
LIB = s21_math.a
UNAME = $(shell uname)
ifeq ($(UNAME), Linux)
	CHECK_FLAGS = -lcheck -pthread -lrt -lm -lsubunit 
else     
	CHECK_FLAGS = -lcheck 	
endif

all: s21_math.a

s21_math.a: clean
	$(CC) -c s21*.c
	ar rcs s21_math.a *.o
	ranlib s21_math.a
	
test: s21_math.a
	$(CC) $(CHECK_FLAGS) tests.c $(LIB) -o test
	./test

gcov_report: s21_math.a
	$(CC) $(CHECK_FLAGS) --coverage  *.c  -o test
	./test
	lcov -t "test" -o test.info -c -d .
	genhtml -o report test.info
	open report/index.html
	
style:
	clang-format --style=Google -i *.c *.h

clean:
	rm -rf report test *.gcda *.gcno *.info *.o *.a

rebuild: clean all

.PHONY = all clean test gcov_report rebuild check style
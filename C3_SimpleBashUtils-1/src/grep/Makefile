CC = gcc
FLAGS = -Wall -Werror -Wextra

all: s21_grep

s21_grep: s21_grep.c
	@$(CC) $(FLAGS) s21_grep.c -o s21_grep

test: 
	sh grep_testing.sh > rezult.txt

clean:
	rm -rf *.o 
	rm -rf s21_grep

rebuild: 
	clean all
CC = gcc
FLAGS = -Wall -Werror -Wextra

all: s21_cat

s21_cat: s21_cat.c
	@$(CC) $(FLAGS) s21_cat.c -o s21_cat 

test: 
	sh testing.sh > rezult.txt

clean:
	rm -rf *.o 
	rm -rf s21_cat

rebuild: 
	clean all
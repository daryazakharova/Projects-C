UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
CHECK_LIBS = $(shell pkg-config --libs check)
else
CHECK_LIBS = -lcheck
endif

CC = gcc
FLAGS = -std=c11 -Wall -Werror -Wextra 
NAME = s21_smartcalc
TEST_NAME = testing

COVERAGE_FILES = ./*.gcno
COVERAGE_RESULTS = ./*.gcda
GCOV_FILES = ./*.gcov
LCOV_FILES = ./*.info

GTK_FILES = gtk_*.c
LOGIC_FILES = backend.c parser_calc.c stack.c
LOGIC_OBJECT_FILES = backend.o parser_calc.o stack.o

LIBS = `pkg-config --libs --cflags gtk+-3.0` -rdynamic -lm

DIST_NAME=SmartCalc	
DIST_FILES=*.c *.h Makefile 

all: clean install run uninstall

$(NAME).a:
	@rm -rf *.o *.a
	$(CC) $(FLAGS) -c $(LOGIC_FILES)
	ar rc $(NAME).a $(LOGIC_OBJECT_FILES)

install: $(NAME).a
	mkdir -p ./build
	$(CC) $(GTK_FILES) $(NAME).a -o ./build/$(NAME) $(LIBS) 
	cp -rf ./build/$(NAME) $(HOME)/$(NAME)
	@echo "Calc has been successfully installed"

run: install
	./build/s21_smartcalc

uninstall:
	rm -rf build/
	rm -rf $(HOME)/$(NAME)
	rm -rf *.tar
	@echo "Calc has been successfully uninstalled"

clean:
	rm -rf *.o *.a $(COVERAGE_RESULTS) $(COVERAGE_FILES) $(GCOV_FILES) $(LCOV_FILES) $(TEST_NAME) gcov_report/ $(TEST_NAME).dSYM *.zip docs/ build/

dvi: docs
	open docs/html/index.html

docs: clean
	doxygen Doxyfile

dist:
	mkdir $(DIST_NAME)
	cp -r $(DIST_FILES) $(DIST_NAME)
	zip -r $(DIST_NAME).zip $(DIST_NAME)
	rm -rf $(DIST_NAME)

compile_test:
	checkmk $(TEST_NAME).check | $(CC) $(FLAGS) $(LOGIC_FILES) -xc - $(CHECK_LIBS) -o $(TEST_NAME) --coverage

tests: compile_test
	@rm -f $(COVERAGE_RESULTS)
	./$(TEST_NAME)	

gcov: compile_test
	@rm -f $(COVERAGE_RESULTS)
	./$(TEST_NAME)
	@rm -f $(GCOV_FILES)
	gcov $(TEST_NAME).c -f

gcov_report: gcov
	@rm -f $(LCOV_FILES)
	lcov -t $(NAME) -o $(NAME).info -c -d .
	lcov -r $(NAME).info "$(PWD)/$(TEST_NAME).check" -o $(NAME).info
	@rm -rf gcov_report
	genhtml $(NAME).info --function-coverage -o gcov_report
	open gcov_report/index.html

clang:
	clang-format -n *.c *.h

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem *.c

valgrind_test: compile_test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./$(TEST_NAME)

gtk_mac:
	brew install gtk+3

gtk_linux:
	sudo apt-get install libgtk-3-dev

rebuild: clean all

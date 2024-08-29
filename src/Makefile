PROJECT=s21_math
OBJ_DIR=./obj
UNAME_S:=$(shell uname -s)
TEST_SRC=s21_test.c
GCC=gcc -Werror -Wall -Wextra -std=c11
LIB=$(shell find . -name '*.c')
REPORT_FILES=$(shell find . -name '*.gcno') $(shell find . -name '*.gcda')
INC:=$(shell find . -name '*.h')
OBJ=$(patsubst %.c,$(OBJ_DIR)/*.o, $(LIB))

ifeq ($(UNAME_S),Linux)
	CHECK_FLAGS = -lcheck -lsubunit
	OPEN_CMD = xdg-open
	ADD_LIB = -lm -lrt -lpthread -D_GNU_SOURCE
endif

ifeq ($(UNAME_S),Darwin)
	CHECK_FLAGS = $(shell pkg-config --cflags --libs check)
	OPEN_CMD = open
	ADD_LIB =
endif

$(OBJ_DIR)/*.o: *.c $(INC)
	$(GCC) $(ADD_LIB) -I ./ $< -c -o $@

all: clean gcov_report $(PROJECT).a test

clean:
	rm -rf s21_test *.out
	rm -rf $(OBJ_DIR)/*.o $(OBJ_DIR)/*.gc*
	rm -rf ./gcov/*.o ./gcov/*.gc*
	rm -rf ./*.gc*
	rm -rf $(PROJECT).a
	rm -rf report*

clang:
	clang-format --style=Google -n ./*.h ./*.c
	clang-format --style=Google -i *.h ./*.c

$(PROJECT).a: $(OBJ)
	ar rcs $@ $(OBJ_DIR)/*.o

set_report_gcc:
	$(eval GCC += -fprofile-arcs -ftest-coverage -fPIC)
	@echo s21_math:Check build

test: $(TEST_SRC) $(PROJECT).a
	$(GCC) $^ -o s21_test $(CHECK_FLAGS) $(ADD_LIB)
	./s21_test

gcov_report: clean set_report_gcc test
	gcov ./*.c -o $(OBJ_DIR)/*
	mv *.gcov ./gcov
	mv ./*.gc* $(OBJ_DIR)/*.gc* ./gcov
	lcov -t ./gcov -o report.info -c -d ./gcov
	genhtml -o report report.info

.PHONY: clean $(OBJ) $(PROJECT) $(PROJECT).a test clang all $(PROJECT).a set_report_gcc gcov_report

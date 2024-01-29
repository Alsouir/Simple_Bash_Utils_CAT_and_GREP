all: s21_grep test_grep

TARGET1 = s21_grep
CC = gcc -Wall -Wextra -Werror 

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

$(TARGET1) : s21_grep.o
	$(CC) s21_grep.o -o $(TARGET1)

test_grep: test_grep.sh
	sh test_grep.sh

%.o : %.c
	$(CC) -c $< -o $@

clean:
	rm $(TARGET1) *.o

cpp:
	cp ../../materials/linters/.clang-format .
	clang-format -i *.c *.h 
	leaks -atExit -- ./s21_grep
	

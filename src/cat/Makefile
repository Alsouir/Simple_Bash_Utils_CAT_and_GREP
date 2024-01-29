all: s21_cat test_cat
TARGET1 = s21_cat

CC = gcc -Wall -Wextra -Werror 

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c, %.o, $(SRC))

$(TARGET1) : s21_cat.o options.o 
	$(CC) s21_cat.o options.o -o $(TARGET1)

test_cat: test_cat.sh
	sh test_cat.sh

%.o : %.c
	$(CC) -c $< -o $@

clean:
	rm $(TARGET1) *.o

cpp:
	cp ../../materials/linters/.clang-format .
	clang-format -i *.c *.h *.sh
	cppcheck --enable=all --suppress=missingIncludeSystem *.c *.h 
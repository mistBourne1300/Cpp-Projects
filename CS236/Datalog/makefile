
# makefile for project 2 example tests

NUM:=2

numbers:=21 22 23 24 25 26 27 28 61 62

tests:=project$(NUM)-tests

.SILENT: all run

all: run
	@rm $(tests)/out.txt

run:
	for number in $(numbers) ; \
	do \
		echo "Running input $$number" ; \
		./lab$(NUM) $(tests)/in$$number.txt > $(tests)/out.txt ; \
		diff $(tests)/out$$number.txt $(tests)/out.txt || (echo "diff failed on test $$number \n") ; \
	done

compile:
	g++ -Wall -Werror -std=c++17 -g *.cpp -o lab$(NUM)


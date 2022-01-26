
# makefile for project 1 pass-off tests

NUM:=1

buckets:=20 40 60 80 100

numbers_20:=21 22 23
numbers_40:=41
numbers_60:=61 62
numbers_80:=81 82
numbers_100:=101 102

tests:=project$(NUM)-passoff

.SILENT: all $(buckets)

all: $(buckets)
	@rm $(tests)/out.txt

$(buckets):
	echo "Bucket $@"; \
	for number in ${numbers_$@} ; \
	do \
		echo "Running input $$number" ; \
		./lab$(NUM) $(tests)/$@/input$$number.txt > $(tests)/out.txt ; \
		diff $(tests)/$@/answer$$number.txt $(tests)/out.txt || (echo "diff failed on test $$number \n") ; \
	done \

compile:
	g++ -Wall -Werror -std=c++17 -g *.cpp -o lab$(NUM)


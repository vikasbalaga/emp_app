api:api.o lib_mylib.a
	gcc api.o -o api -L. -l_mylib
api.o:api.c
	gcc -c api.c
lib_mylib.a:linked_list.o functions.o
	ar -rcs lib_mylib.a linked_list.o functions.o
linked_list.o:linked_list.c
	gcc -c linked_list.c
functions.o:functions.c
	gcc -c functions.c
analyze:
	cppcheck --enable=all --output-file=analysis.txt *.c *.cc
clean:
	@rm -f *.o
	@rm -f lib_mylib.a
NUMS = $(VALS)
VALS = 6 7 8 9 10
hello:
	for val in $(NUMS); do echo $$val; done 
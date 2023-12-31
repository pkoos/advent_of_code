.PHONY : clean

main: main.o main.a
	gcc -Wall -Wextra -g -o $@ $^

main.o: main.c
	gcc -Wall -Wextra -g -c -o $@ $^

main.a: 1/day_one.o util.o
	ar rcs $@ $^

%.o: %.c
	gcc -Wall -Wextra -g -c -o $@ $<

clean :
	rm -f main main.a 1/day_one.o util.o main.o
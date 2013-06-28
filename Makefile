# Public domain, 2013 Simone Basso <bassosimone@gmail.com>
.PHONY: all clean
all:
	cc -Wall -o main main.c
	cc -Wall -o overflow overflow.c
clean:
	rm -f -- main

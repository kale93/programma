# Public domain, 2013 Simone Basso <bassosimone@gmail.com>
.PHONY: all clean
all:
	cc -Wall -o main main.c
clean:
	rm -f -- main

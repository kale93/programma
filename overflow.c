/* Public domain, 2013 Simone Basso <bassosimone@gmail.com> */

#include <stdio.h>

#define MAXBUF 9
#define STRING "ciao mondocrudele"

/*
 * Find the minimim MAXBUF by which the output of the printf() is what
 * you expect the printf() to output.
 */
int main(int argc, char *const *argv)
{
    int k = 0;
    char buf[MAXBUF];

    sscanf(STRING, "%*s %s", buf);
    printf("%x\n", k);

    return 0;
}

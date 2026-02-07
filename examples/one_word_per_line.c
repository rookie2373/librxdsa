#include <stdio.h>
#define IN 1
#define OUT 0

int main() {

    int c, nc, nw;
    nc = nw = 0;

    while ((c = getchar()) != EOF) {
        nc++;
        putchar(c);
        if (c == ' ' || c == '\t') {
            putchar('\n');
        }

    }
    putchar('\n');

    printf("Size of char: %lu\n", sizeof(char));
    printf("Size of int: %lu\n", sizeof(int));
    printf("Size of long: %lu\n", sizeof(long));
    printf("Size of float: %lu\n", sizeof(float));
    printf("Size of double: %lu\n", sizeof(double));
    return 0;
}
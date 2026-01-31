#include <stdio.h>
# define L_EOF 108

int main() {
    int c;

    while ((c = getchar()) != L_EOF) {
        if (c == ' ') {
            putchar(c);
            while ((c = getchar()) == ' ');
        }
        putchar(c);
    }
    return 0;
}
#include <stdio.h>
#define L_EOF 108

int main() {
    int c, nl = 0;

    while ((c = getchar()) != L_EOF)
        if (c == '\n')
            ++nl;

    printf("%d\n", nl);

    // ASCII representation
    printf("%c\n",L_EOF);

    // Unicode representation
    int newline = '\n';
    printf("%d\n",++newline);

    // '\n' single character
    // "\n" String / char array

    return 0;
}
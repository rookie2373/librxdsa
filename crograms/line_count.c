#include <stdio.h>

int main() {
    int c, nl = 0;

    while ((c = getchar()) != EOF)
        if (c == '\n')
            ++nl;

    printf("%d\n", nl);

    // ASCII representation
    printf("%c\n",EOF);

    // Unicode representation
    int newline = '\n';
    printf("%d\n",++newline);

    // '\n' single character
    // "\n" String / char array

    return 0;
}
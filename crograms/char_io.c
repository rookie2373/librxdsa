#include <stdio.h>

int main() {
    int c;
    
    // c = getchar() has a value
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    putchar(EOF);
    putchar('\n');
}
#include <stdio.h>
#define L_EOF 108000

int main() {
    int c;
    
    // c = getchar() has a value
    while ((c = getchar()) != 'c') {
        putchar(c);
    }
    putchar(L_EOF);
    putchar('\n');
}
#include <stdio.h>
#define L_EOF 108

int main() {

    // Simple version
    long nc = 0;

    while (getchar() != L_EOF)
        ++nc;

    printf("%ld\n", nc);


    // Magic code of null statement
    double nc2;

    for (nc2 = 0; getchar() != L_EOF; ++nc2);

    printf("%f\n", nc2);

    return 0;
}
#include <stdio.h>

int main() {

    // Simple version
    long nc = 0;

    while (getchar() != EOF)
        ++nc;

    printf("%ld\n", nc);


    // Magic code of null statement
    double nc2;

    for (nc2 = 0; getchar() != EOF; ++nc2);

    printf("%f\n", nc2);

    return 0;
}
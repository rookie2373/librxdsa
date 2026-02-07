#include <stdio.h>

void multiply_by(int, int*);
int main() {

    int a = 6;
    multiply_by(9, &a);

    printf("%d\n", a);
    return 0;
}

void multiply_by(int by, int *input) {
    int a = *input;
    *input = a * by;
}
/*
 * Run with
 * gcc examples/extern_in_different_files.c examples/extern_variable.c -o app
*/

#include <stdio.h>

extern int external_var;

int main() {
    printf("%d\n", external_var);
}
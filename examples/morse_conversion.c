#include "librxdsa.h"

int main() {
    Morse m;
    init_morse(&m);

    char code[] = "01";
    int len = 2;

    printf("%c\n", morse_to_char(&m, code, len));
}
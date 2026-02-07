#include <stdio.h>
#define IN 1
#define OUT 0

int main() {
    int c, nc, nw, nl, state;
    nc = nw = nl = 0;
    state = OUT;

    while ((c = getchar()) != EOF) {
        ++nc;

        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
        }
        else if (state == OUT) {
            state = IN;
            nw++;
        }

        if (c == '\n') {
            nl++;
        }
    }

    printf("Chars: %d\n",nc);
    printf("Words: %d\n",nw);
    printf("Newlines: %d\n", nl);


    return 0;
}
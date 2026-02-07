#include <stdio.h>

#define ZERO_SLASH 0
#define ONE_SLASH 1
#define TWO_SLASH 2
#define STAR_OPEN 3
#define STAR_CLOSE 4

int main() {
    int state = ZERO_SLASH;
    char c;


    while ((c = getchar()) != EOF) {

        if (c == '/') {
            if (state == ONE_SLASH)
                state = TWO_SLASH;
            else
                state = ONE_SLASH;
        }

        if (c == '*') {
            if (state == ONE_SLASH)
                state = STAR_OPEN;
        }

        if (state == STAR_OPEN) {
            while ((c = getchar()) != '*') {}
            state = STAR_CLOSE;
            c = getchar();
        }

        if (state == TWO_SLASH) {
            while ((c = getchar()) != '\n') {}
            state = ZERO_SLASH;
        }

        if (state == ZERO_SLASH)
            putchar(c);

        if (state == STAR_CLOSE && c == '/')
            state = ZERO_SLASH;
    }
}
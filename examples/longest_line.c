#include <stdio.h>
#define MAXLINE 10000

void copy(char from[], char to[]) {
    int i = 0;

    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}

void rxreverse(char from[], char to[]) {
    int max = 0;
    while (from[max] != '\0')
        ++max;
    printf("%D\n", max);

    for (int i = 1; i <= max; i++) {
        to[max - i] = from[i - 1];
    }
    to[max] = '\0';
}

int rxgetline(char s[], int max_len) {
    int c, i;

    for (i = 0; i < max_len && (c=getchar()) != EOF && c != '\n'; i++)
        s[i] = c;
    
    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    int j = i - 1;
    if (s[j] == '\n')
        --j;

    while (s[j] == '\t' || s[j] == ' ')
        --j;

    ++j;
    s[j] = '\0';

    return j;
}

int main() {
    int len, max;
    max = 0;
    char line[MAXLINE];
    char longest[MAXLINE];

    while ((len = rxgetline(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(line, longest);
        }
    }

    longest[max] = '\0';

    printf("%s\n", longest);
    printf("%d\n", max);

    char reverse[MAXLINE];

    rxreverse(longest, reverse);

    printf("%s\n", reverse);
    return 0;
}
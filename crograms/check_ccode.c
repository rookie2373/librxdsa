#include <stdio.h>

/* States for Finite State Machine */
#define IN_CODE 0
#define IN_S_COMMENT 1   /* // ... */
#define IN_M_COMMENT 2   /*  ... */
#define IN_STRING 3      /* "..." */
#define IN_CHAR 4        /* '...' */
#define PRE_SLASH 5      /* Just saw a / */
#define PRE_STAR 6       /* Just saw a * inside a multi-line comment */

int main() {
    int c;
    int state = IN_CODE;
    int round, curly, square;
    round = curly = square = 0;

    while ((c = getchar()) != EOF) {
        if (state == IN_CODE) {
            if (c == '/') {
                state = PRE_SLASH;
            } else if (c == '\"') {
                state = IN_STRING;
                putchar(c);
            } else if (c == '\'') {
                state = IN_CHAR;
                putchar(c);
            } else {
                putchar(c);

                switch (c) {
                    case '(':
                        ++round;
                        break;
                    case ')':
                        --round;
                        break; 
                    case '{':
                        ++curly;
                        break;
                    case '}':
                        --curly;
                        break;
                    case '[':
                        ++square;
                        break;
                    case ']':
                        --square;
                        break;
                }
                
                if(round < 0 || square < 0 || curly < 0){
                            printf("Invalid brackets\n");
                            return 1;
                        }
            }
        } 
        else if (state == PRE_SLASH) {
            if (c == '/') {
                state = IN_S_COMMENT;
            } else if (c == '*') {
                state = IN_M_COMMENT;
            } else {
                /* It wasn't a comment! It's Math (Division). 
                   Print the slash we held back, then the current char. */
                putchar('/');
                putchar(c);
                state = IN_CODE;
            }
        } 
        else if (state == IN_S_COMMENT) {
            if (c == '\n') {
                putchar(c); /* Comments end at newline */
                state = IN_CODE;
            }
        } 
        else if (state == IN_M_COMMENT) {
            if (c == '*') state = PRE_STAR;
        } 
        else if (state == PRE_STAR) {
            if (c == '/') state = IN_CODE;
            else if (c != '*') state = IN_M_COMMENT;
            /* If it's another '*', stay in PRE_STAR */
        } 
        else if (state == IN_STRING) {
            putchar(c);
            if (c == '\\') putchar(getchar());
            else if (c == '\"') state = IN_CODE;
        } 
        else if (state == IN_CHAR) {
            putchar(c);/* Handle '\'' escape */
            if (c == '\\') putchar(getchar()); /* The 'Skip Next' logic */
            else if (c == '\'') state = IN_CODE;
        }
    }

    if (round != 0 || curly != 0 || square != 0) {
        printf("Invalid brackets\n");
        return 1;
    }
    return 0;
}

#ifndef MORSE_CODE_H
#define MORSE_CODE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char morse_tree[32];
} Morse;

void init_morse(Morse *m);
int morse_left(int idx);
int morse_right(int idx);
char morse_map(Morse *m, int idx);
char morse_to_char(Morse *m, char morse_code[], int morse_code_len);

#endif // MORSE_CODE_H
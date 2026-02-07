#include "morse_code.h"

void init_morse(Morse *m) {
    strcpy(m->morse_tree, "#ETIANMSURWDKGOHVF#L#PJBXCYZQ##");
}

int morse_left(int idx) {
    return 2 * idx + 1;
}

int morse_right(int idx) {
    return 2 * idx + 2;
}

char morse_map(Morse *m, int idx) {
    return m->morse_tree[idx];
}

char morse_to_char(Morse *m, char morse_code[], int morse_code_len) {
    int idx = 0;
    for (int i = 0; i < morse_code_len; i++) {
        if (morse_code[i] == '0')
            idx = morse_left(idx);
        else
            idx = morse_right(idx);
    }

    return morse_map(m, idx);
}
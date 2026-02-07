#include <stdio.h>
#include <string.h>

typedef struct {
    char morse_tree[32];
} Morse;

int left(int idx) {
    return 2 * idx + 1;
}

int right(int idx) {
    return 2 * idx + 2;
}

char map(Morse m, int idx) {
    return m.morse_tree[idx];
}

void init(Morse *m) {
    strcpy(m->morse_tree, "#ETIANMSURWDKGOHVF#L#PJBXCYZQ##");
}

int main() {

    char morseA[] = "01";
    size_t length = sizeof(morseA) / sizeof(morseA[0]) - 1;
    Morse my_morse;
    init(&my_morse);

    int idx = 0;

    for (int i = 0; i < length ; i++) {
        if(morseA[i] == '0'){
            idx = left(idx);
        }
        else {
            idx = right(idx);
        }
    }

    printf("%d\n", idx);

    printf("%c\n", map(my_morse, idx));

    return 0;
}

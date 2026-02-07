#include <stdio.h>

int powerplus(int base, int power);

int main() {

    int base = 3, power = 3;

    printf("%d %d %d\n", base, power, powerplus(base, power));
    return 0;
}

int powerplus(int base, int power) {
    int res = 1;

    while (power > 0) {
        if (power & 1) {
            res = res * base;
        }

        base = base * base;
        power >>= 1;
    }

    return res;
}
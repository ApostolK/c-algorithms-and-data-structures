#include <stdio.h>

int main() {
    int a = 5;  // egyik oldal
    int b = 7;  // másik oldal

    int terulet = a * b;
    int kerulet = 2 * (a + b);

    printf("A teglalap terulete: %d\n", terulet);
    printf("A teglalap kerulete: %d\n", kerulet);

    return 0;
}

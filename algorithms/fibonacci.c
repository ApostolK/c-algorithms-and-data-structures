#include <stdio.h>

// Kiirja a Fibonacci sorozatot a megadott hatarig
void fibonacci(int hatar) {
    int a = 0, b = 1, c = 0;

    printf("\033[1;34mFibonacci sorozat %d-ig:\033[0m\n", hatar);

    // Elso elem mindig 0
    printf("%d ", a);

    // Addig megyunk, amig a kovetkezo szam kisebb vagy egyenlo a hatarral
    while (b <= hatar) {
        printf("%d ", b);
        c = a + b;
        a = b;
        b = c;
    }
    printf("\n");
}

int main(void) {
    int hatar;

    printf("Add meg a hatar erteket: ");
    while (scanf("%d", &hatar) != 1 || hatar < 0) {
        printf("\033[1;31mHibas bemenet! Adj meg egy pozitiv egesz szamot:\033[0m ");
        while (getchar() != '\n'); // bemeneti puffer tisztitasa
    }

    fibonacci(hatar);
    return 0;
}

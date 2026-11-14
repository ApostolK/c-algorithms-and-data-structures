#include <stdio.h>
#include <math.h>

#define PI1 3.141593  // konstans definíció #define-nal
const double PI2 = 3.141593; // konstans változóval

int main() {
    double r;
    printf("Add meg a kor sugarat: ");
    scanf("%lf", &r);

    // a) saját konstanssal
    double kerulet1 = 2 * PI1 * r;
    double terulet1 = PI1 * r * r;
    printf("a) Saját PI-vel: kerulet=%.2f, terulet=%.2f\n", kerulet1, terulet1);

    // b) math.h M_PI konstanssal
    double kerulet2 = 2 * M_PI * r;
    double terulet2 = M_PI * r * r;
    printf("b) M_PI-vel: kerulet=%.2f, terulet=%.2f\n", kerulet2, terulet2);

    return 0;
}

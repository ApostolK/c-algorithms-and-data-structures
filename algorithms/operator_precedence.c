#include <stdio.h>

int main() {
    // a) Int típusú változó
    int int_result = 6 * 2 / 3 + 5 / 2 - 7 * 3 % 2;
    printf("Int eredmény: %d\n", int_result);
    

    // b) Float típusú változó
    float float_result = 6 * 2 / 3 + 5 / 2 - 7 * 3 % 2;
    printf("Float eredmény: %.2f\n", float_result);

    // c) Módosított kifejezés, hogy az osztás valódi számokkal történjen
    float modified_result = 6.0 * 2 / 3 + 5.0 / 2 - 7 * 3 % 2;
    printf("Módosított eredmény (valódi szám): %.2f\n", modified_result);

    // d) Precedencia sorrendje: szorzás, osztás, modulus először végrehajtódik,
    // majd az összeadás és kivonás.
    
    return 0;
}
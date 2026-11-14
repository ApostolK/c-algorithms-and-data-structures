#include <stdio.h>
#include <stdlib.h>

int cmp_desc(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;
    return y - x; // csökkenő rendezéshez
}

// Saját bináris keresés csökkenő sorrendhez
int binary_search_desc(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)   // mivel csökkenő
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

int main() {
    int points[] = { 400, 380, 350, 300, 200, 150, 120, 100, 80, 40 };
    int n = sizeof(points) / sizeof(points[0]);

    int max = points[0];
    int target = max / 2;

    printf("Legmagasabb pontszam: %d, fele: %d\n", max, target);

    // ---- Lineáris keresés ----
    int linear_index = -1;
    for (int i = 0; i < n; i++) {
        if (points[i] == target) {
            linear_index = i;
            break;
        }
    }

    printf("Linearis keresessel index: %d\n", linear_index);

    // ---- Bináris keresés (saját) ----
    int bin_index = binary_search_desc(points, n, target);
    printf("Binaris keresessel index: %d\n", bin_index);

    // ---- bsearch ----
    int *ptr = bsearch(&target, points, n, sizeof(int), cmp_desc);
    if (ptr)
        printf("bsearch() index: %td\n", (ptr - points));
    else
        printf("bsearch() nem talalta.\n");

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20

// Minimumkiválasztásos rendezés
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;

        int tmp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = tmp;
    }
}

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
    int grades[N];
    srand(time(NULL));

    // ---- Véletlen jegyek ----
    for (int i = 0; i < N; i++)
        grades[i] = rand() % 5 + 1;

    printf("Eredeti jegyek:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", grades[i]);
    printf("\n");

    // ---- Rendezes minimumkivalasztassal ----
    selection_sort(grades, N);

    printf("Rendezve (selection sort):\n");
    for (int i = 0; i < N; i++)
        printf("%d ", grades[i]);
    printf("\n");

    // ---- Atlag ----
    double sum = 0;
    for (int i = 0; i < N; i++)
        sum += grades[i];
    double avg = sum / N;

    printf("Atlag: %.2f\n", avg);

    // ---- Median ----
    double median = (grades[N/2 - 1] + grades[N/2]) / 2.0;
    printf("Median: %.2f\n", median);

    // ---- Modusz ----
    int mode = grades[0];
    int mode_count = 1;
    int current = grades[0];
    int current_count = 1;

    for (int i = 1; i < N; i++) {
        if (grades[i] == current)
            current_count++;
        else {
            if (current_count > mode_count) {
                mode = current;
                mode_count = current_count;
            }
            current = grades[i];
            current_count = 1;
        }
    }

    if (current_count > mode_count) {
        mode = current;
        mode_count = current_count;
    }

    printf("Modusz: %d (elofofordulas: %d)\n", mode, mode_count);

    // ---- qsort kipróbálása ----
    qsort(grades, N, sizeof(int), cmp);

    printf("Rendezve qsort()-tal:\n");
    for (int i = 0; i < N; i++)
        printf("%d ", grades[i]);
    printf("\n");

    return 0;
}

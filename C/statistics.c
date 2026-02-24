#include <stdio.h>
#include <stdlib.h>

int compare_ints(const void *a, const void *b) {
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    return (ia > ib) - (ia < ib);
}

double calculate_mean(const int arr[], int n) {
    long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return (double)sum / n;
}

double calculate_median(const int arr[], int n) {
    int *copy = (int *)malloc(n * sizeof(int));
    if (copy == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        copy[i] = arr[i];
    }

    qsort(copy, n, sizeof(int), compare_ints);

    double median;
    if (n % 2 == 1) {
        median = copy[n / 2];
    } else {
        median = (copy[(n / 2) - 1] + copy[n / 2]) / 2.0;
    }

    free(copy);
    return median;
}

void calculate_mode(const int arr[], int n) {
    int *copy = (int *)malloc(n * sizeof(int));
    if (copy == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        copy[i] = arr[i];
    }

    qsort(copy, n, sizeof(int), compare_ints);

    int max_count = 1;
    int current_count = 1;

    for (int i = 1; i < n; i++) {
        if (copy[i] == copy[i - 1]) {
            current_count++;
        } else {
            if (current_count > max_count) {
                max_count = current_count;
            }
            current_count = 1;
        }
    }
    if (current_count > max_count) {
        max_count = current_count;
    }

    if (max_count == 1) {
        printf("Mode: No mode (all values occur once)\n");
        free(copy);
        return;
    }

    printf("Mode(s): ");
    current_count = 1;
    int first_printed = 1;

    for (int i = 1; i <= n; i++) {
        if (i < n && copy[i] == copy[i - 1]) {
            current_count++;
        } else {
            if (current_count == max_count) {
                if (!first_printed) {
                    printf(", ");
                }
                printf("%d", copy[i - 1]);
                first_printed = 0;
            }
            current_count = 1;
        }
    }

    printf(" (frequency = %d)\n", max_count);
    free(copy);
}

void print_list(const int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main(void) {
    int values[] = {4, 1, 2, 2, 3, 4, 5, 4, 2, 6, 7, 2, 4};
    int n = sizeof(values) / sizeof(values[0]);

    printf("C (Procedural) Statistics Calculator\n");
    printf("Input values: ");
    print_list(values, n);
    printf("Mean: %.2f\n", calculate_mean(values, n));
    printf("Median: %.2f\n", calculate_median(values, n));
    calculate_mode(values, n);

    return 0;
}

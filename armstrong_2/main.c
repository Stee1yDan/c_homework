#include "array_utils.h"
#include "armstrong.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


int main() {
    int* arr;
    size_t size = 0;
    size_t capacity = 4;
    int n;

    arr = malloc(capacity * sizeof(int));

    if (!arr) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Ввод параметра n
    printf("Enter n: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input\n");
        free(arr);
    return 1;
    }

    printf("Enter numbers (Ctrl+D to finish):\n");
    while (scanf("%d", &arr[size]) == 1) {
        if (++size >= capacity) {
            capacity *= 2;
            int* temp = realloc(arr, capacity * sizeof(int));
            if (!temp) {
                fprintf(stderr, "Memory error\n");
                free(arr);
                return 1;
            }
            arr = temp;
        }
    }

    armstrong_transform(&arr, &size, n);

    print_array(arr, size);

    free(arr);
}

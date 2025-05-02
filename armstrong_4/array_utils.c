#include "array_utils.h"
#include "utils.h"
#include "armstrong.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

int* convert_string_to_int_array(const char* s, size_t* out_size) {
    int* arr = NULL;
    size_t count = 0;
    const char* p = s;

    while (*p) {
        while (*p && isspace((unsigned char)*p)) p++;
        if (!*p) break;

        char* end;
        long val = strtol(p, &end, 10);
        if (p == end) {
            p++;
            continue;
        }
        int* tmp = realloc(arr, (count + 1) * sizeof(int));
        if (!tmp) {
            free(arr);
            *out_size = 0;
            return NULL;
        }
        arr = tmp;
        arr[count++] = (int)val;
        p = end;
    }

    *out_size = count;
    return arr;
}

int add_element(int** arr, size_t* size, size_t index, int value) {
    if (index > *size) return -1;

    int* temp = realloc(*arr, (*size + 1) * sizeof(int));
    if (!temp) return -1;
    
    *arr = temp;
    
    if (index < *size) {
        memmove(*arr + index + 1, 
                *arr + index, 
                (*size - index) * sizeof(int));
    }
    
    (*arr)[index] = value;
    (*size)++;
    return 0;
}

int remove_element(int** arr, size_t* size, size_t index) {
    if (index >= *size) return -1;

    memmove(*arr + index, 
            *arr + index + 1, 
            (*size - index - 1) * sizeof(int));

    if (*size == 1) {
        return MEMORY_ERROR;
    }
    
    int* temp = realloc(*arr, (*size - 1) * sizeof(int));
    if (!temp && (*size > 1)) return MEMORY_ERROR;
    
    *arr = temp;
    (*size)--;
    return SUCCESS;
}

void print_array(const int* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



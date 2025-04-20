#include "array_utils.h"
#include "armstrong.h"
#include "utils.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>

int add_element(int** arr, size_t* size, size_t index, int value) {
    if (index > *size) return -1;

    int* temp = realloc(*arr, (*size + 1) * sizeof(int));
    if (!temp) return MEMORY_ERROR;
    
    *arr = temp;
    
    if (index < *size) {
        memmove(*arr + index + 1, 
                *arr + index, 
                (*size - index) * sizeof(int));
    }
    
    (*arr)[index] = value;
    (*size)++;
    return SUCCESS;
}

int remove_element(int** arr, size_t* size, size_t index) {
    if (index >= *size) return -1;

    memmove(*arr + index, 
            *arr + index + 1, 
            (*size - index - 1) * sizeof(int));

    int* temp = realloc(*arr, (*size - 1) * sizeof(int));
    if (!temp && (*size > 1)) return MEMORY_ERROR;
    
    *arr = temp;
    (*size)--;
    return SUCCESS;
}


// !!! Note: Для большей читаемости кода, realloc был вынесен в спомогательные фукнции remove_element и add_element. !!!
TransformationStatus armstrong_transform(int** arr, size_t* size, int n) {

    for (size_t i = 0; i < *size; i++) {
        int num = (*arr)[i];

        if (get_digits_sum(num) <= n) {
            TransformationStatus rm_status 
                = remove_element(arr, size, i);

            if (rm_status == MEMORY_ERROR) {
                return MEMORY_ERROR;
            }

            i--;
            continue;
        }

        int sum;

        if (is_armstrong(num, &sum) == ARMSTRONG) {
            TransformationStatus add_status 
                = add_element(arr,size,i,num);

            if (add_status == MEMORY_ERROR) {
                return MEMORY_ERROR;
            }

            i++;
            continue;
        }
    }

    return SUCCESS;
}

void print_array(const int* arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

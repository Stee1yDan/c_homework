#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <stddef.h>

typedef enum {
    SUCCESS = 0,
    MEMORY_ERROR = -1
} TransformationStatus;

int add_element(int** arr, size_t* size, size_t index, int value);
int remove_element(int** arr, size_t* size, size_t index);
void print_array(const int* arr, size_t size);
TransformationStatus armstrong_transform(int** arr, size_t* size, int n);

#endif

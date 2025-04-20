#ifndef ARRAY_UTILS_H
#define ARRAY_UTILS_H

#include <stddef.h>

typedef enum {
    SUCCESS = 0,
    MEMORY_ERROR = -1
} TransformationStatus;

int get_digits_sum(int num);
int add_element(int** arr, size_t* size, size_t index, int value);
int remove_element(int** arr, size_t* size, size_t index);
int* convert_string_to_int_array(const char* s, size_t* out_size);
void print_array(const int* arr, size_t size);
void clean_buffer();
TransformationStatus armstrong_transform(int** arr, size_t* size, int n);

#endif

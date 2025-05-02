#ifndef ARMSTRONG_H
#define ARMSTRONG_H

#include <stddef.h>
#include "array_utils.h"
#include "linked_list_utils.h"

typedef enum {
    SUCCESS = 0,
    MEMORY_ERROR = -1
} TransformationStatus;

typedef enum {
    ARMSTRONG = 1,
    NOT_ARMSTRONG = 0,
    ERROR = -1
} Status;

Status is_armstrong(int number, int* sum);
TransformationStatus armstrong_transform(int** arr, size_t* size, int n);
TransformationStatus list_armstrong_transform(List** list, int n);

#endif

#ifndef ARMSTRONG_H
#define ARMSTRONG_H

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

#endif

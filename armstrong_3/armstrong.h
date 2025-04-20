#ifndef ARMSTRONG_H
#define ARMSTRONG_H

typedef enum {
    ARMSTRONG = 1,
    NOT_ARMSTRONG = 0,
    ERROR = -1
} Status;

Status is_armstrong(int number, int* sum);

#endif

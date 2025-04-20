#include <math.h>
#include <stddef.h>
#include "armstrong.h"

Status is_armstrong(int number, int* sum) {
    if (number <= 0 || sum == NULL) {
        return ERROR;
    }

    int count = 0;
    int temp = number;
    while (temp != 0) {
        temp /= 10;
        count++;
    }

    temp = number;
    int total = 0;
    while (temp != 0) {
        int digit = temp % 10;
        total += pow(digit, count);
        temp /= 10;
    }

    *sum = total;

    return (total == number) ? ARMSTRONG : NOT_ARMSTRONG;
}

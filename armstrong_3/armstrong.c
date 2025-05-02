#include <math.h>
#include <stddef.h>
#include "armstrong.h"
#include "array_utils.h"

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


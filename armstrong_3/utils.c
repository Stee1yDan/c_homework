#include "utils.h"
#include <stdio.h>
#include <stdlib.h>

int get_digits_sum(int num) {
    num = abs(num);
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

void clean_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

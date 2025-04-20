#include <stdio.h>
#include "armstrong.h"

int main() {
    int number;
    printf("Enter a number: ");
    if (scanf("%d", &number) != 1) {
        printf("Input error.\n");
        return 1;
    }

    int sum;
    Status status = is_armstrong(number, &sum);

    switch (status) {
        case ARMSTRONG:
            printf("The number is an Armstrong number.\nSum: %d\n", sum);
            break;
        case NOT_ARMSTRONG:
            printf("The number is not an Armstrong number.\nSum: %d\n", sum);
            break;
        case ERROR:
            printf("Error: The number must be a positive integer.\n");
            break;
        default:
            printf("Unknown status.\n");
            break;
    }

    return 0;
}

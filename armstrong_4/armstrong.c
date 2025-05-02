#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include "armstrong.h"
#include "array_utils.h"
#include "linked_list_utils.h"

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

        if (get_digits_sum(num) < n) {
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

TransformationStatus list_armstrong_transform(List** plist, int n) {
    if (!plist || !*plist) return MEMORY_ERROR;
    List* list = *plist;
    Node* prev = NULL;
    Node* curr = list->head;

    while (curr) {
        int num = curr->data;

        if (get_digits_sum(num) <= n) {
            Node* to_delete = curr;
            if (!prev) {
                list->head = curr->next;
                curr = list->head;
            } else {
                prev->next = curr->next;
                curr = prev->next;
            }
            free(to_delete);
            list->size--;
            continue;
        }

        int arm_sum;
        if (is_armstrong(num, &arm_sum) == ARMSTRONG) {
            Node* new_node = malloc(sizeof(Node));
            if (!new_node) return MEMORY_ERROR;
            new_node->data = num;
            new_node->next = curr->next;
            curr->next = new_node;
            curr = new_node->next;
            list->size++;
            prev = new_node;  
            continue;
        }

        prev = curr;
        curr = curr->next;
    }

    return SUCCESS;
}

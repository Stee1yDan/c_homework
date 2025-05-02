#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "linked_list_utils.h"

List* list_create() {
    List* list = malloc(sizeof(List));
    if (!list) return NULL;
    list->head = NULL;
    list->size = 0;
    return list;
}

void list_destroy(List* list) {
    if (!list) return;
    Node* current = list->head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(list);
}

List* convert_string_to_int_list(const char* s) {
    if (!s) return NULL;
    List* list = list_create();
    if (!list) return NULL;
    const char* p = s;

    while (*p) {
        while (*p && isspace((unsigned char)*p)) p++;
        if (!*p) break;

        char* end;
        long val = strtol(p, &end, 10);
        if (p == end) {
            p++;
            continue;
        }

        if (list_insert(list, list->size, (int)val) != 0) {
            list_destroy(list);
            return NULL;
        }
        p = end;
    }

    return list;
}


int list_insert(List* list, int pos, int data) {
    if (!list || pos < 0 || pos > list->size) return -1;
    Node* new_node = malloc(sizeof(Node));
    if (!new_node) return -1;
    new_node->data = data;
    if (pos == 0) {
        new_node->next = list->head;
        list->head = new_node;
    } else {
        Node* prev = list->head;
        for (int i = 0; i < pos - 1; i++) {
            prev = prev->next;
        }
        new_node->next = prev->next;
        prev->next = new_node;
    }
    list->size++;
    return 0;
}

int list_remove(List* list, int pos, int* data_out) {
    if (!list || pos < 0 || pos >= list->size) return -1;
    Node* to_remove;
    if (pos == 0) {
        to_remove = list->head;
        list->head = to_remove->next;
    } else {
        Node* prev = list->head;
        for (int i = 0; i < pos - 1; i++) {
            prev = prev->next;
        }
        to_remove = prev->next;
        prev->next = to_remove->next;
    }
    if (data_out) *data_out = to_remove->data;
    free(to_remove);
    list->size--;
    return 0;
}

void list_print(const List* list) {
    if (!list) return;
    Node* current = list->head;
    printf("[");
    while (current) {
        printf("%d", current->data);
        if (current->next) printf(", ");
        current = current->next;
    }
    printf("]\n");
}

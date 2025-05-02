#ifndef LINKED_LIST_UTILS_H
#define LINKED_LIST_UTILS_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct List {
    Node* head;
    int size;
} List;

List* list_create();
List* convert_string_to_int_list(const char* s);
int list_insert(List* list, int pos, int data);
int list_remove(List* list, int pos, int* data_out);
void list_print(const List* list);
void list_destroy(List* list);

#endif
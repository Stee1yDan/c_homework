#include "linked_list_utils.h"
#include "input_processor.h"
#include "armstrong.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


int main() {
    int n;

    printf("Enter n: ");
    if (scanf("%d", &n) != 1) {
        fprintf(stderr, "Invalid input\n");
    return 1;
    }

    clean_buffer();

    printf("Enter line: ");
    char* line = read_line();  
    if (!line){
        return 1;
    } 
    char* filtered_line = filter_numbers_str(line);

    List* list = convert_string_to_int_list(filtered_line);
    list_armstrong_transform(&list, n);

    list_print(list);

    list_destroy(list);
    free(filtered_line);
    free(line);
}

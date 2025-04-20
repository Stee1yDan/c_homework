#include "array_utils.h"
#include "input_processor.h"
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

    size_t size;
    int* arr = convert_string_to_int_array(filtered_line, &size);

    armstrong_transform(&arr, &size, n);

    print_array(arr, size);
}

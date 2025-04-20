#include "input_processor.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TOKEN_SIZE 64

char* read_line(void) {
    char buffer[TOKEN_SIZE];
    char* result = NULL;
    size_t total_len = 0;

    while (fgets(buffer, sizeof(buffer), stdin)) {
        size_t chunk_len = strlen(buffer);
        char* temp = realloc(result, total_len + chunk_len + 1); 
        if (!temp) {
            free(result);
            return NULL;
        }
        result = temp;
        memcpy(result + total_len, buffer, chunk_len);
        total_len += chunk_len;
        result[total_len] = '\0';

        if (buffer[chunk_len - 1] == '\n') {
            result[total_len - 1] = '\0';
            break;
        }
    }

    return result;
}

char* filter_numbers_str(const char* s) {
    size_t len = strlen(s);
    char* out = malloc(len + 1);
    if (!out) return NULL;

    size_t w = 0;
    const char* p = s;

    while (*p) {
        while (*p && isspace((unsigned char)*p)) p++;
        if (!*p) break;

        const char* start = p;
        while (*p && !isspace((unsigned char)*p)) p++;
        const char* end = p;

        int all_digits = 1;
        for (const char* q = start; q < end; ++q) {
            if (!isdigit((unsigned char)*q)) {
                all_digits = 0;
                break;
            }
        }

        if (all_digits) {
            if (w > 0) {
                out[w++] = ' ';
            }
            memcpy(out + w, start, end - start);
            w += end - start;
        }
    }

    out[w] = '\0';
    return out;
}

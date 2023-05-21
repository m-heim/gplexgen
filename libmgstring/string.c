#include "string.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct string *make_string() {
    return (struct string *) malloc(LIBMGSTRING_H_BUFFER_SIZE);
}

void string_clear(struct string *str) {
    memset(str->ptr, 0, str->buffer_size);
}

void string_set(struct string *str, const char *src) {
    size_t len = strlen(src);
}

void string_append(struct string *str, struct string *suffix) {
    if (str->len + suffix->len > str->buffer_size) {
        _string_multiply_buffer(str);
    }
    strcpy(suffix->ptr, str->ptr + str->len);
}

const char *string_get_cstr(struct string *str) {
    return (const char *) str->ptr;
}

int32_t string_get_index(struct string *str, const char *substring) {
    const char *cstr = string_get_cstr(str);
    uint32_t index = 0;
    uint32_t matched_chars = 0;
    uint32_t substr_len = strlen(substring);
    char c;
    while (*(cstr + index) != '\0') {
        if (matched_chars == substr_len) {
            return index - substr_len;
        } else if (c == *(substring + matched_chars)) {
            matched_chars++;
        } else {
            matched_chars = 0;
        }
    }
    return -1;
}

void _string_multiply_buffer(struct string *str) {
    uint32_t new_size = floor(((double) str->buffer_size) * 1.5);
    str->buffer_size = new_size;
    return;
}
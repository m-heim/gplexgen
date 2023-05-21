#ifndef __LIBMGSTRING_H__
#define __LIBMGSTRING_H__

#define LIBMGSTRING_H_BUFFER_SIZE 35

#include <stdint.h>

struct string {
    char *ptr;
    uint32_t len;
    uint32_t buffer_size;
};
void _string_multiply_buffer(struct string *str);
void string_append(struct string *str, struct string *suffix);
void string_clear(struct string *str);
struct string *make_string();
const char *string_get_cstr(struct string *str);

#endif
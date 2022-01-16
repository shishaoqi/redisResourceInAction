#include <stdio.h>
#include <stdint.h>

struct __attribute__ ((__packed__)) sdshdr5 {
    unsigned char flags; /* 3 lsb of type, and 5 msb of string length */
    char buf[];
} sdshdr5;

struct __attribute__ ((__packed__)) sdshdr8 {
    uint8_t len; /* used */
    uint8_t alloc; /* excluding the header and null terminator */
    unsigned char flags; /* 3 lsb of type, 5 unused bits */
    char buf[];
} sdshdr8;

struct __attribute__ ((__packed__)) sdshdr16 {
    uint16_t len; /* used */
    uint16_t alloc; /* excluding the header and null terminator */
    unsigned char flags; /* 3 lsb of type, 5 unused bits */
    char buf[];
} sdshdr16;

struct __attribute__ ((__packed__)) sdshdr32 {
    uint32_t len; /* used */
    uint32_t alloc; /* excluding the header and null terminator */
    unsigned char flags; /* 3 lsb of type, 5 unused bits */
    char buf[];
} sdshdr32;
struct __attribute__ ((__packed__)) sdshdr64 {
    uint64_t len; /* used */
    uint64_t alloc; /* excluding the header and null terminator */
    unsigned char flags; /* 3 lsb of type, 5 unused bits */
    char buf[];
} sdshdr64;

int main() {
    size_t n = sizeof(sdshdr5);
    printf("sdshdr5 size of %zu\n", n);

    n = sizeof(sdshdr8);
    printf("sdshdr8 size of %zu\n", n);

    n = sizeof(sdshdr16);
    printf("sdshdr16 size of %zu\n", n);

    n = sizeof(sdshdr32);
    printf("sdshdr32 size of %zu\n", n);

    n = sizeof(sdshdr64);
    printf("sdshdr64 size of %zu\n", n);
}
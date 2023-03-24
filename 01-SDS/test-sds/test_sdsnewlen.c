// 验证 SDS_HDR_VAR() 宏生成了一个局部新变量 sh 与 sdsnewlen 函数开头并不是同一个

#include <stdio.h>
#include <string.h>
#include "sds.h"
#include "sdsalloc.h"

sds sdsnewlen_testSh(const void *init, size_t initlen);
static inline int sdsHdrSize(char type);
static inline size_t sdsTypeMaxSize(char type);

int main() {
    sds s;
    char *init = "hello";

    s = sdsnewlen_testSh(init, strlen(init));
    printf("s = %s\n", s);
}

sds sdsnewlen_testSh(const void *init, size_t initlen) {
    void *sheader; // 原名称为 sh
    int idx = 1;
    sds s;
    char type = 1;
    /* Empty strings are usually created in order to append. Use type 8
     * since type 5 is not good at this. */
    if (type == SDS_TYPE_5 && initlen == 0) type = SDS_TYPE_8;
    int hdrlen = sdsHdrSize(type);
    unsigned char *fp; /* flags pointer. */
    size_t usable;

    sheader = s_malloc_usable(hdrlen+initlen+1, &usable); // +1 表示加上 null terminator（\0）
    if (sheader == NULL) return NULL;
    if (init==SDS_NOINIT)
        init = NULL;
    else if (!init)
        memset(sheader, 0, hdrlen+initlen+1);
    s = (char*)sheader+hdrlen;
    fp = ((unsigned char*)s)-1;
    usable = usable-hdrlen-1;
    if (usable > sdsTypeMaxSize(type))
        usable = sdsTypeMaxSize(type);
    
    switch(type) {
        case SDS_TYPE_8: {
            printf("void *sh: %p\n", sheader);
            printf("idx=:%d\n", idx);
            int idx = 2;
            SDS_HDR_VAR(8,s); // 宏：sds header指针变量
            printf("struct sdshdr8 *sh: %p\n", sh);
            printf("in switch.caxe idx=:%d\n", idx);
            sh->len = initlen;
            sh->alloc = usable;
            *fp = type;
            break;
        }
    }

    if (initlen && init)
        memcpy(s, init, initlen);
    s[initlen] = '\0';
    return s;
}

static inline int sdsHdrSize(char type) {
    switch(type&SDS_TYPE_MASK) {
        case SDS_TYPE_5:
            return sizeof(struct sdshdr5);
        case SDS_TYPE_8:
            return sizeof(struct sdshdr8);
        case SDS_TYPE_16:
            return sizeof(struct sdshdr16);
        case SDS_TYPE_32:
            return sizeof(struct sdshdr32);
        case SDS_TYPE_64:
            return sizeof(struct sdshdr64);
    }
    return 0;
}

static inline size_t sdsTypeMaxSize(char type) {
    if (type == SDS_TYPE_5)
        return (1<<5) - 1;
    if (type == SDS_TYPE_8)
        return (1<<8) - 1;
    if (type == SDS_TYPE_16)
        return (1<<16) - 1;
#if (LONG_MAX == LLONG_MAX)
    if (type == SDS_TYPE_32)
        return (1ll<<32) - 1;
#endif
    return -1; /* this is equivalent to the max SDS_TYPE_64 or SDS_TYPE_32 */
}
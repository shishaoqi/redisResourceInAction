#include <stdio.h>
#include "sds.h"

int main() {
    sds s;
    s = sdsnew(NULL); // == sdsnewlen(NULL, 0), the buffer is initialized with zero bytes.
    s = sdsnew(SDS_NOINIT); // If SDS_NOINIT is used, the buffer is left uninitialized   // 注意 sdsnew(SDS_NOINIT) ！= sdsnewlen(SDS_NOINIT, 0)
    s = sdsempty(); // 追踪源码总结： sdsnew(SDS_NOINIT) 与 sdsempty() 很相似：--》1.the buffer is left uninitialized
   
    // 但很不辛，没有这样调用 sdsnew(SDS_NOINIT), 只下面这种
    //len = strtol(buf+1,NULL,10);
    /* Read it into a string object. */
    //argsds = sdsnewlen(SDS_NOINIT,len);
    s = sdsnewlen(SDS_NOINIT, 30);

    sdsfree(s);
    return 0;
}
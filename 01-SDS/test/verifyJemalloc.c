#include <stdio.h>
#include "zmalloc.h"

// 查询当前使用的是哪个内存分配器
int main() {
    void *p = malloc(10241024);
    sleep(1000);
    free(p);

    return 0;
}
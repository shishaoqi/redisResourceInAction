#include <stdio.h>
#include "zmalloc.h"
#include <jemalloc/jemalloc.h>

int main(void)
{
    int *j = 0;
    void *ptr = malloc(sizeof(j));

    int err = jemk_mallctl("renas.lookup", &j, &ptr, NULL, 0);
    printf("return %d", err);
}

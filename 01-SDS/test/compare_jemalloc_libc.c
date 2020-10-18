#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
// #include "zmalloc.h" 当开启这个时，请把替换如下的 malloc --> zmalloc  free --> zfree

#define MSECOND 1000000

int main(void)
{
    int i = 0;
    char pad = 0;
    char *ptr = NULL;
    size_t size = 128;
    float timeuse = 0;
    struct timeval  tpstart;
    struct timeval tpend;
    int loops = 100000000;

    srand((int)time(0));

    gettimeofday(&tpstart, NULL);
    for (i = 0; i < loops; i++) {
        size = rand() & 0x0000000000000fff;
        ptr = malloc(size);// zmalloc
        pad = rand() & 0xff;
        memset(ptr, pad, size);
        free(ptr); // zfree
    }

    gettimeofday(&tpend, NULL);

    timeuse = MSECOND*(tpend.tv_sec-tpstart.tv_sec)+tpend.tv_usec-tpstart.tv_usec;
    timeuse /= MSECOND;
    printf("Used Time [%f] with [%d] loops\n", timeuse, loops);

    return 0;
}


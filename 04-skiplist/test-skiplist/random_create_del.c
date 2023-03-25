#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"zmalloc.h"
#include"skiplist.h"

#ifndef RAND_MAX
#  define RAND_MAX ((int) ((unsigned) ~0 >> 1))
#endif

int main() {
    zskiplist* sl;
    char characters[] = "abcdefghijklmgopqrstuvwxyz";
    zskiplistNode* node;

    srand((int)time(NULL));
    sl = zslCreate();

    int n;
    for (n = 0; n < 20; n++) {
        int i = 0;
        int sum = 0;
        sds newStr = sdsempty();
        while(i < 5) {
            if(i == 0) {
                //newStr = sdsempty();
            }   
            int r = RandomInteger(0, 20);
            sum += r;
            char c = characters[r];
            sdscatlen(newStr, &c, 1);
            i++;
        }
        printf("newStr = %s\n", newStr);

        zslInsert(sl, sum, newStr);
    }

    sds s = sdsnew("aaaaa");
    sds e = sdsnew("zzzzz");
    zlexrangespec firstRange = { .min = s, .max = e, .minex = 0, .maxex = 0 };
    zlexrangespec lastRange = { .min = s, .max = e, .minex = 0, .maxex = 0 };
    node = zslFirstInLexRange(sl, &firstRange);
    printf("first element: %s, score: %f\n", node->ele, node->score);
    node = zslLastInLexRange(sl, &lastRange);
    printf("last node -- element: %s, score: %.2f\n", node->ele, node->score);

    zlexrangespec range  = { .min = s, .max = e, .minex = 0, .maxex = 0 };
    while(node != NULL) {
        printf("element: %s, score: %f\n", node->ele, node->score);

        zslDelete(sl, node->score, node->ele, NULL);
        node = zslFirstInLexRange(sl, &range);
    }

    zslFree(sl);

    return 0;
}

int RandomInteger(int low, int high)
{
    int k;
    double d;

    d = (double) rand() / ((double) RAND_MAX + 1);
    k = (int) (d * (high - low +1));
    return (low + k);
}

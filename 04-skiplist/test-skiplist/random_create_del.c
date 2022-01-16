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


    zrangespec* firstRange;
    zrangespec* lastRange;
    //firstRange = zmalloc(sizeof(*zlexrangespec));
    zslFirstInRange(sl, firstRange);
    zslLastInRange(sl, lastRange);

    //range = 
    // range->min = sdsNew("aaaaa");
    // range->max = sdsNew("zzzzz");
    // range->minex = -1;
    // range->maxex = 999;
    // zskiplistNode* node = zslFirstInLexRange(sl, &range);

    // while(node != NULL) {
    //     zslDelete(sl, node->score, node->ele, NULL);
    //     node = zslFirstInLexRange(sl, range);
    // }
}

int RandomInteger(int low, int high)
{
    int k;
    double d;

    d = (double) rand() / ((double) RAND_MAX + 1);
    k = (int) (d * (high - low +1));
    return (low + k);
}

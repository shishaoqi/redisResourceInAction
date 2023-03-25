#include<stdio.h>
#include"skiplist.h"

int main() {
    zskiplist *sl;
    zskiplistNode *sln;
    zskiplistNode **dsln;
    sds s, s_temp, spe;
    
    s = sdsnew("aaa");
    sl = zslCreate();
    sln = zslInsert(sl, 25, s);

    spe = sdsdup(s);
    sln = zslInsert(sl, 55, spe);
    sln = zslInsert(sl, 95, NULL);

    s_temp = sdsdup(s);
    sln = zslInsert(sl, 15, s_temp);

    s_temp = sdsdup(s);
    sln = zslInsert(sl, 35, s_temp);

    s_temp = sdsnew("good");
    sln = zslInsert(sl, 50, s_temp);

    zrangespec range = { .min = 0, .max = 90, .minex = 0, .maxex = 0 };
    sln = zslFirstInRange(sl, &range);
    while(sln != NULL) {
        printf("element: %s, score: %.2f\n", sln->ele, sln->score);

        zslDelete(sl, sln->score, sln->ele, NULL);
        sln = zslFirstInRange(sl, &range);
    }

    zslFree(sl);
}
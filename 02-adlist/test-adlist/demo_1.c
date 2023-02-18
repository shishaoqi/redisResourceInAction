#include <stdio.h>
#include "adlist.h"
#include "zmalloc.h"

typedef int intT;

int main() {
    list *myList;
    listIter *iter;
    listNode *node;
    myList = listCreate();

    int i;
    intT *num;
    for(i = 0; i < 10; i++) {
        num = zcalloc(sizeof(intT));
        *num = i;
        myList = listAddNodeTail(myList, num);
    }

    int a = 88;
    int b = 99;
    myList = listAddNodeTail(myList, &a);
    myList = listAddNodeTail(myList, &b);

    iter = listGetIterator(myList, AL_START_HEAD);
    while((node = listNext(iter)) != NULL) {
        printf("integer value = %d \n", *(int*)listNodeValue(node));
    }

    listRelease(myList);
}
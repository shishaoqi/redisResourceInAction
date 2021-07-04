#include <stdio.h>
#include <string.h>
#include "sds.h"
#include "dict.h"

uint64_t dictSdsHash(const void *key) {
    return dictGenHashFunction((unsigned char*)key, sdslen((char*)key));
}

int dictSdsKeyCompare(void *privdata, const void *key1,
        const void *key2)
{
    int l1,l2;
    DICT_NOTUSED(privdata);

    l1 = sdslen((sds)key1);
    l2 = sdslen((sds)key2);
    if (l1 != l2) return 0;
    return memcmp(key1, key2, l1) == 0;
}

void dictSdsDestructor(void *privdata, void *val)
{
    DICT_NOTUSED(privdata);

    sdsfree(val);
}

/* Hash type hash table (note that small hashes are represented with ziplists) */
dictType hashDictType = {
    dictSdsHash,                /* hash function */
    NULL,                       /* key dup */
    NULL,                       /* val dup */
    dictSdsKeyCompare,          /* key compare */
    dictSdsDestructor,          /* key destructor */
    dictSdsDestructor,          /* val destructor */
    NULL                        /* allow to expand */
};

int main() {
    dict *d;
    d = dictCreate(&hashDictType, NULL);

    char *str1 = "key1";
    int val1 = 1;
    dictAdd(d, str1, &val1);

    char *str2 = "key2";
    int val2 = 2;
    dictAdd(d, str2, &val2);

    dictIterator *iter;
    dictEntry *entry;
    iter = dictGetIterator(d);
    while((entry = dictNext(iter)) != NULL) {
        printf("integer value = %d \n", *(int*)dictGetVal(entry));
    }

    dictRelease(d);
}
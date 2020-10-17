/* 
* @Author: shishao
* @Date:   2018-10-29 13:17:03
* @Last Modified by:   shishao
* @Last Modified time: 2018-10-31 21:03:32
* @Description: sdsnewlen  sdslen  sdsMakeRoomFor  sdsavail  sdscatsds  sdscat
*/

#include <stdio.h>
#include <string.h>
#include "sds.h"

int main() {
    char *strp = "hello";
    sds moreMemry;

    moreMemry = sdsnewlen(strp, strlen(strp) + 10);
    printf("%s\n", moreMemry);

    size_t length = sdslen(moreMemry);
    printf("String length is %d\n", length);

    //sdsavail
    length = sdsavail(moreMemry);
    printf("String avail length is %d\n", length);

    //sdsMakeRoomFor
    sds newMoreMemry = sdsMakeRoomFor(moreMemry, 100);
    printf("%s\n", newMoreMemry);

    //sdscatsds
    char *cat_str = "catHello";
    sds second_sds = sdsnew(cat_str);
    second_sds = sdscatsds(second_sds, second_sds);
    printf("sdscatsds function result: %s\n", second_sds);

    //sdsavail
    length = sdsavail(newMoreMemry);
    printf("New string avail length is %d\n", length);

    //sdscat
    sds moreMemry_sec = sdsnewlen(strp, strlen(strp));
    char *catStrp = " world";
    moreMemry_sec = sdscat(moreMemry_sec, catStrp);
    printf("New string is: %s\n", moreMemry_sec);

    return 0;
}
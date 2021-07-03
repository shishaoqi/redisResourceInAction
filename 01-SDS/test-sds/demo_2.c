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

    moreMemry = sdsnewlen(strp, strlen(strp));
    printf("%s\n", moreMemry);

    size_t length = sdslen(moreMemry);
    printf("String length is %lu\n", length);

    //sdsavail
    length = sdsavail(moreMemry);
    printf("String avail length is %lu\n", length);

    char *addStr = "abcedf";
    moreMemry = sdscat(moreMemry, addStr);
    printf("New moreMemry string is: %s\n\n\n", moreMemry);


  

    //sdscatsds
    sds cat_str = sdsnew("NewCatHello");
    sds second_sds = sdsnew("abgd");
    second_sds = sdscatsds(second_sds, cat_str);
    printf("sdscatsds function result: %s\n", second_sds);

    //sdsMakeRoomFor
    sds newMoreMemry = sdsMakeRoomFor(moreMemry, 100);
    printf("%s\n", newMoreMemry);
    
    //sdsavail
    length = sdsavail(newMoreMemry);
    printf("New string avail length is %lu\n", length);

    //sdscat
    sds moreMemry_sec = sdsnewlen(strp, strlen(strp));
    char *catStrp = " world";
    moreMemry_sec = sdscat(moreMemry_sec, catStrp);
    printf("New string is: %s\n", moreMemry_sec);

    return 0;
}
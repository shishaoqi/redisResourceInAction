/*
* @Author: shishao
* @Date:   2018-10-28 23:08:37
* @Last Modified by:   shishao
* @Last Modified time: 2018-11-04 22:47:44
* @Describtion: sdsnew sdslen  sdsnewlen functions test.
*/

#include <stdio.h>
#include <string.h>
#include "sds.h"

int main() {
    char *str = "hello";
    sds sdsStr;

    sdsStr = sdsnew(str);
    printf("sdsStr content: %s\n", sdsStr);

    size_t length = sdslen(sdsStr);
    printf("sdsStr length: %d\n", length);

    sds secondStr = "keep doing";
    sdsStr = sdsnewlen(secondStr, strlen(secondStr));
    printf("new sdsStr content: %s\n", secondStr);

    length = sdslen(sdsStr);
    printf("new sdsStr length: %d\n", length);

    //create empty string
    sds emptyStr = sdsempty();
    printf("This is empty string: %s\n", emptyStr);

    //dumplicate a string
    sds dupStr = sdsdup(sdsStr);
    printf("dumplicate of sdsStr: %s\n", dupStr);

    return 0;
}
/*
* @Author: shishao
* @Date:   2018-10-28 23:08:37
* @Last Modified by:   shishao
* @Last Modified time: 2019-05-14 23:51:47
* @Describtion: sdsnew sdslen  sdsnewlen functions test.
*/

#include <stdio.h>
#include <string.h>
#include "sds.h"

int main() {
    char *str = "hello";
    sds sdsStr;

    // 创建一个包含给定C字符串的SDS
    sdsStr = sdsnew(str);
    printf("sdsStr content: %s\n", sdsStr);

    // 返回SDS的已使用空间字节数
    size_t length = sdslen(sdsStr);
    printf("sdsStr length: %d\n", length);

    sds secondStr = "keep doing";
    // 根据给定的初始化字符串 init 和字符串长度 initlen，创建一个新的 sds
    sdsStr = sdsnewlen(secondStr, strlen(secondStr));
    printf("new sdsStr content: %s\n", sdsStr);

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
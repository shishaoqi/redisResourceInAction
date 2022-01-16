#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <poll.h>
#include <string.h>
#include <time.h>
#include <errno.h>
#include "ae.h"
 
void loop_init(aeEventLoop *lp)
{
    printf("loop init!\n");
}
 
void file_cb(aeEventLoop *lp, int fd, void *date, int mask)
{
    char buf[1024] = {'\0'};
    int len = read(fd, buf, sizeof(buf) - 1);
    printf("fd = %d, data = %s\n", fd, buf);
}
 
int time_cb(aeEventLoop *lp, long long id, void *data)
{
    static int num = 0;
    printf("now is %ld\n", time(NULL));
    if (++num == 50) {
        return AE_NOMORE;
    }
    return 5 * 1000;
}
 
void fin_cb(aeEventLoop *lp, void *data)
{
    printf("fin_cb run!\n");
}
 
int main(int argc, char *argv[])
{
    aeEventLoop *lp = NULL;
 
    lp = aeCreateEventLoop(1024);
    aeSetBeforeSleepProc(lp, loop_init);
 
    int res;
    res = aeCreateFileEvent(lp, STDIN_FILENO, AE_READABLE, file_cb, NULL); // STDIN_FILENO 是标准输入的文件描述符
    if (res) {
        printf("aeCreateFileEvent error! res = %d\n", res);
    }
 
    res = aeCreateTimeEvent(lp, 5*1000, time_cb, NULL, fin_cb);
    if (res) {
        printf("aeCreateTimeEvent error! res = %d\n", res);
    }
 
    aeMain(lp);
 
    return 0;
}
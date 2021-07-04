#include <stdio.h>
#include "dict.h"

/* _serverAssert is needed by dict */
void _serverAssert(const char *estr, const char *file, int line) {
    fprintf(stderr, "=== ASSERTION FAILED ===");
    fprintf(stderr, "==> %s:%d '%s' is not true",file,line,estr);
    *((char*)-1) = 'x';
}

void _serverPanic(const char *file, int line, const char *msg, ...) {
    va_list ap;
    va_start(ap,msg);
    char fmtmsg[256];
    vsnprintf(fmtmsg,sizeof(fmtmsg),msg,ap);
    va_end(ap);

    bugReportStart();
    //serverLog(LL_WARNING,"------------------------------------------------");
    //serverLog(LL_WARNING,"!!! Software Failure. Press left mouse button to continue");
    //serverLog(LL_WARNING,"Guru Meditation: %s #%s:%d",fmtmsg,file,line);

    //if (server.crashlog_enabled) {
#ifdef HAVE_BACKTRACE
        logStackTrace(NULL, 1);
#endif
        printCrashReport();
    //}

    // remove the signal handler so on abort() we will output the crash report.
    removeSignalHandlers();
    bugReportEnd(0, 0);
}
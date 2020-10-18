#include <stdio.h>
#include <string.h>
#include <jemalloc/jemalloc.h>

int main() {
    #if defined(USE_TCMALLOC)
    printf("defined(USE_TCMALLOC)\n");
    #define ZMALLOC_LIB ("tcmalloc-" __xstr(TC_VERSION_MAJOR) "." __xstr(TC_VERSION_MINOR))
    #include <google/tcmalloc.h>
    #if (TC_VERSION_MAJOR == 1 && TC_VERSION_MINOR >= 6) || (TC_VERSION_MAJOR > 1)
    #define HAVE_MALLOC_SIZE 1
    #define zmalloc_size(p) tc_malloc_size(p)
    #else
    #error "Newer version of tcmalloc required"
    #endif

    #elif defined(USE_JEMALLOC)
    printf("defined(USE_JEMALLOC)\n");
    #define ZMALLOC_LIB ("jemalloc-" __xstr(JEMALLOC_VERSION_MAJOR) "." __xstr(JEMALLOC_VERSION_MINOR) "." __xstr(JEMALLOC_VERSION_BUGFIX))
    #if (JEMALLOC_VERSION_MAJOR == 2 && JEMALLOC_VERSION_MINOR >= 1) || (JEMALLOC_VERSION_MAJOR > 2)
    #define HAVE_MALLOC_SIZE 1
    #define zmalloc_size(p) je_malloc_usable_size(p)
    #else
    printf("Newer version of jemalloc required");
    #endif

    #elif defined(__APPLE__)
    printf("defined(__APPLE__)\n");
    #include <malloc/malloc.h>
    #define HAVE_MALLOC_SIZE 1
    #define zmalloc_size(p) malloc_size(p)
    #endif

    #ifndef ZMALLOC_LIB
    printf("defined(ZMALLOC_LIB)\n");
    #define ZMALLOC_LIB "libc"
    printf("defined(ZMALLOC_LIB libc)\n");
    #ifdef __GLIBC__
    printf("defined(__GLIBC__)\n");
    #include <malloc.h>
    #define HAVE_MALLOC_SIZE 1
    #define zmalloc_size(p) malloc_usable_size(p)
    #endif
    #endif

    /* We can enable the Redis defrag capabilities only if we are using Jemalloc
    * and the version used is our special version modified for Redis having
    * the ability to return per-allocation fragmentation hints. */
    #if defined(USE_JEMALLOC) && defined(JEMALLOC_FRAG_HINT)
    printf("HAVE_DEFRAG\n");
    #define HAVE_DEFRAG
    #endif
}

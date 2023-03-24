#include <stdio.h>

#define SDS_TYPE_5  0
#define SDS_TYPE_8  1
#define SDS_TYPE_16 2
#define SDS_TYPE_32 3
#define SDS_TYPE_64 4
#define SDS_TYPE_MASK   7


int main() {
    printf("SDS_TYPE_5: %d\n", SDS_TYPE_5 & SDS_TYPE_MASK);
    printf("SDS_TYPE_8: %d\n", SDS_TYPE_8 & SDS_TYPE_MASK);
    printf("SDS_TYPE_64: %d\n", SDS_TYPE_64 & SDS_TYPE_MASK);
}
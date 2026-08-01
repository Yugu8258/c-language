#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    // 固定宽度整数类型
    int32_t myInt32 = INT32_MAX;

    uint32_t myUInt32 = UINT32_MAX;

    uint64_t myUInt64 = UINT64_MAX;

    printf("int32_t: %" PRId32 "\n", myInt32);
    printf("uint32_t: %" PRIu32 "\n", myUInt32);
    printf("uint64_t: %" PRIu64 "\n", myUInt64);

    return 0;
}


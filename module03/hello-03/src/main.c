#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    // 请注意, 这里的x, y, z仅仅是测试程序, 并无实际意义.
    uint32_t x, y, z;

    // 多重赋值
    x = y = z = 10;

    printf("x: %" PRIu32 "\n", x);
    printf("y: %" PRIu32 "\n", y);
    printf("z: %" PRIu32 "\n", z);

    return 0;
}


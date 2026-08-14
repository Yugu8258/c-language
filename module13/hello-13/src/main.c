#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    // typedef
    // 为基本数据类型创建别名
    typedef uint32_t u32;

    u32 number = 1;

    printf("number = %" PRIu32 "\n", number);
    
    return 0;
}


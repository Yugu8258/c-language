#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    // 空指针, 没有指向任何楼层的地址
    uint32_t *ptr_to_floor = NULL;

    // 尝试通过空指针访问数据

    if (ptr_to_floor == NULL)
    {
        printf("没有指定楼层的地址!\n");
        // shortcut 不做任何处理
    }
    else
    {
        printf("楼层的地址是: %p, 楼层号: %" PRIu32 "\n", (void*)ptr_to_floor, *ptr_to_floor);
    }

    return 0;
}


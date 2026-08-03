#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    // 计划晚上出去吃饭, 你的决策依赖与两个条件:
    // 是否有优惠卷, 或者饭店有其他的活动.

    bool has_coupon = true;         // 是否有优惠券
    bool is_special_event = false;  // 饭店是否有活动

    // 逻辑OR || 或的短路行为
    if (has_coupon || is_special_event)
    {
        printf("晚上出去吃饭!\n");
    }
    else
    {
        printf("晚上不出去吃饭!\n");
    }

    return 0;
}


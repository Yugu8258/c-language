#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    // 逻辑表达式也应该得到简化
    bool is_weekend = true;
    bool has_invitation = true;

    if (!has_invitation)
    {
        return -1;
    }

    return 0;
}


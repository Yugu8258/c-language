#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

int main(void)
{
    uint32_t wrong_attempts = 3;
    bool is_locked = wrong_attempts >= 3; // 密码如果输入错误三次就锁定

    if (is_locked)
    {
        puts("账户被锁定");
        return 0;
    }
    
    return 0;
}


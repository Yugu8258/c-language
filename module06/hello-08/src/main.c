#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define ACCOUNT_COUNT 3

int main(void)
{
    uint64_t account_balances[ACCOUNT_COUNT] = { 1000, 1500, 2000 };

    puts("初始账户金额:");
    for (uint8_t index = 0; index < ACCOUNT_COUNT; index++)
    {
        printf("账户 %" PRIu8 " 金额 %" PRIu64 " 元\n", index + 1, account_balances[index]);
    }

    account_balances[0] += 5000;
    account_balances[1] -= 500;

    puts("变动后的账户金额:");
    for (uint8_t index = 0; index < ACCOUNT_COUNT; index++)
    {
        printf("账户 %" PRIu8 " 金额 %" PRIu64 " 元\n", index + 1, account_balances[index]);
    }
    return 0;
}


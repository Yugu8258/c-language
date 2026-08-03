#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    // 在线购物平台的优惠卷系统
    // 根据用户的购物车总额和会员等级, 系统提供不同等级的折扣
   
    // 1. 如果用户是VIP, 购物总额度超过100, 提供20%折扣
    // 2. 如果用户不是VIP, 但购物车总额度超过50, 提供10%折扣
    // 3. 如果用户购物车总额度不超过50, 没有折扣
    // 特殊情况: 如果用户VIP, 但购物车总额不超过100, 也提供5%折扣

    double cart_total;

    bool is_vip;

    double discount_rate = 0.0;

    // 设置
    cart_total = 120.0;

    is_vip = true;

    // 判断

    // 首先检查用户是否为VIP
    if (is_vip) // 是否为vip
    {
        if (cart_total > 100.0) // vip, 购物车总额超过100.0
        {
            discount_rate = 0.20;
        }
        else // vip, 购物车总额没有超过100.0
        {
            discount_rate = 0.05;
        }
    }
    else if (cart_total > 50) // 无vip, 购物车总额超过50
    {
        discount_rate = 0.10;
    }
    else // 不是vip, 购物车总额没有超过50
    {
        discount_rate = 0.0;
    }

    printf("您的折扣为: %.2f%%\n", discount_rate * 100.0);

    return 0;
}


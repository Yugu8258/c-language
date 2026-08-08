#include <stdio.h>

int main(void)
{
    int floor_number = 103;

    int *ptr_to_floor = &floor_number;

    printf("当前楼层号: %d, 地址: %p\n", *ptr_to_floor, (void*)ptr_to_floor);

    {
        // 创建一个新的作用域

        int temp_floor = 104; // 另一个门牌号

        ptr_to_floor = &temp_floor; // 指针现在指向新的楼层
    }

    // temp_floor已经离开作用域, 这个程序中不存在temp_floor当然, 他的值和地址也已经不存在了.
    // 那么现在问题来了, 我已经把temp_floor的地址交给了ptr_to_floor, ptr_to_floor -> ???

    printf("试图尝试访问新的楼层号, 可能的地址： %p, 值是未定的: %d\n", (void*)ptr_to_floor, *ptr_to_floor);

    return 0;
}


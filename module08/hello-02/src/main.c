#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    // 指针
    // 指针也是一个变量
    // 指针是一个特殊的变量
    // 指针不存具体的数值
    // 指针存储的是数据的地址
    // 指针也是有地址

    // 就像快递员的地图上的标记每个楼层的门牌号(地址)

    uint32_t building_floors[5] = { 101, 102, 103, 104, 105 };

    // 变量类型 uint32_t*
    // 变量名 ptr_floor_103
    uint32_t *ptr_floor_103 = &building_floors[2];

    printf("building_floors[2]的地址是: %p\n", &building_floors[2]);

    printf("ptr_floor_103指针变量保存的地址是: %p\n", ptr_floor_103);

    return 0;
}


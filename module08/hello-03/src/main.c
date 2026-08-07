#include <stdio.h>
#include <inttypes.h>

int main(void)
{
    // 指针

    uint32_t building_floors[5] = { 101, 102, 103, 104, 105 };

    printf("building_floors[2] = %" PRIu32 "\n", building_floors[2]);

    // ptr_floor_103 -> (指向) &building_floors[2]
    uint32_t *ptr_floor_103 = &building_floors[2];

    printf("快递员通过*(指针相当于一个地图工具), 它带着ptr_floor_103这个指针变量(它存储了业主的地址)去寻找...\n");
    printf("于是它找到了业主的门牌号: %d\n", *ptr_floor_103);
    printf("于是它找到了业主的门牌号: %d\n", building_floors[2]);

    // 快递员找到你了, 但是你搬家啦
    // 你要求快递员: 我要搬家啦, 会搬到106
    uint32_t *ptr_new_106 = ptr_floor_103;

    *ptr_new_106 = 106;
    printf("building_floors[2]: %d\n", building_floors[2]);

    return 0;
}


#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main(void)
{
    // 僵尸类别
    uint32_t regular_zombie = 1;
    uint32_t conehead_zombie = 2;
    uint32_t bucket_head_zombie = 3;
    uint32_t flag_zombie = 4;
    uint32_t newspaper_zombie = 5;

    // 定义一个包含不同类型的僵尸数组
    uint32_t zombies[10] = { regular_zombie, conehead_zombie, bucket_head_zombie, flag_zombie, regular_zombie, bucket_head_zombie, bucket_head_zombie, flag_zombie,regular_zombie, regular_zombie };

    // 假如标号6-10也是特定植入
    uint32_t battle_plants[5] = { 6, 7, 8, 9, 10 };

    // 假如一下是可选植物列表的ID
    uint32_t available_plants[10] = { 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 };

    printf("Zombies in the game (Type ids):\n");
    for (uint32_t i = 0; i < 10; i++)
    {
        printf("%" PRIu32 " ", zombies[i]);
    }
    printf("\n");

    printf("\nPlants selected for battle (Type ids):\n");
    for (uint32_t i = 0; i < 5; i++)
    {
        printf("%" PRIu32 " ", battle_plants[i]);
    }
    printf("\n");

    printf("\nAvailable plants for selection (Type ids):\n");
    for (uint32_t i = 0; i < 10; i++)
    {
        printf("%" PRIu32 " ", zombies[i]);
    }
    printf("\n");

    return 0;
}


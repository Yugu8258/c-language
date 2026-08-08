#include <stdio.h>
#include <inttypes.h>

void update_score(uint32_t *score, uint32_t points);

uint32_t *compare_score(uint32_t *score1, uint32_t *score2);

void double_score(uint32_t *score);

int main(void)
{
    uint32_t player1_score = 100;

    uint32_t player2_score = 150;

    update_score(&player1_score, 50);
    
    uint32_t *higher_score = compare_score(&player1_score, &player2_score);

    printf("较高的分数是: %" PRIu32 "\n", *higher_score);

    double_score(&player1_score);

    return 0;
}

void update_score(uint32_t *score, uint32_t points)
{
    *score += points;

    printf("当前分数: %" PRIu32 "\n", *score);
}

uint32_t *compare_score(uint32_t *score1, uint32_t *score2)
{
    return (*score1 > *score2) ? score1 : score2;
}

void double_score(uint32_t *score)
{
    *score <<= 1;
    printf("翻倍后的分数: %" PRIu32 "\n", *score);
}


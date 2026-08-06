#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

#define CANDIDATE_COUNT 4

int main(void)
{
    uint32_t votes[CANDIDATE_COUNT] = { 0 };

    uint32_t total_votes = 0;

    uint32_t max_votes = votes[0];

    uint32_t winner = 0; // 候选人的index下标索引

    votes[0] += 150;
    votes[1] += 200;
    votes[2] += 180;
    votes[3] += 190;

    for (uint32_t index = 0; index < CANDIDATE_COUNT; index++)
    {
        total_votes += votes[index];

        if (votes[index] > max_votes)
        {
            max_votes = votes[index];
            winner = index + 1; // 更新候选人索引 
        }
    }

    puts("各个候选人的票数: ");
    for (uint32_t index = 0; index < CANDIDATE_COUNT; index++)
    {
        printf("候选人 %" PRIu32 " 获得的票数: %" PRIu32 "\n", index + 1, votes[index]);
    }

    printf("总票数: %" PRIu32 "\n", total_votes);
    printf("获胜候选人: %" PRIu32 "\n", winner);

    return 0;
}


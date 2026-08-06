#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <ctype.h>

#define LETTER_COUNT 26

int main(void)
{
    uint32_t frequency[LETTER_COUNT] = { 0 };

    char text[] = "Example text for frequency analysis.";

    // 统计每个字母出现的次数
    for (uint32_t i = 0; text[i] != '\0'; i++)
    {
        char ch = tolower(text[i]);

        if (ch >= 'a' && ch <= 'z')
        {
            // 更新对应字母的频率
            frequency[ch - 'a']++;
        }
    }

    puts("字母的频率:");
    for (uint32_t i = 0; i < LETTER_COUNT; i++)
    {
        if (frequency[i] > 0)
        {
            printf("%c: %" PRIu32 "\n", 'a' + i, frequency[i]);
        }
    }

    return 0;
}


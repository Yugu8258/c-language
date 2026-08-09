#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TEXT_SIZE 1024
#define WORD_SIZE 100
#define DELIMS " ,.!?\n\r\t"

void replaceWord(const char *text, const char *oldWord, const char *newWord, char *result);
int countChar(const char *text, char ch);
size_t countWords(const char *text);
void extractUniqueWords(const char *text, char uniqueWords[][WORD_SIZE], int *uniqueCount);

int main(void)
{
    char text[TEXT_SIZE] = "This is a simple test. This text is for testing.";

    char replacedText[TEXT_SIZE] = { 0 };

    char oldWord[] = "test";

    char newWord[] = "example";

    char countCharTarget = 's';

    char uniqueWords[TEXT_SIZE][WORD_SIZE] = { 0 };

    int uniqueCount = 0;

    replaceWord(text, oldWord, newWord, replacedText);

    printf("Replaced Text : %s\n", replacedText);

    int charCount = countChar(replacedText, countCharTarget);
    printf("Character '%c' appears %d times.\n", countCharTarget, charCount);

    int wordCount = countWords(replacedText);
    printf("Total number of words: %d\n", wordCount);

    // 调用提取唯一单词
    extractUniqueWords(replacedText, uniqueWords, &uniqueCount);
    printf("\nUnique words count: %d\n", uniqueCount);
    for (int i = 0; i < uniqueCount; ++i)
    {
        printf("[%d] %s\n", i, uniqueWords[i]);
    }

    return 0;
}

void replaceWord(const char *text, const char *oldWord, const char *newWord, char *result)
{
    char buffer[TEXT_SIZE] = { 0 };
    char *bufPtr = buffer; // 维护buffer尾部指针, 避免反复strlen
    const char *pos = text;
    const char *temp;

    size_t oldLen = strlen(oldWord);
    size_t bufCap = sizeof(buffer);

    while ((temp = strstr(pos, oldWord)) != NULL)
    {
        // pos ~ temp: 匹配之间普通字符串
        size_t segLen = (size_t)(temp - pos);

        // 剩余空间, 预留 '\0'
        size_t remain = bufCap - (size_t)(bufPtr - buffer) - 1;

        if (segLen > 0 && remain > 0)
        {
            size_t copyLen = segLen < remain ? segLen : remain;
            strncat(bufPtr, pos, copyLen);
            bufPtr += copyLen;
        }

        // 追加新单词
        remain = bufCap - (size_t)(bufPtr - buffer) - 1;
        if (remain > 0)
        {
            strncat(bufPtr, newWord, remain);
            bufPtr += strlen(newWord);
        }

        pos = temp + oldLen;
    }

    // 追加末尾剩余部分
    size_t remain = bufCap - (size_t)(bufPtr - buffer) - 1;
    if (remain > 0)
    {
        strncat(bufPtr, pos, remain);
    }

    // 拷贝结束, 强制保证NULL终止
    strncpy(result, buffer, TEXT_SIZE - 1);
    result[TEXT_SIZE - 1] = '\0';
}

int countChar(const char *text, char ch)
{
    int count = 0;
    while (*text)
    {
        if (*text == ch) { count++; }
        text++;
    }

    return count;
}

size_t countWords(const char *text)
{
    if (text == NULL) { return 0; }

    const char *delim = DELIMS;

    size_t cnt = 0;

    while (*text != '\0')
    {
        text += strspn(text, delim); // 跳过全部空白和标点
        if (*text == '\0') { break; }
        cnt++;
        text += strcspn(text, delim); // 跨过当前单词
    }

    return cnt;
}

void extractUniqueWords(const char *text, char uniqueWords[][WORD_SIZE], int *uniqueCount)
{
    if (text == NULL || uniqueWords == NULL || uniqueCount == NULL)
    {
        if (uniqueCount != NULL)
        {
            *uniqueCount = 0;
        }
        return;
    }

    *uniqueCount = 0;
    const char *p = text;

    while (*p != '\0')
    {
        // 跳过分隔符
        p += strspn(p, DELIMS);
        if (*p == '\0') { break; }

        // 获取当前单词长度
        size_t segLen = strcspn(p, DELIMS);

        char tmp[WORD_SIZE] = { 0 };
        size_t copyLen = (segLen < (WORD_SIZE - 1)) ? segLen : (WORD_SIZE - 1);
        strncpy(tmp, p, copyLen);
        tmp[copyLen] = '\0';

        // 判断是否已经存在
        int exist = 0;
        for (int i = 0; i < *uniqueCount; ++i)
        {
            if (strcmp(tmp, uniqueWords[i]) == 0)
            {
                exist = 1;
                break;
            }
        }

        // 不存在, 且数组还有空间才存入
        if (!exist && (size_t)(*uniqueCount) < TEXT_SIZE)
        {
            strncpy(uniqueWords[*uniqueCount], tmp, WORD_SIZE - 1);
            uniqueWords[*uniqueCount][WORD_SIZE - 1] = '\0';
            (*uniqueCount)++;
        }

        p += segLen;
    }
}


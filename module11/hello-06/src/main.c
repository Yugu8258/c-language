#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *fp = fopen("123.txt", "r+");
    // 打开文件失败
    if (fp == NULL)
    {
        perror("打开文件失败\n");
        return EXIT_FAILURE;
    }

    // ftell
    // fseek
    // rewind

    // 使用ftell获取当前文件指针的位置
    long position = ftell(fp);
    printf("当前位置: %ld\n", position);

    // 开始读取
    char buffer[100];
    if (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("从文件读取: %s", buffer);
        // 再次使用ftell获取新的位置
        position = ftell(fp);
        printf("读取后的新位置: %ld\n", position);
    }

    // 使用fseek函数移动到文件的开始
    fseek(fp, 0, SEEK_SET);
    printf("使用fseek后移动到开始位置, SEEK_SET = 0: %ld\n", ftell(fp));

    // rewind
    rewind(fp);
    printf("使用rewind直接移动到开始的位置: %ld\n", ftell(fp));

    // 关闭文件
    fclose(fp);

    return EXIT_SUCCESS;
}


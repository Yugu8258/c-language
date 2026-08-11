#include <stdio.h>

#define SIZE 50

int main(void)
{
    // scanf

    char name[SIZE];

    scanf("%49[^\n]", name); // 最多49个字符, 读到\n停下
    getchar(); // 必须吃掉留在缓冲区的换行符

    printf("[%s]\n", name);

    return 0;
}


#include <stdio.h>
#include <string.h>

int main(void)
{
    // sprintf

    char buf[20];
    int age = 22;
    const char *name = "zhangsan";

    // sprintf: 格式化输出到字符数组, 自动追加 '\0'
    sprintf(buf, "name: %s age: %d", name, age);
    printf("buf = \"%s\"\n", buf);

    printf("strlen(buf) = %zu\n", strlen(buf));

    // 危险溢出示例(不要在实际代码中写)
#if 0
    char small[8];
    // 输出内容超过缓冲区, 缓冲区溢出, 未定义行为!
    sprintf(small, "hello world 123456");
    printf("%s\n", small);
#endif

    return 0;
}


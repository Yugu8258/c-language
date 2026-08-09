#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char buf[32];
    char tiny_buf[10];
    int id = 1001;
    const char* msg = "test message";

    printf("==== snprintf demo ====\n");
    
    // 1. 缓冲区足够, 正常输出
    int ret1 = snprintf(buf, sizeof(buf), "id = %d, msg = %s", id, msg);
    printf("buf: \"%s\"\n", buf);
    printf("ret1 = %d, buf_size = %zu\n\n", ret1, sizeof(buf));

    // 2. 缓冲区不足, 发生截断, 依然保证合法 '\0' 字符串
    int number = 99999;
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wformat-truncation"
    int ret2 = snprintf(tiny_buf, sizeof(tiny_buf), "very_long_string_%d", number);
#pragma GCC diagnostic pop
    printf("tiny_buf: \"%s\"\n", tiny_buf);
    printf("ret2 = %d, tiny_buf size = %zu\n\n", ret2, sizeof(tiny_buf));
    if ((size_t)ret2 >= sizeof(tiny_buf))
    {
        printf("-> detected output truncated!\n\n");
    }

    // 3. snprintf(NULL, 0): 只计算需要多少字节, 不写入内存
    int need_bytes = snprintf(NULL, 0, "id = %d, msg = %s", id, msg);
    printf("need output chars (exclude '\\0'): %d\n", need_bytes);
    // 动态分配内存 need_bytes + 1 存放 '\0'
    char *heap_buf = (char *)malloc((size_t)need_bytes + 1);
    if (heap_buf != NULL)
    {
        snprintf(heap_buf, (size_t)need_bytes + 1, "id = %d, msg = %s", id, msg);
        printf("heap_buf: \"%s\"\n", heap_buf);
        free(heap_buf);
    }

    // 4. buf_size = 1, 只能放一个 '\0'
    char one[1];
    const char *demo_str = "abcdef";
    snprintf(one, sizeof(one), "%s", demo_str);
    printf("one[0] = %d (expect 0)\n", one[0]);

    return 0;
}


#define _POSTX_C_SOURCE 200809L

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

#if defined(_WIN32)
#include <crtdbg.h>
#include <windows.h>
#include <wchar.h> /* fwprintf */
#endif

// 函数声明
static size_t cross_strlen_s(const char *s, size_t maxsize);

#if defined(_WIN32)
static void my_invalid_param_handler(
        const wchar_t *expr,
        const wchar_t *func,
        const wchar_t *file,
        unsigned int line,
        uintptr_t reserved
);

static void platform_setup(void);
#endif

int main(void)
{
    // strlen
    // string length

#if defined(_WIN32)
    platform_setup();
#endif

    char buf1[] = "Hello World";
    char buf2[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' }; // 无 \0 截断场景

    size_t ret;

    printf("=== corss-platform strlen_s demo ===\n");

    // 正常有终止符
    ret = cross_strlen_s(buf1, sizeof(buf1));
    printf("buf1 = \"%s\", cross_strlen_s ret = %zu\n", buf1, ret);

    // 没有 \0, maxsize = 8, 返回0
    ret = cross_strlen_s(buf2, sizeof(buf2));
    printf("buf2 no null-terminated, cross_strlen_s ret = %zu\n", ret);
    
    // NULL指针测试
#if 0
    ret = cross_strlen_s(NULL, 16);
    printf("ret = %zu\n", ret);
#endif

    return 0;
}

// 函数定义
static size_t cross_strlen_s(const char *s, size_t maxsize)
{
#if defined(_WIN32)
    return strlen_s(s. maxsize);
#else
    // Linux/macOS 模拟实现
    if (s == NULL || maxsize == 0)
    {
        // Windows会触发invalid prarmeter
        return 0;
    }
    
    for (size_t i = 0; i < maxsize; i++)
    {
        if (s[i]  == '\0') { return i; }
    }

    // 遍历完成maxsize没有找到'\0', 放回0
    return 0;
#endif
}

#if defined(_WIN32)
static void my_invalid_param_handler(
        const wchar_t *expr,
        const wchar_t *func,
        const wchar_t *file,
        unsigned int line,
        uintptr_t reserved
)
{
    (void)reserved;
    fwprintf(stderr, L"[InvalidParam] expr: %s func: %s file: %s line: %u\n",
            expr ? expr : L"(null)",
            func ? func : L"(null)",
            file ? file : L"(null)",
            line);

    ExitProcess(EXIT_FAILURE);
}

static void platform_setup(void)
{
    _set_invalid_parameter_handler(my_invalid_param_handler);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
}
#endif


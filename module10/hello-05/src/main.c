#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#if defined(_WIN32)
#include <crtdbg.h>
#include <windows.h>
#include <wchar.h>
#endif

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

static bool cross_strcat_s(char *dest, size_t dest_buf_size, const char *str);

int main(void)
{
    // strcat
#if defined(_WIN32)
    platform_setup();
#endif

    char buf[32];
    
    // 必须 初始化, dest要有 '\0'
    snprintf(buf, sizeof(buf), "Hello ");

    printf("=== strcat cross-platform demo ===\n");
    printf("before: buf = \"%s\"\n", buf);

    bool ok = cross_strcat_s(buf, sizeof(buf), "World!");
    if (ok)
    {
        printf("after append: buf = \"%s\"\n", buf);
    }
    else
    {
        printf("append failed\n");
    }
    
    // 测试缓冲区溢出场景
    char small_buf[10] = { "ABC" };
    ok = cross_strcat_s(small_buf, sizeof(small_buf), "1234567890abcdef");
    if (!ok)
    {
        printf("small buffer append correctly rejected\n");
    }

    return 0;
}

/**
 * @brief 跨平台strcat_s封装
 * @param dest 输出缓冲区
 * @param dest_buf_size dest缓冲区总字节大小
 * @param src 源字符串
 * @return true成功, false缓冲区不足/入参非法
 */
static bool cross_strcat_s(char *dest, size_t dest_buf_size, const char *str)
{
#if defined(_WIN32)
    // Windows原生 strcat_s
    errno_t ret = strcat_s(dest, dest_buf_size, str);
    return (ret == 0);
#else
    // Linux/macOS
    if (dest == NULL || str  == NULL || dest_buf_size == 0) { return false; }

    // 获取dest当前字符串长度
    size_t dest_len = strlen(dest);
    if (dest_len >= dest_buf_size) { return false; }

    // 剩余可用空间, 包含末尾'\0'
    size_t remain = dest_buf_size - dest_len;
    size_t src_len = strlen(str);

    // 放不下, 溢出
    if (src_len >= remain) { return false; }

    // 安全拼接
    memcpy(dest + dest_len, str, src_len + 1);

    return true;
#endif
}

#if defined(_WIN32)
static void my_invalid_param_handler(
        const wchar_t *expr,
        const wchar_t *func,
        const wchar_t *file,
        unsigned int line,
        uintptr_t resverved
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

static void paltform_setup(void)
{
    _set_invalid_parameter_handler(my_invalid_param_handler);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
}
#endif


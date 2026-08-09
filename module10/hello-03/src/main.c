#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#if defined(_WIN32)
#include <crtdbg.h>
#include <windows.h>
#include <wchar.h>
#else
#include <signal.h>
#include <execinfo.h>
#include <unistd.h>
#endif

/**************** 函数声明 (原型) ****************/
#if defined(_WIN32)
static void my_invalid_param_handler(
        const wchar_t *expression,
        const wchar_t *function,
        const wchar_t *file,
        unsigned int line,
        uintptr_t pReserved
);
#endif

#if !defined(_WIN32)
static void sigsegv_handler(int sig);
#endif

static void platform_setup(void);
/**********************************************/

int main(void)
{
    // 调用函数

    platform_setup();

    char buf[32];
    const char *src = "hello cross platform";

    printf("=== cross-platform demo start ===\n");

#if defined(_WIN32)
    strcpy_s(buf, sizeof(buf), src);
#else
    snprintf(buf, sizeof(buf), "%s", src);
#endif
    printf("normal copy: %s\n", buf);

#if 0
    char *bas_ptr = NULL;
#if defined(_WIN32)
    strcpy_s(bad_ptr, 16, "test carsh");
#else
    strcpy(bad_ptr, "test carsh");
#endif
#endif

    printf("demo exit ok\n");

    return 0;
}

// 函数的定义
#if defined(_WIN32)
static void my_invalid_param_handler(
        const wchar_t *expression,
        const wchar_t *function,
        const wchar_t *file,
        unsigned int line,
        uintptr_t pReserved
)
{
    (void)pReserved;
    fwprintf(stderr, L"[Windows InvalidParam] expr: %s\n", expression ? expression : L"(null)");
    fwprintf(stderr, L"func: %s file: %s line:%u\n",
            function ? function : L"(null)",
            file ? file : L"(null)",
            line
    );
    ExitProcess(EXIT_FAILURE);
}
#endif

#if !defined(_WIN32)
static void sigsegv_handler(int sig)
{
    (void)sig;
    void *bt_buf[32];
    int bt_sz = backtrace(bt_buf, 32);
    fprintf(stderr, "\n[SIGSEGV CRASH] backtrace:\n");
    backtrace_symbols_fd(bt_buf, bt_sz, STDERR_FILENO);
    _exit(127);
}
#endif

static void platform_setup(void)
{
#if defined(_WIN32)
    _set_invalid_parameter_handler(my_invalid_param_handler);
    _CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
    _CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDERR);
#else
    struct sigaction sa;
    sa.sa_handler = sigsegv_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGSEGV, &sa, NULL);
#endif
}


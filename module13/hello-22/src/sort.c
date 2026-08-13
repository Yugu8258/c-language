#define _GNU_SOURCE

#include "sort.h"

#include <stdlib.h>

// 跨平台的问题

// 跳板需要同时持有(用户回调 + 用户上下文)
typedef struct
{
    CompareFunc user_cmp;
    void *user_ctx;
} TrampolineArg;

// 包装器

// BSD 平台跳板: 签名 void *ctx, a, b
static int bsd_trampoline(void *arg, const void *a, const void *b)
{
    TrampolineArg *t = (TrampolineArg *)arg;
    return t->user_cmp(a, b, t->user_ctx);
}

// GNU / Windows 跳板: 签名 a, b, ctx
static int std_trampoline(const void *a, const void *b, void *arg)
{
    TrampolineArg *t = (TrampolineArg *)arg;
    return t->user_cmp(a, b, t->user_ctx);
}

void genericSort(void *array, size_t length, size_t elemSize, CompareFunc compare, void *context)
{
    TrampolineArg t_arg = {
        .user_cmp = compare,
        .user_ctx = context
    };

    // qsort()
#if defined (_WIN32)
    // Windows qsort_s 匹配 std_trampoline
    qsort_s(array, length, elemSize, std_trampoline, &t_arg);
#elif defined(__linux__) && defined(_GNU_SOURCE)
    // GUN/Linux qsort_r
    qsort_r(array, length, elemSize, std_trampoline, &t_arg);
#elif defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__)
    // BSD / macOS qsort_t 参数顺序不一样
    qsort_r(array, length, elemSize, &t_arg, bsd_trampoline);
#else
#error "Platform not supported for genericSort"
#endif
}


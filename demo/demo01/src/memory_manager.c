#include "memory_manager.h"
#include "logger.h"

#include <stdalign.h>


// 安全的分配内存
void *safe_malloc(size_t size)
{
    assert(size > 0);

    void *ptr = NULL;

#if defined(__STDC_VERSION__) && __STDC_VERSION__ >= 201112L
    // C11 安全的分配对齐内存, alignof(max_align_t)指定了对齐边界
    ptr = aligned_alloc(alignof(max_align_t), size);
#else
    ptr = malloc(size);
#endif

    if (ptr == NULL)
    {
        // 在实际应用中, 可能不希望在分配内存失败后停止程序, 这里为了调试方便找出问题使用了断言函数
        // 在实际企业开发中应该根据需求堆错误进行处理
        fprintf(stderr, "Memory allocation failed for size %zu.\n", size);
        assert(ptr != NULL);
    }

    return ptr;
}

// 安全的重新分配内存...
void *safe_remalloc(void *ptr, size_t new_size)
{
    void *new_ptr = realloc(ptr, new_size);
    if (new_ptr == NULL)
    {
        log_message(LOG_ERROR, "Failed to realocate to %zu bytes of memory.", new_size);
    }

    return new_ptr;
}

// 安全的释放内存, 并将指针设置为NULL
void safe_free(void **ptr)
{
    if (ptr && *ptr)
    {
        free(*ptr);
        *ptr = NULL; // 将指针设置为NULL, 防止野指针
    }
    else
    {
        log_message(LOG_WARNING, "Attempted to free a null or already freed pointer.");
    }
}


#include "memory_management.h"

#include <stdio.h>
#include <stdlib.h>

#if defined(__linux__) || defined(__unix__)
#include <malloc.h>
#endif

static size_t current_memory_usage = 0;

// 安全分配内存
void *safe_malloc(size_t size)
{
    void *ptr = malloc(size);
    if (ptr != NULL)
    {
        current_memory_usage += size;
        return ptr;
    }

    fprintf(stderr, "Error: Memory allocation failed for %zu bytes.\n", size);
    exit(EXIT_FAILURE);
}

// 安全重新分配内存
void *safe_realloc(void *ptr, size_t new_size)
{
    size_t old_size = 0;
    if (ptr)
    {
#ifdef _WIN32
        old_size = _msize(ptr); // 特定用于Windows
#elif defined(__linux__) || defined(__unix__)
        old_size = malloc_usable_size(ptr); // 特定用于Linux / macOS
#else
        old_size = 0;
#endif
    }

    void *new_ptr = realloc(ptr, new_size);
    if (new_ptr != NULL)
    {
        current_memory_usage += new_size - old_size;
        return new_ptr;
    }

    fprintf(stderr, "Error: Memory reallocation failed for %zu bytes.\n", new_size);
    exit(EXIT_FAILURE);
}

// 安全释放内存
void safe_free(void **ptr)
{
    if (ptr == NULL || *ptr == NULL) { return; }

#ifdef _WIN32
    current_memory_usage -= _msize(*ptr);
#elif defined(__linux__) || defined(__unix__)
    current_memory_usage -= malloc_usable_size(*ptr);
#endif
    free(*ptr);
    *ptr = NULL;
}

// 打印当前内存的使用情况
void print_memory_usage(void)
{
    printf("Current memory usage: %zu bytes.\n", current_memory_usage);
}

// 将内存管理信息写入到文件的函数声明
void memory_management_dump_to_file(const char *filename)
{
    FILE *fp = NULL;
    fp = fopen(filename, "w");
    if (fp == NULL)
    {
        fprintf(stderr, "Error: Unable to open %s file for writing.\n", filename);
        return;
    }

    fprintf(fp, "Current memory usage: %zu bytes.\n", current_memory_usage);

    fclose(fp);
}


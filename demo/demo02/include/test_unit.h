#pragma once

#include <stdbool.h>
#include <stdio.h>

typedef enum TestResult
{
    TEST_PASSED,
    TEST_FAILED
} TestResult;

typedef TestResult(*test_case_function)(void);

typedef struct TestCase
{
    char *test_name;
    test_case_function function;
} TestCase;

void run_test_suite(TestCase *tests, size_t test_count);

#define VERIFY(expression) \
    do { \
        if (!(expression)) { \
            printf("Test failed: %s, Line: %d\n", __FILE__, __LINE__); \
            return TEST_FAILED; \
        } \
    } while (0)

TestResult test_generic_queue_enqueue_dequeue(void);
TestResult test_memory_management_allocation_free(void);
TestResult test_type_safety_checks(void);

// 测试用例


#include "test_unit.h"
#include "generic_queue.h"
#include "memory_management.h"

#include <stdio.h>

void run_test_suite(TestCase *tests, size_t test_count)
{
    size_t passed_count = 0;

    for (size_t i = 0; i < test_count; ++i)
    {
        printf("Running test: %s\n", tests[i].test_name);
        TestResult result = tests[i].function();
        if (result == TEST_PASSED)
        {
            printf("[PASS]%s Test Passed\n", tests[i].test_name);
            passed_count++;
        }
        else
        {
            printf("[FAIL]%s Test Failed\n", tests[i].test_name);
        }
    }

    printf("\nTest Suite Summary: %zu/%zu tests passed\n", passed_count, test_count);
}

TestResult test_generic_queue_enqueue_dequeue(void)
{
    GenericQueue *queue = queue_create();
    VERIFY(queue != NULL);

    int test_data = 42;
    GenericValue value;
    value.ptrValue = &test_data;

    bool enqueue_result = queue_enqueue(queue, value, TYPE_PTR);
    VERIFY(enqueue_result == true);

    GenericValue dequeue_value;
    DataType dequeue_type;

    bool dequeue_result = queue_dequeue(queue, &dequeue_value, &dequeue_type);
    VERIFY(dequeue_result == true);

    VERIFY(dequeue_type == TYPE_PTR);
    VERIFY((*(int *)dequeue_value.ptrValue) == test_data);

    queue_destroy(queue);

    return TEST_PASSED;
}

TestResult test_memory_management_allocation_free(void)
{
    int *p = safe_malloc(sizeof(int));
    VERIFY(p != NULL);
    *p = 999;

    int *p2 = safe_realloc(p, sizeof(int) * 4);
    VERIFY(p2 != NULL);
    p = p2;

    safe_free((void **)&p);
    VERIFY(p == NULL);

    return TEST_PASSED;
}


TestResult test_type_safety_checks(void)
{
    GenericValue v;
    v.i32Value = 1234;
    VERIFY(v.i32Value == 1234);

    v.f64Value = 3.14;
    VERIFY(v.f64Value > 3.0 && v.f64Value < 3.2);
    return TEST_PASSED;
}


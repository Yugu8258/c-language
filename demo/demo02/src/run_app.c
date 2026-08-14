#include "test_unit.h"

#include <stdlib.h>

int main(int argc, char *argv[])
{
    // 泛型

    TestCase test_list[] = {
        {"Queue Enqueue Dequeue", test_generic_queue_enqueue_dequeue},
        {"Memory Alloc Free", test_memory_management_allocation_free},
        {"Type Safety", test_type_safety_checks}
    };

    size_t count = sizeof(test_list) / sizeof(test_list[0]);
    run_test_suite(test_list, count);

    return EXIT_SUCCESS;
}


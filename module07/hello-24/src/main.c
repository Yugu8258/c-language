#include <stdio.h>
#include <inttypes.h>

int32_t add_two_numbers(int32_t num1, int32_t num2);

int main(void)
{
    int32_t result = add_two_numbers(5, 10);

    printf("The sum is: %d\n", result);

    return 0;
}

/**
 * Calculates the sum of two integers.
 *
 * Parameters:
 * - num1: The first integer for the sum.
 * - num2: The second integer for the sum.
 *
 * Returns:
 * - The sum of num1 and num2 as an int32_t.
 *
 * Notes:
 * - The function uses int32_t to ensure the calculation is compatible across different platform.
 * - This is a basic example intended for beginers who are not yet familiar with pointer.
 */
int32_t add_two_numbers(int32_t num1, int32_t num2)
{
    return num1 + num2;
}


#include <stdio.h>

int main(void)
{
    // double

    double num1 = 123.456;
    double num2 = 76.543;

    double sum = num1 + num2;
    double difference = num1 - num2;
    double product = num1 * num2;
    double quotient = num1 / num2;

    printf("Sum : %lf\n", sum);
    printf("Difference : %lf\n", difference);
    printf("Product : %lf\n", product);
    printf("Quotient : %lf\n", quotient);

    return 0;
}


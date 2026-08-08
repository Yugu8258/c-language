#include <stdio.h>

int main(void)
{
    int matrix[2][3] = {
        { 1, 2, 3 };
        { 2, 3, 4 };
    };

    int (*ptr)[3] = matrix;

    // (*ptr)[3] : ptr是一个指针, 它指向一个包含3个int元素的一维数组

    return 0;
}


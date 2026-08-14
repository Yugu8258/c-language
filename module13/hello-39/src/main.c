#include <stdio.h>

#define ROWS 3
#define COLS 4

// 传递过来的数组的列数已经确定
// void print_matrix(int (*matrix)[COLS], int rows);
// void print_matrix(int matrix[][COLS], int rows); // 编译器会转换为上面的写法

// void print_matrix(int matrix, int rows, int cols); // 使用一维数组模拟二维数组
// void print_matrix(int **matrix, int rows, int cols); // 动态二维数组

void print_matrix(int (*matrix)[COLS]);

void flip_image(int (*image)[COLS]);

int main(int argc, char *argv[])
{
    int arr[ROWS][COLS] = {
        { 1, 2, 3, 4 },
        { 2, 3, 4, 5 },
        { 3, 4, 5, 6 }
    };

    print_matrix(arr);

    flip_image(arr);

    printf("\n");
    print_matrix(arr);

    return 0;
}

void print_matrix(int (*matrix)[COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void flip_image(int (*image)[COLS])
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS / 2; j++)
        {
            // 交换对称
            int temp = image[i][j];
            // 镜像索引(symmetric index)
            image[i][j] = image[i][COLS - 1 - j];
            image[i][COLS - 1 - j] = temp;
        }
    }
}


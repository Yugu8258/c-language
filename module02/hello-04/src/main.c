#include <stdio.h>

int main(void)
{
    int number = 100;

    // 十进制表示
    printf("Decimal : %d\n", number);

    // 八进制表示
    printf("Octal : %o\n", number);

    // 以十六进制表示(小写)
    printf("Hexadeciaml (lowercase) : %#x\n", number);

    // 以十六进制表示(大写)
    printf("Hexaseciaml (uppercase) : %#X\n", number);

    // 左对齐
    printf("Left-aligned  : %-10d|\n", number);

    // 右对齐
    printf("Right-aligend : %10d|\n", number);
    
    // 特别标注正负号
    printf("Show plus : %+d\n", number);
    
    // 前导零
    printf("Leading zeros : %010d\n", number);

    return 0;
}


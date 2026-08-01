#include <stdio.h>

int main(void)
{
    // short
    short myShort = 100;

    printf("myShort : %hd\n", myShort);

    // 800x600
    unsigned short screenWidth = 800;
    unsigned short screenHeight = 600;

    // x,y
    unsigned short x = 400;
    unsigned short y = 300;

    printf("The screen resolution is : %hu X %hu\n", screenWidth, screenHeight);

    printf("Current position is : (%hu, %hu)\n", x, y);

    unsigned short color;

    color = 0b1111100000000000;

    printf("RED : 0x%x\n", color);

    return 0;
}


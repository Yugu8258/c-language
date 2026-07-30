#include <stdio.h>

int main(void)
{
    // float
    float temperature = 36.5f;

    float humidity = 48.3f;

    float speed_of_sound = 343.5e2f; // 343.5 * (10 ^ 2)

    float length = 12.34f, width = 23.45f, height = 343.56f;

    printf("Temperature: %f\n", temperature);
    printf("Humidity: %f\n", humidity);
    printf("Speed of Sound: %f\n", speed_of_sound);
    printf("Dimensions (LxWxH): %f x %f x %f\n", length, width, height);

    return 0;
}


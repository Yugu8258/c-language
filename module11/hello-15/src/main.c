#include <stdio.h>
#include <stdlib.h>

typedef struct GameSetting
{
    float volume;
    int resoultion_x;
    int resoultion_y;
    int difficulty;
} GameSetting;

void save_game_settings(const GameSetting *settings, const char *filename);
void load_game_settings(GameSetting *settings, const char *filename);

int main(void)
{
    // fread
    // fwrite

    // 读写二进制

    // 写二进制
    GameSetting settings = { 0.75f, 1920, 1080, 2 };

    save_game_settings(&settings, "game_settings.bin");

    // 读二进制
    GameSetting loaded_settings;

    load_game_settings(&loaded_settings, "game_settings.bin");

    puts("游戏配置已经加载!");
    printf("音量: %.2lf\n分辨率: %dx%d\n难度: %d\n",
            loaded_settings.volume,
            loaded_settings.resoultion_x,
            loaded_settings.resoultion_y,
            loaded_settings.difficulty);

    return 0;
}

void save_game_settings(const GameSetting *settings, const char *filename)
{
    FILE *file = NULL;

    file = fopen(filename, "wb");
    if (file == NULL)
    {
        perror("打开文件失败!");
        return;
    }

    fwrite(settings, sizeof(GameSetting), 1, file);

    fclose(file);
    filename = NULL;
}

void load_game_settings(GameSetting *settings, const char *filename)
{
    FILE *file = NULL;

    file = fopen(filename, "rb");
    if (file == NULL)
    {
        perror("打开文件失败!");
        return;
    }

    fread(settings, sizeof(GameSetting), 1, file);

    fclose(file);
    file = NULL;
}


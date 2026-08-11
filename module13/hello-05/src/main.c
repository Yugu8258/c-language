#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *name;
    int level;
    int hp;
} Character;

Character *create_character(const char *name, int level, int hp);
void free_character(Character *character);

int main(void)
{
    
    Character *hero = create_character("Hero", 1, 100);
    if (hero == NULL)
    {
        return EXIT_FAILURE;
    }

    free_character(hero);

    return EXIT_SUCCESS;
}

Character *create_character(const char *name, int level, int hp)
{
    Character *new_character = (Character *)malloc(sizeof(Character));
    if (new_character == NULL)
    {
        perror("Failed to allocate memory for new character.");
        return NULL;
    }

    new_character->name = (char *)malloc(strlen(name) + 1);
    if (new_character->name == NULL)
    {
        perror("Failed to allocate memory for new caharacter name.");
        free(new_character); // 防止内存泄露
        return NULL;
    }

    size_t name_len = strlen(name);
    strncpy(new_character->name, name, name_len);
    new_character->name[name_len] = '\0';

    new_character->level = level;
    new_character->hp = hp;

    return new_character;

}

void free_character(Character *character)
{
    if (character != NULL)
    {
        free(character->name); // 释放name字符串占用的内存
        free(character);
    }
}


#ifndef GAME_TYPES_H
#define GAME_TYPES_H

typedef enum
{
    Warrior,    // 战士
    Mage,       // 法师
    Rogue       // 流氓
} CharacterClass;

typedef enum
{
    Goblin,     // 妖怪
    Troll,      // 巨魔
    Dragon      // 巨龙
} EnemyType;

typedef enum
{
    weapon,     // 武器
    potion,     // 药水
    armor       // 盔甲
} ItemType;

#endif /* GAME_TYPES_H */


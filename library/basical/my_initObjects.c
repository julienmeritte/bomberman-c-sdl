/*
** ETNA PROJECT, 11/10/2019 by vignan_q
** my_initObjects.c
** File description:
**
*/

#include "../../include/objects.h"

#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

struct character my_initBaseCharacter(struct character character) {
    character.hitbox.charHeight = 30;
    character.hitbox.charWidth = 30;
    character.stats.lifePoints = 10;
    return character;
}

struct character my_initMyCharacter()
{
    struct character character;
    character = my_initBaseCharacter(character);
    character.colors.red = 147;
    character.colors.green = 112;
    character.colors.blue = 219;
    return character;
}

struct character my_initEnemyCharacter()
{
    struct character character;
    character = my_initBaseCharacter(character);
    character.colors.red = 220;
    character.colors.green = 20;
    character.colors.blue = 60;
    return character;
}

struct character my_initCharacter(enum _characterType characterType) {
    switch (characterType) {
        case 0:
            SDL_Log("My Character initialized with base stats.");
            return my_initMyCharacter();
        case 1:
            SDL_Log("Enemy Character initialized with base stats.");
            return my_initEnemyCharacter();
    }
}
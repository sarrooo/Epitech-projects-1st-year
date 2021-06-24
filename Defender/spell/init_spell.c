/*
** EPITECH PROJECT, 2021
** defender
** File description:
** init spell
*/

#include "../include/defender.h"

void game_load_spell_fire(game_t *game)
{
    game->map.fireball.texture_spell =
    sfTexture_createFromFile("./asset/firesheet.png", NULL);
    game->map.fireball.cursor_texture =
    sfTexture_createFromFile("./asset/cursor.png", NULL);
    game->map.fireball.sprite_spell = sfSprite_create();
    game->map.fireball.cursor = sfSprite_create();
    sfSprite_setTexture(game->map.fireball.sprite_spell,
    game->map.fireball.texture_spell, sfTrue);
    sfSprite_setTexture(game->map.fireball.cursor,
    game->map.fireball.cursor_texture, sfTrue);
    game->map.fireball.available = 1;
    game->map.fireball.rect = (sfIntRect){0, 0, 100, 208};
    sfSprite_setTextureRect(game->map.fireball.sprite_spell,
    game->map.fireball.rect);
    game->map.fireball.position = (sfVector2f){0, 0};
    game_load_spell_sound_fire(game);
    game->map.fireball.targeting = -1;
    game->map.fireball.damage = 80;
    game->map.fireball.available = 0;
    game->map.fireball.last_move = 0;
}

void game_load_spell_freeze(game_t *game)
{
    game->map.freeze.texture_spell =
    sfTexture_createFromFile("./asset/freezesheet.png", NULL);
    game->map.freeze.cursor_texture =
    sfTexture_createFromFile("./asset/cursor.png", NULL);
    game->map.freeze.sprite_spell = sfSprite_create();
    game->map.freeze.cursor = sfSprite_create();
    sfSprite_setTexture(game->map.freeze.sprite_spell,
    game->map.freeze.texture_spell, sfTrue);
    sfSprite_setTexture(game->map.freeze.cursor,
    game->map.freeze.cursor_texture, sfTrue);
    game->map.freeze.available = 1;
    game->map.freeze.rect = (sfIntRect){0, 0, 100, 200};
    sfSprite_setTextureRect(game->map.freeze.sprite_spell,
    game->map.freeze.rect);
    game->map.freeze.position = (sfVector2f){0, 0};
    game_load_spell_sound_freeze(game);
    game->map.freeze.targeting = -1;
    game->map.freeze.damage = 80;
    game->map.freeze.available = 0;
    game->map.freeze.last_move = 0;
}

void game_load_spell_sound_freeze(game_t *game)
{
    game->map.freeze.animation = 0;
    game->map.freeze.icone = sfSprite_create();
    game->map.freeze.t_icone =
    sfTexture_createFromFile("./asset/freeze.png", NULL);
    sfSprite_setTexture(game->map.freeze.icone,
    game->map.freeze.t_icone, sfTrue);
    sfSprite_setPosition(game->map.freeze.icone,
    (sfVector2f){0, 100});
    sfSprite_setColor(game->map.freeze.cursor, sfBlue);
    game->map.freeze.soundbuffer =
    sfSoundBuffer_createFromFile("./asset/glace.ogg");
    game->map.freeze.sound = sfSound_create();
    sfSound_setBuffer(game->map.freeze.sound,
    game->map.freeze.soundbuffer);
    sfSound_setLoop(game->map.freeze.sound, sfTrue);
}

void game_load_spell_sound_fire(game_t *game)
{
    game->map.fireball.animation = 0;
    game->map.fireball.icone = sfSprite_create();
    game->map.fireball.t_icone =
    sfTexture_createFromFile("./asset/fire.png", NULL);
    sfSprite_setTexture(game->map.fireball.icone,
    game->map.fireball.t_icone, sfTrue);
    sfSprite_setPosition(game->map.fireball.icone,
    (sfVector2f){0, 0});
    sfSprite_setColor(game->map.fireball.cursor, sfRed);
    game->map.fireball.soundbuffer =
    game->map.fireball.soundbuffer =
    sfSoundBuffer_createFromFile("./asset/meteor.ogg");
    game->map.fireball.sound = sfSound_create();
    sfSound_setBuffer(game->map.fireball.sound,
    game->map.fireball.soundbuffer);
    sfSound_setLoop(game->map.fireball.sound, sfTrue);
}

void game_destroy_spell(game_t *game)
{
    sfTexture_destroy(game->map.fireball.texture_spell);
    sfTexture_destroy(game->map.fireball.cursor_texture);
    sfTexture_destroy(game->map.fireball.t_icone);
    sfSprite_destroy(game->map.fireball.sprite_spell);
    sfSprite_destroy(game->map.fireball.cursor);
    sfSprite_destroy(game->map.fireball.icone);
    sfSound_destroy(game->map.fireball.sound);
    sfSoundBuffer_destroy(game->map.fireball.soundbuffer);
    sfTexture_destroy(game->map.freeze.texture_spell);
    sfTexture_destroy(game->map.freeze.cursor_texture);
    sfTexture_destroy(game->map.freeze.t_icone);
    sfSprite_destroy(game->map.freeze.sprite_spell);
    sfSprite_destroy(game->map.freeze.cursor);
    sfSprite_destroy(game->map.freeze.icone);
    sfSound_destroy(game->map.freeze.sound);
    sfSoundBuffer_destroy(game->map.freeze.soundbuffer);
}

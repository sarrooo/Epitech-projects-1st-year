/*
** EPITECH PROJECT, 2021
** m_defender
** File description:
** create str to wave
*/

#include "include/defender.h"

void destroy_wave_str(game_t *main_s)
{
    int i = 0;

    for (i = 0; main_s->map.wave[i] != NULL; i++)
        free(main_s->map.wave[i]);
    free(main_s->map.wave[i]);
}

char **load_wave(game_t *main_s)
{
    char **wave = malloc(sizeof(char *) * 11);

    main_s->map.wave = malloc(sizeof(char *) * 11);
    main_s->map.wave[0] = "111  32  21221   22";
    main_s->map.wave[1] = "1111  2121212 12   223";
    main_s->map.wave[2] = "323232 32121 22";
    main_s->map.wave[3] = "33 222322  23111";
    main_s->map.wave[4] = "11221  1121122 43222   3211";
    main_s->map.wave[5] = "221211 222222   2222   21221111";
    main_s->map.wave[6] = "333 3333    33333   3333";
    main_s->map.wave[7] = "222 111 21212121   33213211";
    main_s->map.wave[8] = "3 212321 3212322  11112332";
    main_s->map.wave[9] = "4 221231212 333212  4 32122  2222";
    main_s->map.wave[10] = NULL;
    return (wave);
}
/*
** EPITECH PROJECT, 2021
** B-PSU-210-LYN-2-1-42sh-ahmed.abouelleil-sayed
** File description:
** error_handling_set
*/

#include "shell42.h"

static int check_non_alpha(char letter)
{
    int ok = 0;

    if (!(letter > 64 && letter < 91))
        ok = 1;
    if (ok == 1 && letter > 96 && letter < 123)
        ok = 0;
    if (ok == 1 && letter > 47 && letter < 58)
        ok = 0;
    if (ok == 1 && letter == '.')
        ok = 0;
    if (ok == 1) {
        dprintf(2,
        "set: Variable name must contain alphanumeric characters.\n");
        return 1;
    }
    return 0;
}

static void check_begin_letter(char *str, char **args, int *ok)
{
    int i = 0;

    if (!(args[0][0] >= 'A' && args[0][0] <= 'Z'))
        *ok = 1;
    if (*ok == 1 && args[0][0] >= 'a' && args[0][0] <= 'z')
        *ok = 0;
    if (*ok == 0) {
        for (i = 0; args[0][i] != 0 && args[0][i] != 32; i++);
        if (i != strlen(args[0]))
            *ok = 1;
    }
}

int set_error_handling(char *str)
{
    char **args = pars_set_var(str);
    int ok = 0;

    check_begin_letter(str, args, &ok);
    if (ok == 1) {
        dprintf(2, "set: Variable name must begin with a letter.\n");
        destroy_var_array(args);
        return 1;
    }
    for (int i = 0; args[0][i] != 0; i++) {
        if (check_non_alpha(args[0][i]) == 1) {
            destroy_var_array(args);
            return 1;
        }
    }
    destroy_var_array(args);
    return 0;
}